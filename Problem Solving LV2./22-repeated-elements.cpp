#include <iostream>
#include <string>

using namespace std;

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

void ReadArray(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;

    cout << "\nEnter array elements: \n";
    for (int i = 0; i <= arrLength - 1; i++)
    {
        cout << "\n Element[ " << i + 1 << " ] : ";
        cin >> arr[i] ;
    }
}

void PrintArray(int arr[100], int& arrLength)
{
    for (int i = 0; i <= arrLength - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int TimesRepeated(int Number, int arr[100], int arrLength)
{
    int Count = 0;
    for (int i = 0; i <= arrLength - 1; i++)
    {
        if (Number == arr[i])
            Count++;
    }
    return Count;
}

int main()
{
    int arrLength = 0;
    int arr[100];
    ReadArray(arr, arrLength);

    short NumberToCheck = ReadPositiveNumber("\n Enter The Number You Want To Check : ");

    cout << "\n Original Array : ";
    PrintArray(arr, arrLength);
    cout << "\nNumber : " << NumberToCheck
        << " is Repeated " << TimesRepeated(NumberToCheck, arr, arrLength) << " Time(s).\n";

    return 0;;
} 