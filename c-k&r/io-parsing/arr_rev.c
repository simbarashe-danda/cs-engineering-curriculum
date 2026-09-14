#include <stdio.h>
#include <string.h>

void reverse(char*, size_t);
void get_input(char*);
enum {NULLT='\0', NEWL='\n', MAX=1000};

int main(void)
{
    char input[MAX];
    get_input(input);

    size_t len = strlen(input);
    reverse(input, len);
    printf("%s\n", input);
}

/* function that takes a line input and stores it in an array */
void get_input(char* input_arr)
{
    int c;  // character input
    int i = 0;
    while((c=getchar()) != EOF && c!=NEWL && i < MAX-1)
        input_arr[i++] = c;
    input_arr[i] = NULLT;    // add the null terminator at the end
}

/* This function uses pointer arithmetic to reverse an array */
void reverse(char* ptr, size_t len)
{
    if (len == 0) return; 
    char* end_ptr = ptr + (len-1);  // pointer to last char
    
    while (ptr < end_ptr) { 
        char temp = *ptr;
        *ptr++ = *end_ptr;
        *end_ptr-- = temp;
    }
}

/* PROOF the program always works for all inputs : */

/* The start and end pointers namely ptr and end_ptr are all converging towards the mid point. */
    /* First notice if len is even  the difference between the two pointers is also odd and vice versa for even*/

    /* Notice the while loop is always true as long as the difference between the two pointers is non negative. */
    /* Also notice the change in the distance is always even. */

    /*  Hence the proof is that since the parity of the distance between the two pointers never changes,
        Assuming convergence towards the mid means swapping is happening,
        This implies for even length all characters are swapped.
        For odd length the middle character is not swapped, asuming the sequnce n-1, n, n+1;
        Then the pointers all point at n on the next iteration, which invalidates the condition. */
    /* if the array is empty, reverse function terminates emmidiately. */

/* Hence the program works for all cases. */