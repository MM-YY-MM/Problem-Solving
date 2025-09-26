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

void PrintFirstLetterOfEachWord(string S1)
{
    bool IsFirstLetter = true;

    cout << "\nFirst letter of this string: \n";
    for (int i = 0; i <= S1.length() - 1; i++)
    {
        if ((S1[i] != ' ') && IsFirstLetter)
        {
            cout << S1[i] << endl;
        }

        IsFirstLetter = (S1[i] == ' ') ? true : false;
    }
}

int main()
{
    PrintFirstLetterOfEachWord(ReadString());

    system("pause>0");
}