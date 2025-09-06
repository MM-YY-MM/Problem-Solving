#include <iostream>
#include <string>

using namespace std;

struct strTaskDuration
{
	int NumberOfDays = 0, NumberOfHours = 0
		, NumberOfMinutes = 0, NumberOfSeconds = 0;
};

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

strTaskDuration ReadTaskDuration()
{
	strTaskDuration TaskDuration;
	TaskDuration.NumberOfDays = ReadPositiveNumber("Please Enter Number Of Days?");
	TaskDuration.NumberOfHours = ReadPositiveNumber("Please Enter Number Of Hours?");
	TaskDuration.NumberOfMinutes = ReadPositiveNumber("Please Enter Number Of Minutes?");
	TaskDuration.NumberOfSeconds = ReadPositiveNumber("Please Enter Number Of Seconds?");

	return TaskDuration;
}

int TaskDurationInSeconds(strTaskDuration TaskDuration)
{
	int DurationInSeconds = TaskDuration.NumberOfDays * 24 * 60 * 60;
	DurationInSeconds += TaskDuration.NumberOfHours * 60 * 60;
	DurationInSeconds += TaskDuration.NumberOfMinutes * 60;
	DurationInSeconds += TaskDuration.NumberOfSeconds;

	return DurationInSeconds;
}

int main()
{
	cout << "\n Task Duration In Seconds : " << TaskDurationInSeconds(ReadTaskDuration());
	cout << endl;

	return 0;
} 
