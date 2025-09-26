#include <iostream>   
#include <cstdlib>    
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void Fill3x3RandomMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (int i = 0; i <= Rows - 1; i++)
    {
        for (int j = 0; j <= Cols - 1; j++)
        {
            Matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

int ColSum(int Matrix[3][3],short Rows, short ColNumber)
{
    int Sum = 0;
    for (int i = 0; i <= Rows - 1; i++)
    {
        Sum += Matrix[i][ColNumber];
    }
    return Sum;
}

void PrintEachColSum(int Matrix[3][3], short Rows, short Cols)
{
    for (int j = 0; j < Cols; j++)
    {
        cout << " Col " << j + 1 << " Sum = " << ColSum(Matrix, Rows, j) << endl;
    }
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (int i = 0; i <= Rows - 1; i++)
    {
        for (int j = 0; j <= Cols - 1; j++)
        {
            cout << setw(3) << Matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    Fill3x3RandomMatrix(Matrix, 3, 3);
    cout << "\nThe Following is a 3x3 random matrix : \n";
    PrintMatrix(Matrix, 3, 3);
   
    cout << "\nThe Following are tha sum each col in the matrix : \n";
    PrintEachColSum(Matrix, 3, 3);

    system("pause>0");
}