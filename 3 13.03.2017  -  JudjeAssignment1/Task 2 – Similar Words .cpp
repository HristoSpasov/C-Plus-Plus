#include<iostream>
#include<string>
#include<sstream>
using namespace std;

void wordsCompare(const string& splitedString, const string& compareWord, const int& targetPercentageMatch, int& matchCounter);
string InputSplit (char* inputCharArr, int inputCharArrLenght);
int main()
{
    /// Read input
    string inputLine, compareWord;
    int targetPercentageMatch, matchCounter = 0;
    getline(cin, inputLine);
    cin >> compareWord >> targetPercentageMatch;

    /// Split input line
    char * inputCharArr = new char[inputLine.length() + 1];
    copy(inputLine.begin(), inputLine.end(), inputCharArr);
    inputCharArr[inputLine.length()] = '\0';
    int inputCharArrLenght = inputLine.length() + 1;
    string splitedString = InputSplit (inputCharArr, inputCharArrLenght);

    wordsCompare(splitedString, compareWord, targetPercentageMatch, matchCounter); /// Calculate matchCounter

    delete[] inputCharArr; /// Clear array from stack;

    /// Print result
    cout << matchCounter;

    return 0;
}

string InputSplit (char* inputCharArr, int inputCharArrLenght)
{
    stringstream splitedInput;

    for (int i = 0; i < inputCharArrLenght; i++)
    {
        if (isalpha(*(inputCharArr + i)))
        {
            splitedInput << *(inputCharArr + i);
        }
        else
        {
            splitedInput << " ";
        }
    }

    return splitedInput.str();
}

void wordsCompare (const string& splitedString, const string& compareWord, const int& targetPercentageMatch, int& matchCounter)
{
    stringstream splitedStringStream(splitedString);
    string currWord = "";
    while(splitedStringStream >> currWord)
    {
        double currWordPercentageMatch;
        int currWordMatchCharCount = 0;

        /// For all valid words count the matching chars and calculate match percent
        if (currWord[0] == compareWord[0] && currWord.length() == compareWord.length())
        {
            for (int i = 0; i < currWord.length(); i++)
            {
                if (currWord[i] == compareWord[i])
                {
                    currWordMatchCharCount++;
                }
            }

            /// Calculate match percent
            currWordPercentageMatch = currWordMatchCharCount / (double)currWord.length() * 100.0;

            /// If match percent is >= targetPercentageMatch increase the counter;
            if(currWordPercentageMatch >= targetPercentageMatch)
            {
                matchCounter++;
            }
        }
    }
}
