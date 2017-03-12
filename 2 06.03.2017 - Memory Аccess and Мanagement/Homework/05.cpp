/// Capitalize all letters preceded by non alphabetical symbol

#include<iostream>
#include<string>
using namespace std;

void ResultString (string & text);

int main()
{
    cout <<  "Enter text: ";
    string text, result;
    getline(cin, text);
    ResultString(text);

    cout << text;

    return 0;
}

void ResultString (string & text)
{
    for (int i = 0; i < text.length(); i++)
    {
        bool currIsLetter = ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'));
        bool prevIsLetter = ((text[i - 1] >= 'a' && text[i - 1] <= 'z') || (text[i - 1] >= 'A' && text[i - 1] <= 'Z'));

        if(currIsLetter && !prevIsLetter)
        {
           text[i] = toupper(text[i]);
        }
    }
}
