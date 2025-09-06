#include <iostream>
#include <string>

using namespace std;

int ReadTotalSales()
{
	int TotalSales;
	cout << "Please enter a Total Sales?" << endl;
	cin >> TotalSales;
	return TotalSales;
}

float GetCommissionPercentage(float TotalSales)
{
	if (TotalSales >= 1000000)
		return 0.01;
	else if (TotalSales >= 500000)
		return 0.02;
	else if (TotalSales >= 100000)
		return 0.03;
	else if (TotalSales >= 50000)
		return 0.05;
	else
		return 0.00;
}

float CalculateTotalCommission(float TotalSales)
{
	return TotalSales * GetCommissionPercentage(TotalSales);
}

int main()
{
	float TotalSales = ReadTotalSales();

	cout << "Commission Percentage = " << GetCommissionPercentage(TotalSales) << endl;
	cout << "Total Commission = " << CalculateTotalCommission(TotalSales) << endl;
	
	return 0;
}
 
