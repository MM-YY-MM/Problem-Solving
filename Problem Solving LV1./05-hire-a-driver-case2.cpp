#include <iostream>
#include <string>

using namespace std;

struct stInfo
{
	short Age;
	bool HasDrivingLicense;
	bool HasRecommendation;
};

stInfo ReadInfo()
{
	stInfo Info;

	cout << "PLease Enter The Age?\n";
	cin >> Info.Age;

	cout << "Do you Have Driver License?\n";
	cin >> Info.HasDrivingLicense;

	cout << "Do you Have Recommendation?\n";
	cin >> Info.HasRecommendation;

	return Info;
}

bool IsAccepted(stInfo Info)
{
	if (Info.HasRecommendation)
	{
		return true;
	}
	else
	{
		return (Info.Age >= 21 && Info.HasDrivingLicense);
	}
}

void PrintResult(stInfo Info)
{
	if (IsAccepted(Info))
		cout << "\n Hired" << endl;
	else
		cout << "\n Rejected" << endl;
}

int main()
{
	PrintResult(ReadInfo());
	return 0;
} 
