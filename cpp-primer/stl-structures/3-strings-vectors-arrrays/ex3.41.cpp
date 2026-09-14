/* Exercise 3.41: Write a program to initialize a vector from an array of ints. */
#include <iostream>
#include <vector>
using std::vector;
using std::begin, std::end;

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};     // array of 10 ints

    // initialize a vector from an array of ints
    vector<int> intvec{begin(arr), end(arr)};   // initialize from all elements of the array arr

/* Exercise 3.42: Write a program to copy a vector of ints into an array of ints.*/

    vector<int> int_vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // intvec2 contains 10 int elements
    int int_arr[10];   // empty array with capacity of 10
    int* int_ptr = int_arr; // pointer to first element
    int index = 0;    // count

    for (auto i : int_vec) // for element in int_vec
    {
        int_ptr[index++] = i; // assign then increment
    }
}