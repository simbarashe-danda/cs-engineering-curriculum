/* Exercise 6.47: Revise the program you wrote in the exercises in § 6.3.2 (p.228)
that used recursion to print the contents of a vector to conditionally print information about its execution.
For example, you might print the size of the vector on each call.
Compile and run the program with debugging turned on and again with it turned off. */

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
    if (ivec.size() == n) {
        std::cerr << "\nVector size is " << ivec.size() 
        << ", vector index is " << n
        << " in function " << __func__
        << " at time " << __TIME__ << std::endl;
        return;
    }
    
    // action 
    std::cerr << "\nVector size is " << ivec.size()
        << ", vector index is " << n
        << " in function " << __func__
        << " at time " << __TIME__ << std::endl;
    recur_print(ivec, n+1); // recursive step
}  