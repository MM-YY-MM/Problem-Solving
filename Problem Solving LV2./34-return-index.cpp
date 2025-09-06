 
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
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number < 0);
    return Number;
}

short FindNumberPositionInArray(int arr[100], int arrLength, int SearchForArray)
{
    for (int i = 0; i <= arrLength - 1; i++)
    {
        if (SearchForArray == arr[i])
            return i;
    }

    return -1;
}

int main()
{
    srand((unsigned)time(NULL));

    int arrLength = 0;
    int arr[100];
    int SearchForArray = 0;

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    SearchForArray = ReadPositiveNumber("\nPlease enter a number to search for?");
    
    cout << "\nNumber You are Looking for is: " << SearchForArray << "\n";
    short NumberPosition = FindNumberPositionInArray(arr, arrLength, SearchForArray);
    if (NumberPosition == -1)
        cout << "\nThe Number is Not found :-(\n";
    else
    {
        cout << "\nThe Number Found at Position: " << NumberPosition << "\n";
        cout << "\nThe Number Found its order: " << NumberPosition + 1 << "\n";
    }


    return 0;;
}