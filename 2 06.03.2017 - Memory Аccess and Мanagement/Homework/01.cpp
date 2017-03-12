#include<iostream>
using namespace std;

bool IsArrayLargeEnough (int arraySize, int numbersToCompare); // Check if numbers for compare are more than array size;
void ReadArrayNumbers (int firstArray[], int secondArray[], int numbersToCompare); // Read array data;
bool CompareArrays (int firstArray[], int secondArray[], int numbersToCompare); // Declare bool array to compare arrays


int main()
{
    cout << "Input arraySize and the total numbers in each array" << endl;
    int arraySize, numbersToCompare;;
    cin >> arraySize >> numbersToCompare;

    if (!IsArrayLargeEnough (arraySize, numbersToCompare))
    {
        cout << "Arrays are not big enough to store all numbers or negative input value." << endl;
    }
    else
    {
        // Declare both arrays
        int firstArray[arraySize];
        int secondArray[arraySize];

        ReadArrayNumbers (firstArray, secondArray, numbersToCompare); // Read arrays elements

        // Print result
        if (CompareArrays (firstArray, secondArray, numbersToCompare))
        {
            cout << "Both the arrays are equal!" << endl;
        }
        else
        {
            cout << "The arrays are not equal!" << endl;
        }
    }

    return 0;
}

bool IsArrayLargeEnough (int arraySize, int numbersToCompare)
{
    if (numbersToCompare > arraySize || arraySize < 0 || numbersToCompare < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void ReadArrayNumbers (int firstArray[], int secondArray[], int numbersToCompare)
{
    for (int i = 0; i < numbersToCompare; i++)
    {
        int currFirstArrayValue, currSecondArrayValue;
        cout << "Input value for element [" << i << "] in first array!" << endl;
        cin >> currFirstArrayValue;
        cout << "Input value for element [" << i << "] in first array!" << endl;
        cin >> currSecondArrayValue;

        firstArray[i] = currFirstArrayValue;
        secondArray[i] = currSecondArrayValue;
    }
}

bool CompareArrays (int firstArray[], int secondArray[], int numbersToCompare)
{
    int equalNumbersCount = 0;

    for(int i = 0; i < numbersToCompare; i++)
    {
        if (firstArray[i] == secondArray[i])
        {
            equalNumbersCount++;
        }
    }

    if (equalNumbersCount == numbersToCompare)
    {
        return true;
    }
    else
    {
        return false;
    }
}
