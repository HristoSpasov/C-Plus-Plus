/// Print the real roots of
/// quadratic equation ax2 + bx + c = 0

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    /// Declare and read input values of the quadratic equation
    double a, b, c;
    cin >> a >> b >> c;

    if(a == 0) /// If a is 0 the equation is not quadratic
    {
        cout << "Element 'a' is 0 => the equation is not quadratic." << endl;
    }
    else
    {
        double discriminant = pow(b, 2.0) - 4 * a * c;

        if (discriminant > 0)
        {
            double x1, x2;

            x1 = (-b + sqrt(discriminant)) / (2 * a);
            x2 = (-b - sqrt(discriminant)) / (2 * a);

            cout << "Discriminant is positive => the equation has  2 real roots." << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
        else if (discriminant = 0)
        {
            double x;

            x = -b / (2 * a);

            cout << "Discriminant is 0 => the equation has  1 real root." << endl;
            cout << "x = " << x << endl;
        }
        else
        {
            cout << "Discriminant is negative => the equation does not have any real roots." << endl;
        }
    }

    return 0;
}
