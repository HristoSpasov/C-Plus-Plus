/// Count occurences of word in text

#include<iostream>
#include<string>
using namespace std;

int Occurences (const string & text, const string & searchWord);

int main()
{
    string text, searchWord;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter word to search for: ";
    getline(cin, searchWord);

    int searchWordCount = Occurences(text,searchWord);

    cout << "Word [ " << searchWord << " ] was found " << searchWordCount << " times."  << endl;

    return 0;
}

int Occurences (const string & text, const string & searchWord)
{
    int searchWordCount = 0;

    size_t searchWordMatch = text.find(searchWord);

    while (searchWordMatch != string::npos)
    {
        searchWordCount++;
        searchWordMatch = text.find(searchWord, searchWordMatch+1);
    }

    return searchWordCount;
}
