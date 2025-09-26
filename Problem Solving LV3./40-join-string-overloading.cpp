#include <iostream>   
#include <string>
#include <vector>

using namespace std;

string JoinString(vector <string> & vString,string Delimiter)
{
    string S1 = "";

    for (string& s : vString)
    {
        S1 = S1 + s + Delimiter;
    }

    return S1.substr(0, S1.length() - Delimiter.length());
}

string JoinString(string arrString[], short Length, string Delimiter)
{
    string S1 = "";

    for (int i = 0; i < Length; i++)
    {
        S1 = S1 + arrString[i] + Delimiter;
    }

    return S1.substr(0, S1.length() - Delimiter.length());
}

int main()
{
    string Delimiter = ",#,";
    short Length = 4;

    vector <string> vString{ "Mohammed","Ali","Fadi","Maher" };
    string arrString[] = { "Mohammed","Ali","Fadi","Maher" };

    cout << "\nVector after join: \n";
    cout << JoinString(vString, Delimiter);

    cout << "\n\nArray after join: \n";
    cout << JoinString(arrString, Length, Delimiter);

    system("pause>0");
}