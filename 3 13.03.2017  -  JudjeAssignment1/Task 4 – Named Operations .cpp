#include<iostream>
#include<sstream>
#include<string>
#include <limits>
using namespace std;

int * GetInputArrayLenghtAndPointer (const string& inputArray, int& arrayLenght);
string ** CommandArray (const int& numberOfInputCommands);
string GetOutput (const int arrayLenght,int * inputArrayPointer, const int numberOfInputCommands,string ** commandArrayPointer, int& totalOperationsCounter);
int GetCommandId (const int numberOfInputCommands, string ** commandArrayPointer, const string& commandName);
int GetSum (const int& arrayLenght,int * inputArrayPointer, const int& startIndex, const int& endIndex);
int GetAverage (const int& arrayLenght,int * inputArrayPointer, const int& startIndex, const int& endIndex);
int GetMin (const int& arrayLenght,int * inputArrayPointer, const int& startIndex, const int& endIndex);
int GetMax (const int& arrayLenght,int * inputArrayPointer, const int& startIndex, const int& endIndex);

int main()
{
    /// Read input string, calculate array, allocate array in memory and parse input string in integer array
    string inputArray;
    getline(cin, inputArray);
    int arrayLenght = 0;
    int * inputArrayPointer = GetInputArrayLenghtAndPointer (inputArray, arrayLenght);

    /// Get input commands
    int numberOfInputCommands;
    cin >> numberOfInputCommands;
    string ** commandArrayPointer = CommandArray(numberOfInputCommands);

    //for(int i = 0; i < 4; i++)
    //{
      //  for(int j = 0; j < numberOfInputCommands; j++)
        //{
          //  cout << *(*(commandArrayPointer + i) + j) << " ";
        //}
        //cout << endl;
    //}

    /// Make array operations and get result stream
    int totalOperationsCounter = 0;
    string result = GetOutput(arrayLenght, inputArrayPointer, numberOfInputCommands, commandArrayPointer, totalOperationsCounter);
    result = result.substr(0, result.size() - 1);

    /// Print result
    cout << "[" << totalOperationsCounter << "]{" << result << "}" << endl;

    return 0;
}

string GetOutput (const int arrayLenght,int * inputArrayPointer, const int numberOfInputCommands, string ** commandArrayPointer, int& totalOperationsCounter)
{
    stringstream resultStream;
    string currCommand;

    /// Read and execute operations on array
    while (true)
    {
        getline(cin, currCommand);

        if (currCommand == "end")
        {
            break;
        }

        totalOperationsCounter++;

        /// Get command tokens
        stringstream currCommandTokens(currCommand);
        string commandName;
        int startIndex, endIndex, commandNameId;
        currCommandTokens >> commandName;
        currCommandTokens >> startIndex >> endIndex;

        commandNameId = GetCommandId(numberOfInputCommands, commandArrayPointer, commandName); /// Call function to get command ID from command array

        /// Switch commandNameId to make correct calculations
        int currResult = 0;
        switch(commandNameId)
        {
        case 0:
            {
                currResult = GetSum (arrayLenght, inputArrayPointer, startIndex, endIndex - 1);
            }
            break;

        case 1:
            {
                currResult = GetAverage (arrayLenght, inputArrayPointer, startIndex, endIndex - 1);
            }
            break;

        case 2:
            {
                currResult = GetMin (arrayLenght, inputArrayPointer, startIndex, endIndex - 1);
            }
            break;

        case 3:
            {
                currResult = GetMax (arrayLenght, inputArrayPointer, startIndex, endIndex - 1);
            }
            break;
        }

        /// Add current result to stream
        resultStream << commandName << "(" << startIndex << "," << endIndex << ")=" << currResult << ",";
    }

    return resultStream.str();
}

string ** CommandArray (const int& numberOfInputCommands)
{
    string **commandArray;

    /// Allocate memory for command array
    commandArray = new string*[4]; /// We have 4 type of commands
    for (int i = 0; i < 4; i++)
    {
        commandArray[i] = new string[numberOfInputCommands]; /// Max commands per command type
    }

    /// Set defaultValues for all fields in command array
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < numberOfInputCommands; j++)
        {
            commandArray[i][j] = "unknownX";
        }
    }

    /// Read command types and names

    // Set counter for each command type
        int zeroTypeCounter = 0;
        int oneTypeCounter = 0;
        int twoTypeCounter = 0;
        int threeTypeCounter = 0;
    for(int i = 0; i < numberOfInputCommands; i++)
    {
        string currCommandName;
        int currCommandId;
        cin >> currCommandName;
        cin >> currCommandId;
        cin.ignore();

        ///Switch to save command name in correct command type array
        switch(currCommandId)
        {
        case 0:
            {
                commandArray[currCommandId][zeroTypeCounter] = currCommandName;
                zeroTypeCounter++;
            }
            break;

        case 1:
            {
                commandArray[currCommandId][oneTypeCounter] = currCommandName;
                oneTypeCounter++;
            }
            break;

        case 2:
            {
                commandArray[currCommandId][twoTypeCounter] = currCommandName;
                twoTypeCounter++;
            }
            break;

        case 3:
            {
                commandArray[currCommandId][threeTypeCounter] = currCommandName;
                threeTypeCounter++;
            }
            break;
        }
    }

    return commandArray;
}

int * GetInputArrayLenghtAndPointer (const string& inputArray, int& arrayLenght)
{
    /// Count array elements
    int currNum;
    stringstream inputArrayStream(inputArray);

    while(inputArrayStream >> currNum)
    {
        arrayLenght++;
    }

    /// Allocate input array
    int *inputArrayInt;
    inputArrayInt = new int[arrayLenght];

    /// Fill array elements
    stringstream ParseStream(inputArray); /// Put input in stream
    for(int i = 0; i < arrayLenght; i++)
    {
        ParseStream >> currNum;
        inputArrayInt[i] = currNum;
    }

    return inputArrayInt;
}

int GetCommandId (const int numberOfInputCommands, string ** commandArrayPointer, const string& commandName)
{
    string currCommand;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < numberOfInputCommands; j++)
        {
            currCommand = *(*(commandArrayPointer + i) + j);
            if (currCommand == commandName)
            {
                return i;
            }
        }
    }
}

int GetSum (const int& arrayLenght,int * inputArrayPointer, const int& startIndex, const int& endIndex)
{
    int sum = 0;

    for (int i = startIndex; i <= endIndex; i++)
    {
        sum += *(inputArrayPointer + i);
    }

    return sum;
}

int GetAverage (const int& arrayLenght,int * inputArrayPointer, const int& startIndex, const int& endIndex)
{
    int sum = 0;
    int numCount = 0;

    for (int i = startIndex; i <= endIndex; i++)
    {
        sum += *(inputArrayPointer + i);
        numCount++;
    }

    return (int)sum / numCount;
}

int GetMin (const int& arrayLenght,int * inputArrayPointer, const int& startIndex, const int& endIndex)
{
    int currNum;
    int minNum = numeric_limits<int>::max();

    for (int i = startIndex; i <= endIndex; i++)
    {
        currNum = *(inputArrayPointer + i);
        if (currNum < minNum)
        {
            minNum = currNum;
        }
    }

    return minNum;
}

int GetMax (const int& arrayLenght,int * inputArrayPointer, const int& startIndex, const int& endIndex)
{
    int currNum;
    int maxNum = numeric_limits<int>::min();

    for (int i = startIndex; i <= endIndex; i++)
    {
        currNum = *(inputArrayPointer + i);
        if (currNum > maxNum)
        {
            maxNum = currNum;
        }
    }

    return maxNum;
}
