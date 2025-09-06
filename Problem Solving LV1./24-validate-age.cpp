#include <iostream>
#include <string>

using namespace std;

short ReadAge()
{
	short Age;

	cout << "Please enter your Age ? " << endl;
	cin >> Age;

	return Age;
}

bool ValidateNumberInRange(int Number, int From, int To)
{
	return (Number >= From && Number <= To); 
}

void PrintResult(short Age)
{
	if (ValidateNumberInRange(Age, 18, 45))
		cout << Age << " is a valid age \n";
	else
		cout << Age << " is inValid age \n";
}

int main()
{
	PrintResult(ReadAge());
  
	return 0;
} 
