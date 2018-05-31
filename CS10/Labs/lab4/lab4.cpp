//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab4.cpp
/// @brief Lab 4
///
/// @author Evan Wilbur [ewilb001@ucr.edu]
/// @date April 17, 2015
//  ================== END ASSESSMENT HEADER ===============


#include <iostream>

using namespace std;

int main()
{
    string lower = "\nYou entered a lowercase letter.";
    string upper = "\nYou entered an uppercase letter.";
    string number = "\nYou entered a numeric digit.";
    string unknown = "\nYou entered an unknown character type.";
    char userChar;

    cout << "Enter a character: ";
    cin >> userChar;

    if('0' <= userChar && userChar <= '9')
    {
        cout << number << endl;
    }
    else if('A' <= userChar && userChar <= 'Z')
    {
        cout << upper;
    }
    else if('a' <= userChar && userChar <= 'z')
    {
        cout << lower;
    }
    else
    {
        cout << unknown;
    }

    return 0;
}
