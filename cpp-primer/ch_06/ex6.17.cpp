/* Exercise 6.17: Write a function to determine whether a string contains
any capital letters.
Write a function to change a string to all lowercase.
Do the parameters you used in these functions have the same type? If so, why?
If not, why not?*/

#include <iostream>
#include <string>
using std::string;
using std::cout, std::endl;

void to_all_lower(string*); // takes pointer to string

int main()
{
    string word = "Hello WORLD";
    cout << word << endl;
    to_all_lower(&word);
    cout << word << endl;
}
/* function converts string to all lowercase */
void to_all_lower(string* str_ptr) {
    for (auto& ch : *str_ptr)   // ch is ref to string pointed to by str_ptr
        ch = tolower(ch);
}