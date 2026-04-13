/* Exercise 6.36: Write the declaration for a function that returns a reference to an array of ten strings,
without using either a trailing return, decltype, or a type alias.*/

#include <string>
#include <iostream>
using std::string;

string (& fcn(string))[10];

/* Exercise 6.37: Write three additional declarations for the function in the previous exercise
One should use a type alias, one should use a trailing return, and the third should use decltype.
Which form do you prefer and why?*/

// type alias
typedef string arrT[10];
arrT& fcn1(string);

// trailing return
auto fcn2(string) -> string(&)[10];

// decltype
string arrT2[10];
decltype(arrT2)& fcn3(string);


/* Exercise 6.38: Revise the arrPtr function on to return a reference to the array.*/

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

// returns a reference to an array of five int elements
decltype(odd) &arrRef(int);

/* testing */
int main()
{
    auto& res = arrRef(2);   // ref to array of 5
    for (auto i : res)
        std::cout << i << std::endl;
}
decltype(odd) &arrRef(int i)
{
 return (i % 2) ? odd : even; // returns a ref to the array
}  

/* Would it be possible to define isShorter as a constexpr? If so, do so.
If not, explain why not.*/