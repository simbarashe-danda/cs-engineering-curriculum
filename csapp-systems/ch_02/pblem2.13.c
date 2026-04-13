/* Declarations of functions implementing operat~ons bis and bic */ 
int bis(int x, int m);
int bic(int x, int m); 

/* Compute xly using only calls to functions bis and bic */ 
int bool_or(int x, int y) { 
    int result = bis(x, y);
    return result;
} 

/* Compute x^y using on1y calls to functions on bis and bic */
int bool_xor(int x, int y) { 
    int result = bis(bic(x,y), bic(y,x));   // xor is (p & ~q) v (~p & q)
    return result;
}

int bis (int x, int m) {
    int r =  x | m;    // set 1 everywhere were  is 1
    return r;
}

int bic(int x, int m) {
/* set 0 everytime when m is 1 */
    int r = x & ~m;  // x and not m
    return r;
}

