//  =============== BEGIN ASSESSMENT HEADER ================
/// @file mathematics.cpp
/// @brief assn6
///
/// @author Evan Wilbur [ewilb001@ucr.edu]
/// @date May 5, 2015
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment,
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============


#include <iostream>
#include <cmath>
#include <string>

const int OK = 0;
const int DIV_ZERO = 1;
const int SQRT_ERR = 2;

using namespace std;

int division(double a, double b, double &result)
{
	if (b == 0)
	{
		return DIV_ZERO;
	}
	else
	{
		result = a / b;
		return OK;
	}
}

int quadratic(double a, double b, double c, double &root1, double &root2)
{
    //comment
	if (pow(b, 2) - 4 * a * c < 0)
	{
		return SQRT_ERR;
	}

	else
	{
		root1 = ((-1) * b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		root2 = ((-1) * b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		return OK;
	}
}

int pythagorean(double a, double b, double &result)
{
	result = sqrt(pow(a, 2) + pow(b, 2));

	return OK;
}

int acquireOperands(const string &op, double &x, double &y, double &z)
{
	if (op == "division" || op == "pythagorean")
	{
		cout << "Enter your first number: ";
		cin >> x;
		cout << endl;

		cout << "Enter your second number: ";
		cin >> y;
		cout << endl;

		return 2;
	}
	else
	{
		cout << "Enter your first number: ";
		cin >> x;
		cout << endl;

		cout << "Enter your second number: ";
		cin >> y;
		cout << endl;

		cout << "Enter your third number: ";
		cin >> z;
		cout << endl;

		return 3;
	}
}


int main()
{
	string operation;

	double gin;
	double tonic;
	double shitfuck;
	double result;
	double result2;

	int isValid;


	do
	{
		cout << "Please choose an operation: ";
		cin >> operation;
		cout << endl;

		if (operation != "pythagorean"
      && operation != "division"
      && operation != "quadratic")
		{
			cout << "Error: Operation not supported." << endl;
		}
	} while (operation != "pythagorean"
          && operation != "division"
          && operation != "quadratic");

	acquireOperands(operation, gin, tonic, shitfuck);

	if (operation == "division")
	{
		isValid = division(gin, tonic, result);
		if (isValid == OK)
        {
            cout << "Equation: " << gin << " / " << tonic << endl;
            cout << "Result: " << result << endl;
        }
        else
        {
            cout << "Error: Cannot divide by zero." << endl;
        }
	}
	else if (operation == "pythagorean")
	{
		isValid = pythagorean(gin, tonic, result);
		if (isValid == OK)
        {
            cout << "Result: " << result << endl;
        }
	}
	else
	{
		isValid = quadratic(gin, tonic, shitfuck, result, result2);
		if (isValid == 0)
        {
            cout << "Equation: " << gin << "x^2 + " << tonic << "x + " << shitfuck;
            cout << "Result: " << result << ", " << result2 << endl;
        }
        else
        {
            cout << "Error: negative discriminate." << endl;
        }
	}
return 0;

}
