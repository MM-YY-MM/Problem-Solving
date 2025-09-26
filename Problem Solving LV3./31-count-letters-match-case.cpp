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

char ReadCharacter()
{
    char Ch1 = '0';
    cout << "\nPlease Enter a Character?\n";
    cin >> Ch1;
    return Ch1;
}

char InvertCharacterCase(char Ch1)
{
    return isupper(Ch1) ? tolower(Ch1) : toupper(Ch1);
}

short CountLetter(string S1, char Letter, bool MatchCase = true)
{
    short Counter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (MatchCase)
        {
            if (S1[i] == Letter)
                Counter++;
        }
        else
        {
            // Two Method
            if (toupper(S1[i]) == toupper(Letter))
                Counter++;
            /*if (tolower(S1[i]) == tolower(Letter))
                Counter++;*/
        }
    }
    return Counter;
}

int main()
{
    string S1 = ReadString();
    char Ch1 = ReadCharacter();

    cout << "\nLetter \'" << Ch1 << "\' Count = " << CountLetter(S1, Ch1) << endl;

    cout << "\nLetter \'" << Ch1 << "\' Or \'";
    cout << InvertCharacterCase(Ch1) << "\' Count = ";
    cout << CountLetter(S1, Ch1, false) << endl;
    
    system("pause>0");
}