/// This code:
/// 1. Reads the number of rows to be summed from console
/// 2. Reads rows one by one from console and sums numbers

#include<iostream>
#include<sstream>
#include<string>

int totalSum = 0; /// Holds total sum;

using namespace std;

void GetRowElemetsCount (const string& currLine, int& resultLenght); /// Function to get number of elements for each row
void parseNumbers(const string& currLine, const int& resultLenght); /// Parse string to int[] array in heap
void TotalSumCalculate (int * currRowArr, const int& resultLenght); /// Call from parseNUmber function to calculate total sum

int main()
{
    /// Read number of input rows
    cout << "Enter numbers of rows to read: ";
    int numberOfRows, currline = 1;
    cin >> numberOfRows;
    cin.ignore();

    /// Loop over each row
    while(numberOfRows > 0)
    {
        cout << "Enter line " << currline << " elements separated by at least one whitespace: ";
        string currLine = "";
        getline(cin, currLine);
        int resultLenght = 0;
        GetRowElemetsCount (currLine, resultLenght); /// Get the lenght of current row
        parseNumbers(currLine, resultLenght); /// Parse numbers to int[] array
        numberOfRows--;
        currline++;
    }

    cout << "Total sum is: " << totalSum << endl; /// Print result;

    return 0;
}

void GetRowElemetsCount (const string& currLine, int& resultLenght)
{
    stringstream ss;
    ss << currLine;
    int number = 0;
    while(ss >> number)
    {
        resultLenght++;
    }
}

void parseNumbers(const string& currLine, const int& resultLenght)
{
    int * currRowArr = new int[resultLenght]; /// Create array to hold current row int values
    stringstream ss;
    ss << currLine;
    int number = 0;

    for (int i = 0; i < resultLenght; i ++)
    {
        ss >> number;
        currRowArr[i] = number;
    }

    TotalSumCalculate (currRowArr, resultLenght); /// Call function to sum current row array elements

    delete[] currRowArr; /// Free the memory allocated for current row array
}

void TotalSumCalculate (int * currRowArr, const int& resultLenght)
{
    for (int i = 0; i < resultLenght; i++)
    {
        totalSum += *(currRowArr + i);
    }
}
