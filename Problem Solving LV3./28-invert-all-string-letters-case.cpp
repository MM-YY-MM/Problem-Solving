#include <iostream>   
#include <string>

using namespace std;

string ReadString()
{
    string Text = " ";
    cout << "Please Enter Your String?\n";
    getline(cin, Text);
    return Text;
}

char InvertCharacterCase(char Ch1)
{
    return isupper(Ch1) ? tolower(Ch1) : toupper(Ch1);
}

string InvertAllStringLettersCase(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = InvertCharacterCase(S1[i]);
    }
    return S1;
}

int main()
{
    string S1 = ReadString();

    cout << "\nStrint after inverting all letters case:\n";
    S1 = InvertAllStringLettersCase(S1);
    cout << S1 << endl;


    system("pause>0");
}