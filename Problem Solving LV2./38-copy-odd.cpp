#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

enum enOddOrEven { Odd = 1, Even = 2 };

enOddOrEven CheckOddOrEven(int Number)
{
    if (Number % 2 != 0)
        return enOddOrEven::Odd;
    else
        return enOddOrEven::Even;
}

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;

    for (int i = 0; i <= arrLength - 1; i++)
        arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " "; 
    cout << "\n";
}

void CopyOddNumber(int arrSource[100], int arrDestination[100], int arrLength, int& arrLengthDestination)
{
    for (int i = 0; i <= arrLength - 1; i++)
    {
        if (arrSource[i] % 2 != 0)
            AddArrayElement(arrSource[i], arrDestination, arrLengthDestination);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100];
    int arr2[100];
    int arrLength = 0;
    int arr2Length = 0;

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray 1 elements : \n";
    PrintArray(arr, arrLength);

    CopyOddNumber(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 2 Odd Number : \n";
    PrintArray(arr2, arr2Length);

    return 0;
}
 