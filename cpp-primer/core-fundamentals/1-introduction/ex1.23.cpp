// write a program that reads several transactions and counts how many transactions occur for each ISBN.

#include <iostream>
#include "Sales_item.h"
using namespace std;

int main()
{
    Sales_item book1, book2;
    int trans = 0;

    if(cin >> book1)
    trans = 1;
    {
        while(cin >> book2)
        {
            if(book1.isbn() == book2.isbn())
            {
                ++trans;
            }
            else{
                cout << book1.isbn() << " has " << trans << " transactions " << endl;
                book1 = book2;
                trans = 1;
            }
        }
        cout << trans << endl;
    }
    return 0;
}