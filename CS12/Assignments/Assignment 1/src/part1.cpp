//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<1>/part1.cpp 
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
#include <cstdlib>
#include <cmath>

using namespace std;

const int SMALLER_ARRAY = 1000;
const int LARGER_ARRAY = 100000;


double randFloat(double a, double b)
{
   return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

double sum(double randArray[], int arraySize)
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
    return pow(varianceSqr / arraySize, 1);
}

int main()
{
    srand(333);

    double userLowerBound,
           userUpperBound,
           randSmallArray[SMALLER_ARRAY],
           randLargeArray[LARGER_ARRAY],
           theoreticalMean,
           theoreticalVariance,
           actualMeanLower,
           actualVarianceLower,
           actualMeanUpper,
           actualVarianceUpper;


    cout << "Enter a lower bound for the random integer. ";
    cin >> userLowerBound;

    cout << "Enter an upper bound for the random integer. ";
    cin >> userUpperBound;

    theoreticalMean = (userLowerBound + userUpperBound) / 2.0;
    theoreticalVariance = pow(userUpperBound - userLowerBound, 2) / 12;


    for(int i = 0; i < SMALLER_ARRAY; i++)
    {
        randSmallArray[i] = randFloat(userLowerBound, userUpperBound);
    }

    for(int i = 0; i < LARGER_ARRAY; i++)
    {
        randLargeArray[i] = randFloat(userLowerBound, userUpperBound);
    }

    actualMeanLower     = average (randSmallArray, SMALLER_ARRAY);
    actualMeanUpper     = average (randLargeArray, LARGER_ARRAY);
    actualVarianceLower = variance(randSmallArray, SMALLER_ARRAY);
    actualVarianceUpper = variance(randLargeArray, LARGER_ARRAY);

    cout << theoreticalMean     << ' '
         << actualMeanLower     << ' '
         << theoreticalVariance << ' '
         << actualVarianceLower << endl;

    cout << theoreticalMean     << ' '
         << actualMeanUpper     << ' '
         << theoreticalVariance << ' '
         << actualVarianceUpper << endl;
}

