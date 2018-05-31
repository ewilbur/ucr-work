#include "Date.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
	Date a(11, 12, 1993);
	Date b(5, 19, 2016);

	cout << (a - b) << endl;
}
