#include <iostream>
#include <string>

using namespace std;

void ReadNumbers(int& A, int& B, int& C)
{
	cout << "Please enter your A ? " << endl;
	cin >> A;

	cout << "Please enter your B ? " << endl;
	cin >> B;

	cout << "Please enter your C ? " << endl;
	cin >> C;
}

int MaxOf2Numbers(int A, int B, int C)
{
	if (A > B)
		if (A > C)
			return A;
		else
			return C;
    
	else
		if (B > C)
			return B;
		else
			return C;
}

void PrintResults(int Max)
{
	cout << "\n The Maximum Number is : " << Max << endl;
}

int main()
{
	int A, B, C;
	ReadNumbers(A, B, C);
	PrintResults(MaxOf2Numbers(A, B, C));

	return 0;
}
 
