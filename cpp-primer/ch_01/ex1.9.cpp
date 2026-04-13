// program that uses a while to sum the numbers from 50 to 100

#include <iostream>
int main()
{
    int sum = 0, val = 50;
    while (val <= 100) // is true until condition () false
    {
        sum += val;
        ++val; // increment operator
    }
    std::cout << "The sum of 50 to 100 is " << sum << std::endl;
    return 0;
}