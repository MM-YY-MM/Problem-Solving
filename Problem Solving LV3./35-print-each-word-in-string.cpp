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

void PrintEachWordInString(string S1)
{
    string Delim = " "; //Delimiter

    cout << "\nYour string words are: \n";
    short pos = 0;
    string sWord; //define a string variable

    //use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // Store the Word 
        if (sWord != "")
        {
            cout << sWord << endl;
        }

        S1.erase(0, pos + Delim.length()); //erase() until position and  move to next word.
    }

    if (S1 != "")
    {
        cout << S1 << endl; // it print last word of the string
    }
}

int main()
{
    string S1 = ReadString();

    PrintEachWordInString(S1);

    system("pause>0");
}