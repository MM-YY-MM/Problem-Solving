#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

enPrimNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2);
    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime;
    }
    return enPrimNotPrime::Prime;
}

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int arr1[100], int& arrLength)
{

    cout << "\nEnter number of elements:\n";
    cin >> arrLength;

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

void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength,int & arr2Length)
{
    int Counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
        {
            arrDestination[Counter] = arrSource[i];
            Counter++;
        }
    }

    arr2Length = Counter;
}

int main()
{
    srand((unsigned)time(NULL));

    int arrLength = 0;
    int arr1[100];
    
    FillArrayWithRandomNumbers(arr1, arrLength);

    int arr2[100];
    int arr2Length = 0;
    CopyOnlyPrimeNumbers(arr1, arr2, arrLength, arr2Length);

    cout << "\nArray 1 elements : \n";
    PrintArray(arr1, arrLength);

    cout << "\nPrime Number in Array 2 : \n";
    PrintArray(arr2, arr2Length);

    return 0;;
}

 