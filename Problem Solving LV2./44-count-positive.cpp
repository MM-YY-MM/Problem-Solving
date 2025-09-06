#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{

    cout << "\nEnter number of elements:\n";
    cin >> arrLength;

    for (int i = 0; i <= arrLength - 1; i++)
        arr[i] = RandomNumber(-100, 100);

}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int PositiveCountArray(int arr[100], int arrLength)
{
    int Counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] >= 0)
            Counter++;
    }

    return Counter;
}

int main()
{
    srand((unsigned)time(NULL));

    int arrSource[100];
    int arrLength = 0;

    FillArrayWithRandomNumbers(arrSource, arrLength);

    cout << "\nArray elements: \n";
    PrintArray(arrSource, arrLength);

    cout << "\nPositive Numbers Count is: " << PositiveCountArray(arrSource, arrLength) << endl;

    return 0;
}
 