/* Write a program to print all line inputs longer than 80*/

#include <stdio.h>      // input-output library
#define MINLINE 80      // minimum line length
#define MAXLINE 1000    // maximum line length

int getline_len(char line[],int lim);   // declare function that takes chatacter array as argument and return int

int main (void)
{
    char line[MAXLINE];     // define character array that contains line inputs
    int len;    // line length

    while((len=getline_len(line,MAXLINE))>0)    // while there is a line
        if(len>MINLINE)
            printf("%s\n",line);    // print character arrays with length greater than 80
    return 0;   // normal termination
}

int getline_len(char line[],int lim)    // define getline, a function that returns line length
{
    int c;      // character input
    int i;    // counting variable, amd used as subscript

    /* i<lim-1 is meant to reserve space for the null character, every character array must have a null character */
    for(i=0; (c=getchar()) !=EOF && c!='\n' && i<lim-1; ++i)    // runs if there is no end-of-file and we have not reached newline
        line[i] = c;    // append character to line
    if(c == '\n') {
        line[i] = c;    // newline is also a character, we must append it
        ++i;            // we increment counter everytime we append
    }
    line[i] = '\0';     // null character that signals the end point of the char array
    return i;           // return count to the calling function
}