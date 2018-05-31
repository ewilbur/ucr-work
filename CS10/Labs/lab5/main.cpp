//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab5.cpp
/// @brief Lab 4
///
/// @author Evan Wilbur [ewilb001@ucr.edu]
/// @date April 24, 2015
//  ================== END ASSESSMENT HEADER ===============

#include <iostream>

using namespace std;

void exercise1()
{
    string userInput;

    cout << "Enter a word: ";
    cin >> userInput;
    cout << endl;

    for(int i = 0; i < userInput.length(); i++)
    {
        if(userInput.at(i) == 'e')
        {
            userInput.at(i) = '3';
        }
        else if(userInput.at(i) == 'i')
        {
            userInput.at(i) = '1';
        }
        else if(userInput.at(i) == 'x')
        {
            userInput.at(i) = '*';
        }
    }
    cout << "Your word transformed is " << userInput << endl;

}

void exercise2()
{
    char charToFind = '.';
    string wordToFind = "stop";
    string userInput;
    unsigned int wordIndex;
    unsigned int charIndex;

    cout << "Enter a word ";
    cin >> userInput;

    wordIndex = userInput.find(wordToFind);
    charIndex = userInput.find(charToFind);

    if((charIndex < userInput.length())
       && (userInput.at(charIndex) == charToFind))
    {
        cout << "The character '.' is located at index " << charIndex << endl;
    }
    else
    {
        cout << "The entry does not contain the character '.'" << endl;
    }
    if((wordIndex < userInput.length())
            && (userInput.at(wordIndex) == wordToFind.at(0)))
    {
        cout << "The word " << wordToFind << " starts at index " << wordIndex;
        cout << endl;
    }
    else
    {
        cout << "The entry does not contain the word 'stop'" << endl;
    }


}

int main()
{
    int ex;

    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;

    //Take your comment you filthy animal

    if(ex == 1)
    {
        exercise1();
    }
    else if(ex == 2)
    {
        exercise2();
    }
    else
    {
        cout << "Hey idiot, enter a correct exercise next time";
    }

    return 0;
}
