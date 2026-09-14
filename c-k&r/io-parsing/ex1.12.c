/* Write a Program that prints it's output one word per line*/

#include <stdio.h>  // include console input-output library

#define IN 1    // inside a word
#define OUT 0   // outside a word   


int main(void)
{
    int char_input;  // variable for holding console character input
    unsigned state; // records whether program is currrently in a word or not

    state = OUT;    // program is ofcourse not in a word before running

    while ((char_input = getchar()) != EOF ) // console input not end of file
    {
        /* determine character is IN word or OUT word*/
        if (char_input != '\n' && char_input != '\t' && char_input != ' ')
        {
            putchar(char_input);    // make character part of a word
            state = IN;     // program in a valid word
        }
        else if (state == IN) // else if were are not in a word, and we were previously in word
        {
            putchar('\n');  // insert newline
            state = OUT;        // update our current state
        }
    }
}