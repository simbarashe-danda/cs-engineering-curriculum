/* Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as as possible of the text.*/
#include <stdio.h>      // input-output library
#define MAXLINE 1000    // maxmum characters in a line

int getline_len (char line[], int maxline);   // declare getline_len function that returns int
void copy_array (char to[], char from[]);   // declare function copy_array that copies arrays from one to another

int main (void)
{
    char line[MAXLINE];
    char longest[MAXLINE];
    int length;

    int max = 0;
    while((length = getline_len(line,MAXLINE)) > 0)   // while there is a line
        if(max < length) {      // if current max length is less that current length
            max = length;    // update our new maximum length
            copy_array(longest,line);
        }
    if(max>0)   // if there was a line
        printf("Longest line has %d characters.\nThe longest string is: %s\n",max,longest); /* print longest array and longest string*/

    return 0;   // normal termination
}

/* define getline_len function */
int getline_len (char line[], int maxline)
{
    int cnt;    // character count
    int c;          // character input
    
    for(cnt = 0;(c=getchar()) != EOF && c!='\n'; ++cnt)     //  loop stops upon newline or end of file
        if(cnt<maxline-1)   // prevent out of range subscripts
            line[cnt] = c;  // append characters to a character array
    if((cnt<maxline-1) && c == '\n') {    // we need to include newline character in our array because its an character too
        line[cnt] = c;
        line[++cnt] = '\0';     // newline means what follows is end of string
    }
    else if(cnt<=maxline-1)
        line[cnt] = '\0';   // at the end we must at \0, thats actually after eof termination in this case

    return cnt;     // pass line count to the calling function
}
/* define the copy_array function that copies array elements from one array to another */
void copy_array (char to[], char from[])
{
    int index = 0;
    while((to[index] = from[index]) != '\0')  // copy index until end of character array. condition  from[index]) != '\0' must be true
        ++index;
}
