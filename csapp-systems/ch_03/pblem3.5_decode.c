/*
	movq	(%rdi), %r8
	movq	(%rsi), %rcx
	movq	(%rdx), %rax
	movq	%r8, (%rsi)
	movq	%rcx, (%rdx)
	movq	%rax, (%rdi)
	ret                     */
/* C code for decode1 that will have an effect equivalent to the assembly.
    void decode1(long *xp, long *yp, long *zp).
    xp in %rdi, yp in %rsi, zp in %rdx.                     */

void decode1(long *xp, long *yp, long *zp) {
    long x = *xp;   // %r8
    long n = *yp;   // %rcx
    long ret = *zp;  // %rax

    *yp = x; // r8 to (%rsi)
    *zp = n;    // rcx to (%rdx)
    *xp = ret;  // %rax to (%rdi)

}