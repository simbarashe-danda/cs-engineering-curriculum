/* Exercise 3.20: Read a set of integers into a vector. Print the sum of each pair of adjacent elements.
Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to last, and so on.*/

#include <iostream> // include the std io library
using std::cout;
using std::endl;
#include <vector> // include the vector library
using std::vector;

int main()
{
    // we assume this is our input
    vector<int> input{1,2,3,4,5,6,7,8,9,10}; // input contains first 9 natural numbers

    vector<int> natural_numb; // empty vector, this is what we will grow from input
    // we assume this is the while(cin >>) equivalent
    for (auto n : input) // for n in input
    {
        natural_numb.push_back(n); // append n to natural_numb vector
    }

    // Print the sum of each pair of adjacent elements.
    for (unsigned index = 0;
        index+1 < natural_numb.size(); ++index)  // avoid out of range subscripting index+1
        {
            int sum = natural_numb[index] + natural_numb[index+1]; // sum adjacent pairs
            cout << sum << " ";
            
        }
    cout << endl;

 /* Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to last, and so on.*/
    if (natural_numb.size() < 2) return 0; // if less than 2, terminate
    
    for ( unsigned index = 0, dindex = natural_numb.size()-1; // dindex is decrement index
    index != dindex && index < dindex; // ! and < almost same thing but just good safety
    ++index,--dindex) // increment index, dcrement dindex

    {
        int sum = natural_numb[index] + natural_numb[dindex]; // sum first and last, second and second from last,...
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}