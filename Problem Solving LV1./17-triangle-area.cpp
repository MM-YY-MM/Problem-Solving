#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void ReadNumbers(float& A, float& H)
{
	cout << "Please enter Triangle base A ? " << endl;
	cin >> A;

	cout << "Please enter Triangle height H ? " << endl;
	cin >> H;
}

float TriangleArea(float A, float H)
{
	float Area = (A / 2) * H;

	return Area;
}

void PrintResult(float Area)
{
	cout << "\n Triangle Area = " << Area << endl;
}

int main()
{
	float A, B;
	ReadNumbers(A, B);
	PrintResult(TriangleArea(A, B));

	return 0;
}
 
