/*
 ******************************************************************************
 Evan Wilbur
 CS14 UCR Winter 2016
 February 2016
 Assignment 3
 Lab Section 21
 ******************************************************************************
 */


#include <iostream>
#include <list>
#include <iterator>
#include <cmath>
#include <fstream>
#include <string>
#include "Fraction.h"
#include <sstream>
#include <cstdlib>
#include <ctime>


using namespace std;


template <class ListType, class ListIter>
ListIter move(list< ListType > &lst, ListIter, ListIter);

template <class ListType, class ListIter>
void merge(list< ListType > &lst, ListIter, int, ListIter, int);

/*template <class ListType>
void mergeSort(list< ListType > &lst, int, int);*/

template <class ListType>
void mergeSort(list< ListType > &lst);

template <class ListType, class ListIter>
void mergeSort(list< ListType > &lst, ListIter node, int size);

template <class ListType>
int size(list< ListType > &lst);

template <class ListType>
void print(list< ListType > &lst);

bool is_user_idiot(char*);

bool fileExists(char*);

int file_size(string);

void make_file(string, int);


int main(int argc, char *argv[])
{
	//*******************************************/
	// Make sure the user didn't make a mistake */
	//*******************************************/
	cout << endl;
	if(argc != 2)
	{
		cout << "Error: expected 1 command line argument, received " << argc - 1;
		return 1;
	}

	else if(is_user_idiot(argv[1]))
	{
		cout << "Error: invalid file name.";
		return 1;
	}

	else if(fileExists(argv[1]))
	{
		cout << "Warning the file " << argv[1] << ".out already exists. " << endl;
		cout << "The current file will be overwritten if you continue.\n" << endl;

		cout << "Do you wish to continue? (y / n) ";

		char answer;
		cin >> answer;

		while(answer != 'y' && answer != 'n')
		{
			cout << "Do you wish to continue? (y / n) ";
			cin >> answer;
		}

		if(answer != 'y')
			return 1;
	}



	string strFile = argv[1];
	string strOut = strFile + ".out";
	string strIn = strFile + ".txt";

//	make_file(strIn, 20);

	string line;

	ofstream outputFile(strOut.c_str());
	ifstream inputFile(strIn.c_str());


	// Go through the file
	for(; getline(inputFile, line);)
	{
		// Integer signal
		if(line == "i")
		{
			
			int val;
			getline(inputFile, line);
			stringstream ss(line);

			list<int> intList;
			list<int>::iterator iter;

			// Create the int list
			while(ss >> val)
				intList.push_back(val);

			// Sort it
			mergeSort(intList);

			outputFile << "i" << endl;

			iter = intList.begin();

			// Store it
			for(; iter != intList.end(); ++iter)
				outputFile << *iter << ' ';

			outputFile << endl;
		}

		else
		{
			// Same as above, but with fraction class 
			int num;
			int den;
			getline(inputFile, line);
			stringstream ss(line);

			list<Fraction> fracList;
			list<Fraction>::iterator iter;

			while(ss >> num)
			{
				ss >> den;
				fracList.push_back(Fraction(num, den));
			}

			mergeSort(fracList);

			outputFile << "f" << endl;

			iter = fracList.begin();

			for(; iter != fracList.end(); ++iter)
				outputFile << *iter << ' ';

			outputFile << endl;
		}
	}

	outputFile.close();
	inputFile.close();
}

/* Print the list. Not needed for actual program */
template <class ListType>
void print(list< ListType > &lst)
{
	typename list<ListType>::iterator a;
	for(a = lst.begin(); a != lst.end(); a++)
		cout << *a << ' ';
}

/* Moves a node from source and inserts it before dest. Returns node after
 * source's original position */
template <class ListType, class ListIter>
ListIter move(list< ListType > &lst, ListIter source, ListIter dest)
{
	lst.insert(dest, *source);
	return lst.erase(source);
}

/* Merge left part of list with right part */
template <class ListType, class ListIter>
void merge(list< ListType > &lst, ListIter left, int leftSize, ListIter right, int rightSize)
{
	if(leftSize == 0 || rightSize == 0);

	else
	{
		if(*left < *right || *left == *right)
		{
			++left;
			--leftSize;
			merge(lst, left, leftSize, right, rightSize);
		}

		else
		{
			right = move(lst, right, left);
			
			--rightSize;
			merge(lst, left, leftSize,right, rightSize);
		}
	}

	
	
}

/*template <class ListType>
void mergeSort(list< ListType > &lst, int start, int size)
{
	// List of size 1 or 0 is already sorted 
	if(size <= 1)
		return;

	else
	{
		// Set the new right index to be halfway between the
		// passed values 
		int rightIndex = (size / 2) + start;

		int leftSize = rightIndex - start;
		int rightSize = size - leftSize;

		// Sort the left 
		mergeSort(lst, start, leftSize);

		// Sort the right 
		mergeSort(lst, rightIndex, rightSize);

		typename list<ListType>::iterator leftNode, rightNode;

		leftNode = rightNode = lst.begin();
		advance(leftNode, start);
		advance(rightNode, rightIndex);

		
		// Merge the two halves together 
		merge(lst, leftNode, leftSize, rightNode, rightSize);
	}
}*/

template <class ListType, class ListIter>
void mergeSort(list< ListType > &lst, ListIter leftNode, int size)
{
	if(size <= 1)
		return;

	else
	{
		int leftSize = size / 2;
		int rightSize = size - leftSize;
		int leftIndex = distance(lst.begin(), leftNode);

		ListIter rightNode = leftNode;
		advance(rightNode, leftSize);

		mergeSort(lst, leftNode, leftSize);
		mergeSort(lst, rightNode, rightSize);

		leftNode = lst.begin();

		advance(leftNode, leftIndex);
		rightNode = leftNode;
		advance(rightNode, leftSize);

		merge(lst, leftNode, leftSize, rightNode, rightSize);
	}
}

template <class ListType>
void mergeSort(list< ListType > &lst)
{
	typename list< ListType >::iterator a = lst.begin();
	mergeSort(lst, a, size(lst));
}

/* Returns size of linked list */
template <class ListType>
int size(list< ListType > &lst)
{
	int sum = 0;
	typename list<ListType>::iterator a = lst.begin();

	for(; a != lst.end(); ++a)
		++sum;

	return sum;
}

/* Not complete, checks for valid file input */
bool is_user_idiot(char *input)
{
	int i = 0;
	for(; input[i] != '\0'; ++i)
	{
		if(input[i] == '.')
			return true;
	}

	return false;
}

/* Checks if the file exists */
bool fileExists(char *fileName)
{
	string cppStr = fileName;
	cppStr += ".out";

	ifstream file(cppStr.c_str());

	if(file.good())
	{
		file.close();
		return true;
	}

	else
	{
		file.close();
		return false;
	}

}

/* No longer needed */
int file_size(string file)
{
	ifstream f(file.c_str());

	string line;

	int i = 0;

	for(; getline(f, line); ++i);

	f.close();

	return i;
}

void make_file(string name, int size)
{
	srand(time(0));

	ofstream file(name.c_str());

	for(int i = 0; i < size * 2; i++)
	{
		if(rand() % 2 == 0)
		{
			file << "i" << endl;
			for(int j = 0; j < size; j++)
			{
				file << -1 * (rand() % 100) << ' ';
			}
			file << endl;
		}
		else
		{
			file << "f" << endl;
			for(int j = 0; j < (size + 1) * 2; j++)
			{
				file << 1 + rand() % 100 << ' ';
			}
			file << endl;
		}
	}

	file.close();
}