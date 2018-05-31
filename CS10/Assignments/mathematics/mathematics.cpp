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
		cout << "Error: Cannot divide by zero." << endl;
		return DIV_ZERO;
	}
	else
	{
		result = a / b;
		cout << "Equation: " << a << " / " << b << endl;
		cout << "Result: " << result << endl;
		return OK;
	}
}

int quadratic(double a, double b, double c, double &root1, double &root2)
{
    //comment
	if (pow(b, 2) - 4 * a * c < 0)
	{
		cout << "Error: negative discriminate." << endl;
		return SQRT_ERR;
	}

	else
	{
		root1 = ((-1) * b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		root2 = ((-1) * b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		cout << "Equation: " << a << "x^2 + " << b << "x + " << c;
		cout << "Result: " << root1 << ", " << root2 << endl;
		return OK;
	}
}

int pythagorus(double a, double b, double &result)
{
	result = sqrt(pow(a, 2) + pow(b, 2));

	cout << "Result: " << result << endl;
	return OK;
}

int acquireOperands(const string &op, double &x, double &y, double &z)
{
	if (op == "division" || op == "pythagorus")
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


	do
	{
		cout << "Please choose an operation: ";
		cin >> operation;
		cout << endl;

		if (operation != "pythagorus" && operation != "division" && operation != "quadratic")
		{
			cout << "Error: Operation not supported." << endl;
		}
	} while (operation != "pythagorus" && operation != "division" && operation != "quadratic");

	acquireOperands(operation, gin, tonic, shitfuck);

	if (operation == "division")
	{
		division(gin, tonic, result);
	}
	else if (operation == "pythagorus")
	{
		pythagorus(gin, tonic, result);
	}
	else
	{
		quadratic(gin, tonic, shitfuck, result, result2);
	}

}
