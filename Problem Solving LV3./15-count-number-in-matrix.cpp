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

int main()
{

    int Matrix1[3][3] = { {9,1,12},{0,9,1},{0,9,9} };

    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);
    
    short Number = 0;
    cout << "\nEnter the number to count in matrix? ";
    cin >> Number;

    cout << "\nNumber " << Number << " count in matrix is " <<
        CountNumberInMatrix(Matrix1, Number, 3, 3) << endl;

    system("pause>0");
}