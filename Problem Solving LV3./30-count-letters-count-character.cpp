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

short CountLetter(string S1, char Letter)
{
    short Counter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] == Letter)
            Counter++;
    }
    return Counter;
}

int main()
{
    string S1 = ReadString();
    char Ch1 = ReadCharacter();

    cout << "\nLetter \'" << Ch1 << "\' Count = " << CountLetter(S1, Ch1) << endl;
    
    system("pause>0");
}