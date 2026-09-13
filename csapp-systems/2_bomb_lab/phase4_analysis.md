**Phase4 Reverse Engineering Analysis**

*see phase4_asm.s for commented assembly code*

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
jg     401029 <phase_4+0x1d>        # go to 401029
call   40143a <explode_bomb>        # else explode bomb
```

This sequence of instructions indicates that the number of successfully parsed ints must be greater than 1

Rule1: `inputs_parsed >= 2`

`401029` has instr: `cmpl   $0xe,0x8(%rsp)` # compare val1 to 14

This instruction follows right after that:\
instr: `jbe    401035 <phase_4+0x29>`      # if val1 <= 14 (unsigned) go to 401035

That means the program enforces an upper bound check on` val1` -> the program restricts the first input value before calling the helper function

Rule2: `0 <= val1 <= 14`

The following instructions follow:
```
mov    $0xe,%edx                    # edx = 14
mov    $0x0,%esi                    # esi = 0
mov    0x8(%rsp),%edi               # edi = val1
call   400fce <func4>               # call recursive function func4
```
The instructions indicate that, func4 is called with parameters `%edi = val1`, `%esi = 0`, and `%edx = 14`.\
Mathematically, fcn: `func4` implements a binary search algorithm over the range `[0, 14]` tracking a target `val1`.\
Let the behavior of `func4` be modeled dynamically.\
The function calculates a midpoint: 
```
%ecx = %esi + (%edx - %esi) / 2 = 0 + (14 - 0) / 2 = 7
```

`Assume val1 = 7` in the current execution path

instr: `cmp %edi, %ecx` then compares if `mid == val1`,\
Since` 7 == 7`, the condition at `400fe2 (jle)` is met, routing execution to `400ff2`.\
instr: `cmp %edi, %ecx `at `400ff7` checks if `mid >= val1`.\
Since `7 >= 7`, the condition is met, routing execution directly to `401007`.\
The register %eax is set to 0 before the jump, meaning fcn: `func4` returns 0 when `val1 = 7`.

The following instructions follow in phase_4:
```
cmp    $0x0,%eax                    # compare return value of func4 with 0
jne    40104d <phase_4+0x41>       # if return value != 0, explode bomb
cmpl   $0x0,0xc(%rsp)              # compare val2 to 0
je     401052 <phase_4+0x46>       # if val2 == 0, success
call   40143a <explode_bomb>       # else explode bomb
```
instr: `cmp $0x0, %eax` then compares if the return value of `func4 == 0`.\
instr: `cmpl $0x0, 0xc(%rsp)` then compares if `val2 == 0`.

This means it must be the case that for the chosen path, the return value of fcn: `func4` must be 0, and `val2` must be 0

if the conditions are met, the program skips the bomb explosion block and proceeds to `401052`\
instr: `add $0x18, %rsp` frees the stack and the program ends.

Its therefore clear that in order for a call to fcn: explode_bomb to not be called,\
Rule3: val1 must yield a return value of 0 from fcn: `func4`, and `val2 = 0`

Thus Rule1, Rule2 and Rule3 conclude:\
Thus the chosen input target is the pair : `[7, 0]`

This completes the analysis of phase4
