/* Given two vectors of ints, write a program to determine whether one vector is a prefix of the other.
For vectors of unequal length, compare the number of elements of the smaller vector.
For example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5, 8, respectively your program should return true.*/

#include <iostream>
#include <vector>
using std::vector, std::cout, std::endl;

vector <int> ivec {0,1,1,2};
vector <int> ivec2 {0, 1, 1, 2, 3, 5, 8};

int main()
{
    decltype(ivec2.size()) i = 0; // subscript variable for the second vector

    for (auto v : ivec) { // for every element v in ivec
        if (i < ivec2.size()) /* prevent out of bound subscripting the second vector*/
            if (v != ivec2[i++])  /* if elements dont ,match */ {
                cout << "false" << endl;
                return 0; } // print false then terminate
    }
    cout << "true" << endl; // if termination hasnt occured that means elements match
    /* if i < ivec2.size() makes sure program works correctly nomatter which vector is the bigger one*/
}
