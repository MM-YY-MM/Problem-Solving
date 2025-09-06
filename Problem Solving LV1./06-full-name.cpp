#include <iostream>
#include <string>

using namespace std;

struct stInfo
{
	string FirstName;
	string LastName;
};

stInfo ReadInfo()
{
	stInfo Name;

	cout << "Please Enter Your First Name?\n";
	cin >> Name.FirstName;

	cout << "Please Enter Your Last Name?\n";
	cin >> Name.LastName;

	return Name;
}

string GetFullName(stInfo Info)
{
	string FullName = "";

	FullName = Info.FirstName + " " + Info.LastName;

	return FullName;
}

void PrintFullName(string FullName)
{

	cout << "\n Your full name is: " << FullName << endl;

}

int main()
{

	PrintFullName(GetFullName(ReadInfo()));

	return 0;

} 
