/// Reverse positive decimal number.

#include<iostream>
using namespace std;

int reverseDecimal (int n);

int main()
{
    int n;
    cout << "Enter integer number to reverse" << endl;
    cin >> n;

    /// Print reversed number
    cout << "Reversed number is " << reverseDecimal(n) << endl;

    return 0;
}

int reverseDecimal(int n)
{
    int reversedNumberValue = 0;

    while(n != 0)
    {
        reversedNumberValue = reversedNumberValue * 10;
        reversedNumberValue = reversedNumberValue + n % 10;
        n = n / 10;
    }

    return reversedNumberValue; /// Return reversed number to main function
}
