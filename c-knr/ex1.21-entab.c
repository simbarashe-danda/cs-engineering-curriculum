#include <stdio.h>

#define MAX 100     // i dont expect a sentence to be longer than 100
#define TMAX 800    // given a max of 100 \t, the max spaces is 800
/* Tmax prevents out of bound subscripting */

char input_arr[TMAX];    // array that stores input
char final_arr[MAX];    // our finalized array


/* function declarations */
void get_input(void);  
int is_all_space(int, int);

/* the entab program */
int main(void) {

    get_input();  // call the get_input() function

    int i, i2 ,tab_stop;
    i = i2 = 0;
    tab_stop = 8;   // tab stop happens 8,16,..
    

    for (i = 0; input_arr[i2] != '\0'; ++i) { 

        if (i2 == tab_stop) // if we are at current tab stop
            tab_stop += 8; // always update tab stop
        
        // if char is space OR if distance to next tabstop is not all spaces
        if ( (input_arr[i2] != ' ') || (!is_all_space(tab_stop, i2)) ) { 
            final_arr[i] = input_arr[i2];
            ++i2; continue; }
        
        if (is_all_space(tab_stop, i2)) {
            final_arr[i] = '\t';
            i2 = tab_stop;  // update i2
            /* no reason to update tabstop since it will get updated later */ }
    }
    final_arr[i] = '\0';   // finally put the null char
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

/* function that takes distance to next tab stop and checks if its occupied by spaces only */
int is_all_space(int tab_stop, int i2) {
    for (int e = i2; e <= tab_stop; ++e){
        if (input_arr[e] != ' ')
            return 0;   // false
    }
    return 1;   // true
}


