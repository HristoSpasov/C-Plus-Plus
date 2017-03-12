#include<iostream>
#include<sstream>
#include<string>
#include<fstream>

using namespace std;

bool FilesExist (const string& firstFile, const string& secondFile);
bool FileLinesCountIsEqual (const string& firstFile, const string& secondFile);
bool CompareLineByLine (const string& firstFile, const string& secondFile);

int main()
{
    string firstFile, secondFile;
    cout << "Enter first file to compare: ";
    cin >> firstFile;
    cout << "Enter second file to compare: ";
    cin >> secondFile;

    if (FilesExist (firstFile, secondFile))
    {
        if (FileLinesCountIsEqual (firstFile, secondFile))
        {
            if (CompareLineByLine (firstFile, secondFile))
            {
                cout << "The files are equal." << endl;
            }
            else
            {
                cout << "The files are NOT equal." << endl;
            }
        }
    }

    return 0;
}

bool CompareLineByLine (const string& firstFile, const string& secondFile)
{
    ifstream firstFileInputStream(firstFile.c_str()), secondFileInputStream(secondFile.c_str());

    int lineNumber = 0, noMatch_Counter = 0;
    string currFirstFileLine, currSecondFileLine;

    while(!firstFileInputStream.eof())
    {
        firstFileInputStream >> currFirstFileLine;
        secondFileInputStream >> currSecondFileLine;
        lineNumber++;

        if (currFirstFileLine.compare(currSecondFileLine) != 0)
        {
            cout << "On line " << lineNumber << " the strings are not equal!" << endl;
            cout << " * String in '" << firstFile << " ' is: '" << currFirstFileLine << " '" << endl;
            cout << " * String in '" << secondFile << " ' is: '" << currSecondFileLine << " '" << endl;
            noMatch_Counter++;
        }
    }

    /// Check counter for number of no match occurences.
    if (noMatch_Counter > 0)
        {
            return false;
        }
        else
        {
            return true;
        }
}


bool FileLinesCountIsEqual (const string& firstFile, const string& secondFile)
{
    int firstFileLineCounter = 0, secondFileLineCounter = 0;
    ifstream inputFirstFileStream, inputSecondFileStream;
    inputFirstFileStream.open(firstFile.c_str());
    inputSecondFileStream.open(secondFile.c_str());

    string currStream;

    while (!inputFirstFileStream.eof())
    {
        getline(inputFirstFileStream, currStream);
        firstFileLineCounter++;
    }

    while (!inputSecondFileStream.eof())
    {
        getline(inputSecondFileStream, currStream);
        secondFileLineCounter++;
    }

    /// Return result;
    if(firstFileLineCounter != secondFileLineCounter)
    {
        cout << "The files have different amount of lines:" << endl;
        cout << "   * File ' " << firstFile << " ' has " << firstFileLineCounter << " lines." << endl;
        cout << "   * File ' " << secondFile << " ' has " << secondFileLineCounter << " lines." << endl;
        return false;
    }
    else
    {
        return true;
    }
}

bool FilesExist (const string& firstFile, const string& secondFile)
{
    bool openFirstFile = true;
    bool openSecondFile = true;

    ifstream firstInputFileStream, secondInputFileStream;

    /// Open the files
    firstInputFileStream.open(firstFile.c_str(), ios::binary);
    secondInputFileStream.open(secondFile.c_str(), ios::binary);

    if (!firstInputFileStream)
    {
        cout << "Could not open " << firstFile << endl;

        openFirstFile = false;
    }

    if (!secondInputFileStream)
    {
        cout << "Could not open " << secondFile << endl;
        openSecondFile = false;
    }

    /// Return result to main;
    if (openFirstFile && openSecondFile)
    {
        return true;
    }
    else
    {
        return false;
    }
}
