/// Program that shows the sign of the product
/// of 3 real numbers without calculating the sum;

#include <iostream>
using namespace std;

int main()
{
    /// Read input data
    int a, b, c;
    cin >> a >> b >> c;

    int minusSignCounter; /// Minus sign counter
    bool isZero = false;

    /// Count the negative numbers
    if (a < 0)
    {
        minusSignCounter++;
    }

    if(b < 0)
    {
        minusSignCounter++;
    }

    if(c < 0)
    {
        minusSignCounter++;
    }

    /// If some of the input numbers are 0 the isZero bool
    /// is set to true;
    if(a ==0 || b == 0 || c == 0)
    {
        isZero = true;
    }

    /// Print the result
    if(isZero == true)
    {
      cout << "The sum is 0" << endl;
    }
    else
    {
        if(minusSignCounter % 2 == 0)
        {
            cout << "The product of the numbers is positive '+'" << endl;
        }
        else
        {
            cout << "The product of the numbers is negative '-'" << endl;
        }
    }

    return 0;
}
