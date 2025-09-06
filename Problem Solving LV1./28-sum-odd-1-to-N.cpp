#include <iostream>
#include <string>

using namespace std;

enum enOddOrEven { Odd = 1, Even = 2 };

int ReadNumber()
{
	int Number;
	cout << "Please enter the Number ? " << endl;
	cin >> Number;
	return Number;
}

enOddOrEven CheckOddOrEven(int Number)
{
	if (Number % 2 != 0)
		return enOddOrEven::Odd;
	else
		return enOddOrEven::Even;
}

int SumOddNumbersFromNto1_UsingWhile(int N)
{
	int Counter = 0;
	int Sum = 0;

	cout << "Sum Odd Numbers using While Statement:\n";
	while (Counter < N)
	{
		Counter++;
		if (CheckOddOrEven(Counter) == enOddOrEven::Odd)
		{
			Sum += Counter;
		}
	}
  
	return Sum;
}

int SumOddNumbersFromNto1_UsingDoWhile(int N)
{
	int Counter = 0;
	int Sum = 0;
  
	cout << "Sum Odd Numbers using Do..While Statement:\n";
	do
	{
		Counter++;
		if (CheckOddOrEven(Counter) == enOddOrEven::Odd)
		{
			Sum += Counter;
		}
	} while (Counter < N);

	return Sum;
}

int SumOddNumbersFromNto1_UsingFor(int N)
{
	int Sum = 0;

	cout << "Sum Odd Numbers using For Statement:\n";
	for (int Counter = 1; Counter <= N; Counter++) 
	{
		if (CheckOddOrEven(Counter) == enOddOrEven::Odd)
		{
			Sum += Counter;	
		}
	}

	return Sum;
}

int main()
{
	int N = ReadNumber();

	cout << SumOddNumbersFromNto1_UsingWhile(N) << endl;
	cout << SumOddNumbersFromNto1_UsingDoWhile(N) << endl;
	cout << SumOddNumbersFromNto1_UsingFor(N) << endl;

	return 0;
} 
