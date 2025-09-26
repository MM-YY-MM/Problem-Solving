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

int RowSum(int Matrix[3][3],short RowNumber, short Cols)
{
    int Sum = 0;
    for (int j = 0; j <= Cols - 1; j++)
    {
        Sum += Matrix[RowNumber][j];
    }
    return Sum;
}

void FillRowSumInArray(int Matrix[3][3], int arrSum[3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        arrSum[i] = RowSum(Matrix, i, Cols);
    }
}

void PrintRowsSumArray(int arrSum[3], short Rows)
{
    for (int i = 0; i < Rows; i++)
    {
        cout << " Row " << i + 1 << " Sum = " << arrSum[i] << endl;
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
    int arrSum[3];

    Fill3x3RandomMatrix(Matrix, 3, 3);
    cout << "\nThe Following is a 3x3 random matrix : \n";
    PrintMatrix(Matrix, 3, 3);

    FillRowSumInArray(Matrix, arrSum, 3, 3);
    cout << "\nThe Following are tha sum each row in the matrix from array : \n";
    PrintRowsSumArray(arrSum, 3);

    system("pause>0");
}