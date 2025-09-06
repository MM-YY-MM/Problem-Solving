#include <iostream>
#include <string>

using namespace std;

float ReadSquareSide()
{
	float A;

	cout << "Please enter Square Side A ? " << endl;
	cin >> A;

	return A;
}

float CircleAreaInscribedInSquare(float A)
{
	const float PI = 3.141592653589793238;
	float Area = (PI * (pow(A, 2))) / 4;

	return Area;
}

void PrintResult(float Area)
{
	cout << "\n Circle Area In scribed In Square = " << Area << endl;
}

int main()
{
	PrintResult(CircleAreaInscribedInSquare(ReadSquareSide()));

	return 0;
}
 
