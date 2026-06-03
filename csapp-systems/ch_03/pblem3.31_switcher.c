void switcher(long a, long b, long c, long *dest)
{
    /* Assembly in asm file pblem3.31_switcher.s to C*/
    long val;   
    switch(a) {
    case 5 :        // .L7
        c = b ^ 15;
        /* Fall through */
    case 0 :        //.L3 
        val = c + 112 ;
        break;
    case 2 :       // .L5 
    case 7 :        // .L5 
        val = (b + c) << 2;
        break;
    case 4 :     // same as .L6
        val = a;
        break;
    default:        // .L2
        val = b;
    }
    *dest = val;    // .L6
}
