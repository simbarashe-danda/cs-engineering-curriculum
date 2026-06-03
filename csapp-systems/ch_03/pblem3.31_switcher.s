    .text
    .globl  switcher
    .type   switcher, @function

# a in %rdi, b in %rsi, c in %rdx, d in %rcx

switcher:
    cmpq    $7, %rdi        
    ja      .L2             # if a > 7 , goto default
    jmp     *.L4(,%rdi,8)   # table[%rdi*8]

    .section        .rodata
    .align 8
.L4:
    .quad   .L3   # a = 0
    .quad   .L2   # not in case: default
    .quad   .L5   # a = 2
    .quad   .L2   # not in case: default
    .quad   .L6   # a = 4
    .quad   .L7   # case 5
    .quad   .L2   # case 6
    .quad   .L5   # case 7

    .text
.L7:
    xorq    $15, %rsi
    movq    %rsi, %rdx  # c = b ^ 15
    # fall through
.L3:
    leaq    112(%rdx), %rdi # a = c + 112
    jmp     .L6         # break
.L5:
    leaq    (%rdx,%rsi), %rdi
    salq    $2, %rdi            # a = (b + c) << 2
    jmp     .L6                 # break
.L2:
    movq    %rsi, %rdi          # default; a = b
.L6:
    movq    %rdi, (%rcx)       # *d = a, dereference
    ret
