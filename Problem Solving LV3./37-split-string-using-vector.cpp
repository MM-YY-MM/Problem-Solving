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

vector <string> SplitString(string S1,string Separator)
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

int main()
{
    //Testing
    string S1 = "Ali,Fadi,Momen,Hussian,Yousry,Kareem,Mohammed";
    string S2 = "Ali#,,$Fadi#,,$Momen#,,$Hussian#,,$Yousry#,,$Kareem#,,$Mohammed";

   /* cout << "\n String One\n";
    vector <string> vString = SplitString(S1, ",");

    cout << "\nTokens = " << vString.size() << endl;
    for (const string& N : vString)
    {
        cout << N << endl;
    }*/

    cout << "\n String Two\n";
    vector <string> vString = SplitString(S2, "#,,$");

    cout << "\nTokens = " << vString.size() << endl;
    for (const string& N : vString)
    {
        cout << N << endl;
    }

    system("pause>0");
}