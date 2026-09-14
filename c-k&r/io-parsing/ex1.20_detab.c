#include <stdio.h>

#define MAX 100     // i dont expect a sentence to be longer than 100
#define TMAX 800    // given a max of 100 \t, the max spaces is 800
/* Tmax prevents out of bound subscripting */

char input_arr[MAX];    // array that stores input
char final_arr[TMAX];    // our finalized array

/* function declarations */
void get_input(void);  
void manual_tab(int);

/* global variable, accessed by all functions */
int i2;

/* the detab program */
int main(void) {

    get_input();  // call the get_input() function

    int i, tab_diff, tab_stop;
    tab_stop = 8;   // tab stop happens 8,16,..
    

    for (i = 0; input_arr[i] != '\0'; ++i) { 

        if (i2 == tab_stop) // if we are at current tab stop
            tab_stop += 8; // always update tab stop
        
        tab_diff = tab_stop - i2;    // distance from next tab stop

        if (input_arr[i] != '\t')
            final_arr[i2++] = input_arr[i];
        else manual_tab(tab_diff);
    }
    final_arr[i2] = '\0';   // finally put the null char
    printf("%s\n",final_arr);  // console ouput

    return 0;   // normal termination
}

/* function that takes input and stores it in an array */
void get_input() {
    int c;  // character input
    int cnt = 0;
    while((c=getchar()) != EOF && c!='\n' && cnt < MAX-1)
        input_arr[cnt++] = c;
    input_arr[cnt] = '\0';    // add the null terminator at the end
}

/* function that manually inserts the correct number of spaces until the next tab stop*/
void manual_tab(int diff) {
    for (int e = 0;e <= diff-1; ++e, ++i2)
        final_arr[i2] = ' ';
}


