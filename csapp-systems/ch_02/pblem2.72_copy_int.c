/* You are given the task of writing a function that will copy an integer val into a 
buffer buf, but it should do so only if enough space is available in the buffer.

Here is the code you write: 
/* Copy integer into buffer if space is available */ 
/* WARNING: The following code is buggy */ 
void copy_int(int val, void *buf, int maxbytes) { 
    if (maxbytes-sizeof(val) >= 0) 
        memcpy(buf, (void *) &val, sizeof(val)); 
}

/*
You carefully test the code and discover that it always copies the value to the 
buffer, even when maxbytes is too small.

A. Explain why the conditional test in the code always succeeds.
    sizeof returns size_t which is unsigned long.
    because the expression result is converted to unsigned, its never negatiive.

B. Show how you can rewrite the conditional test to make it work properly. */

/* mathematically x-y >= 0 is same as  x >= y */
void copy_int1(int val, void *buf, int maxbytes) {
    if (maxbytes >= (int)sizeof(val))   // cast sizeof to int, assuming user is stupid enough to pass negative val for maxbytes
        memcpy(buf, (void *) &val, sizeof(val)); 
}