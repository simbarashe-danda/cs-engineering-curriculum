/* Exercise 6.25: Write a main function that takes two arguments.
Concatenate the supplied arguments and print the resulting string. */

#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::string wrd1 = argv[1] ; // or *(argv+1)
    std::string wrd2 = argv[2]; // or *(argv+2)

    std::cout << wrd1 + wrd2 << std::endl;
    // or 
    std::cout << *(argv+1) << *(argv+2) << std::endl;
}