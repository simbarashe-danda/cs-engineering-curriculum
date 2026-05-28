// translating assembly in pblem3.7_scale2.s to C

long test(long x, long y, long z) {
    /* x in %rdi, y in %rsi , z in %rdx */
    long val = x + y + z;
    if (x < -3)
        if (y < z)
            val = x * y;
        else  val = y * z;  // L3
    else if (x > 2)  // L2
       val = x * z;
    return val; // L1
}
