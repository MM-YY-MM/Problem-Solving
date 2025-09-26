#include <iostream>   
#include <string>

using namespace std;

char ReadCharacter()
{
    char Ch1 = '0';
    cout << "Please Enter a Character?\n";
    cin >> Ch1;
    return Ch1;
}

char InvertCharacterCase(char Ch1)
{
    return isupper(Ch1) ? tolower(Ch1) : toupper(Ch1);
}

int main()
{
    char Ch1 = ReadCharacter();

    cout << "\nChar after inverting case:\n";
    Ch1 = InvertCharacterCase(Ch1);

    cout << Ch1 << endl;

    system("pause>0");
}