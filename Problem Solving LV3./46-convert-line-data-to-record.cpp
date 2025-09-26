#include <iostream>   
#include <string>
#include <vector>

using namespace std;

struct stClient
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0;
};

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

stClient ConvertLineDataToRecord(string Line, string Separator = "#//#")
{
    stClient Client;
    vector <string> vClientData;

    vClientData = SplitString(Line, Separator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); // cast string to double

    return Client;
}

void PrintClientData(stClient Client)
{
    cout << "\n\nThe following is the extracted client record: \n";
    cout << "Account Number: " << Client.AccountNumber << endl;
    cout << "Pin Code      : " << Client.PinCode << endl;
    cout << "Name          : " << Client.Name << endl;
    cout << "Phone         : " << Client.Phone << endl;
    cout << "Account Balance: " << Client.AccountBalance << endl;
}

int main()
{
    string stLine = "A150#//#1234#//#Mahmoud Yousry#//#00201015356002#//#5270.000000";
    cout << "\nLine Record is: \n";
    cout << stLine;

    stClient Client = ConvertLineDataToRecord(stLine);

    PrintClientData(Client);

    system("pause>0");
}