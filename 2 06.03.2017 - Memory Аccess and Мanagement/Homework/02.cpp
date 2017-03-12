/// The code returns the leftmost sequence of
/// equal elements

#include<iostream>
using namespace std;

void InputArrayElements (int intArr[], int arrSize);
int ResultArray (int intArr[],int resultArray[], int arrSize);

int main()
{
    cout << "Enter array size: " <<endl;;
    int arrSize;
    cin >> arrSize;
    int intArr[arrSize];
    int resultArray[arrSize];
    InputArrayElements (intArr, arrSize);
    int resultArrLenght = ResultArray (intArr, resultArray, arrSize);

    // Print result
    for(int i = 0; i < resultArrLenght; i++)
    {
        cout << resultArray[i] << " ";
    }

    return 0;
}

void InputArrayElements (int intArr[], int arrSize)
{
    cout << "Enter array values one by one" << endl;
    for (int i = 0; i < arrSize; i ++)
    {
        int currValue;
        cin >> currValue;
        intArr[i] = currValue;
    }
}

int ResultArray (int intArr[], int resultArray[], int arrSize)
{
    int currStartIndex, currMaxStartIndex, currLenght, currMaxLenght;
    currStartIndex = 0;
    currMaxStartIndex = 0;
    currLenght = 1;
    currMaxLenght = 1;

    for(int i = 0; i < arrSize - 1; i++)
    {
        if (intArr[i] == intArr[i + 1])
        {
            currLenght++;

            if (currLenght > currMaxLenght)
            {
                currMaxLenght = currLenght;
                currMaxStartIndex = currStartIndex;
            }
        }
        else
        {
            if (currLenght > currMaxLenght)
            {
                currMaxLenght = currLenght;
                currMaxStartIndex = currStartIndex;
            }

            currLenght = 1;
            currStartIndex = i + 1;
        }
    }

    for(int i = 0,j = currMaxStartIndex; i < currMaxLenght;i++, j++)
    {
        resultArray[i] = intArr[j];
    }

    return currMaxLenght;
}
