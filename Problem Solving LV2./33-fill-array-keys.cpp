#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

enum enCharType { SmallLetter = 1, CapitalLeter = 2, SpecialCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

char GetRandomCharacter(enCharType  CharType)
{
    switch (CharType)
    {
    case enCharType::SmallLetter:
        return (char)RandomNumber(97, 122);
    case enCharType::CapitalLeter:
        return (char)RandomNumber(65, 90);
    case enCharType::SpecialCharacter:
        return (char)RandomNumber(33, 46);
    case enCharType::Digit:
        return (char)RandomNumber(48, 57);
    }
}

string GenerateWord(enCharType CharType, short Length)
{
    string Word = "";
    for (int Counter = 1; Counter <= Length; Counter++)
    {
        Word += GetRandomCharacter(CharType);
    }
    return Word;
}

string GenerateKey()
{
    string Key = "";

    Key += GenerateWord(enCharType::CapitalLeter, 4) + "-";
    Key += GenerateWord(enCharType::CapitalLeter, 4) + "-";
    Key += GenerateWord(enCharType::CapitalLeter, 4) + "-";
    Key += GenerateWord(enCharType::CapitalLeter, 4);

    return Key;
}

void FillArrayWithKeys(string arr[100], int& arrLength)
{
    for (int i = 0; i <= arrLength - 1; i++)
    {
        arr[i] = GenerateKey();
    }
}

void PrintStringArray(string arr[100], int arrLength)
{
    cout << "\nArray elements:\n\n";

    for (int i = 0; i < arrLength; i++)
    {
        cout << "Array[" << i << "] : ";
        cout << arr[i] << "\n";
    }
    cout << "\n";
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

int main()
{
    srand((unsigned)time(NULL));

    int arrLength = 0;
    string arr[100];

    arrLength = ReadPositiveNumber("Pleaes enter how many keys to generate? \n ");

    FillArrayWithKeys(arr, arrLength);
    PrintStringArray(arr, arrLength);

    return 0;;
}
 