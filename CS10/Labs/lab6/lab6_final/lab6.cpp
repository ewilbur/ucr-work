//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab6.cpp
/// @brief Lab 6
///
/// @author Evan Wilbur [ewilb001@ucr.edu]
/// @date May 2, 2015
//  ================== END ASSESSMENT HEADER ===============

#include <iostream>

using namespace std;


// test for a valid user input
bool validUserInput(int input)
{

    if ((-1 <= input) && (input <= 100))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    //Declaring needed variables
    
    int numberOfAs = 0;
    int numberOfBs = 0;
    int numberOfCs = 0;
    int numberOfDs = 0;
    int numberOfFs = 0;
    int userInput;
    static int MIN_GRADE_FOR_A = 90;
    static int MIN_GRADE_FOR_B = 80;
    static int MIN_GRADE_FOR_C = 70;
    static int MIN_GRADE_FOR_D = 60;
    static int MIN_GRADE_FOR_F = 0;

    cout << "Enter one or more grades, or -1 to stop:" << endl;

    do
    {
        cin >> userInput;

        if (validUserInput(userInput))
        {
            if ((userInput >= MIN_GRADE_FOR_F) &&
            (userInput < MIN_GRADE_FOR_D))
            {
                numberOfFs++;
            }

            else if ((userInput >= MIN_GRADE_FOR_D) &&
            (userInput < MIN_GRADE_FOR_C))
            {
                numberOfDs++;
            }

            else if ((userInput >= MIN_GRADE_FOR_C) &&
            (userInput < MIN_GRADE_FOR_B))
            {
                numberOfCs++;
            }

            else if ((userInput >= MIN_GRADE_FOR_B) &&
            (userInput < MIN_GRADE_FOR_A))
            {
                numberOfBs++;
            }

            else if (userInput >= MIN_GRADE_FOR_A)
            {
                numberOfAs++;
            }
        }
        else
        {
            cout << "This is an invalid input" << endl;
            return 0;
        }

    } while (userInput != -1);

    cout << "The grades breakdown is:" << endl;
    cout << "As: " << numberOfAs << endl;
    cout << "Bs: " << numberOfBs << endl;
    cout << "Cs: " << numberOfCs << endl;
    cout << "Ds: " << numberOfDs << endl;
    cout << "Fs: " << numberOfFs << endl;

    return 0;
}
