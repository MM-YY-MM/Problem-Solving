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

void PrintPerfectNumbersFrom1ToN(int Number)
{
	cout << "\n";
	cout << "Perfect Numbers from " << 1 << " To " << Number;
	cout << " are : " << endl;

	for (int i = 1; i <= Number; i++)
	{
		if (IsCheckPerfect(i))
		{
			cout << i << endl;
		}
	}
}

int main()
{
	int Number = ReadPositiveNumber("Please Enter a Number");
	PrintPerfectNumbersFrom1ToN(Number);
	return 0;
} 