#include <iostream>

using namespace std;

const int Q = 2,
          R = 3,
          S = 3,
          ROW_LENGTH = 3;

void initializeArray(int a[], int arrayLength)
{
	for(int i = 0; i < arrayLength; i++)
	{
		a[i] = 0;
	}
}

void printArray(int a[], int arrayLength)
{
    for(int i = 0; i < arrayLength; i++)
    {
        if(i % ROW_LENGTH == 0 && i != 0)
        {
            cout << endl;
        }
        cout << a[i] << ' ';
    }
    //cout << endl;
}

void fillArray(int a[], int arrayLength)
{
    for(int i = 0; i < arrayLength; i++)
    {
        cin >> a[i];
    }
}


void matrixMult(const int a[][R], const int b[][S], int product[][S])
{
    for(int i = 0; i < Q; i++)
        for(int j = 0; j < S; j++)
    {
        product[i][j] = 0;
        for(int k = 0; k < R; k++)
            product[i][j] += a[i][k] * b[k][j];
    }
}

void promptUser(int numRows, int numCol, char matrixName)
{
    cout << "Enter Matrix " << matrixName
         << " size ("
         << numRows
         << 'x'
         << numCol
         << "): ";
}

int main()
{
    int q[Q][R],
        w[R][S],
        prod[Q][S];
    
    initializeArray(*q, Q*R);
    initializeArray(*w, R * S);
    initializeArray(*prod, Q * S);

    promptUser(Q, R, 'A');
    fillArray(*q, Q * R);

    promptUser(R, S, 'B');
    fillArray(*w, R * S);
    cout << endl;
    cout << "Res:" << endl;

    matrixMult(q, w, prod);

    printArray(*prod, Q * S);
}
