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

void FillArrayWithRandomNumbers(int arr1[100], int& arrLength)
{
    for (int i = 0; i < arrLength; i++)
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

void SumOf2Array(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arrSum[i] = arr1[i] + arr2[i];
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arrLength = ReadPositiveNumber("How Many to Enter Elements?");
    int arr1[100],arr2[100],arrSum[100];

    FillArrayWithRandomNumbers(arr1, arrLength);
    FillArrayWithRandomNumbers(arr2, arrLength);

    cout << "\nArray 1 elements : \n";
    PrintArray(arr1, arrLength);

    cout << "\nArray 2 elements : \n";
    PrintArray(arr2, arrLength);

   SumOf2Array(arr1, arr2, arrSum, arrLength);

    cout << "\nSum of Array1 and Array2 elements : \n";
    PrintArray(arrSum, arrLength);

    return 0;;
} 