#include<iostream>
using namespace std;

void arrScan (char **arr, const int& rows, const int& cols, int startRow, int startCol, const char& searchChar, const char& replaceChar);

int main()
{
    /// Read row and col number
    int rows, cols;
    cin >> rows >> cols;
    cin.ignore();

    char **arr; /// Declare array;

    /// Allocate memory
    arr = new char*[rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new char[cols];
    }

    /// Read array elements
    for(int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cin >> arr[row][col];
        }
    }

    /// Read fill char
    char replaceChar;
    cin >> replaceChar;
    cin.ignore();

    /// Read start index
    int startRow, startCol;
    cin >> startRow >> startCol;
    cin.ignore();

    char searchChar = arr[startRow][startCol]; /// Get search char value from array

    arrScan (arr, rows, cols, startRow, startCol, searchChar, replaceChar); /// Call function to search and replace chars

    /// Print result
    for(int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cout << arr[row][col];
        }
        cout << endl;
    }

    /// Free memory to prevent memory leak
    for (int row = 0; row < rows; row++)
    {
        delete[] arr[row];
    }

    delete[] arr;

    return 0;
}

void arrScan (char **arr, const int& rows, const int& cols, int startRow, int startCol, const char& searchChar, const char& replaceChar)
{
    if (arr[startRow][startCol] == searchChar)
    {
        arr[startRow][startCol] = replaceChar;

        if (startRow + 1 < rows)
        {
            arrScan (arr, rows, cols, startRow + 1, startCol, searchChar, replaceChar);
        }

        if (startRow - 1 >= 0)
        {
            arrScan (arr, rows, cols, startRow - 1, startCol, searchChar, replaceChar);
        }

        if(startCol + 1 < cols)
        {
            arrScan (arr, rows, cols, startRow, startCol + 1, searchChar, replaceChar);
        }

        if(startCol - 1 >= 0)
        {
            arrScan (arr, rows, cols, startRow, startCol - 1, searchChar, replaceChar);
        }
    }
}
