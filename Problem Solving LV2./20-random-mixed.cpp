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

int main()
{
    srand((unsigned)time(NULL));

    cout << GetRandomCharacter(enCharType::SmallLetter) << endl;
    cout << GetRandomCharacter(enCharType::CapitalLeter) << endl;
    cout << GetRandomCharacter(enCharType::SpecialCharacter) << endl;
    cout << GetRandomCharacter(enCharType::Digit) << endl;

    return 0;;
}