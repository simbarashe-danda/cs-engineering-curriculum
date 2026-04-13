/* Using only bit-level and logical operations, write a C expression that is equivalent to x == y.
In other words, it will return 1 when x and y are equal and 0 otherwise. */

int is_equal(int x, int y) {
    return !(x ^ y);
}