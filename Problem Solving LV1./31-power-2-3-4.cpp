#include <iostream>
#include <string>

using namespace std;

int ReadNumber()
{
	int Number;
	cout << "Please enter the Number ? " << endl;
	cin >> Number;
	return Number;
}

void Power_f2_3_4(int Number)
{
	int a, b, c;

	a = Number * Number;
	b = Number * Number * Number;
	c = Number * Number * Number * Number;

	cout << a << " " << b << " " << c << endl;
}

int main()
{
	Power_f2_3_4(ReadNumber());

	return 0;
} 
