#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int arr1[100], int& arrLength)
{

    cout << "\nEnter number of elements:\n";
    cin >> arrLength;

    for (int i = 0; i <= arrLength - 1; i++)
    {
        arr1[i] = RandomNumber(1, 100);
    }

}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i <= arrLength - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
{
    for (int i = 0; i <= arrLength - 1; i++)
    {
        arrDestination[i] = arrSource[i];
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arrLength = 0;
    int arr1[100];
    
    FillArrayWithRandomNumbers(arr1, arrLength);

    int arr2[100];
    CopyArray(arr1, arr2, arrLength);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr1, arrLength);

    cout << "\nArray 2 elements after copy:\n";
    PrintArray(arr2, arrLength);

    return 0;;
}

 