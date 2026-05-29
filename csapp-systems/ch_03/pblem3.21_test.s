# long test(long x, long y)
# x in %rdi, y in %rsi

test:
    leaq    0(,%rdi,8), %rax    # rax = 8x      (1)
    testq   %rsi, %rsi          # test y
    jle     .L2                 #  if y > 0

    movq    %rsi, %rax          # rax = y
    subq    %rdi, %rax          # rax = y - x
    movq    %rdi, %rdx          # rdx = x
    andq    %rsi, %rdx          # rdx = x & y
    cmpq    %rsi, %rdi          # compare x with y
    cmovge  %rdx, %rax          # rax = x & y if x >= y   (2)
    ret                         # return y-x or x&y        (3)

.L2:                            # else if y <= 0
    addq    %rsi, %rdi          # x += y
    cmpq    $-2, %rsi           # compare y to -2
    cmovle  %rdi, %rax          # rax = x + y if y <= -2    (4)
    ret                         # return x+y or 8x          (5)
