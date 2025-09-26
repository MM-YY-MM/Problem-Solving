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
            Matrix[i][j] = RandomNumber(1, 10);
        }
    }
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            printf("%0*d\t",2, Matrix[i][j]);
        }
        cout << "\n";
    }
}

void PrintMiddleRowOfMatrix(int Matrix[3][3], short Rows)
{
    short MiddleRow = Rows / 2;

    for (int i = 0; i < Rows; i++)
    {
        printf("%0*d\t",2,Matrix[MiddleRow][i]);
    }
    cout << "\n";
}

void PrintMiddleColOfMatrix(int Matrix[3][3],short Cols)
{
    short MiddleCol = Cols / 2;

    for (int j = 0; j < Cols; j++)
    {
        printf("%0*d\t", 2, Matrix[j][MiddleCol]);
    }
    cout << "\n";
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];

    Fill3x3RandomMatrix(Matrix1, 3, 3);
    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMiddle Row of Matrix1 is: \n";
    PrintMiddleRowOfMatrix(Matrix1, 3);

    cout << "\nMiddle Cols of Matrix1 is: \n";
    PrintMiddleColOfMatrix(Matrix1, 3);

    system("pause>0");
}