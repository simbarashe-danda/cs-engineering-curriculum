/* Exercise 3.23: Write a program to create a vector with ten int elements.
Using an iterator, assign each element a value that is twice its current value.
Test your program by printing the vector.*/
#include <iostream>  // library for data input and output
using std::cin;     // input stream
using std::cout, std::endl; // output stream
#include <vector>  // library for dynamic array
using std::vector;

int main ()     // main program function
{
    /* create a vector with ten int elements */
    vector<int> n{0,1,2,3,4,5,6,7,8,9}; // n contains 10 int elements with value 0-9

    /* Using an iterator, assign each element a value that is twice its current value */
    for (auto indx = n.begin(); // indx points to int values in n
        indx != n.end() && !n.empty();
        ++indx)
        {
            *indx = 2 * (*indx); // multiply current value by 2
        }
    /* Test your program by printing the vector.*/
    for (auto i = n.begin(); i != n.end() && !n.empty(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
}