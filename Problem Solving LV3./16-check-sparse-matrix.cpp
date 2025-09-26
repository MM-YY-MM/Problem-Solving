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

short CountNumberInMatrix(int Matrix1[3][3], short Number, short Rows, short Cols)
{
    short CountNum = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Number == Matrix1[i][j])
                CountNum++;
        }
    }
    return CountNum;
}

bool IsSparseMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    short SizeMatrix = Rows * Cols;
    return (CountNumberInMatrix(Matrix1, 0, 3, 3) >= ceil((float)SizeMatrix / 2));
}

int main()
{

    int Matrix1[3][3] = { {0,0,12},{0,0,1},{0,0,9} };

    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);
    
    if (IsSparseMatrix(Matrix1, 3, 3))
        cout << "\nYES: It is Sparse.";
    else
        cout << "\nNO: It is NOT Sparse.";

    system("pause>0");
}