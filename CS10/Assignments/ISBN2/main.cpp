#include <iostream>

using namespace std;

int main()
{
    int isbn;          //Declaring the variables
    int checksum = 0;  //Initializing the variable
    int runningNum;
    cout << "Please enter the first 9 digits of the ISBN: ";
    cin >> isbn;
    for(int i = 0; i < 9; i++)          //For loop computing the running checksum
    {
        runningNum = isbn % 10;
        isbn /= 10;
        checksum += runningNum * (9 - i);
    }
    cout << "\nChecksum: " << checksum % 11;

    return 0;
}
