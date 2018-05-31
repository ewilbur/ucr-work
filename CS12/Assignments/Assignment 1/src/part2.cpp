//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<1>/part2.cpp 
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

    double lowerBoundLargeVariance = 4 - (2 * pow(3, 0.5)),
           upperBoundLargeVariance = 4 + (2 * pow(3, 0.5)),
           lowerBoundSmallVariance = 4 - (pow(3, 0.5) / 2),
           upperBoundSmallVariance = 4 + (pow(3, 0.5) / 2),
           smallVarianceArray[ARRAY_SIZE],
           largeVarianceArray[ARRAY_SIZE],
           meanSmallVariance,
           meanLargeVariance,
           varianceSmallVariance,
           varianceLargeVariance,
           theoreticalVarianceSmall = 0.5,
           theoreticalVarianceLarge = 2.0,
           theoreticalMean = 4;

           for(int i = 0; i < ARRAY_SIZE; i++)
           {
               smallVarianceArray[i] = randFloat(lowerBoundSmallVariance,
                                                 upperBoundSmallVariance);
               largeVarianceArray[i] = randFloat(lowerBoundLargeVariance,
                                                 upperBoundLargeVariance);
           }

           meanSmallVariance     = average(smallVarianceArray, ARRAY_SIZE);
           meanLargeVariance     = average(largeVarianceArray, ARRAY_SIZE);
           varianceSmallVariance = variance(smallVarianceArray, ARRAY_SIZE);
           varianceLargeVariance = variance(largeVarianceArray, ARRAY_SIZE);

           cout << theoreticalMean          << ' '
                << meanSmallVariance        << ' '
                << theoreticalVarianceSmall << ' '
                << varianceSmallVariance    << endl;

           cout << theoreticalMean          << ' '
                << meanLargeVariance        << ' '
                << theoreticalVarianceLarge << ' '
                << varianceLargeVariance    << endl;
}

