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

int MyRound(float Number)
{

    int IntPart = 0;
    IntPart = int(Number); 

    float FractionPart = GetFractionPart(Number);

    if (abs(FractionPart) >= 0.5)
    {
        if (Number > 0) 
            return ++Number;
        else
            return --Number;
    }
    else
        return IntPart;

}

int main()
{
    float Number = ReadNumber("\nEnter The Number?");


    cout << "\nMy round Result : " << MyRound(Number) << endl;
    cout << "\nC++ round Result : " << round(Number) << endl;

    
    return 0;
}
 