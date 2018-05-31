//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<1>/part3.cpp 
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

const int ARRAY_SIZE = 500;

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
    return pow(varianceSqr / arraySize, 0.5);
}

int main()
{
    srand(333);

    double lowerBoundZeroMean = -3 * pow(3, 0.5),
           upperBoundZeroMean = 3 * pow(3, 0.5),
           theoreticalZeroMean = 0,
           actualZeroMean,
           actualZeroVar,
           zeroMeanArray[ARRAY_SIZE],

           lowerBoundNegMean = -4 - (3 * pow(3, 0.5)),
           upperBoundNegMean = -4 + (3 * pow(3, 0.5)),
           theoreticalNegMean = -4,
           actualNegMean,
           actualNegVar,
           negMeanArray[ARRAY_SIZE],

           theoreticalVar = 3;

           for(int i = 0; i < ARRAY_SIZE; i++)
           {
               zeroMeanArray[i] = randFloat(lowerBoundZeroMean,
                                            upperBoundZeroMean);

               negMeanArray[i]  = randFloat(lowerBoundNegMean,
                                            upperBoundNegMean);
           }

           actualZeroMean = average(zeroMeanArray, ARRAY_SIZE);
           actualNegMean  = average(negMeanArray, ARRAY_SIZE);

           actualZeroVar = variance(zeroMeanArray, ARRAY_SIZE);
           actualNegVar  = variance(negMeanArray, ARRAY_SIZE);

           cout << theoreticalZeroMean << ' '
                << actualZeroMean      << ' '
                << theoreticalVar      << ' '
                << actualZeroVar       << endl;

           cout << theoreticalNegMean  << ' '
                << actualNegMean       << ' '
                << theoreticalVar      << ' '
                << actualNegVar        << endl;
}

