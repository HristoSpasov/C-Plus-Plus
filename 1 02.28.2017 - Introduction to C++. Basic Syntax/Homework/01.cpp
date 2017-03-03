/// Conditional statement that examines two
/// integer variables and exchange their
/// values if the first one is greater then the
/// second one

#include <iostream>

using namespace std;

int main()
{
    int firstNumber;
    int secondNumber;

    cin >> firstNumber >> secondNumber;

    if (firstNumber > secondNumber)
    {
        int tmpNumber;
        tmpNumber = firstNumber;
        firstNumber = secondNumber;
        secondNumber = tmpNumber;
    }

    cout << "first " << firstNumber << endl;
    cout << "second " << secondNumber << endl;

    return 0;
}
