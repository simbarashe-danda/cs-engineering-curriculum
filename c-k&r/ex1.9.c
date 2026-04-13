/* Write a program to copy its input to its output, replacing each string of one more strings blanks by a single blank */
#include <stdio.h>

int main()
{
    int n, c;
    n = 0; // blank count
    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
            n = 0; // reset blank count
        }
        else if (c == ' ') // blank
            if (++n < 2) // if blank count is 1 or 0
                putchar(c); // print blank
                // prevents consecutive printing of blanks
    }
}