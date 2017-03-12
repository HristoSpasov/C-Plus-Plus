/// Sort numbers between given start and end ID in array

#include<iostream>
#include<sstream>
#include<string>
using namespace std;

bool ValidateIndexes (int startIndex, int endIndex, int arrSize);
void ReadArray (int intArr[], int arrSize);
void GetSubArrayValues (int intArr[], int sortedSubArr[], int arrSize, int subArrSize, int startIndex, int endIndex);
void SortSubArray (int sortedSubArr[], int subArrSize);
void ReturnSortedSubArrayToArray (int sortedSubArr[], int intArr[], int arrSize, int subArrSze, int startIndex, int endIndex);
void PrintResult (int intArr[], int arrsize);

int main()
{
    cout << "Enter integer values for startIndex, endIndex and arraySize:" << endl;;
    int startIndex, endIndex, arrSize;
    cin >> startIndex >> endIndex >> arrSize;

    if (!ValidateIndexes(startIndex, endIndex, arrSize))
    {
        cout << "Wrong input. Indexes are not inside the array!";
    }
    else
    {
        int intArr[arrSize]; /// Allocate array in memory;
        ReadArray (intArr, arrSize); /// Read array numbers;
        int subArrSize = endIndex - startIndex + 1;
        int sortedSubArr[subArrSize]; /// Allocate sorted sub array in memory
        GetSubArrayValues (intArr, sortedSubArr, arrSize, subArrSize, startIndex, endIndex); /// Returns subArray values in ascending order
        ReturnSortedSubArrayToArray (sortedSubArr, intArr, arrSize, subArrSize, startIndex, endIndex); /// Return sorted sub array in the main array
        PrintResult (intArr, arrSize); /// Pint intArray after sorting the sub array
    }

    return 0;
}

void PrintResult (int intArr[], int arrsize)
{
    stringstream result;

    for (int i = 0; i < arrsize; i++)
    {
        result << intArr[i] << ", ";
    }

    string resultString = result.str(); /// Get result string from the stream
    string print = resultString.substr(0, resultString.length() - 2); /// Remove the trailing zero from output
    cout << "After sorting the sub array the result is: [" << print << "]" << endl; /// Print result
}

void ReturnSortedSubArrayToArray (int sortedSubArr[], int intArr[], int arrSize, int subArrSize, int startIndex, int endIndex)
{
    for(int i = startIndex, j = 0; i <= endIndex; i++, j++)
    {
        intArr[i] = sortedSubArr[j];
    }
}

void SortSubArray (int sortedSubArr[], int subArrSize)
{
    for (int i = 0; i < subArrSize; i++)
    {
        for (int j = i; j < subArrSize; j++)
        {
            if(sortedSubArr[i] > sortedSubArr[j])
            {
                sortedSubArr[i] = sortedSubArr[i] + sortedSubArr[j];
                sortedSubArr[j] = sortedSubArr[i] - sortedSubArr[j];
                sortedSubArr[i] = sortedSubArr[i] - sortedSubArr[j];
                j--;
            }
        }
    }
}

void GetSubArrayValues (int intArr[], int sortedSubArr[], int arrSize, int subArrSize, int startIndex, int endIndex)
{
    for(int i = 0, j = startIndex; i < subArrSize; i++, j++)
    {
        sortedSubArr[i] = intArr[j];
    }

     SortSubArray (sortedSubArr, subArrSize); /// Call sort function;
}

void ReadArray (int intArr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << "Enter array number " << i + 1 << ": ";
        int currNum;
        cin >> currNum;
        intArr[i] = currNum;
    }
}

bool ValidateIndexes (int startIndex, int endIndex, int arrSize)
{
    if(startIndex < 0 || endIndex < 0
       || startIndex > arrSize - 1
       || endIndex > arrSize - 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
