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

int CountDigitFrequency(int Number,short DigitToCheck)
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

int main()
{

	int Number = ReadPositiveNumber("Please Enter The Main Number?");
	int DigitToCheck = ReadPositiveNumber("Please Enter one Digit to Check?");

	cout << "Digit " << DigitToCheck << " Frequency is " << CountDigitFrequency(Number, DigitToCheck) << " Time(s).\n";

	return 0;
}
 