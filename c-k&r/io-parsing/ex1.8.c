/* Write a program to count blanks, tabs and newline*/
#include <stdio.h>

int main()
{
    int c;
    int n = 0;
    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n') // blank or tab or newline
            ++n;
    printf("%d\n", n);
}