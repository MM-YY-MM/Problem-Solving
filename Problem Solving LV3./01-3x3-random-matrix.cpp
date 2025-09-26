#include <iostream>   
#include <cstdlib>    
#include <iomanip>

using namespace std;  

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void Fill3x3RandomMatrix(int Matrix[3][3],short Rows, short Cols)
{
    for (int i = 0; i <= Rows - 1; i++)
    {
        for (int j = 0; j <= Cols - 1; j++)
        {
            Matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
           cout << setw(3) << Matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    srand((unsigned)time(NULL));  
    
    int Matrix[3][3];

    Fill3x3RandomMatrix(Matrix, 3, 3);
    cout << "The Following is a 3x3 random matrix: \n";
    PrintMatrix(Matrix, 3, 3);

    system("pause>0");
}