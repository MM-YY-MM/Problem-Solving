#include <iostream>   
#include <string>
#include <vector>

using namespace std;

string RepalceWordInStringUsingBuiltInFunction(string S1,string StringToReplace,string sReplaceTo)
{
    short pos = S1.find(StringToReplace);

    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
        pos = S1.find(StringToReplace); //find Text
    }

    return S1;
}

int main()
{
    string S1 = "Welcome To Jordan , Jordan is a nice Country";
    string StringToReplace = "Jordan";
    string ReplaceTo = "USA";

    cout << "\nOriginal String\n" << S1;

    cout << "\n\nString After Replace: \n";
    cout << RepalceWordInStringUsingBuiltInFunction(S1, StringToReplace, ReplaceTo);
    cout << endl;
    
    system("pause>0");
}