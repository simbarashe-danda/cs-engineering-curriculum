**Phase3 Reverse Engineering Analysis**

*see phase3_asm.s for commented assembly code*

instr: instruction\
fcn : function

instr: `sub $0x18, %rsp` allocates 24 bytes on stack\
instr: `lea 0xc(%rsp), %rcx` means `%rcx` points to stack offset 12\
instr: `lea 0x8(%rsp), %rdx` means `%rdx` points to stack offset 8

fcn: `__isoc99_sscanf@plt` is then called, which means 24 bytes allocated on stack are for storing 2 ints from input,\
 and `%rdx`, `%rcx` are pointers to the variables when reading the 2 ints from input\
We can therefore, Let `val1` be `0x8(%rsp)` and `val2` be `0xc(%rsp)`

```
cmp    $0x1,%eax                    # if items_parsed > 1
jg     400f6a <phase_3+0x27>        # go to 400f6a
call   40143a <explode_bomb>        # else explode bomb
```

This sequence of instructions indicates that the number of successfully parsed ints must be greater than 1

Rule1: `inputs_parsed >= 2`

`400f6a` has instr: `cmpl   $0x7,0x8(%rsp)` # compare val1 to 7

This instruction follows right after that:\
instr:` ja     400fad <phase_3+0x6a>`      # if val1 > 7 (unsigned) explode bomb

That means the program enforces an upper bound check on val1 -> the program is setting up a switch-case jump table over a limited index range

Rule2: `0 <= val1 <= 7`

The following instructions follow:\
`mov    0x8(%rsp),%eax`             # eax = val1\
`jmp    *0x402470(,%rax,8)`         # go to jump table target

The instructions indicate that, the target destination is determined dynamically by the value of val1 using an array of 8-byte pointers starting at `0x402470`.\
Assume `val1 = 0` in the current execution path

instr: `jmp *0x402470(,%rax,8)` then routes execution directly to address 400f7c for case 0

The following instructions follow:
```
400f7c: mov    $0xcf,%eax           # eax = 0xcf
jmp    400fbe <phase_3+0x7b>        # go to verify block
400fbe: cmp    0xc(%rsp),%eax       # compare eax and val2
je     400fc9 <phase_3+0x86>        # if eax == val2
call   40143a <explode_bomb>        # explode
```

instr: `cmp %eax, 0xc(%rsp)` then compares `if %eax == val2` of which `%eax = 0xcf (207 in decimal)`\
instr: `call 40143a <explode_bomb>` is called if `%eax != val2`.

This means it must be the case that for the chosen path, `val2 = 207`

`if %eax == val2`, the program skips the bomb explosion block and proceeds to `400fc9`\
instr: `add $0x18, %rsp` frees the stack and the program ends.

Its therefore clear that in order for a call to fcn: explode_bomb to not be called,\
Rule3: `if val1 == 0`, `then val2 = 207`

Thus Rule1, Rule2 and Rule3 conclude:\
Thus the chosen input target is the pair : `[0, 207]`

This completes the analysis of phase3
