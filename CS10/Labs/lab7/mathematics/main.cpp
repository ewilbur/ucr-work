#include <iostream>
#include <cmath>

using namespace std;

const int OK = 0;
const int DIV_ZERO = 1;
const int SQRT_ERR = 2;

int acquireOperands(string operation)
{
    if (operation == "quadratic")
    {
        return 3;
    }
    else
    {
        return 2;
    }
}

int main()
{
    throw 0;

    return 0;
}
