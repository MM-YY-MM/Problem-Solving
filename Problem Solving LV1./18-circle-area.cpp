#include <iostream>
#include <string>

using namespace std;

float ReadRadious()
{
	float R;

	cout << "Please enter radious R ? " << endl;
	cin >> R;

	return R;
}

float CircleArea(float R)
{
	const float PI = 3.141592653589793238;
	float Area = PI * (pow(R, 2));

	return Area;
}

void PrintResult(float Area)
{
	cout << "\n Circle Area = " << Area << endl;
}

int main()
{
	PrintResult(CircleArea(ReadRadious()));

	return 0;
}
 
