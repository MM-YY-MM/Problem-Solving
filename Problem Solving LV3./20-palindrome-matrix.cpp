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

bool IsPalindromeMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols/2; j++)
        {
            if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
                return false;
        }
    }
    return true;
}

int main()
{
    //Testing
    int Matrix1[3][3] = { {1,2,1},{5,5,5},{7,3,7} };
    //int Matrix1[3][3] = { {1,2,1},{5,8,1},{7,3,7} };

    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    if (IsPalindromeMatrix(Matrix1, 3, 3))
        cout << "\nYES: Matrix is Palindrome";
    else
        cout << "\nNO: Marix is NOT Palindrome";

    system("pause>0");
}