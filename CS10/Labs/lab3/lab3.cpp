//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab3.cpp
/// @brief Lab 3
///
/// @author Evan Wilbur [ewilb001@ucr.edu]
/// @date April 10, 2015
//  ================== END ASSESSMENT HEADER ===============

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double paid;
    double total;

    cout << "Enter purchase amount: ";
    cin >> total;
    cout << "Enter amount received: ";
    cin >> paid;

    //int change = (int)round((total - paid) * 100);
    int change = static_cast<int>((paid - total) * 100 + 0.5);

    cout << "\nTotal Change: $" << change / 100.00 << endl;

    int dollars = change / 100;
    change = change % 100;
    int quarters = change / 25;
    change = change % 25;
    int dimes = change / 10;
    change %= 10;
    int nickles = change / 5;
    change %= 5;

    cout << "\ndollars " << dollars << endl;
    cout << "quarters " << quarters << endl;
    cout << "dimes " << dimes << endl;
    cout << "nickels " << nickles << endl;
    cout << "pennies " << change << endl;
    return 0;
}
