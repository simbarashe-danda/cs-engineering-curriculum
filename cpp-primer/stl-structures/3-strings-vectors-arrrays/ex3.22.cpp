/* Exercise 3.22: Revise the loop that printed the first paragraph in text to instead change the elements in text that correspond to the first paragraph to all uppercase.
After you’ve updated text, print its contents.*/
#include <iostream> // lib for read and write of data
using std::cin;
using std::cout, std::endl;
#include <string>  // lib for char arrays
using std::string;

int main() // main program function
{
    string line; // holds line input
    while (getline(cin, line)) // read full line console input
    {
        for (auto chr = line.begin();            // chr points to character in line
            chr != line.end() && !line.empty(); // begin and end not same
            ++chr) {
                *chr = toupper(*chr); // convert characters to uppercase
            }
        cout << line << endl; // console output

        if (line.empty())
            break; // terminates on empty line
    }
    
    return 0;  // program success
}