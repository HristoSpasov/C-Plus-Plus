/// This code:
/// 1. Reads name for input and output files
/// 2. Reads input file and sums the numbers
/// 3. Prints the result in file
/// NB! The input file should be placed in the same dir as the .cpp file
/// NB! There is no input validation.

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>

long long totalSum = 0LL;

using namespace std;

void ParseLine (const string& currLine, const int& currLineLenght);
void SumLine (const int * currLineArr, const int& currLineLenght);

int main()
{
    /// Read names of input & output files;
    string inputFileName, outputFileName;
    cout << "Write the name of input file: ";
    cin >> inputFileName;
    cout << "Write the name of output file: ";
    cin >> outputFileName;

    ifstream inputFileStream(inputFileName.c_str());
    string currLine = "";
    while(getline(inputFileStream, currLine))
    {
        int currNumberParse;
        int currLineLenght = 0;
        stringstream inputSS(currLine);
        while(inputSS >> currNumberParse)
        {
            currLineLenght++;
        }
        ParseLine (currLine, currLineLenght);
    }

    /// Print result to file
    ofstream outputFile(outputFileName.c_str());
    outputFile << "Total sum of all lines is: " << totalSum << "!" << endl;

    return 0;
}

void ParseLine (const string& currLine, const int& currLineLenght)
{
    int * currLineArr = new int[currLineLenght];
    stringstream inputSS(currLine);

    for (int i = 0; i < currLineLenght; i++)
    {
        int currNum;
        inputSS >> currNum;
        currLineArr[i] = currNum;
    }

    SumLine (currLineArr, currLineLenght);

    delete[] currLineArr;
}

void SumLine (const int * currLineArr, const int& currLineLenght)
{
    for (int i = 0; i < currLineLenght; i++)
    {
        totalSum += *(currLineArr + i);
    }
}

