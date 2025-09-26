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

bool IsNumberInMatrix(int Matrix[3][3], short Number, short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Number == Matrix[i][j])
                return true;
        }
    }
    // It is NOT Exists
    return false;
}

void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    int Number = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Number = Matrix1[i][j];
            if (IsNumberInMatrix(Matrix2, Number, 3, 3))
                cout << Matrix1[i][j] << "\t";
        }
    }
}

int main()
{

    int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
    int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };

    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);
    
    cout << "\nMatrix2: \n";
    PrintMatrix(Matrix2, 3, 3);

    cout << "\nIntersected Numbers are: \n";
    PrintIntersectedNumbers(Matrix1, Matrix2, 3, 3);


    system("pause>0");
}