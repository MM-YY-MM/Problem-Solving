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

int main()
{
    string Delimiter = " ";

    vector <string> vString{ "Mohammed","Ali","Fadi","Maher" };

    cout << "Vector after join: \n";
    cout << JoinString(vString, Delimiter);

    system("pause>0");
}