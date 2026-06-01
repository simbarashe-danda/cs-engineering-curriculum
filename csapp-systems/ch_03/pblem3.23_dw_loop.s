# long dw_loop(long x)
# x initially in %rdi
# let y = rcx and n = rdx
dw_loop:
    movq    %rdi, %rax         # rax = x
    movq    %rdi, %rcx         
    imulq   %rdi, %rcx         # rcx = x*x  (y = x^2)
    leaq    (%rdi,%rdi), %rdx  # rdx = 2rdi (n = 2x)
.L2:
    leaq    1(%rcx,%rax), %rax # rax = rax + rcx + 1 : (x += y + 1)
    subq    $1, %rdx           # --rdx (--n)
    testq   %rdx, %rdx        
    jg      .L2                # if n > 0, jump back to L2: LOOP
    rep; ret                   # return x
