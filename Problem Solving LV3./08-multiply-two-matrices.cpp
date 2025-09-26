#include <iostream>   
#include <cstdlib>    

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

void MultiplyMatrix(int Matrix1[3][3], int Matrix2[3][3],
    int Multiply[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Multiply[i][j] = Matrix1[i][j] * Matrix2[i][j];
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2[3][3], MatrixResult[3][3];

    Fill3x3RandomMatrix(Matrix1, 3, 3);
    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    Fill3x3RandomMatrix(Matrix2, 3, 3);
    cout << "\nMatrix2: \n";
    PrintMatrix(Matrix2, 3, 3);

    MultiplyMatrix(Matrix1, Matrix2, MatrixResult, 3, 3);
    cout << "\nResults: \n";
    PrintMatrix(MatrixResult, 3, 3);

    system("pause>0");
}