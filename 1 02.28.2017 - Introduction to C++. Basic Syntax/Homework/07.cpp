/// Program to count all trailing zeros

#include <iostream>
using namespace std;

int main()
{
    double n;
    int factorialTrailingZeros = 0;
    cin >> n;

    while (n >= 1)
    {
        double currZeroesToAdd = n / 5.0;
        factorialTrailingZeros += (int)currZeroesToAdd;
        n = n / 5.0;
    }

    cout << factorialTrailingZeros << endl;

    return 0;
}
