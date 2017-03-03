/// Calculate the greatest common
/// divisor (GCD) of two numbers

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    while(a != 0)
    {
        /// Change place of numbers if a < b
        if (a < b)
        {
            a = a + b;
            b = a - b;
            a = a - b;
        }

        a = a % b;
    }

    /// Print result
    cout << "The (GCD) is: " << b << endl;

    return 0;
}
