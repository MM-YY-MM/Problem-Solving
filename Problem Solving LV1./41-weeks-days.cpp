#include <iostream>
#include <string>

using namespace std;

float ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	
	return Number;
}

float HoursToDays(float NumberOfHours)
{
	return NumberOfHours / 24;
}

float HoursToWeeks(float NumberOfHours)
{
	return NumberOfHours / 24 / 7;
}

float DaysToWeeks(float NumberOfDays)
{
	return NumberOfDays / 7;
}

void PrintResults(float NumberOfHours,float NumberOfDays,float NumberOfWeeks)
{
	cout << "Total Hours = " << NumberOfHours << endl;
	cout << "Total Days = " << NumberOfDays << endl;
	cout << "Total Weeks = " << NumberOfWeeks << endl;
	cout << "***************************" << endl;
	cout << "Total Weeks = " << HoursToWeeks(NumberOfHours) << endl;
}

int main()
{
	float NumberOfHours = ReadPositiveNumber("Please Enter Number Of Hours?");
	float NumberOfDays = HoursToDays(NumberOfHours);
	float NumberOfWeeks = DaysToWeeks(NumberOfDays);

	cout << endl;
	PrintResults(NumberOfHours, NumberOfDays, NumberOfWeeks);

	return 0;
}
