/// Program that reads from the console
/// a sequence of integer numbers and
/// returns the max and the min numbers

#include <iostream>
using namespace std;

int main()
{
    /// Input data
    int n, minNumber, maxNumber;
    cout << "Enter the count of the numbers in the sequence: " << endl;
    cin >> n;

    /// Loop over to read and compare all the numbers in the sequence
    for(int i = 0; i < n; i++)
    {
        int currNum;
        cout << "Enter number in the sequence: " << endl;
        cin >> currNum;

        /// Assign values of max and min
        ///number equal to the first number value
        if (i == 0)
        {
            minNumber = currNum;
            maxNumber = currNum;
        }

        /// Compare current number value to current min and max numbers
        if (currNum > maxNumber)
        {
            maxNumber = currNum;
        }

        if (currNum < minNumber)
        {
            minNumber = currNum;
        }
    }

    /// Print result
    if (n <= 0) /// If no numbers entered
    {
        cout << "No numbers to compare." << endl;
    }
    else /// If there are 1 or more numbers in the sequence print the result
    {
        cout << "Max number is: " << maxNumber << endl;
        cout << "Min number is: " << minNumber << endl;
    }

    return 0;
}
