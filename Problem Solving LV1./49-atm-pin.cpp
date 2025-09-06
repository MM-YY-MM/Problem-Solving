#include <iostream>

using namespace std;

string ReadPinCode()
{
	string PinCode;
	cout << "Please enter PIN Code \n";
	cin >> PinCode;
	return PinCode;
}

bool Login()
{
	string PinCode;
	do
	{
		PinCode = ReadPinCode();

		if (PinCode == "1234")
		{
			// this will exit the function and return true Login
			return 1; 
		}
		else
		{
			cout << "\nWrong PIN\n";
			system("color 4F"); //turn screen to Red
		}
	} while (PinCode != "1234");

	return 0; //when you reach here this means login failed
}

int main()
{
	if (Login())
	{
		system("color 2F"); //turn screen to green
		cout << "\n Your Account Balance is " << 7500 << '\n';
	}

	return 0;
}
 
