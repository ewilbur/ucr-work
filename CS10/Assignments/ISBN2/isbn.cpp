//  =============== BEGIN ASSESSMENT HEADER ================
/// @file isbn.cpp
/// @brief assn2
///
/// @author Evan Wilbur [ewilb001@ucr.edu]
/// @date April 10, 2015
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment,
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============

#include <iostream>

using namespace std;

int main()
{
    int isbn;          //Declaring the variables
    int checksum = 0;  //Initializing the variable
    int runningNum;
    cout << "Please enter the first 9 digits of the ISBN: ";
    cin >> isbn;
    for(int i = 0; i < 9; i++)//For loop computing the running checksum
    {
        runningNum = isbn % 10;
        isbn /= 10;
        checksum += runningNum * (9 - i);
    }
    cout << "\nChecksum: " << checksum % 11;

    return 0;
}
