#include "BST.h"

#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;
/*
int main()
{
	BST<int> a;
	srand(time(0));
	for(int i = 0; i < 200; i++)
		a.insert(rand() % 203);

	cout << a << endl;


}*/

template<class Type>
void splinter(BST<Type>&, BST<Type>&, BST<Type>&, BST<Type>&);

string strip(string);
bool file_exists(string);
bool setup(string, ifstream&, ofstream&);
void makefile(string);

// AVL tree implemented. EXTRA CREDIT PLEASE :P 

int main(int argc, char *argv[])
{
	// Not the correct number of inputs
	if(argc != 2)
	{
		cout << "Error expected 1 file passed as cmd argument, received " << argc - 1 << endl;
		return 1;
	}

	string userFile = argv[1];
	ofstream resultFile;
	ifstream dataFile;

	makefile(userFile);

	if(setup(userFile, dataFile, resultFile))
	{
		string lineA;
		string lineB;

		for(int i = 1; getline(dataFile, lineA); i++)
		{
			if(lineA == "") getline(dataFile, lineA);

			getline(dataFile, lineB);

			stringstream ssA(lineA);
			stringstream ssB(lineB);

			BST<double> a, b, c, d;

			double aVal;
			double bVal;

			while(ssA >> aVal) a.insert(aVal);
			while(ssB >> bVal) b.insert(bVal);

			splinter(a, b, c, d);

			resultFile << "TEST CASE: " << i << endl;

			a.print_order(resultFile);
			resultFile << endl;
			b.print_order(resultFile);
			resultFile << endl;
			c.print_order(resultFile);
			resultFile << endl;
			d.print_order(resultFile);
			resultFile << endl << endl;

			resultFile << a << endl;
			resultFile << b << endl;
			resultFile << c << endl;
			resultFile << d << endl;

		}
	}

	else return 1;

	resultFile.close();
	dataFile.close();
}

template<class Type>
void splinter(BST<Type> &a, BST<Type> &b, BST<Type> &intersect, BST<Type> &symDif)
{
	// For everything in a
	for(int i = 0; i < a.values().size(); ++i)
	{
		// Put it in b if the value is also in b
		if(b.search(a.values().at(i)))
			intersect.insert(a.values().at(i));

		// Otherwise it's not in b so it belongs in the symDif
		else
			symDif.insert(a.values().at(i));
	}

	// For everything in b
	for(int i = 0; i < b.values().size(); ++i)
	{
		// If it's not in the intersection, put it in symDif
		if(!intersect.search(b.values().at(i)))
			symDif.insert(b.values().at(i));
	}

	return;
}


// Removes the ".txt" or any other file tag from the string
string strip(string input)
{
	int i;
	for(i = input.size(); i >= 0; --i)
		if(input[i] == '.') break;

	return (i == -1) ? input : input.substr(0, i);
}

// Checks if the file exists
bool file_exists(string fileName)
{
	ifstream file(fileName.c_str());

	if(file.good())
	{
		file.close();
		return true;
	}

	file.close();
	return false;
}

// Lazy implementation to get some working data file
// Don't judge this, it's 8PM and I'm late to a friend's birthday party
// Think of this as a brute force check of valid file names
// Obviously this should be improved
bool setup(string userArgument, ifstream &data, ofstream &result)
{
	if(file_exists(userArgument))
	{
		data.open(userArgument.c_str());
		userArgument = strip(userArgument) + ".out";
		result.open(userArgument.c_str());
		return true;
	}

	else
	{
		userArgument += ".txt";
		if(file_exists(userArgument))
		{
			data.open(userArgument.c_str());
			userArgument = strip(userArgument) + ".out";
			result.open(userArgument.c_str());
			return true;
		}

		userArgument = strip(strip(userArgument)) + ".txt";
		if(file_exists(userArgument))
		{
			data.open(userArgument.c_str());
			userArgument = strip(userArgument) + ".out";
			result.open(userArgument.c_str());
			return true;
		}
	}

	cout << "error: unable to open file " << userArgument << ".txt. Perhaps you didn't type it in correctly?" << endl;
	return false;
}

void makefile(string name)
{
	name = strip(name);

	name += ".txt";

	ofstream f(name.c_str());
	srand(time(0));

	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			f << rand() % 203 << ' ';
		}

		f << endl;
	}

	f.close();
}
