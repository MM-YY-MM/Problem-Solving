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

string UpperAllString(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = toupper(S1[i]);
    }
    return S1;
}

string LowerAllString(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}

int main()
{
    string S1 = ReadString();

    cout << "\nString after Upper:\n";
    S1 = UpperAllString(S1);
    cout << S1 << endl;
 
    cout << "\nString after Lower:\n";
    S1 = LowerAllString(S1);
    cout << S1 << endl;

    system("pause>0");
}