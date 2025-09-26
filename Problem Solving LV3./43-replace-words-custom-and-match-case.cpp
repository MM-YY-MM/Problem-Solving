#include <iostream>   
#include <string>
#include <vector>

using namespace std;

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

string JoinString(vector <string>& vString, string Delimiter)
{
    string S1 = "";

    for (string& s : vString)
    {
        S1 = S1 + s + Delimiter;
    }

    //Using TrimRight?
    return S1.substr(0, S1.length() - Delimiter.length());
}

string LowerAllstring(string S1)
{
    string LetterAllString = "";
    for (int i = 0; i < S1.length(); i++)
    {
        LetterAllString += tolower(S1[i]);
    }
    return LetterAllString;
}

string RepalceWordInStringUsingSplit(string S1, string StringToReplace, string ReplaceTo,bool MatchCase = true)
{
    vector <string> vString = SplitString(S1, " ");

    for (string& s : vString)
    {
        if (MatchCase)
        {
            if (s == StringToReplace)
            {
                s = ReplaceTo;
            }
        }
        else
        {
            if (LowerAllstring(s) == LowerAllstring(StringToReplace))
            {
                s = ReplaceTo;
            }
        }
    }

    return JoinString(vString, " ");
}

int main()
{
    string S1 = "Welcome To Jordan , Jordan is a nice Country";
    string StringToReplace = "jordan";
    string ReplaceTo = "USA";

    cout << "\nOriginal String\n" << S1;

    cout << "\n\nReplace with match case: \n";
    cout << RepalceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo);
    
    cout << "\n\nReplace with dont match case: \n";
    cout << RepalceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo,false);
    cout << endl;

    system("pause>0");
}