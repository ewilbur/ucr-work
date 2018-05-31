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
    int rollingSum = 0;
    for (int i = 0; i < numberOfDice; i++)
    {
        rollingSum += (rand() % numberOfSides) + 1;
    }
    return rollingSum;
}

int mostLandings(const vector<int> &board, int startInterval, int endInterval)
{
    //comment
    int maxIndex = startInterval;

    for (int i = startInterval; i < endInterval; i++)
    {
        if (board[i] > board[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void simulateRound(vector<int> &board, int lastIndex)
{
    int index = rollNDice(NUM_OF_DICE, NUM_OF_FACE) - 1;

    while (index < lastIndex)
    {
        board[index]++;
        index += rollNDice(NUM_OF_DICE, NUM_OF_FACE);
        /*if (index == lastIndex)
        {
            board[0]++;
        }*/
    }
}

void printBoard(vector<int> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        cout << board[i] << endl;
    }
}



int main()
{

    srand(time(0));

    int sides;
    int spots;
    int simulations;

    cout << "How many sides of the board are there? ";
    cin >> sides;
    cout << endl;

    cout << "How many spots are on each side? ";
    cin >> spots;
    cout << endl;

    cout << "How many simulations? ";
    cin >> simulations;
    cout << endl;

    int boardLength = (sides * spots);

    vector<int> board (boardLength);

    for (simulations; simulations != 0; simulations--)
    {
        simulateRound(board, boardLength);
    }

    cout << "The following spots on each side have the most landings: " << endl;

    for (int i = 0; i < sides; i++)
    {
        int lowerBound = i * spots;
        int upperBound = i * (spots + 1);
        int lands = mostLandings(board, lowerBound, upperBound);

        cout << "On side " << i + 1 << ", spot " << lands + 1
        << " has the most landings: " << board[lands] << endl;
    }


    printBoard(board);

    return 0;
}
