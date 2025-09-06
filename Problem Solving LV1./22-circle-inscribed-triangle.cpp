#include <iostream>
#include <string>

using namespace std;

void ReadTriangleData(float& A, float& B)
{
	cout << "Please enter Triangle side A ? " << endl;
	cin >> A;

	cout << "Please enter Triangle base B ? " << endl;
	cin >> B;
}

float CircleAreaByITriangle(float A, float B)
{
	const float PI = 3.141592653589793238;

  //Calculations Priorities
  //float Area = ((PI * pow(B, 2)) / 4) *(((2 * A) - B) / ((2 * A) + B));
	float Area = ((PI * pow(B, 2)) / 4) *((2 * A - B) / (2 * A + B));

	return Area;
}

void PrintResult(float Area)
{
	cout << "\n Circle Area Inscribed in an Isosceles Triangle  = " << Area << endl;
}

int main()
{
	float A, B;
	ReadTriangleData(A, B);
	PrintResult(CircleAreaByITriangle(A, B));

	return 0;
} 
