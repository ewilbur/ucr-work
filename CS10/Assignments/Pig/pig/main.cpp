//  =============== BEGIN ASSESSMENT HEADER ================
/// @file pig.cpp
/// @brief assn5
///
/// @author Evan Wilbur [ewilb001@ucr.edu]
/// @date May 8, 2015
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment,
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <float.h>
#include <cmath>

using namespace std;

int genRandInt(int lowerBound, int upperBound)
{
    return lowerBound + (rand() % (upperBound - lowerBound + 1));

}

int singleTurn(int holdValue)
{
    static int MIN_ROLL_VALUE = 1;
    static int MAX_ROLL_VALUE = 6;
    int score = 0;
    int diceRoll;

    while(score < holdValue)
    {
        diceRoll = genRandInt(MIN_ROLL_VALUE, MAX_ROLL_VALUE);
        if(diceRoll == 1)
        {
            return 0;
        }
        else
        {
            score += diceRoll;
        }
    }
    return score;
}



int main()
{
    int holdValue = 0;
    int numberOfSimulations = 0;
    int score = 0;

    float numberNullScore = 0;
    float numberHold0 = 0;
    float numberHold1 = 0;
    float numberHold2 = 0;
    float numberHold3 = 0;
    float numberHold4 = 0;
    float numberHold5 = 0;

    cout << "What value should we hold at? ";
    cin >> holdValue;
    cout << endl;
    cout << "Hold-at-N turn simulations? ";
    cin >> numberOfSimulations;
    cout << endl << "Score\tEstimated Probability" << endl;

    srand(time(0));

    //TODO find a better way of doing this without using arrays

    for(int i = 0; i < numberOfSimulations; i++)
    {
        score = singleTurn(holdValue);

        if(score == 0)
        {
            numberNullScore += 1;
        }
        else if(score == holdValue)
        {
            numberHold0 += 1;
        }
        else if(score == (holdValue + 1))
        {
            numberHold1+= 1;
        }
        else if(score == (holdValue + 2))
        {
            numberHold2 += 1;
        }
        else if(score == (holdValue + 3))
        {
            numberHold3 += 1;
        }
        else if(score == (holdValue + 4))
        {
            numberHold4 += 1;
        }
        else if(score == (holdValue + 5))
        {
            numberHold5 += 1;
        }

    }

    double nullPercent = floor((numberNullScore / numberOfSimulations + 0.000005) * pow(10, 6)) / pow(10,6);
    double percentHold0 = numberHold0 / numberOfSimulations;
    double percentHold1 = numberHold1 / numberOfSimulations;
    double percentHold2 = numberHold2 / numberOfSimulations;
    double percentHold3 = numberHold3 / numberOfSimulations;
    double percentHold4 = numberHold4 / numberOfSimulations;
    double percentHold5 = numberHold5 / numberOfSimulations;

	cout << "0\t";
	printf("%.*f\n", FLT_DIG, nullPercent);
	cout << holdValue << "\t";
	printf("%.*f\n", FLT_DIG, percentHold0);
	cout << holdValue + 1 << "\t";
	printf("%.*f\n", FLT_DIG, percentHold1);
	cout << holdValue + 2 << "\t";
	printf("%.*f\n", FLT_DIG, percentHold2);
	cout << holdValue + 3 << "\t";
	printf("%.*f\n", FLT_DIG, percentHold3);
	cout << holdValue + 4 << "\t";
	printf("%.*f\n", FLT_DIG, percentHold4);
	cout << holdValue + 5 << "\t";
	printf("%.*f\n", FLT_DIG, percentHold5);

    return 0;
}
