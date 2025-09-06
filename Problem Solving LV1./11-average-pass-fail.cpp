#include <iostream>
#include <string>

using namespace std;

enum enPassFail { Pass = 1, Fail = 2 };

void ReadNumbers(int& Mark1, int& Mark2, int& Mark3)
{
	cout << "Please enter your Mark 1 ? " << endl;
	cin >> Mark1;

	cout << "Please enter your Mark 2 ? " << endl;
	cin >> Mark2;

	cout << "Please enter your Mark 3 ? " << endl;
	cin >> Mark3;
}

int SumOf3Marks(int Mark1, int Mark2, int Mark3)
{
	return Mark1 + Mark2 + Mark3;
}

float CalculateAverage(int Mark1, int Mark2, int Mark3)
{
	return (float)SumOf3Marks(Mark1, Mark2, Mark3) / 3;
}

enPassFail CheckAverage(int Average)
{
	if (Average >= 50)
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
}

void PrintResults(int Average)
{
	cout << "\n The Average is : " << Average << endl;

	if (CheckAverage(Average) == enPassFail::Pass)
		cout << "\n You Passed..!" << endl;
	else
		cout << "\n You Failed..!" << endl;
}

int main()
{
	int Mark1, Mark2, Mark3;
	ReadNumbers(Mark1, Mark2, Mark3);
	PrintResults(CalculateAverage(Mark1, Mark2, Mark3));

	return 0;
}
 
