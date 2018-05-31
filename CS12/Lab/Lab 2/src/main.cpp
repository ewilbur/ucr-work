#include <iostream>
#include <cstring>

using namespace std;

void mystrcat(char* destination, const char source[])
{
    int firstNullDest = 0;
    /*Loops through the destination string to find the first null character*/
    while(destination[firstNullDest] != '\0')
    {
        firstNullDest++;
    }

    int lastNullDest = firstNullDest;

    /*The only way I could guess the length of the array. This finds the last
    last case of a null character*/
    while(destination[lastNullDest] == '\0')
    {
        lastNullDest++;
    }

    int sourceIndex = 0;
    int destIndex = firstNullDest;
    /*This is the actual concfcatenating part of the function. Will terminate
    if the loops reaches beyond the size of the destination string */
    while(source[sourceIndex] != '\0'/* && sourceIndex != lastNullDest*/)
    {
        destination[destIndex] = source[sourceIndex];
        destIndex++;
        sourceIndex++;
    }
    destination[lastNullDest] = '\0';
    cout << destination << endl;
}


