/* Write all four versions of f. Each function should print a
distinguishing message. Check your answers for the previous exercise. If your
answers were incorrect, study this section until you understand why your
answers were wrong.*/

#include <iostream>
void f() {
    std::cout << "void args" << std::endl;
}
void f(int) {
    std::cout << "int arg" << std::endl;
}
void f(int, int) {
    std::cout << "2 int args" << std::endl;
}
void f(double, double = 3.14) {
    std::cout << "2 double args" << std::endl;
}
int main() 
{
    /* my expectation */
    f(2.56, 42); // compiler must throw error, ambigous
    f(42);  // okay, call 1 int arg
    f(42, 0);   // okay, calls  2 int args
    f(2.56, 3.14);  // okay, 2 double args
}
/* correct  */