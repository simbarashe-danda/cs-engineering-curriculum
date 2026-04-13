/*  Using pointers, write a function to swap the values of two ints.
Test the function by calling it and printing the swapped values. */
#include <iostream>
void swap(int*, int*);
int main()
{
    int x = 100;
    int y = 20;
    swap(&x, &y);   // addresses as arguments
    std::cout << x << " " << y << std::endl;
}

/* functions with pointers as parameters */
void swap(int* n1, int* n2) {
    int temp = *n1; // temporary
    *n1 = *n2;  // n1 now has value of *n2
    *n2 = temp; // now has prev val of *n1 
    }