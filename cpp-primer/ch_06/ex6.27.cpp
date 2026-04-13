/* Exercise 6.27: Write a function that takes an initializer_list<int>
and produces the sum of the elements in the list.*/

#include <iostream>
#include <initializer_list> // library for many ars
using std::initializer_list;

int sum(initializer_list<int>); // takes many args
int main()
{
    std::cout << sum({1,2,3,4,5,6,7,8,9,10}) << std::endl;
}

int sum(initializer_list<int> int_list)
{
    int sum = 0;
    for(auto i : int_list)  // for elem in list of args
        sum += i;
    return sum;
}