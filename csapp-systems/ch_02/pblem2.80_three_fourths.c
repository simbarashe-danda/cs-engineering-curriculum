/* 2.80 Write code for a function threefourths that,
for integer argument x, computes the value of 3x/4, rounded toward zero.
It should not overflow. */

int three_fourths(int x) {
    int q = x >> 2; // quotient after division by 4
    int r = x & 3; // remainder(x mod 4) from x = q.d + r
    q = (q << 2) - q; // 3.q
    r = (r << 2)- r; // 3.r

    /* biasing for 3r/4 to round towards 0 */
    int x_sign = x >> ((sizeof(int) << 3) -1); // sign bit of x
    // from (1 << k) -1 , k = 2; bias = 3
    int biased = x_sign & 3; // since x_sign is either -1 0r 0, its same as x_sign . bias

    /* from derivation: 3x/4 = 3q + 3r/4 */
    return q + ((r + biased) >> 2); // bias is applied to r to compensate loss of precision on q = x/4
    /* division using bias:  (x + bias >> k). x=r, k = 2. */
}