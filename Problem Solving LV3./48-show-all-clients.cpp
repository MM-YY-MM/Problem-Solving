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

void PrintClientRecord(stClient DataClient)
{
    cout << "| " << left << setw(15) << DataClient.AccountNumber;
    cout << "| " << left << setw(10) << DataClient.PinCode;
    cout << "| " << left << setw(40) << DataClient.Name;
    cout << "| " << left << setw(16) << DataClient.Phone;
    cout << "| " << left << setw(12) << DataClient.AccountBalance;
}

void PrintAllClients(vector <stClient> vDataClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vDataClients.size() << ") Client(s).";
    cout << "\n-------------------------------------------------------";
    cout << "--------------------------------------------------\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(16) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n-------------------------------------------------------";
    cout << "--------------------------------------------------\n";

    for (stClient & DataClient : vDataClients)
    {
        PrintClientRecord(DataClient);
        cout << endl;
    }

    cout << "\n-------------------------------------------------------";
    cout << "--------------------------------------------------\n";
}

int main()
{
    vector <stClient> vDataClients = LoadClientsDataFromFile(ClientsFileName);

    PrintAllClients(vDataClients);

    system("pause>0");
}