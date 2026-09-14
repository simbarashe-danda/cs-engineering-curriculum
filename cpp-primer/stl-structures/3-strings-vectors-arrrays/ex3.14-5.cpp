/* Exercise 3.14: Write a program to read a sequence of ints from cin and store those values in a vector.
   Exercise 3.15: Repeat the previous program but read strings this time.*/
#include <iostream>
#include <vector>
using std::cin;
using std::vector;

// for ex 3.15
#include <string>
using std::string;

int main()
{
    // a program to read a sequence of ints from cin and store those values in a vector.
    int number;
    vector<int> group;

    while (cin >> number)
    {
        group.push_back(number); // append number to group
    }

    // a program to read strings from cin and store those values in a vector.
    string word;
    vector<string> text_doc;

    while (cin >> word)
    {
        text_doc.push_back(word); // append word to text_doc    
    }
}