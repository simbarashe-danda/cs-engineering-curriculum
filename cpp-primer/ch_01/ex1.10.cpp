// There is a decrement operator (--) that subtracts 1 write a while that prints the numbers from ten down to zero.
#include <iostream>
int main()
{
    int diff = 11;
    while (diff > 0)
    {
        --diff; // decrement operator 1
        std::cout << diff << std::endl;
    }
    return 0;
}