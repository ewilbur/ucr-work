#include <string>
#include <iostream>
#include <cmath>
#include <ctime>


using namespace std;

void reverse(string&);

int main()
{
}

void reverse(string &s)
{
	if(s.size()) 
	{
		string t = s.substr(1);
		reverse(t);
		s = t + s.at(0);
	}
	return;
}

