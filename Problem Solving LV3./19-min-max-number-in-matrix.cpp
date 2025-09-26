#include <iostream>   

using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << Matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

int MinNumbersInMatrix(int Matrix[3][3],short Rows,short Cols)
{
    int Minimum = Matrix[0][0];
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] < Minimum)
                Minimum = Matrix[i][j];
        }
    }
    return Minimum;
}

int MaxNumbersInMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int Max = Matrix[0][0];
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] > Max)
                Max = Matrix[i][j];
        }
    }
    return Max;
}

int main()
{

    int Matrix1[3][3] = { {77,5,12},{22,20,6},{14,3,9} };

    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMinimum Numbers is: ";
    cout << MinNumbersInMatrix(Matrix1, 3, 3);

    cout << "\n\nMaximum Numbers is: ";
    cout << MaxNumbersInMatrix(Matrix1, 3, 3);

    system("pause>0");
}