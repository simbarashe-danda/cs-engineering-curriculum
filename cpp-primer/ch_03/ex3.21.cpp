/*Exercise 3.21: Using iterators: Read a sequence of words from cin and store the values a vector.
After you’ve read all the words, process the vector and change each word to uppercase.
Print the transformed elements, eight words to a line. */

#include <iostream> // include stdlib for read and write io
using std::cin;
using std::cout, std::endl;
#include <vector> // inlude stdlib vector for dynamic array
using std::vector;
#include <string> // include stdlib string for char array
using std::string;

int main () // main program function
{
    string wrd;              // holds input
    vector<string> txt_doc; // container for wrd(s)

    /* Read a sequence of words from cin */
    while (cin >> wrd && wrd != "QT") // read i-stream data, terminate on "QT"
    {
        txt_doc.push_back(wrd); // grow txt_doc using wrd input
    }

    /* process the vector*/
    for (auto indx = txt_doc.begin();               // indx points to starting string
        indx != txt_doc.end() && !indx->empty();   // begin and end not equal & string not empty
        ++indx)                                   // increment indx
        {
            /* change each word to uppercase*/
            for (auto chr = indx->begin();  // chr points to starting char
        chr != indx->end();                // begin and end not equal
        ++chr)                            // increment
        {
            *chr = toupper(*chr); // convert characters to uppercase
        }

    }
    
    /* Print the transformed elements*/
    unsigned cnt{0};                                 // count tracking variable
    for (auto word = txt_doc.begin();               // word points to starting word
        word != txt_doc.end() && !word->empty();   // begin and end not equal & string not empty
        ++word)                                   // increment
        {
            /* eight words to a line*/
            cout << *word << " "; // console output
            if (++cnt == 8) {    // increment while checking condition
                cout << endl;   // flush buffer in o-stream and put newline
                cnt = 0;       // reset count
            }

        }
    /* program end */
    cout << endl; // flush o-stream
    return 0; // program success



}