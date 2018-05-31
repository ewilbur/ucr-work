#include <iostream>

using namespace std;

const int M = 2,
          N = 3;

void printArray(int a[], int arrayLength)
{
    for(int i = 0; i < arrayLength; i++)
    {
        if(i % N == 0 && i != 0)
        {
            cout << endl;
        }
        cout << a[i] << ' ';
    }
    cout << endl;
}

void matrixAdd(int a[][N], int b[][N], int sum[][N])
{
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
    {
        sum[i][j] = a[i][j] + b[i][j];
    }
}

void fillArray(int a[], int arrayLength)
{
    for(int i = 0; i < arrayLength; i++)
    {
        cin >> a[i];
    }
}

int main()
{
    int a[M][N];
    int b[M][N];
    int sum[M][N];

    cout << "Enter Matrix A: ";
    fillArray(*a, M * N);

    cout << endl << "Enter Matrix B: ";
    fillArray(*b, M * N);
    cout << endl;

    matrixAdd(a, b, sum);

    cout << "Res: " << endl;
    printArray(*sum, M*N);

}
