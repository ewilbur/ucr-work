//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp
/// @brief Lab 7
///
/// @author Evan Wilbur [ewilb001@ucr.edu]
/// @date May 8, 2015
//  ================== END ASSESSMENT HEADER ===============


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int genRandomNumber(int lowerBound, int upperBound)
{
    return lowerBound + (rand() % (upperBound - lowerBound + 1));
}

int exercise1()
{
    int lowerBound;
    int upperBound;
    cout << endl << "Enter the smallest possible number: ";
    cin >> lowerBound;
    cout << endl <<  "Enter the biggest possible number: ";
    cin >> upperBound;
    cout << endl;

    for(int i = 0; i < 3; i++)
    {
        cout << "Random number: " << genRandomNumber(lowerBound, upperBound);
        cout << endl;
    }
    return 0;
}

int exercise2()
{
    string flips;

    do
    {
        int headsOrTails = genRandomNumber(1, 2);

        if(headsOrTails == 1)
        {
            cout << endl << "Flip: heads" << endl;
        }
        else
        {
            cout << endl << "Flip: tails" << endl;
        }
        cout << "Toss the coin again (yes/no)? ";
        cin >> flips;
    }while(flips == "yes");
}

int main()
{
    int exerciseNumber;

    cout << "Which exercise? ";
    cin >> exerciseNumber;

    srand(time(0));

    if(exerciseNumber == 1)
    {
        exercise1();
        return 0;

    }
    else
    {
        exercise2();
        return 0;
    }
    //make a comment here
}
