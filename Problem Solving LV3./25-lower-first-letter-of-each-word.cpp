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

string LowerFirstLetterOfEachWord(string S1)
{
    bool IsFirstLetter = true;

    for (int i = 0; i <= S1.length() - 1; i++)
    {
        if ((S1[i] != ' ') && IsFirstLetter)
        {
            S1[i] = tolower(S1[i]);
        }

        IsFirstLetter = (S1[i] == ' ') ? true : false;
    }
    return S1;
}

int main()
{
    string S1 = ReadString();

    cout << "\nString after conversion: \n";

    S1 = LowerFirstLetterOfEachWord(S1);
    cout << S1 << endl;

    system("pause>0");
}