#include <stdio.h>
/* Determine whether arguments can be added without overflow */
int tadd_ok(int x, int y);

int main(void) 
{
    printf("%d\n", tadd_ok(-2000000000, -2000000001));// must be 0
    printf("%d\n", tadd_ok(2000000000, 2000000001));// must be 0
    printf("%d\n", tadd_ok(-2000000000, 1000000001));// must be 1
    printf("%d\n", tadd_ok(-20000000, -20000001));// must be 1
    printf("%d\n", tadd_ok(-20000000, 20000001));// must be 1
    return 0;
}
int tadd_ok(int x, int y) {
    int sum = x + y;
    if (x > 0 && y > 0 && sum < 0)
        return 0; // positive overflow
    else if (x < 0 && y < 0 && sum > 0)
        return 0; // negative overflow
    return 1;   // remaining cases cant cause overflow
}