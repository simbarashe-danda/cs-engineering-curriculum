/* Exercise 5.23: Write a program that reads two integers from the standard input and prints the result of dividing the first number by the second.

Revise your program to throw an exception if the second number is zero.
Test your program with a zero input to see what happens on your system if you don’t catch an exception.

Revise your program from the previous exercise to use a try block to catch the exception.
The catch clause should print a message to the user and ask them to supply a new number and repeat the code inside the try.*/

#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout, std::endl;
using std::runtime_error;

int a,b;

int main()
{
    cout << "Enter any two integers where the second one is the divisor eg 10 and 5: " << endl;
    while (cin >> a >> b) {
            
            /* The following code might contain division by zero hence try it */
        try {
            /* raise a zero division exception before division */
        if (b == 0)
            throw runtime_error (" Division by zero\n");
            /* this runs if execption didnt occur */
        cout << a << " divided by " << b << " is " << a/b << endl;
        break;

        } catch (runtime_error& err) {   // catch raised exception
            cout << err.what(); // what the exception is
            cout << " Do you want to supply a new non zero divisor? (Y/n )" << endl;

            char rep; // reply
            cin >> rep;


            if (rep != 'n') // if reply is  'no'
                break; // terminate while loop
        }
    }
}