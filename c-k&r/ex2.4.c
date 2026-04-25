/* Exercise 2-4.
Write an alternative version of squeeze(s1,s2) that deletes each
character in  s1 that matches any character in the string s2. */
#include <stdio.h>
void squeeze(char*, const char*);
int not_occurs(const char*, int);

int main(void)
{
    /* testing */
    char s1[] = "hello world";
    char s2[] = "hey c programmers";
    squeeze(s1, s2);
    printf("%s\n", s1); // should be "llwld"
}

/* not time efficient, O(N^2) time */
void squeeze(char* s1, const char* s2) { // const: prevent mutation of s2
    int i, j;
    for (i = j = 0; s1[i] != '\0'; ++i)
        if (not_occurs(s2, s1[i])) // if indexed char of s1 is not in s2
            s1[j++] = s1[i];
    s1[j] = '\0';
}

int not_occurs(const char* str, int c) {
    int i = 0;
    while(str[i] != '\0')
        if (str[i++] == c) return 0;  // c is in str
    return 1;
}

