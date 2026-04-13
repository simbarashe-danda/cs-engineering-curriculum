/* Write a function reverse(s) that reverses the character string s.
Use it to write a function that reverses its input at a time.*/

#include <stdio.h>
#define MAXSIZE 100   // max string length. Well i dont expect any single word to be longer than 100!!

void getstring(char s[]);  // declare function that gets string inputs
void reverse(char s[]);    // declare function that reserves strings

int main ()
{
    char s[MAXSIZE] = {0};    // character array that holds inputs
    getstring(s), reverse(s);   // get character input and reverse it
    printf("%s\n",s);       // console output reversed string
    return 0;           // normal termination
}
/* getstring function definition */
void getstring(char s[])    // function definition
{
    int c;          // character input
    int i=0;          // subscript variable
    /* character input */
    while((c=getchar())!=EOF && c!='\n')    // while char input is not newline, reads only single words
        s[i++] = c;             // append to to the array, s
    if(c=='\n')             // if input is newline
        s[i++] = c;         // append it to char
    s[i] = '\0';    // add null character
}
/* reverse function definition */
void reverse(char s[])
{
    char s2[MAXSIZE] = {0};     // temporary array to be used in reversing
    int i=0, i2=0;          // subscript variables
    
    /* count number of characters in s excluding null*/
    while((s[++i])!='\0'); // count size of s, and store in i;exclude null
    i-=1;   // prevent out of bound subscripting

    /* reversing logic */
    while(s2[i2++]=s[i--],i>=0);    // i2 is 0 and is incrementing, i is size of s and is decrementing
    s2[i2]='\0';     // add null

    i=0;    // reset i
    while((s[i]=s2[i++])!='\0');   // copy the reversed string to s
}