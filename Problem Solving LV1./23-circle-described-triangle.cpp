#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void ReadTriangleData(float& A, float& B, float& C)
{
	cout << "Please enter Triangle side A ? " << endl;
	cin >> A;

	cout << "Please enter Triangle base B ? " << endl;
	cin >> B;

	cout << "Please enter Triangle side C ? " << endl;
	cin >> C;
}

float CircleAreaByATriangle(float A, float B, float C)
{
	const float PI = 3.141592653589793238;
	const float P = (A + B + C) / 2;

	float M = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));
	float Area = PI * pow(M, 2);
	
	return Area;
}

void PrintResult(float Area)
{
	cout << "\n Circle Area Described Around an Arbitrary Triangle  = " << Area << endl;
}

int main()
{
	float A, B, C;
	ReadTriangleData(A, B, C);
	PrintResult(CircleAreaByATriangle(A, B, C));

	return 0;
} 
