#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void FillArray(int arr[100], int& arrLength)
{
    arrLength = 10;
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " "; 
    cout << "\n";
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i; 
    }
    return -1;
}

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
{

    for (int i = 0; i <= SourceLength - 1; i++)
    {
        if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
            AddArrayElement(arrSource[i], arrDestination, DestinationLength);
    }

}

int main()
{
    srand((unsigned)time(NULL));

    int arrSource[100];
    int arrDestination[100];
    int arrLength = 0;
    int arrLengthDestination = 0;

    FillArray(arrSource, arrLength);

    cout << "\nArray 1 elements : \n";
    PrintArray(arrSource, arrLength);

    CopyDistinctNumbersToArray(arrSource, arrDestination, arrLength, arrLengthDestination);

    cout << "\nArray 2 Distinct elements : \n";
    PrintArray(arrDestination, arrLengthDestination);

    return 0;
}