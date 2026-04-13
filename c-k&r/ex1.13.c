/* Write a program to print a histogram of the lengths of words in its input. */

#include <stdio.h>

#define IN 0    // in word
#define OUT 1   // outside word

int main(void)
{
    int c;  // input variable
    int state;      // record current state
    int w_len;   // word length

    int len_arr[20];  // histogram array

    state = OUT;
    w_len =  0;

    /* initialize all array elements to zero */
    for (int i = 0; i < 20; ++i)
        len_arr[i] = 0;
    

    while ((c = getchar()) != EOF)
    {
        if (c != '\n' && c != '\t' && c != ' ')  // if char is part of a word
        {
            ++w_len;
            state = IN;     // we are in word
        }
        else if (state == IN) {   // previous state was IN
            ++len_arr[w_len];
            w_len = 0; // reset
            state = OUT;    // we are not in word
        }
    }
    for (int i = 0; i < 20; ++i)
        printf(" %d",len_arr[i]);   
    printf("\n");
}