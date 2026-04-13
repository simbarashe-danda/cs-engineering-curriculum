/* Exercise 5.14: Write a program to read strings from standard input looking for duplicated words.
The program should find places in the input where one word is followed immediately by itself.
Keep track of the largest number of times a single repetition occurs and which word is repeated.
Print the maximum number of duplicates, or else print a message saying that no word was repeated.
For example, if the input is how now now now brown cow cow the output should indicate that the word now occurred three times.*/

#include <string>
#include <iostream>
using std::string;
using std::cin, std::cout, std::endl;

int main ()
{
    string word, large, prev_wrd;
    int max = 0, cnt = 1;

    while (cin >> word) {   // while there is input
        if ((word == prev_wrd) && (++cnt > max))
            large = word, max = cnt; // update largest rep and its count so far
        else cnt = 1;   // reset cnt
        prev_wrd = word;   // previous word always holds input
    }
    if (max>0) {cout << large << " times " << max << endl; return 0;}
    // should be  now  3 times
    cout << "no repetitions" << endl;
}
