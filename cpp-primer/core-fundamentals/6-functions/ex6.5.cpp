/* Write a function to return the absolute value of its argument */

#include <iostream>
using std::cout, std::endl;

int abs_val(int num) {
    if (num >= 0)
        return num;
    return (-1 * num);
}

int main()
{
    cout << abs_val(3) << abs_val(-5) << abs_val(0) << endl;
}

