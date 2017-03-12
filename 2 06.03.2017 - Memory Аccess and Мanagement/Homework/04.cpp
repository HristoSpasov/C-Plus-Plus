/// Check if expression brackets are placed correctly;

#include<iostream>
#include<string>
using namespace std;

bool ExpressionIsValid (char bracketsArr[], int bracketsCounterArr[], string expression);

int main()
{
    char bracketsArr[2] = { '(', ')' };
    int bracketsCounterArr[2] = {0, 0};

    cout << "Enter expression: ";
    string expression;
    getline(cin, expression);

    /// Print result
    if(!ExpressionIsValid (bracketsArr, bracketsCounterArr, expression))
    {
        cout << "Brackets are NOT correctly placed!" << endl;
    }
    else
    {
        cout << "Brackets are correctly placed!" << endl;
    }

    return 0;
}

bool ExpressionIsValid (char bracketsArr[], int bracketsCounterArr[], string expression)
{
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == bracketsArr[0])
        {
            bracketsCounterArr[0]++;
        }
        else if (expression[i] == bracketsArr[1])
        {
            bracketsCounterArr[1]++;
        }
    }

    if (bracketsCounterArr[0] != bracketsCounterArr[1])
    {
        return false;
    }
    else
    {
        return true;
    }
}
