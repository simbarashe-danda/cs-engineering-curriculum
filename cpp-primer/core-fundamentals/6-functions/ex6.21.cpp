/* Exercise 6.21: Write a function that takes an int and a pointer to an int and 
returns the larger of the int value or the value to which the pointer points.
What type should you use for the pointer? */

#include <iostream>

int larger_one(int, int*);

int main()
{
    int x = 100;
    int y = 150;
    std::cout << larger_one(x, &y) << std::endl;
}

int larger_one(int x, int* ptr) {
    if (x > *ptr)
        return x;
    return *ptr;    // else
}