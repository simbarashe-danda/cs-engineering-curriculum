/* A program to "fold" long input lines into two or more shorter lines after 
the last non-blank character that occurs before the n-th column of input.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* constant expressions */
enum {NEWL = '\n', SP = ' ', TAB = '\t', NULLT = '\0', MAX = 1001, NTH = 5};

/* function declarations */
void get_input(char*);
int is_overflow(const char*,unsigned*, unsigned);
void reset(unsigned*, unsigned*);
void tab_logic(unsigned*, unsigned*);

int main(void)
{   
    char input[MAX];    // holds user input
    get_input(input);   // get user input

    unsigned last_sp; // last space index
    int overflow = 0; // initially false
    size_t arr_len = strlen(input);

    for (unsigned i = 0, col = 1; input[i] != NULLT; ++i) {   // until end of array

        if ( i+NTH < arr_len) // avoid out of bound subscripting
            if (col == 1) { overflow = is_overflow(input, &last_sp, i); }  // check overflow

        /* special case : word has overflow */
        if (i == last_sp && overflow) {
            putchar(NEWL); // put newline
            reset(&col, &last_sp); // reset col and last_sp
            continue;
        }

        /* normal case 3: tab character logic */
        if (input[i] == TAB) {
            tab_logic(&col, &last_sp); // implement tab logic+
            continue;   }
        
        /* normal case 2, NTH: no overflow OR overflow but word is long */
        if (col == NTH) {  // we have reached nth col
            putchar(input[i]);
            putchar(NEWL);  // newline
            reset(&col, &last_sp); // reset
            continue;
        }

        /* skip printing a space on n+1 if its there */
        if (col == 1 && i != 0 && input[i] == SP) { continue;}

        /* normal case 1 */
        putchar(input[i]); // else keep printing
        ++col;  // increment column index
    }
}

/* function that takes input and stores it in an array */
void get_input(char* input) {   // input is pointer to first index of input
    int c;  // character input
    unsigned i = 0;
    while((c=getchar()) != EOF && c!=NEWL && i < MAX-1)  // reserves space for null
        input[i++] = c;
    if (c == NEWL) input[i++] = c; // put newline char

    input[i] = NULLT;    // add the null terminator at the end
}

/* function that checks if a word overwraps between nth column and n+1 */
int is_overflow(const char* ptr,unsigned* last_sp, unsigned i)
{
    unsigned n = i + NTH - 1; // nth
    unsigned n_1 = i + NTH; // n+1

    /* <ctype.h> (isspace) expects an unsigned char, so we cast */
    if ( !( isspace((unsigned char)ptr[n]) || isspace((unsigned char)ptr[n_1]) ) ) { // equivalent to not space n AND not space n+1
        while (ptr[n] != SP)    // find the last space
            if (n-- == i) {return 0;}   // word had no spaces behind
        *last_sp = n; // update the index of the last space
        return 1;   // true
    }
    return 0;   // else false
}

/* function for resetting variables */
void reset(unsigned* col, unsigned* last_sp) {
    *col = 1;
    *last_sp = 0; }

/* function that makes sure tabs dont overflow to n+1 column */
void tab_logic(unsigned* col, unsigned* last_sp) {
    unsigned tab_size = 8 - ((*col - 1) % 8);    // tab spaces

    /* special case 2: If  NTH is smaller than tab size, might happen on small screens. */
    if (NTH < tab_size) {
        for (unsigned c = *col; c <= NTH; ++c) {putchar(SP);} // put space until column end
        putchar(NEWL);  // create new line
        reset(col, last_sp); // reset
        return; }
    /* common case, NTH > tabsize */
    if (*col + tab_size  > NTH) {  // tab causes overflow, NTH > tabsize
        putchar(NEWL);  // create new line
        reset(col, last_sp); // reset
        return; }
    putchar(TAB); // else put the tab
}
