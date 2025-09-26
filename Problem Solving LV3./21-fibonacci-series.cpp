#include <iostream>   

using namespace std;

void PrintFebonacciSeriesUsingLoop(int Number)
{
    int FebNumber = 0;
    int Prev2 = 0, Prev1 = 1;

    cout << "1\t";
    for (int i = 2; i <= Number; i++)
    {
        FebNumber = Prev2 + Prev1;
        cout << FebNumber << "\t";
        Prev2 = Prev1;
        Prev1 = FebNumber;
    }
}

int main()
{
    PrintFebonacciSeriesUsingLoop(10);

    system("pause>0");
}