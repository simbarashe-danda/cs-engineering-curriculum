
#include <vector>
using std::vector;
#include <iostream>

/*Exercise 6.54: Write a declaration for a function that takes two int parameters
and returns an int, and declare a vector whose elements have this function pointer type.*/
int func (int, int);
vector<decltype(func)*> fnptrVec;   // elements are pointer to a function that takes two ints and returns int

/* Exercise 6.55: Write four functions that add, subtract, multiply, and divide two int values.
Store pointers to these values in your vector from the previous exercise.*/
int add(int, int);
int mult(int, int);
int diff(int, int);
int divd(int, int);

int main()
{
    fnptrVec = {add, mult, diff, divd}; // they decay to pointers
    
    /* Exercise 6.56: Call each element in the vector and print their result. */
    for (auto& func_ptr : fnptrVec) {
        auto res = func_ptr(6, 2); // call each function with 5 and 2 as args
        std::cout << res << std::endl;
    }
}
int add(int a, int b) {
    return a + b;
}
int mult(int a, int b) {
    return a * b;
}
int diff(int a, int b) {
    return a - b;
}
int divd(int a, int b) {
    return a / b;
}


