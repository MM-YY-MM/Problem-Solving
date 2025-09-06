#include <iostream>
#include <string>

using namespace std;

int ReadNumber()
{
	int Number;
	cout << "Please enter the Number ? " << endl;
	cin >> Number;
	return Number;
}

int ReadPower()
{
	int Number;
	cout << "Please enter the Power ? " << endl;
	cin >> Number;
	return Number;
}

int PowerOfM(int Number, int M)
{
	if (M == 0)
	{
		// Any number powered to zero gives 1
		return 1;
	}

	int Power = 1;

	for (int Counter = 1; Counter <= M; Counter++)
	{
		Power *= Number;
	}

	return Power;
}

int main()
{
  int Number = ReadNumber();
  int Power = ReadPower();
  
	cout << endl << " Result = " << PowerOfM(Number, Power) << endl;
	
	return 0;
} 
