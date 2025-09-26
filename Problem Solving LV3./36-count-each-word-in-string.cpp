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

short CountWord(string S1)
{
    short Counter = 0;
    string Delim = " "; //Delimiter
    short pos = 0;
    string sWord; //define a string variable

    //use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // Store the Word 
        if (sWord != "")
        {
            Counter++;
        }

        S1.erase(0, pos + Delim.length()); //erase() until position and  move to next word.
    }

    if (S1 != "")
    {
        Counter++; // it print last word of the string
    }

    return Counter;
}

int main()
{
    string S1 = ReadString();

    cout << "\nThe number of words in your string is: ";
    cout << CountWord(S1) << endl;

    system("pause>0");
