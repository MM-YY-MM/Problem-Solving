 
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

float CalculateRemainder(float TotalBill, float TotalCashPaid)
{
	return TotalCashPaid - TotalBill;
}

void PrintRemainder(float TotalBill, float TotalCashPaid)
{
	cout << "Total Bill = " << TotalBill << endl;
	cout << "Total Cash Paid = " << TotalCashPaid << endl;

	cout << "***************************\n";
	cout << "Remainder = " << CalculateRemainder(TotalBill, TotalCashPaid) << endl;
}

int main()
{
	float TotalBill = ReadPositiveNumber("Please Enter Total Bill?");
	float TotalCashPaid = ReadPositiveNumber("Please Enter Total Cash Paid?");

	cout << endl;
	PrintRemainder(TotalBill, TotalCashPaid);

	return 0;
}
