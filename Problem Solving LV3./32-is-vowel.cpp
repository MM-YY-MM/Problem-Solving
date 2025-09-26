#include <iostream>   
#include <string>

using namespace std;

char ReadCharacter()
{
    char Ch1 = '0';
    cout << "\nPlease Enter a Character?\n";
    cin >> Ch1;
    return Ch1;
}

bool IsVowel(char Ch1)
{
    Ch1 = tolower(Ch1);

    return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}

int main()
{
    char Ch1 = ReadCharacter();

    if (IsVowel(Ch1))
    {
        cout << "\nYES Letter \'" << Ch1 << "\' is vowel\n";
    }
    else
    {
        cout << "\nNo Letter \'" << Ch1 << "\' is NOT vowel\n";
    }

    system("pause>0");
}