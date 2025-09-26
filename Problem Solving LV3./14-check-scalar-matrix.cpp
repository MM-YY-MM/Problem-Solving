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

bool IsScalarMatrix(int Matrix[3][3], short Rows, short Cols)
{
    const int FirstDiagElements = Matrix[0][0];
    //check Diagonal elements are 1 and rest elements are 0
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            //Check for Diagonal
            if (i == j && Matrix[i][j] != FirstDiagElements)
                return false;
            //Check for Rest Elements
            else if (i != j && Matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}

int main()
{

    int Matrix1[3][3] = { {9,0,0},{0,9,0},{0,0,9} };

    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    if (IsScalarMatrix(Matrix1, 3, 3))
        cout << "\nYES: Matrix is scalar.";
    else
        cout << "\nNO: Matrix is NOT scalar.";

    system("pause>0");
}