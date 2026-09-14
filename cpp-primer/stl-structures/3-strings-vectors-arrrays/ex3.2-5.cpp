/* Exercise 3.2: Write a program to read the standard input a line at a time.
Modify your program to read a word at a time. */
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout, std::endl;
int main()
{
    //cout << "Write a sentence" << endl;
    string str;
    // program to read a word at a time
    while (cin >> str) {
        cout << str << endl; // print one word at a time
    }
    // program to read the standard input a line at a 
    while (getline(cin, str)) {
        cout << str << endl; // print sentence after a time after encountering \n
    } 

/* Exercise 3.3: Explain how whitespace characters are handled in the string input operator and in the getline function. */

/* getline reads characters from the input stream (cin) until it hits a delimiter which is \n by default.
It stores everything before the delimiter in the string , including whitespace.

**cin uses whitespace as delimiter */

/* Exercise 3.4: Write a program to read two strings and report whether the strings are equal.
If not, report which of the two is larger.
(B) Now, change the program to report whether the strings have the same length, and if not, report which is longer*/

// program to read two strings and report whether the strings are equal.
    string str1 = "United States of America";
    string str2 = "Zimbabwe";

    if (str1 == str2) { // if strings are equal
        cout << str1 << " and " << str2 << " are equal" << endl;
    }
    else { // if not, report which of the two is larger. large in terms of aphebetical not length
        if (str1 > str) {
            cout << str1 << " is larger than " << str2 << endl;
        }
        else {
            cout << str2 << " is alphabetically larger than " << str1 << endl;
        }

    }
    // Now, change the program to report whether the strings have the same length
    if (str1.size() == str2.size()) { // if length is same
        cout << str1 << " and " << str2 << " have same length" << endl;
    }
    else { // if not, report which is longer
        if (str1.size() > str.size()) {
            cout << str1 << " is longer than " << str2 << endl;
        }
        else {
            cout << str2 << " is longer than " << str1 << endl;
        } 

    }

    /* Exercise 3.5: Write a program to read strings from the standard input, concatenating what is read into one large string.
    Print the concatenated string. Next, change the program to separate adjacent input strings by a space.*/
    
    // program to read strings from the standard input, concatenating what is read into one large string
    cout << "Write a sentence" << endl;
    string s3, s4; // s3 holds input and s4 holds accumulation
    /*while (cin >> s3) {
        s4 += s3; // we can't do s3 += s3 because cin >> s3 overwrites s3 everytime
    }
    cout << s4 << endl; // Print the concatenated string*/

    // change the program to separate adjacent input strings by a space
    while (cin >> s3) {
        s4 = s4 + " " + s3; // add space and then next string
    }
    cout << s4 << endl;


} 