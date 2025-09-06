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

int MinNumberInArray(int arr[100], int arrLength)
{
    int Min = arr[0];
    for (int i = 0; i <= arrLength - 1; i++)
    {
        if (arr[i] < Min)
            Min = arr[i];
    }
    return Min;
}

int main()
{
    srand((unsigned)time(NULL));

    int arrLength = 0;
    int arr[100];
    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\n Array Elements : ";
    PrintArray(arr, arrLength);

    cout << "\n Min Number Of Array : "
        << MinNumberInArray(arr, arrLength) << endl;
    
    return 0;;
}
 