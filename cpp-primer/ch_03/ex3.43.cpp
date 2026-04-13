/* Write three different versions of a program to print the elements of ia.
One version should use a range for to manage the iteration, the other two should use an ordinary for loop in one case using subscripts and in the other using pointers.
In all three programs write all the types directly.
That is, do not use a type alias, auto, or decltype to simplify the code.*/

#include <iostream>
using std::cout, std::endl;

constexpr int rw = 3;   // row, const and compile-time evaluated
constexpr int clm = 4;  // column, const and compile-time evaluated

/* ia an array of three arrays, which are also arrays of four int elements */
int ia[rw][clm] = { // three elements; each element is an array of size 4
    {0, 1, 2, 3}, // initializers for row 0
    {4, 5, 6, 7}, // initializers for row 1
    {8, 9, 10, 11} // initializers for row 2
};

int main()
{
    /* Version1  use a range for to manage the iteration */
    // for every 4 int array in ia
    for (int (&row)[clm] : ia)    // row is reference to a 4 int array
    {
        // for every int element in each row
        for (int col : row)     // col is each int element
            cout << col << " "; // console output iterated element
        cout << endl;
    }

    /* Version2 use an ordinary for loop  using subscripts */
    for (size_t row = 0; row < rw; ++row)   // row suscript
    {
        for (size_t col = 0; col < clm; ++col)  // column subscript
            cout << ia[row][col] << " ";    // consolr output subscripted element
        cout << endl;
    }
    
    /* Version3 use an ordinary for loop  using pointers*/
    for (int (*row)[clm] = ia; row != ia + rw; ++row)   // row is pointer to 4 int array
    {
        for (int* col = *row; col != *row + clm; ++col) // col is pointer to int elements in row
            cout << *col << " ";    // console output dereferenced element
        cout << endl;
    }
    return 0; // normal termination for all programs
} 