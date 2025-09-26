#include <iostream>   
#include <iomanip>

using namespace std;

void FillMatrixWithOrderedNumbers(int Matrix[3][3], short Rows, short Cols)
{
    int Counter = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Counter++;
            Matrix[i][j] = Counter;
        }
    }
}

void TransposedMatrix(int Matrix[3][3],int Transposed[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Transposed[i][j] = Matrix[j][i];
        }
        // Matrix[j][i] = [0][0] / [1][0] / [2][0]
    }
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (int i = 0; i <= Rows - 1; i++)
    {
        for (int j = 0; j <= Cols - 1; j++)
        {
            cout << Matrix[i][j] << "\t";
        }
        // Matrix[i][j] = [0][0] / [0][1] / [0][2]
        cout << "\n";
    }
}

int main()
{
    int Matrix[3][3], Transposed[3][3];

    FillMatrixWithOrderedNumbers(Matrix, 3, 3);
    cout << "\nThe Following is a 3x3 ordered matrix: \n";
    PrintMatrix(Matrix, 3, 3);

    TransposedMatrix(Matrix, Transposed, 3, 3);

    cout << "\nThe Following is the transposed matrix: \n";
    PrintMatrix(Transposed, 3, 3);

    system("pause>0");
}