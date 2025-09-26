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

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (int i = 0; i <= Rows - 1; i++)
    {
        for (int j = 0; j <= Cols - 1; j++)
        {
            cout << Matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    int Matrix[3][3];
    
    FillMatrixWithOrderedNumbers(Matrix, 3, 3);
    cout << "The Following is a 3x3 ordered matrix: \n";
    PrintMatrix(Matrix, 3, 3);

    system("pause>0");
}