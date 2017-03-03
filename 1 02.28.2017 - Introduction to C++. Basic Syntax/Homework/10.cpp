/// Calculates N-th Fibonacci number
/// without using any loop

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    double token1, token2, result;

    /// Just google the formula ^_^
    token1 = pow((0.5 + (0.5 * sqrt(5.0))), n);
    token2 = pow((0.5 - (0.5 * sqrt(5.0))), n);

    result = (token1 - token2) / sqrt(5.0);

    cout << result << endl;

    return 0;
}

