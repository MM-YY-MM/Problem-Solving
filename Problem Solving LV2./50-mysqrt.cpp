#include <iostream>
#include <cmath>

using namespace std;

float ReadNumber(string Message)
{
    int Number = 0;
    cout << Message << endl;
    cin >> Number;
    return Number;
}

float MySqrt(float Number)
{
    return pow(Number,0.5);
}

int main()
{
    float Number = ReadNumber("\nEnter The Number?");


   cout << "\nMy sqrt Result : " << MySqrt(Number) << endl;
    cout << "\nC++ sqrt Result : " << sqrt(Number) << endl;


    return 0;
} 