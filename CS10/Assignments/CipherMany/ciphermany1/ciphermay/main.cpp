//  =============== BEGIN ASSESSMENT HEADER ================
/// @file cipher.cpp
/// @brief assn4
///
/// @author Evan Wilbur [ewilb001@ucr.edu]
/// @date April 24, 2015
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment,
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============



#include <iostream>

using namespace std;

int positionInString(char letter, string mapping)
{
    for(int i =0; i < mapping.length(); i++)
    {
        if(letter == mapping.at(i))
        {
            return i;
        }
    }
}


bool findIt(char letter, string mapping)
{
    for(int i = 0; i < mapping.length(); i++)
    {
        if(letter == mapping.at(i))
        {
            return true;
        }
        else if((i == (mapping.length() - 1)) && (mapping.at(i) != letter))
        {
            return false;
        }
    }
}

bool validMap(string mapping)
{
    if((mapping == "default") || (mapping.length() == 26))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool validWord(string word, string encryptOrDecrypt, string mapping)
{
    if(encryptOrDecrypt == "encryption")
    {
        for(int i = 0; i < word.length(); i++)
        {
            if((word.at(i) < 97) || (word.at(i) > 122))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        for(int i = 0; i < word.length(); i++)
        {
            if(!(findIt(word.at(i), mapping)))
               {
                   return false;
               }
        }
        return true;
    }
}

bool validMethod(string modus)
{
    if((modus != "encryption") && (modus != "decryption"))
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    string defaultMap = "zyxwvutsrqponmlkjihgfedcba";
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string modusOperendi;
    string translationMap;
    string userWord;
    int letterPosition;

    cout << "What is the method (encryption or decryption)? ";
    cin >> modusOperendi;

    if(!(validMethod(modusOperendi)))
    {
        cout << endl << "Invalid method choice" << endl;
        return 0;
    }

    cout << endl << "What is the translation map (type 'default' to use default): ";
    cin >> translationMap;

    if(!(validMap(translationMap)))
    {
        cout << endl<< "Invalid translation map size" << endl;
        return 0;
    }
    else if(translationMap == "default")
    {
        translationMap = defaultMap;
    }

    cout << endl << "What is the single word to translate: ";
    cin >> userWord;

    if(!(validWord(userWord, modusOperendi, translationMap)))
    {
        cout << endl << "Error: invalid word choice" << endl;
        return 0;
    }

    if(modusOperendi == "encryption")
    {
        for(int i = 0; i < userWord.length(); i++)
        {
            letterPosition = (userWord.at(i) - 97);
            userWord.at(i) = translationMap.at(letterPosition);
        }
        cout << endl << userWord << endl;
        return 0;
    }
    else
    {
        for(int i = 0; i < userWord.length(); i++)
        {
            letterPosition = positionInString(userWord.at(i), translationMap) + 97;
            userWord.at(i) = letterPosition;
        }
        cout << endl << "Decrypted word: " << userWord << endl;
    }


}
