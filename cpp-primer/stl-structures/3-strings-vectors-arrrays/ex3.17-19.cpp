/* Exercise 3.17: Read a sequence of words from cin and store the values a vector.
After you’ve read all the words, process the vector and change each word to uppercase.
Print the transformed elements, eight words to a line.*/
#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::string;
using std::vector;
using std::cout, std::endl;

int main()
{
    //  Read a sequence of words from cin and store the values a vector.
    string word;
    vector<string> txt; // contains word inputs

    while (cin >> word && word != "QT") // read input, terminates when "QT" is input
    {
        txt.push_back(word); // append word to text
    }
    // process the vector and change each word to uppercase.
    for (auto &wrd: txt) // single_wrd is a ref, otherwise we will modify a copy
    {
        for (auto &c : wrd) // c is ref to character in the single_wrd
        {
            c = toupper(c); // convert char to uppercase
        }
    }
    // Print the transformed elements, eight words to a line.
    unsigned cnt{0}; // count tracking
    for (auto wrd : txt)
    {
        cout << wrd << " "; // print uppercase converted text
        if (++cnt == 8) // increment while checking equality
        {
                cout << endl; // newline
                cnt = 0; // reset cnt
        }
    }
    cout << endl;
    return 0; // program success

/*                    Exercise 3.18: Is the following program legal? If not, how might you fix it?*/
vector<int> ivec;
    /*ivec[0] = 42;*/
/* it is ilegal, trying to subscript an index that doesn't exist is undefined. ivec is empty
If the program's main aim is to add 42 to ivec then i would do:*/
ivec.push_back(42); // appends 42 to ivec

/* Exercise 3.19: List three ways to define a vector and give it ten elements, each with the value 42.
Indicate whether there is a preferred way to do so and why.*/

vector<int> intv(10, 42); // intv contains 10 elements with value 42
vector<int> intv2{42,42,42,42,42,42,42,42,42,42}; // intv2 contains 10 elements with value 42
vector<int> intv3 = intv; // elements of intv (which are 10 elements with value 42) are copied into intv3
vector<int> intv4; // empty vector
for (auto i : intv) // for each element in intv
{
    intv4.push_back(i); // appends i to intv4
} // at program, the vector grows until all elements of intv are appended to intv4
}