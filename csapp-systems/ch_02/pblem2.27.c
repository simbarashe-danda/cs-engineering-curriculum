#include <limits.h>
#include <stdio.h>
/* Determine whether arguments can be added without overflow */
int uadd_ok(unsigned x, unsigned y);

int main(void) {
    printf("%d\n", uadd_ok(4000000000, 4000000000));
    printf("%d\n", uadd_ok(10000, 7737388));
}

int uadd_ok(unsigned x, unsigned y) {
    return x <= UINT_MAX - y;
    /*  return 1 if arguments x and y can be added
    without causing overflow */
}