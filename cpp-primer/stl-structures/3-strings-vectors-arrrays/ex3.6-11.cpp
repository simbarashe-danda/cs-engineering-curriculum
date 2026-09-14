// Exercise 3.6: Use a range for to change all the characters in a string to X.
#include <iostream>
#include <string>
using std::string;
using std::cout, std::endl;
using std::cin;

int main()
{
    string str("hello world!!");
    for (auto &c : str) { // c is ref to characters in str
        if (!isspace(c)) { // char is not a whitespace
            c = 'X';
        }
    }
    cout << str << endl;

// Exercise 3.7: What would happen if you define the loop control variable in the previous exercise as type char?
// Predict the results and then change your program to use a char to see if you were right.

/* If the question is asking about doing like this:
    for (char c : str) {
Then we cannot change the characters in str because c will just contain copies of characters in str but it won't be the real str[] character.
Hence the ouput will be an unmodified string, that's why we use a reference. */

// Exercise 3.8: Rewrite the program in the first exercise, first using a while and again using a traditional for loop.
// Which of the three approaches do you prefer and why?.    

// using a while loop to change all the characters in a string to X.
    decltype(str.size()) index = 0; // index holds our position in the characters of str
    while(index < str.size()) {   // condition true if index is less than number of characters in str. index is always one less than number of char
        if (!isspace(str[index])) { // i find it logical to alter only letters or digits
            str[index] = 'W';
        }
        ++index; // increment index to point to next character in str
    }
    cout << str << endl; 

    // using a traditional for loop to change all the characters in a string to F.
    for (decltype(str.size()) i = 0; i < str.size(); ++i) { // if condition is true, run the body then increment i
         if (!isspace(str[i])) {
            str[i] = 'F'; 
        }

}   cout << str << endl;


/* Exercise 3.9: What does the following program do? Is it valid? If not, why not?
cout << s[0] << endl;
Answer: it is not valid because the string is empty; and an out of range subscript is undefined */

/* Exercise 3.10: Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed. */
str = "hello world!!!";
string result;
for (auto c : str) {
    if (!ispunct(c)) {
        result += c;
    }
}
cout << result << endl;

/* Exercise 3.11: Is the following range for legal? If so, what is the type of c? 
const string s = "Keep out!";
for (auto &c : s) {  ... } */

/* Yes it is legal if you don't have plans of modifying s using c;
c is const char&; hence you can't modify the characters of s using c*/

}