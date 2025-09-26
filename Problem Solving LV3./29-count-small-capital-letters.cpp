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

short CountCapitalLetters(string S1)
{
    short Count = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
            Count++;
    }
    return Count;
}

short CountSmallLetters(string S1)
{
    short Count = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
            Count++;
    }
    return Count;
}

enum enWhatToCount { SmallLetters = 1, CapitalLetters = 2, AllLetters = 3 };

short CountLetter(string S1, enWhatToCount WhatToCount = enWhatToCount::AllLetters)
{
    int Count = 0;
    
    if (WhatToCount == enWhatToCount::AllLetters)
        return S1.length();
    for (int i = 0; i < S1.length(); i++)
    {
        if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
            Count++;

        if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
            Count++;
    }

    return Count;
}

int main()
{
    string S1 = ReadString();

    cout << "\n Method One\n";
    cout << "\nString Length = " << S1.length() << endl;
    cout << "Capital Letters Count = " << CountCapitalLetters(S1) << endl;
    cout << "Small Letters Count = " << CountSmallLetters(S1) << endl;

    cout << "\n\nMethod Two\n";
    cout << "\nString Length = " << CountLetter(S1) << endl;
    cout << "Capital Letters Count = " << CountLetter(S1, enWhatToCount::CapitalLetters) << endl;
    cout << "Small Letters Count = " << CountLetter(S1, enWhatToCount::SmallLetters) << endl;

    system("pause>0");
}