/* Exercise 5.19: Write a program that uses a do while loop to repetitively request two strings from the user and report which string is less than the other.*/

#include <iostream>
#include <string>
using std::cout, std::endl, std::cin;
using std::string;

string input1, input2; // string input variables
string reply;

int main()
{
    cout << "i will tell you which word is less than the other! :) \n" << endl;
    do {
        cout << " Enter any two words " << endl;
        cin >> input1 >> input2;
        /* word comparison output control flow*/
        if (input1 < input2)
            cout << input1 << " is lesser than " << input2 << endl;
        else if (input1 > input2)
            cout << input2 << " is lesser than " << input1 << endl;
        else cout << " The two words are equal! ";
        cout << " Do you want to compare another pair of words? (y/n): " << endl;
        cin >> reply; // input reply
    }
    while (reply.size() <= 1 && reply != "n" && !reply.empty());
}