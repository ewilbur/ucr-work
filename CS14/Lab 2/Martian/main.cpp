/*
 ******************************************************************************
 Evan Wilbur
 CS14 UCR Winter 2016
 January 2016
 Assignment 2
 Lab Section 21
 ******************************************************************************
 */


#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Dumb.h"
#include "Smart.h"
#include "Martian.h"
#include "Cache.h"

using namespace std;

bool is_digit(char);
bool is_number(char*);
bool is_flag(char*);
bool check_arguments(int, char**);
int str_to_int(char*);
int length(char*);
int power(int, int);
bool check_flags(vector<string>);



int main(int argc, char *argv[])
{
	string baseFileName;
	int bound;
	vector<string> flags;
	bool tableSet = false;


	if(!check_arguments(argc, argv))
		return 1;

	for(int i = 1; i < argc; i++)
	{
		if(is_flag(argv[i]))
			flags.push_back(argv[i]);

		else if(is_number(argv[i]))
			bound = str_to_int(argv[i]);

		else
			baseFileName = argv[i];
	}

	if(!check_flags(flags))
		return 1;



	ofstream fexcel((baseFileName + ".csv").c_str());
	ofstream ftable((baseFileName + ".out").c_str());

	for(int i = 0; i < flags.size(); i++)
	{
		if(flags.at(i) == "-dumb")
		{
			fexcel << flags.at(i) << endl;

			int j;
			for(j = 1; j < bound; j++)
				fexcel << j << ", ";

			fexcel << j << endl;

			for(j = 1; j <= bound; j++)
			{
				Dumb a(j);
				a.solve();
				fexcel << a.get_ticks();
				if(j != bound)
					fexcel << ", ";

				if(!tableSet)
				{
					ftable << "EA " << j << " = MU " << a;
					ftable << endl;
				}
			}
			fexcel << endl;
			ftable.close();
			tableSet = true;
		}
		else if(flags.at(i) == "-cache")
		{
			fexcel << flags.at(i) << endl;

			int j;
			for(j = 1; j < bound; j++)
				fexcel << j << ", ";
			fexcel << j << endl;

			for(j = 1; j <= bound; j++)
			{
				Cache a(j);
				a.solve();
				fexcel << a.get_ticks();
				if(j != bound)
					fexcel << ", ";

				if(!tableSet)
				{
					ftable << "EA " << j << " = MU " << a;
					ftable << endl;
				}
			}
			fexcel << endl;
			ftable.close();
			tableSet = true;
		}
		else if(flags.at(i) == "-smart")
		{
			fexcel << flags.at(i) << endl;

			int j;
			for(j = 1; j < bound; j++)
				fexcel << j << ", ";
			fexcel << j << endl;

			for(j = 1; j <= bound; j++)
			{
				Smart a(j);
				a.solve();
				fexcel << a.get_ticks();
				if(j != bound)
					fexcel << ", ";

				if(!tableSet)
				{
					ftable << "EA " << j << " = MU " << a;
					ftable << endl;
				}
			}
			fexcel << endl;
			ftable.close();
			tableSet = true;
		}
	}

	fexcel.close();
}

bool is_digit(char character)
{
	return (character >= '0') && (character <= '9');
}

bool is_number(char *character)
{
	if(*character == '\0')
		return true;

	else if(is_digit(*character))
		return is_number(character + 1);

	else return false;
}

bool is_flag(char *character)
{
	return *character == '-';
}


bool check_arguments(int numArgs, char *args[])
{
	int arguments[3] = {0, 0, 0};
	bool valid = true;

	for(int i = 1; i < numArgs; i++)
	{
		if(is_flag(args[i]))
			arguments[0]++;

		else if(is_number(args[i]))
			arguments[1]++;

		else
			arguments[2]++;
	}

	if(arguments[0] == 0)
	{
		cout << "Error: no arguments given for flags" << endl;
		valid = false;
	}

	if(arguments[1] != 1)
	{
		cout << "Error: expected 1 argument for bound, received " << arguments[1] << endl;
		valid = false;
	}
	if(arguments[2] != 1)
	{
		cout << "Error: expected 1 argument for file, received " << arguments[2] << endl;
		valid = false;
	}

	return valid;
}

int length(char *v)
{
	if(*v == '\0')
		return 0;

	else
		return 1 + length(v + 1);
}

int power(int i, int j)
{
	if(j == 0)
		return 1;

	else
		return i * power(i, j - 1);
}

int str_to_int(char *v)
{
	int len = length(v);
	int num = 0;

	for(int i = 0; i < len; i++)
		num += power(10, len - (i + 1)) * (v[i] - '0');

	return num;
}

bool check_flags(vector<string> v)
{
	bool valid = true;
	for(int i = 0; i < v.size(); i++)
	{
		if(v.at(i) != "-smart" && v.at(i) != "-dumb" && v.at(i) != "-cache")
		{
			cout << "Error invalid flag: " << v.at(i) << endl;
			valid = false;
		}
	}
	return valid;
}
