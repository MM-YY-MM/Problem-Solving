#include <iostream>
#include <cmath>

using namespace std;

float ReadNumber(string Message)
{
    float Number = 0;
    cout << Message << endl;
    cin >> Number;
    return Number;
}

int MyFloor(float Number)
{
    if (Number > 0)
        return int(Number);
    else
        return int(Number) - 1;
}

int main()
{
    float Number = ReadNumber("\nEnter The Number?");


    cout << "\nMy floor Result : " << MyFloor(Number) << endl;
    cout << "\nC++ floor Result : " << floor(Number) << endl;


    return 0;
}