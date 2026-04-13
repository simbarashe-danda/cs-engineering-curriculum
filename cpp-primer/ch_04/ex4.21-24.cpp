/*Exercise 4.21:

Write a program to use a conditional operator to find the elements in a vector<int> that have odd value and double the value of each such element.*/
#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::cout, std::endl;
using std::string;

vector<int> ivec{0,1,2,3,4,5,6,7,8,9};    // ivec contains 10 int elements
int main()
{
    auto beg = ivec.begin();
    auto last = ivec.end();
    
    while (beg != last)
    {
        auto val = *beg++;
        cout << ((val % 2 == 1) ? val*val : 0) << " is double of the odd" << endl;
    }
/* Exercise 4.22:

Extend the program that assigned high pass, pass, and fail grades to also assign low pass for grades between 60 and 75 inclusive.
Write two versions: One version that uses only conditional operators; the other should use one or more if statements.
Which version do you think is easier to understand and why?*/
int grade(95);
// Version 1 conditional operators
string finalgrade = (grade > 90) ? "High Pass"
                                :(grade > 75 && grade <= 90 ) ? "Pass"
                                :(grade <= 75 && grade >= 60) ? "Low Pass"
                                : "Fail";
cout << finalgrade << endl;

// Version 2 if statements
if (grade > 90)
    cout << "High Pass" << endl;
else if (grade > 75 && grade <= 90 )
    cout << "Pass" << endl;
else if (grade <= 75 && grade >= 60)
    cout << "Low Pass" << endl;
else
    cout << "Fail" << endl;
/* Version1 can be written faster*/

/* Exercise 4.23: The following expression fails to compile due to operatornprecedence.
Explain why it fails. How would you fix it? */

    string s = "word";
    //string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
    
/*=This code evaluates as s+s[s.size()] first which returns a string. The second step is string == 's' which tries to compare string to char */

}