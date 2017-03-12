/// Replace all string match in text, according to
/// given find and replace string

#include<iostream>
#include<string>

using namespace std;

void SearchAndReplace (string & text, const string & searchString, const string & replaceString);

int main()
{
    string text, searchString, replaceString;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter search word: ";
    cin >> searchString;

    cout << "Enter replace string: ";
    cin >> replaceString;

    SearchAndReplace (text, searchString,  replaceString);

    cout << text;

    return 0;
}

void SearchAndReplace (string & text, const string & searchString, const string & replaceString)
{
    size_t stringMatch = text.find(searchString);

    while(stringMatch != string::npos)
    {
        text.replace(stringMatch, searchString.length(), replaceString);
        stringMatch = text.find(searchString, stringMatch + 1);
    }
}
