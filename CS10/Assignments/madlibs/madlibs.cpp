//  =============== BEGIN ASSESSMENT HEADER ================
/// @file madlibs.cpp
/// @brief assn1
///
/// @author Test Student [ewilb001@ucr.edu]
/// @date April 9, 2015
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment,
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============

#include <iostream>

using namespace std;

int main()
{
    string adj1; //Declaring all my variables
    string adj2;
    string adj3;
    string adj4;
    string verb1;
    string verb2;
    string verb3;
    string verb4;
    string verb5;
    string noun1;
    string noun2;
    string noun3;
    string profession;
    cout << "Please input an adjective: "; //User input section
    cin >> adj1;
    cout << "\n" << "Please input an adjective: ";
    cin >> adj2;
    cout << "\n" << "Please input an adjective: ";
    cin >> adj3;
    cout << "\n" << "Please input an adjective: ";
    cin >> adj4;
    cout << "\n" << "Please input a verb: ";
    cin >> verb1;
    cout << "\n" << "Please input a verb: ";
    cin >> verb2;
    cout << "\n" << "Please input a verb: ";
    cin >> verb3;
    cout << "\n" << "Please input a verb: ";
    cin >> noun1;
    cout << "\n" << "Please input a noun: ";
    cin >> noun2;
    cout << "\n" << "Please input a noun: ";
    cin >> noun3;
    cout << "\n" << "Please input a profession: ";
    cin >> profession;
    cout << "\n";
    cout << "------------------------------------------------------------";
    cout << "--------------------";
    cout << "\n \t Once upon a time there was a " << noun1; //Story time
    cout << " who worked as a ";
    cout << profession <<". One day\n he went to the store to buy a new ";
    cout << noun2 << ".";
    cout << "He looked all around. He found \n" << adj1 << " ones and ";
    cout << adj2 << " ones but none that he liked." << endl;
    cout << "\n \t In frustration the " << noun1;
    cout << " went to the front and asked the " << noun2 << endl;
    cout << " if he could recommend one for him. ";
    cout << "The " << noun2 << " at the front " << noun3;
    cout << "\n to him and said \"";
    cout << adj3 << " " << noun3 <<"\". So he did do this";
    cout << " only to be put\n above line count." << endl;
    cout << "\n \t There's not much else to say about the " << profession;
    cout << ". He ended up getting\n a "<< adj4 <<" "<< noun2;
    cout << " instead, much to his dissapointment.";
    cout << " And that is\n the  " << verb1 << " of how "<< verb2;
    cout << " made a "<< verb3;
    cout << " madlib for his computer \n science course." << endl;
    cout << "------------------------------------------------------------";
    cout << "--------------------";
    cout << "\n";
    return 0;
}

