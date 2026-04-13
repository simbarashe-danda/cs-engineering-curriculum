/* Exercise 5.20: Write a program to read a sequence of strings from the standard input until
either the same word occurs twice in succession or all the words have been read.
Use a while loop to read the text one word at a time.
Use the break statement to terminate the loop if a word occurs twice in succession.
Print the word if it occurs twice in succession, or else print a message saying that no word was repeated.*/

#include <iostream>
#include <string>
using std::cin, std::cout, std::endl;
using std::string;

string word, prev_wrd;
size_t no_repeat = 1;

int main()
{
    while (cin >> word) {
        if (word == prev_wrd) {
            cout << word << " occured twice in succession" << endl;
            no_repeat = 0; // false
            break; // terminate while loop
            } 
        prev_wrd = word; // prev_wrd always holds previous input
    }
    if (no_repeat) cout << " No word was repeated" << endl;
}
