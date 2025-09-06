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

bool IsNumberInArray(int arr[100], int arrLength, int SearchForArray)
{
    return FindNumberPositionInArray(arr, arrLength, SearchForArray) != -1;
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

    if (!IsNumberInArray(arr, arrLength, SearchForArray))
        cout << "\n No, The Number is Not found :-(\n";
    else
        cout << "\n Yes, The Number is found :-)\n";

    return 0;
}
 