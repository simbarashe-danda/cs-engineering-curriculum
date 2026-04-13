#include <iostream>
using std::cout, std::endl;

int main()
{
    unsigned long ul1 = 3, ul2 = 7;
    // ul1 is (28 zeros) 0011, ul2 is   (28 zeros) 0111

/*Exercise 4.27: What is the result of each of these expressions?*/

    ul1 & ul2;  // is .... 0011
    ul1 | ul2;  // is .... 0111
    ul1 && ul2; // is .... 0001
    ul1 || ul2; // is .... 0001

    /* We can confirm the result by :*/
    unsigned long res = ul1 & ul2;  // we can put any of the above expressions to visualize their bit strings
    int n = 0;      // shifting value
    while(n<32) {  // we are guaranteed long has atleast 32 bits
        bool stat = res & 1UL << n++;
        cout << " " << stat;
    }
    cout << endl;
}