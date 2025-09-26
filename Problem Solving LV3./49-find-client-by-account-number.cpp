#include <iostream>   
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

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

vector <stClient> LoadClientsDataFromFile(string FileName)
{
    vector <stClient> vDataClients;
    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        stClient Client;
        string Line = "";

        while (getline(MyFile, Line))
        {
            Client = ConvertLineDataToRecord(Line);
            vDataClients.push_back(Client);
        }

        MyFile.close();
    }

    return vDataClients;
}

string UpperAllstring(string S1)
{
    string LetterAllString = "";
    for (int i = 0; i < S1.length(); i++)
    {
        LetterAllString += toupper(S1[i]);
    }
    return LetterAllString;
}

bool FindClientByAccountNumber(string AccountNumber, stClient& Client)
{
    vector <stClient> vDataClients = LoadClientsDataFromFile(ClientsFileName);

    for (stClient C : vDataClients)
    {
        // Using Function UpperAllstring() --> Match Case 
        if (UpperAllstring(C.AccountNumber) == UpperAllstring(AccountNumber))
        {
            Client = C; // Fill Structure is Found Account Number
            return true;
        }
    }
    // Not Find Account Number --> Not Found
    return false;
}

void PrintClientCard(stClient Client)
{
    cout << "\nThe following are the client details: \n";
    cout << "\nAccount Number: " << Client.AccountNumber;
    cout << "\nPin Code      : " << Client.PinCode;
    cout << "\nName          : " << Client.Name;
    cout << "\nPhone         : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

string ReadSearchAccountNumber()
{
    string S1 = "";
    cout << "Please enter Account Number? ";
    cin >> S1;
    return S1;
}

int main()
{
    stClient Client;
    string AccountNumber = ReadSearchAccountNumber();

    if (FindClientByAccountNumber(AccountNumber, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
    }

    system("pause>0");
}