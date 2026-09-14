/* Exercise 6.33: Write a recursive function to print the contents of a vector. */

#include <iostream>
#include <vector>
using std::vector;

void recur_print(const vector<int>&, size_t);

int main()
{
    vector<int> vec{1,2,3,4,5};
    recur_print(vec , 0);
    std::cout << std::endl;
}

void recur_print(const vector<int>& ivec, size_t n)
{
    /* base case */
    if (ivec.size() == n)
        return;
    
    // action 
    std::cout << ivec[n] << " ";
    recur_print(ivec, n+1); // recursive step
}  