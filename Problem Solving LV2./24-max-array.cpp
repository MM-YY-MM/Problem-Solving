#include <iostream>
#include <string>
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
        arr[i] = RandomNumber(1, 100);

}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i <= arrLength - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int MaxNumberInArray(int arr[100], int arrLength)
{
    int Max = 0;
    for (int i = 0; i <= arrLength - 1; i++)
    {
        if (arr[i] > Max)
            Max = arr[i];
    }
    return Max;
}

int main()
{
    srand((unsigned)time(NULL));

    int arrLength = 0;
    int arr[100];
    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\n Array Elements : ";
    PrintArray(arr, arrLength);

    cout << "\n Max Number Of Array : "
        << MaxNumberInArray(arr, arrLength) << endl;
    
    return 0;;
}
 