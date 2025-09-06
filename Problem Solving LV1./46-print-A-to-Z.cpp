
#include <iostream>
#include <string>

using namespace std;

void PrintLetters_AtoZ()
{
	for (int i = 65; i <= 90; i++)
	{
		cout << char(i) << endl;
	}
}

int main()
{
	PrintLetters_AtoZ();
	return 0;
} 
