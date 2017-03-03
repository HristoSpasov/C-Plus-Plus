/// Reverse positive decimal number. Auto test.

#include<iostream>
#include<iomanip>
using namespace std;

int reverseDecimal (int n);
bool trueOrFalse (int testNumber, int resultNumber);

int main()
{
    int inputArr [11] = {10, 222, 303, 1101, 98745, 8512, 642, 851, 7456, 321, 555}; /// Test numbers array
    int outputArr [11] = {1, 222, 303, 1011, 54789, 2158, 246, 158, 6547, 123, 5554}; /// Result numbers array

    double totalPoints; /// Calculate total points
    totalPoints = 0;

    /// Loop over the array to check the results
    for (int i = 0; i < sizeof(inputArr)/sizeof(inputArr[0]); i++)
    {
        int currTestNumber, currResultNumber;
        bool trueOrfalse;
        currTestNumber = inputArr[i];
        currResultNumber = outputArr[i];
        trueOrfalse = trueOrFalse(currTestNumber, currResultNumber); /// Call function to get True/False result

        /// According to trueOrFalse print result
        if(trueOrfalse)
        {
            cout << "Answer " << i + 1 << " is True" << endl;
            totalPoints += (100.0 / (sizeof(inputArr)/sizeof(inputArr[0])));
        }
        else
        {
            cout << "Answer " << i + 1 << " is False" << endl;
        }
    }

    /// Print total result
    int roundedTotalPoints;

    if ((totalPoints + 0.5) >= (int(totalPoints) + 1))
    {
        roundedTotalPoints = int(totalPoints) + 1;
    }
    else
    {
        roundedTotalPoints = int(totalPoints);
    }

    cout << "Total result is " << roundedTotalPoints << "/100 points" << endl; /// Returns the result rounded to nearest int
    cout << "Total result is " << setprecision(4) << totalPoints << "/100 points" << endl; /// Returns result with 4 digits total
    cout << "Total result is " << fixed << setprecision(4)<< totalPoints << "/100 points" << endl; /// Returns the result with 4 digits after decimal point
    return 0;
}

bool trueOrFalse(int testNumber, int resultNumber)
{
    int reversedNumber;
    reversedNumber = reverseDecimal(testNumber); /// Call reverseDecimal function to reverse the test number

    return (reversedNumber == resultNumber); /// Return True/False to main function
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

    return reversedNumberValue; /// Return reversed number to bool function
}
