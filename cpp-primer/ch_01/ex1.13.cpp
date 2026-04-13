// program that uses a for to sum the numbers from 50 to 100
#include <iostream>
int main()
{
    int sum = 0;
    for (int val = 49; val <= 100; ++val){
        sum += val;
    }
    std::cout << "The sum of 50 to 100 is " << sum << std::endl;
    return 0;
}