#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

void FillArrayWith1ToN(int arr1[100], int& arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arr1[i] = i + 1;
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

void Swap(int& A, int& B)
{
    int Temp;

    Temp = A;
    A = B;
    B = Temp;
}

void ShuffleArray(int arr[100], int arrLength)
{
    for (int i = arrLength - 1; i >= 0; i--)
    {

        int Index1 = RandomNumber(1, arrLength) - 1;
        int Index2 = RandomNumber(1, arrLength) - 1;

        Swap(arr[Index1], arr[Index2]);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arrLength = ReadPositiveNumber("How Many to Enter Elements?");
    int arr1[100];

    FillArrayWith1ToN(arr1, arrLength);

    cout << "\nArray elements before shuffle:\n";
    PrintArray(arr1, arrLength);

    ShuffleArray(arr1, arrLength);

    cout << "\nArray elements after shuffle:\n";
    PrintArray(arr1, arrLength);


    return 0;;
} 