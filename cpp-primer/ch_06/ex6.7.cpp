/* Write a function that returns 0 when it is first called and then generates numbers in sequence each time it is called again.*/
#include <iostream>
#include "chapter6.h"

int main()
{
    for (int i = 1; i <10; ++i) {
        size_t val = funct();
        std::cout << val << std::endl; }
}
int funct(void) {
    static size_t rtrn;
    return rtrn++;
}