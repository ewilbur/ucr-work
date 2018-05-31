//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<2>/main.cpp
/// @brief Assignment <2> for CS 12 <Fall 2015>
///
/// @author <Evan Wilbur> [ewilb001@ucr.edu]
/// @date <10/13/2015>
///
/// @par Enrollment Notes
///     Lecture Section: <001>
/// @par
///     Lab Section: <023>
/// @par
///     TA: <Entezari N>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============


#include <iostream>
#include <fstream>
#include <string>
#include <cmath>



using namespace std;

const int NUM_ROWS = 6,
          NUM_COLS = 8;

void printArray(double a[], int arrayLength)
{
    for(int i = 0; i < arrayLength; i++)
    {
        cout << a[i] << ' ';
        if((i + 1) % NUM_COLS == 0)
        {
            cout << endl;
        }
    }
}


void readUserFile(string fileName, double userData[])
{
    ifstream file;

    file.open(fileName.c_str());

    for(int i = 0; !file.eof(); i++)
        file >> userData[i];

    file.close();
}


void getUserFiles(string &input, string &output)
{
    cout << "Input File: ";
    cin  >> input;
    cout << "Output File: ";
    cin  >> output;
}

void writeArrayToFile(double lst[], int numOfRows, int numOfCols, string dest)
{
    ofstream writer(dest.c_str());

    for(int i = (numOfCols + 1); i < (numOfRows - 1) * numOfCols; i++)
    {
        if(i % numOfCols != 0 && (i + 1) % numOfCols != 0)
        {
            writer << lst[i] << ' ';
        }

        else if((i + 1) % numOfCols == 0)
        {
            writer << endl;
        }
    }
    writer.close();
}

void initializeArray(double lst[], int arrayLength)
{
    for(int i = 0; i < arrayLength; i++)
        lst[i] = 0;
}

double getNewTemp(double lst[], int index)
{
    double newVal = (lst[index - NUM_COLS]
                  +  lst[index + NUM_COLS]
                  +  lst[index + 1]
                  +  lst[index - 1]) / 4;

    return newVal;
}

void updateArray(double lst[], double &maxDif,int numOfRows, int numOfCols)
{
    maxDif = abs(lst[NUM_COLS + 1] - getNewTemp(lst, NUM_COLS + 1));

    for(int i = (numOfCols + 1); i < (numOfRows - 1) * numOfCols; i++)
    {
        if(i % numOfCols != 0 && (i + 1) % numOfCols != 0)
        {
            double newVal = getNewTemp(lst, i);
            if(abs(newVal - lst[i]) > maxDif)
            {
                maxDif = abs(newVal - lst[i]);
            }
            lst[i] = newVal;
        }
    }
}



int main()
{
    string inputFile,
           outputFile;

    getUserFiles(inputFile, outputFile);

    double userInputs[5]{},
           grid[NUM_ROWS][NUM_COLS];

    initializeArray(*grid, NUM_COLS * NUM_ROWS);

    readUserFile(inputFile, userInputs);

    double maxDifference = userInputs[4] + 1;

    for(int i = 1; i < (NUM_ROWS - 1); i++)
    {
        grid[i][0] = userInputs[3];
        grid[i][NUM_COLS - 1] = userInputs[1];
    }
    for(int j = 0; j < NUM_COLS; j++)
    {
        grid[0][j] = userInputs[0];
        grid[NUM_ROWS - 1][j] = userInputs[2];
    }


    while(maxDifference > userInputs[4])
        updateArray(*grid, maxDifference, NUM_ROWS, NUM_COLS);

    writeArrayToFile(*grid, NUM_ROWS, NUM_COLS, outputFile);
    return 0;
}

