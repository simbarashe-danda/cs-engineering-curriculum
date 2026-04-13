// Write a program that prompts the user for two integers
// Print each number in the range specified by those two integers

#include <iostream>
int main ()
{


    std::cout << "Starting with the smallest \n Enter two numbers: " << std::endl; // output to user
    int n1, n2;
    std::cin >> n1 >> n2; // input to cpu
    for (n1, n2; n1 <= n2; ++n1) // even already initialized, i used n1,n2
    {
        std::cout << n1 << std::endl;
    }
    return 0;
}