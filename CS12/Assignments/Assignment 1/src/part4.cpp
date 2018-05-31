//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<1>/part4.cpp 
/// @brief Assignment <1> for CS 12 <Fall 2015r>
///
/// @author <Evan Wilbur> [ewilb001@ucr.edu]
/// @date <10/6/2015>
///
/// @par Enrollment Notes 
///     Lecture Section: <e.g. 001>
/// @par
///     Lab Section: <e.g. 021>
/// @par
///     TA: <TA name>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double randFloat (double a, double b)
{
   return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

double rand_mv(double mean, double var)
{
    double a = mean - sqrt(var * 3);
    double b = mean + sqrt(var * 3);

    cout << a << ' '
         << b << endl;

    return randFloat(a, b);
}
/*double sum(double randArray[], int arraySize)
{
    double sum = 0;

    for(int i = 0; i < arraySize; i++)
    {
        sum += randArray[i];
    }
    return sum;
}

double average(double randArray[], int arraySize)
{
    return sum(randArray, arraySize) / arraySize;
}

double variance(double randArray[], int arraySize)
{
    double mean = average(randArray, arraySize);
    double varianceSqr = 0;

    for(int i = 0; i < arraySize; i++)
    {
        varianceSqr += pow((randArray[i] - mean), 2);
    }
    return pow(varianceSqr / arraySize, 0.5);
}

void testHarness(double x, double y)
{
    double v[5000];
    for(int i = 0; i < 5000; i++)
    {
        v[i] = rand_mv(x, y);
    }
    cout << variance(v, 5000) << endl;
    cout << average(v, 5000) << endl;
}*/

int main()
{
    double mean, var;

    cout << "Enter Mean: ";
    cin >> mean;

    cout << "Enter Variance: ";
    cin >> var;

    rand_mv(mean, var);
}


