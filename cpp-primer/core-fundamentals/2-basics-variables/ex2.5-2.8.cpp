#include <iostream>
using namespace std;

int main()
{
    // ex 2.5
    
    // determine the type of each of the following literals
    // explain the differences among the literals in each of the four examples:

    'a', L'a', "a", L"a"; // char,wide character, string, long string

    10, 10u, 10L, 10uL, 012, 0xC; // integer, unsigned integer, long integer, unsigned long integer, octal integer, hexa-decimal integer

    3.14, 3.14f, 3.14L; // double-precision(default), single-precision float, extended-precision long double

    10, 10u, 10., 10e-2; // integer literal, unsigned int, double-precision, double-precision

    // character literal is the smallest of type char. it can be signed or unsigned
    // wide character literal is meant for the extended ascii system that reaches 255 characters
    // unsigned interger literal can only  be positive or zero
    // a string takes more than one characters
    // long string can take unicode characters

    // Ex 2.6
    // what, if any, are the differences between the following definitions


    int month = 9, day = 7; // decimal int
    int mconth = 011, dcay = 07; // octal int

    // Ex 2.7: What values do these literals represent? What type does each have?
    
    "Who goes with F\145rgus?\012"; // string literal with escape sequences. \145 is 101 = e, \012 is 10 = new 
    // prints "who goes with fergus?\n, \n = new line"
    
    3.14e1L; // extended-precision floating point literal, type long double
    1024.1f; // single-precision floating point literal
    3.14L; // extended-precision 

    // ex: 2.8: using escape sequences, write a program to print 2M followed by a newline

    cout << "\x32\x4d\a" << endl;
    
    // modify the program to print 2, then a tab, then an M, followed by a newline

    cout << "\x32\x20\x4d\a" << endl;

    return 0;




    
}