// Revise the program that printed a range of numbers so that it handles input in which the first number is smaller than the second.
// using if statement , for statement
#include <iostream>
using namespace std;
int main()
{
    cout << "Enter two numbers: " 
    << endl;

    int n1 =  0, n2 = 0;
    cin >> n1 >> n2;
    if(n1 < n2)
    {
        for(int i = n1; i <= n2; ++i)
        {
            cout << i << endl;
        }
    }
    else if(n1 > n2)
    {
        for(int i = n1; i >= n2; --i)
        {
            cout << i << endl;
        }
    }
    else
    {
        cout << "Numbers are equal" << endl;
    }
    return 0;
}