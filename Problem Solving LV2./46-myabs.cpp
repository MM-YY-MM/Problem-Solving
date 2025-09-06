#include <iostream>
#include <cmath>

using namespace std;

int ReadNumber(string Message)
{
    int Number = 0;
    cout << Message << endl;
    cin >> Number;
    return Number;
}

int MyABS(int Number)
{
    if (Number >= 0)
        return Number;
    else
        return Number * -1; // -10 * -1 = (Not -) (Result = 10 * 1 = 10)
}

int main()
{
    int Number = ReadNumber("\nEnter The Number?");

    cout << "\nMy abs Result : " << MyABS(Number) << endl;
    cout << "\nC++ abs Result : " << MyABS(Number) << endl;

    
    return 0;
}