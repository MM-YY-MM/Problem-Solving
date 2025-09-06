#include <iostream>
#include <string>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

bool IsCheckPerfect(int Number) 
{
	int Sum = 0;
	for (int i = 1; i < Number; i++)
	{
		if (Number % i == 0)
		{
			Sum += i;
		}
	}
	return Number == Sum;
}

void PrintResults(int Number)
{
	if (IsCheckPerfect(Number))
		cout << Number << " it's Perfect Number.\n";
	else
		cout << Number << " it's Not Perfect Number.\n";
}

int main()
{
	int Number = ReadPositiveNumber("Please Enter a Number");
	PrintResults(Number);
	return 0;
} 