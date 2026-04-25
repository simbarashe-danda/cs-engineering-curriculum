/* Exercise 2-5.
Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. 

(The standard library function strpbrk does the same job but returns a pointer to the 
location.) */
#include <stdio.h>
int any(const char*, const char*);
int occurs(const char*, const int);

int main(void)
{
    /* testing */
    char s1[] = "hello world"; char s2[] = "c world";
    char s3[] = "mat";

    printf("%c\n", s1[any(s1, s2)]); // should be 'l'
    printf("%d\n", any(s1, s3)); // should be -1
}

/* not efficient, O(N^2) time */
int any(const char* s1, const char* s2) {
    for (int i=0; *s1 != '\0'; ++i, ++s1)
        if (occurs(s2, *s1)) // if indexed char of s1 is in s2
            return i;
    return -1; // no occurence
}

int occurs(const char* str, const int c) {
    int i = 0;
    while(str[i] != '\0')
        if (str[i++] == c) return 1;  // c is in str
    return 0;
}
