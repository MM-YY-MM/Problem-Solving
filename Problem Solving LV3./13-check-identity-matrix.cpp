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

bool IsIdentityMatrix(int Matrix[3][3], short Rows, short Cols)
{
    ////check Diagonal elements are 1 and rest elements are 0
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            //Check Diagonal
            if (i == j && Matrix[i][j] != 1)
                return false;
            //Check Rest Elements
            else if (i != j && Matrix[i][j] != 0)
                return false;
        }
    }
    // Yes Identity Matrix
    return true;
}

int main()
{

    //Testing
    int Matrix1[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    //int Matrix1[3][3] = { {1,0,0},{0,1,0},{0,0,1} };

    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    if (IsIdentityMatrix(Matrix1, 3, 3))
        cout << "\nYES: Matrix is identity.";
    else
        cout << "\nNO: Matrix is NOT identity.";

    system("pause>0");
}