/* Write a program to print a histogram of the frequencies of different characters in its input*/

#include <stdio.h>

#define ASC_CHAR_MAX 127

int main(void)
{
    int c;  // character input
    int c_arr[128] = {0};   // array for all characters
    
    while ((c = getchar()) != EOF) {
        if ((c-0) <= ASC_CHAR_MAX)  // prevent of out of range subscriting
            ++c_arr[c-0];
    }
    for (int i = 0; i <= ASC_CHAR_MAX; ++i)
        if (c_arr[i] != 0) printf(" %d", c_arr[i]);     // print character frequency
    printf("\n");

}
