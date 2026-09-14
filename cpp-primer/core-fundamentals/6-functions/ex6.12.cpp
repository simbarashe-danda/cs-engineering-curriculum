/* Exercise 6.12: Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210)
to use references instead of pointers to swap the value of two ints. Which
version do you think would be easier to use and why? */

#include <iostream>
void swap(int&, int&);

int main()
{
    int x = 100;
    int y = 50;
    swap(x, y);
    std::cout << x << " " << y << std::endl;
}

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}
/* i like the pointer version, its more clear */