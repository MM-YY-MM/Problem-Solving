#include <iostream>   
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void MainMenueScreen();
int main();

const string ClientsFileName = "Clients.txt";

enum enMenue {
    ShowClientsList = 1, AddNewClients = 2, DeleteClients = 3, UpdateClientInfo = 4
    , FindClients = 5, ExitProgram = 6
};

struct stClient
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0;
    bool MarkForDelete = false;
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

    for (stClient& DataClient : vDataClients)
    {
        PrintClientRecord(DataClient);
        cout << endl;
    }

    cout << "\n-------------------------------------------------------";
    cout << "--------------------------------------------------\n";
}

bool IsTheClientAlreadyPresent(string AccountNumber)
{
    vector <stClient> vDataClients = LoadClientsDataFromFile(ClientsFileName); 
    for (stClient& C : vDataClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            return true;
        }
    }
    return false;
}

stClient ReadNewClient()
{
    stClient Client;
    bool ClientAlready = true;

    do
    {
        cout << "Enter Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
        if (IsTheClientAlreadyPresent(Client.AccountNumber))
        {
            ClientAlready = true;
            cout << "\nClient with [" << Client.AccountNumber << "] already exists, ";
        }
        else
        {
            ClientAlready = false;
        }
    } while (ClientAlready);
    
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

void AddClients(char & AddMoreClients)
{ 
    cout << "Adding New Client:\n\n";

    AddNewClient();
    cout << "\n\nClient Added Successfuly, do you want to add more clients? [Y\\N] ";
    cin >> AddMoreClients;
}

void AddNewClientScreen()
{
    char AddMoreClients = 'Y';

    do
    {
        system("cls");
        cout << "\n-----------------------------------\n";
        cout << "\tAdd New Clients Screen\n";
        cout << "-----------------------------------\n";

        AddClients(AddMoreClients);

    } while (toupper(AddMoreClients) == 'Y');
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

bool FindClientByAccountNumber(string AccountNumber, stClient& Client, vector <stClient> vDataClients)
{

    for (stClient & C : vDataClients)
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

void MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stClient>& vDataClients)
{
    for (stClient& C : vDataClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return; // exit from procedure
        }
    }
}

void SaveClientsDataToFile(string AccountNumber, vector <stClient> vDataClients)
{
    fstream MyFile;
    string DataLine = "";

    MyFile.open(ClientsFileName, ios::out); //OverWrite

    if (MyFile.is_open())
    {
        for (stClient& C : vDataClients)
        {
            if (C.MarkForDelete == false)
            {
                //We Only Write Records that are not marked for delete
                DataLine = ConverRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
}

string ReadSearchAccountNumber()
{
    string S1 = "";
    cout << "Please enter Account Number? ";
    cin >> S1;
    return S1;
}

void DeleteClientByAccountNumber(string AccountNumber, vector <stClient>& vDataClients)
{
    stClient Client;
    char Answer = 'y';

    if (FindClientByAccountNumber(AccountNumber, Client, vDataClients))
    {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want delete this client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vDataClients);
            SaveClientsDataToFile(AccountNumber, vDataClients);

            // Refresh or Update Clients Data
            vDataClients = LoadClientsDataFromFile(ClientsFileName);

            cout << "\n\nClient Deleted Successfuly.";
            return; // exit from procedure
        }
        else
        {
            cout << "\n\nOkay, you don't want to delete the client.\n";
            return; // exit from procedure
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
        return; // exit from procedure
    }
}

void DeleteClientScreen(vector <stClient>& vDataClients)
{
    string AccountNumber = "";

    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen\n";
    cout << "-----------------------------------\n";

    AccountNumber = ReadSearchAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vDataClients);
}

stClient ChangeClientData(string AccountNumber)
{
    stClient Client;

    Client.AccountNumber = AccountNumber;

    cout << "\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance? ";
    cin >> Client.AccountBalance;

    return Client;
}

void UpdateClientByAccountNumber(string AccountNumber, vector <stClient>& vDataClients)
{
    stClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, Client, vDataClients))
    {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want update this client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {

            for (stClient& C : vDataClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientData(AccountNumber);
                    break;
                }
            }

            SaveClientsDataToFile(AccountNumber, vDataClients);

            cout << "\n\nClient Updated Successfuly.";
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
    }
}

void UpdateClientInfoScreen(vector <stClient>& vDataClients)
{
    string AccountNumber = "";

    cout << "\n-----------------------------------\n";
    cout << "\tUpdat Client Info Screen\n";
    cout << "-----------------------------------\n";

    AccountNumber = ReadSearchAccountNumber();
    UpdateClientByAccountNumber(AccountNumber,vDataClients);
}

void FindClientScreen(vector <stClient>& vDataClients)
{
    string AccountNumber = "";
    stClient Client;

    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen\n";
    cout << "-----------------------------------\n";
    AccountNumber = ReadSearchAccountNumber();

    if (FindClientByAccountNumber(AccountNumber, Client, vDataClients))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
    }
}

void ExitProgrmScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tPrgram Ends :-)\n";
    cout << "-----------------------------------\n";
}

void GoToMainMenue()
{
    cout << "\n\nPress any key to go Main Menue...";
    system("pause>0");
    system("cls");
    main();
}

void ChooseMainMenue(enMenue Menue, vector <stClient> & vDataClients)
{
    switch (Menue)
    {
    case enMenue::ShowClientsList:
        system("cls");
        PrintAllClients(vDataClients);
        GoToMainMenue();
        break;
    case enMenue::AddNewClients:
        system("cls");
        AddNewClientScreen();
        GoToMainMenue();
        break;
    case enMenue::DeleteClients:
        system("cls");
        DeleteClientScreen(vDataClients);
        GoToMainMenue();
        break;
    case enMenue::UpdateClientInfo:
        system("cls");
        UpdateClientInfoScreen(vDataClients);
        GoToMainMenue();
        break;
    case enMenue::FindClients:
        system("cls");
        FindClientScreen(vDataClients);
        GoToMainMenue();
        break;
    case enMenue::ExitProgram:
        system("cls");
        ExitProgrmScreen();
        system("pause>0");
        break;
    }
}

enMenue ReadChooseMenue()
{
    short c = 0;
    cout << "Choose What do you want to do? [1 to 6]? ";
    cin >> c;
    return (enMenue)c;
}

void MainMenueScreen()
{
    cout << "===========================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Exit.\n";
    cout << "===========================================\n";
}

int main()
{
    vector <stClient> vDataClients = LoadClientsDataFromFile(ClientsFileName);
    
    MainMenueScreen();
    enMenue Menue = ReadChooseMenue();
    ChooseMainMenue(Menue, vDataClients);
    
    system("pause>0");
}