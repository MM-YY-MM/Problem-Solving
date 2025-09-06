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

float GetFractionPart(float Number)
{
    return Number - int(Number);
}

int MyCeiling(float Number)
{
    if (abs(GetFractionPart(Number)) > 0)
    {
        if (Number > 0)
            return int(Number) + 1;
        else
            return int(Number);
    }
    else
        return Number;

}

int main()
{
    float Number = ReadNumber("\nEnter The Number?");


    cout << "\nMy ceil Result : " << MyCeiling(Number) << endl;
    cout << "\nC++ ceil Result : " << ceil(Number) << endl;


    return 0;
} 