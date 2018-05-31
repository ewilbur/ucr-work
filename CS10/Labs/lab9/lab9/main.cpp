//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp
/// @brief Lab 9
///
/// @author Evan Wilbur [ewilb001@ucr.edu]
/// @date May 24, 2015
//  ================== END ASSESSMENT HEADER ===============

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

void fillVector(vector <double> &v)
{
    double d;
    while (cin >> d)
    {
        v.push_back(d);
    }
}

double average(const vector <double> &v)
{
    double sum = 0.;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v.at(i);
    }

    return sum / v.size();
}

double standardDeviation(const vector <double> &v)
{
    //Comment
    double avg = average(v);
    double const vSize = v.size();
    double rollingSum = 0;

    for (int i = 0; i < vSize; i++)
    {
        rollingSum += pow(avg - v[i] , 2);
    }

    return sqrt(rollingSum / vSize);
}

int main()
{
    vector <double> userVector;
    fillVector(userVector);
    cout << standardDeviation(userVector) << endl;
}

