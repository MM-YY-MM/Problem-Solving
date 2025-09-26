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

int main()
{

    int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };

    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);
    
    short Number = 0;
    cout << "\nPlease Enter the number to look for in Matrix? ";
    cin >> Number;

    //Using Count is a slower method
    if (CountNumberInMatrix(Matrix1, Number, 3, 3) > 0)
        cout << "\nYES: It is there.";
    else
        cout << "\nNO:It is NOT there.";

    //This is faster method
    if (IsNumberInMatrix(Matrix1, Number, 3, 3))
        cout << "\nYES: It is there.";
    else              
        cout << "\nNO:It is NOT there.";

    system("pause>0");
}