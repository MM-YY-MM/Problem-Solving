#include <iostream>   
#include <string>
#include <fstream>

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

stClient ReadNewClient()
{
    stClient Client;

    cout << "Enter Account Number? ";

    //Usage of std::ws will extract all the whitespace character
    getline(cin >> ws, Client.AccountNumber);

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance? ";
    cin >> Client.AccountBalance;

    return Client;
}

string ConverRecordToLine(stClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << stDataLine << "\n";
        MyFile.close();
    }
}

void AddNewClient()
{
    stClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConverRecordToLine(Client));
}

void AddClients()
{
    char AddMoreClients = 'Y';

    do
    {
        system("cls");
        cout << "Adding New Client:\n\n";

        AddNewClient();
        cout << "\n\nClient Added Successfuly, do you want to add more clients? [Y\\N] ";
        cin >> AddMoreClients;
    } while (toupper(AddMoreClients) == 'Y');
}

int main()
{
    AddClients();

    system("pause>0");
}