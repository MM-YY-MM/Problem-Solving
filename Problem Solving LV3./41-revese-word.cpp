#include <iostream>   
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
    string Text = " ";
    cout << "Please Enter Your String?\n";
    getline(cin, Text);
    return Text;
}

vector <string> SplitString(string S1, string Separator)
{
    vector <string> vString;
    short pos = 0;
    string Tokens = ""; //define a string variable

    //use find() function to get the position of the delimiters
    while ((pos = S1.find(Separator)) != string::npos)
    {
        Tokens = S1.substr(0, pos); // Store the Token
        if (Tokens != "")
        {
            vString.push_back(Tokens);
        }

        S1.erase(0, pos + Separator.length()); //erase() until position and  move to next token.
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it print last word of the token
    }

    return vString;
}

string TrimRight(string S1)
{
    for (int i = S1.length() - 1; i >= 0; i--)
    {
        if (S1[i] != ' ') // Found letter
        {
            return S1.substr(0, i + 1);
        }
    }
    return "";
}

string ReverseWordInString(string S1)
{
    string Word = "";
    vector <string> vString = SplitString(S1, " ");

    //Declare Iterator
    vector <string> ::iterator iter = vString.end();

    while (iter != vString.begin())
    {
        --iter;
        Word += *iter + " ";
    }

    //Remove Last Space (Two Method)
    //Word = Word.substr(0, Word.length() - 1);
    Word = TrimRight(Word);

    return Word;
}

int main()
{
    string S1 = ReadString();

    cout << "\n\nString after reversing words: \n";
    cout << ReverseWordInString(S1) << endl;
    
    system("pause>0");
}