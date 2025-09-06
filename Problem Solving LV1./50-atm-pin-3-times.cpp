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
	short FailedCount = 3;

	do
	{
		FailedCount--;
		PinCode = ReadPinCode();

		if (PinCode == "1234")
		{
			// this will exit the function and return true Login
			return 1; 
		}
		else
		{
			system("color 4F"); //turn screen to Red
			cout << "\nWrong PIN, You have " << FailedCount << " More is tries\n";
		}

	} while (FailedCount >= 1 && PinCode != "1234");

	return 0; //when you reach here this means login failed
}

int main()
{	
	if (Login())
	{
		system("color 2F"); //turn screen to green
		cout << "\n Your Account Balance is " << 7500 << '\n';
	}
	else
	{
		cout << "\nYour Card blocked call the bank for help. \n";
	}

	return 0;
}
 
