//  =============== BEGIN ASSESSMENT HEADER ================
/// @file boardgame.cpp
/// @brief assn7
///
/// @author Evan Wilbur [ewilb001@ucr.edu]
/// @date May 23, 2015
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment,
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============


#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <vector>

const int NUM_OF_DICE = 2;
const int NUM_OF_FACE = 6;

using namespace std;

int rollNDice(int numberOfDice, int numberOfSides)
{
    //This will simulate rolling two independent die and return their sum.
    int rollingSum = 0;
    for (int i = 0; i < numberOfDice; i++)
    {
        rollingSum += (rand() % numberOfSides) + 1;
    }
    return rollingSum;
}

int mostLandings(const vector<int> &board, int startInterval, int endInterval)
{
    //Given vector<int> and interval of that vector, this will return the
    //largest number in that interval but not including the end interval.
    int maxIndex = startInterval;

    for (int i = startInterval; i <= endInterval; i++)
    {
        if (board[i] > board[maxIndex] && i < board.size())
        {
            maxIndex = i;
        }

    }
    return maxIndex;
}

void simulateRound(vector<int> &board)
{
    int index = rollNDice(NUM_OF_DICE, NUM_OF_FACE);
    while (index < board.size())
    {
        int toDec = index - 1;
        board[toDec]++;
        index += rollNDice(NUM_OF_DICE, NUM_OF_FACE);
        if (index == board.size())
        {
            int deccer = index - 1;
            board[deccer]++;
        }
    }
}

void printBoard(vector<int> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        cout << board[i] << "-----" << i + 1 << endl;
    }
}

int main()
{
    int sides;
    int spots;
    int simulations;
    srand(time(0));

    cout << "How many sides of the board are there? ";
    cin >> sides;
    cout << endl << "How many spots are on each side? ";
    cin >> spots;
    cout << endl << "How many simulations? ";
    cin >> simulations;
    cout << endl << "The following spots on each side have the most landings: "
    << endl;

    vector<int> board (sides * spots);

    for (int i = simulations; i != 0; i--)
    {
        simulateRound(board);
    }

    for (int i = 0; i < sides; i++)
    {
        int lower = (i * spots);
        int upper = lower + (spots - 1);
        int maxLand = mostLandings(board, lower, upper);
        
        cout << "On side " << i + 1 << ", spot " << maxLand + 1
        << " has the most landings: " << board[maxLand] << endl;
    }

}
