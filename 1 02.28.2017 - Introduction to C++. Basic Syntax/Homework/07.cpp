/// Program to count all trailing zeros

#include <iostream>
using namespace std;

int main()
{
    int n, factorialTrailingZeros;
    cin >> n;

    /// For each 5! the trailing zeros increase by 1
    /// For each 25! the trailing zeros increase by 1
    factorialTrailingZeros = n / 5 + n / 25;

    cout << factorialTrailingZeros << endl;

    return 0;
}
