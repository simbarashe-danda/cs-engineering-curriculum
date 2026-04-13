#include <inttypes.h>
#include <stdio.h>
int mult_ok(int32_t,int32_t); // make sure i use 32 bit

int main(void) {
    /* testing */
    printf("%d\n", mult_ok(INT32_MAX, INT32_MAX)); // overflow
    printf("%d\n", mult_ok(INT32_MAX, INT32_MIN)); // overflow
    printf("%d\n", mult_ok(INT32_MIN, INT32_MIN)); // overflow
    printf("%d\n", mult_ok(INT32_MAX, INT32_MIN)); // overflow
    printf("%d\n", mult_ok(1000000000, 2)); // no overflow
    printf("%d\n", mult_ok(1000000000, -2)); // no overflow
}

/* Determine whether arguments can be multiplied without overflow */
int mult_ok(int32_t x, int32_t y) {
    /* cast before opearation or overflow will happpen before assignment */
    int64_t mult = (int64_t)x * (int64_t)y;
    return (mult <= INT32_MAX) && (mult >= INT32_MIN);
    // true if overflow cannot happen
}