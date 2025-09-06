#include <iostream>
#include <string>

using namespace std;

void PrintAllWordsFromAAAToZZZ()
{
	string Word = "";
	cout << "\n";
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				Word = Word + char(i);
				Word = Word + char(j);
				Word = Word + char(k);

				cout << Word << endl;

				Word = ""; // empty
			}
		}
		cout << "\n____________________________\n";
	}

}

int main()
{
	PrintAllWordsFromAAAToZZZ();
	return 0;
}
 