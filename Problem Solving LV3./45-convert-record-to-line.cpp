#include <iostream>   
#include <string>

using namespace std;

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
    getline(cin, Client.AccountNumber);

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

string ConverRecordToLine(stClient Client,string Seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}

int main()
{
    cout << "\nPlease Enter Client Data: \n\n";
    
    //Client --> Record 
    stClient Client;
    Client = ReadNewClient();

    cout << "\n\nClient Record for Saving is: \n";
    cout << ConverRecordToLine(Client);

    system("pause>0");
}