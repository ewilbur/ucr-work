#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int t = time(0) % 86400;
    int seconds = t % 60;
    t /= 60;
    int minute = t % 60;
    t /= 60;
    int hour = t % 12;

    cout << hour << endl;
    cout << minute << endl;
    cout << seconds << endl;

    return 0;
}
