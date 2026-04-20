/* Write a procedure is_little_endian that will return 1 when compiled and run 
on a little-endian machine, and will return 0 when compiled and run on a big- endian machine.
This program should run on any machine, regardless of its word  size. */
#include <stdio.h>
int is_little_endian(void);
int main(void) 
{
    /* test */
    printf("%d\n", is_little_endian());
}
int is_little_endian(void) {
    unsigned x = 0x1; // 0x100.. if litte endian
    unsigned char* ptr = (unsigned char*)(&x); // cast
    return ((*ptr) == 0x1); // true if little endian
}