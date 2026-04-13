#include <ctype.h>
#include <stdio.h>

/*Prototype for library function strlen */
size_t strlen(const char*s);
int strlonger(char*, char*);

int main(void)
{ 
    printf("%d\n",strlonger("hello", "university")); // must print 0
    return 0;
} 

/* Determine whether string s is longer than string t */
/* WARNING: This function  is buggy! */
int strlonger(char*s,char*t){
    return strlen(s) - strlen(t) > 0;
}
/* always returns 1, for len(s) < len(t) 
The subtraction is negative, which is converted to unsigned */
