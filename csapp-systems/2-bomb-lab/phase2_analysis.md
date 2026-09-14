**Phase2 Reverse Engineering Analysis**

*see phase2_asm.s for commented assembly code*

instr: instruction\
fcn : function

instr: `sub $0x28, %rsp` allocates 40 bytes on stack\
instr:` mov %rsp, %rsi` means %rsi points to the top of the stack

fcn: `read_six_numbers` is then called, which means 40 bytes allocated on stack are for storing 6 ints from input,\
 and %rsi is pointer to the array when reading the 6 ints from input\
We can therefore, Let intArr be %rsp,\
That is, `intArr = [rsp, rsp+4, .., rsp+20]`, notice that int is 4 bytes
```
cmpl    $0x1,(%rsp)                 # if val1 == 1
je      400f30 <phase_2+0x34>       # go to 400f30
call    40143a <explode_bomb>       # else explode bomb
```

This sequence of instructions indicates that the first int in the array must be 1

Rule1: `val1 = 1`

`400f30` has instr:` lea 0x4(%rsp)`, %rbx # rbx points to rsp+4

At high level, this is same as `%rbx = intArr + 1`

This instruction follows right after that:\
instr: `lea 0x18(%rsp), %rbp `       # rbp points to rsp+24

That means %rbp works as a loop boundary pointer -> the program is likely setting up a loop over the intArr

The following instructions follow:
```
jmp          400f17 <phase_2+0x1b>  # go to loop start
400f17: mov -0x4(%rbx),%eax         # eax = *(intArr-4)
add          %eax, %eax             # eax = 2*eax
```         

The instructions indicate that, %eax stores the val before that pointed to by %rbx.\
That is, `if *(rbx) = val2` ,`then %eax = val1`

Assume` *(rbx) = val2` and `%eax = val` in the current loop iteration

instr: `add %eax, %eax` then doubles the val stored in %eax, that is,` %eax += %eax`, then `%eax = 2 * val1`

The following instructions follow:
```
cmp     %eax,(%rbx)
je      400f25 <phase_2+0x29>`    # if eax == *(rbx)
call    40143a <explode_bomb>`    # explode
add     $0x4,%rbx   `             # else increment rbx: ptr
cmp     %rbp,%rbx`                # Loop condition check
jne     400f17 <phase_2+0x1b>`    # loop start
jmp     400f3c <phase_2+0x40>`    # end loop
```
instr:` cmp %eax, (%rbx)` then compares `if %eax == val2` of which` %eax = 2*val1`\
instr: `call 40143a <explode_bomb>` is called `if %eax != val2`.

This means it must be the case that in the current iteration, `val2 = 2 * val1`

`if %eax == val2`, `%rbx` is incremented by 4 -> `*(rbx) is now val3`\
instr: `cmp %rbp, %rbx` checks if the pointer %rbx is still in bound, since rbp points to `rsp+24`

`if in_bound`, loop goes to` 400f17` which is loop start, and %eax now stores val2

if` out_of_bound` the program frees the stack and the program ends.

Its therefore clear that in order for a call to fcn:` explode_bomb` to not be called,\
Rule2: `for all val_i in intArr, val_i = val_i-1 * 2`

Thus Rule1 and Rule2 conclude:\
Thus intArr has the geometric series : `[1, 2, 4, 8, 16, 32]`

This completes the analysis of phase2
