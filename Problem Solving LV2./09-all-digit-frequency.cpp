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

int CountDigitFrequency(int Number, short DigitToCheck)
{
	int FreqCount = 0, Remainder = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;

		if (DigitToCheck == Remainder)
			FreqCount++;
	}

	return FreqCount;

}

void PrintAllDigitsFrequency(int Number)
{
	for (int i = 0; i <= 10 - 1; i++)
	{
		int DigitFreqCount = 0;
		DigitFreqCount = CountDigitFrequency(Number, i);

		if (DigitFreqCount > 0)
		{
			cout << "Digit " << i << " Frequency is " << DigitFreqCount << " Time(s).\n";
		}

	}
}

int main()
{

	int Number = ReadPositiveNumber("Please Enter The Main Number?");
	PrintAllDigitsFrequency(Number);
	
	return 0;
}

 