#include <iostream>
#include <string>

using namespace std;

float ReadCircumference()
{
	float L;

	cout << "Please enter Circum ference L ? " << endl;
	cin >> L;

	return L;
}

float CircleAreaByCircumference(float L)
{
	const float PI = 3.141592653589793238;
	float Area = pow(L, 2) / (4 * PI);

	return Area;
}

void PrintResult(float Area)
{
	cout << "\n Circle Area By Circum ference = " << Area << endl;
}

int main()
{
	PrintResult(CircleAreaByCircumference(ReadCircumference()));

	return 0;
} 
