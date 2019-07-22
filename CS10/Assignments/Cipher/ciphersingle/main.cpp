//  =============== BEGIN ASSESSMENT HEADER ================
/// @file encrypt.cpp
/// @brief assn3
///
/// @author Evan Wilbur [ewilb001@ucr.edu]
/// @date April 17, 2015
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment,
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============


#include <iostream>

using namespace std;

bool validMap(string charMap) //Quick validation check
{
    return charMap.length() == 26 || charMap == "default";
}




int main()
{   //variables
    string defaultMap = "zyxwvutsrqponmlkjihgfedcba";
    string characterMap;
    string cipherWord;

    cout << "What is the translation map (type \'default\' to use default): ";
    cin >> characterMap;

    if(validMap(characterMap))
    {
        if(characterMap == "default")
        {
            characterMap = defaultMap;
        }

        cout << "\nWhat is the single word: ";
        cin >> cipherWord;

        char firstChar = cipherWord.at(0);
        int firstCharPosition = (int)firstChar - 97;
        if(firstCharPosition > 25 || firstCharPosition < 0)
        {
            cout << "\nencryption cannot be preformed";
        }
        else
        {
            cipherWord.at(0) = characterMap.at(firstCharPosition);
            cout << "Encrypted word: " << cipherWord;
        }


    }
    else
    {
        cout << "\nError: invalid translation map size.";
    }
    return 0;
}
