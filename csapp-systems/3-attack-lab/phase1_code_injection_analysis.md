**Phase1 Reverse Engineering Analysis**

*see*:\
*`target_disassembly_annotated.s`*

instr: instruction\
fcn : function

Overview:\
Phase 1 targets a code redirection vulnerability via a stack-based buffer overflow in `CTARGET`. The objective is to hijack the control flow of the program when `fcn: getbuf` finishes execution. Instead of letting the function return normally to its caller `fcn: test`, the exploit string must overwrite the saved return address on the stack to redirect execution to an existing procedure, `fcn: touch1`.

instr: `sub $0x28, %rsp` allocates 40 bytes on stack\
instr: `mov %rsp, %rdi` means `%rdi` points to the top of the stack

`fcn: Gets` is then called, which means 40 bytes allocated on stack are for storing input string from user,\
 and `%rdi` is pointer to the buffer when reading the input string from user\
We can therefore, Let `buf be %rsp`,\
That is , `buf = [rsp, rsp+1 ,.., rsp+39]`, notice that buffer holds chars

The program then finishes `fcn: getbuf` and hits the return instruction:\
instr: `ret` pops the return address off the stack and jumps to it

This sequence of instructions indicates that if the input string length exceeds 40 bytes, it will overwrite the saved return address on the stack immediately following the allocated buffer

Rule1: `buf size = 40 bytes`

At high level, the goal is to redirect execution to `fcn: touch1` instead of returning to `fcn: test`

The analysis of the disassembly text reveals that `fcn: touch1` begins at address 0x4017c0. Because this phase does not require code injection, the return address can be manipulated directly by filling the buffer exactly to its capacity and appending the target address.

We must construct an exploit string that fills the 40 bytes of buf and overwrites the saved return address with the address of `fcn: touch1`

That is,
```
exploit string = [40 bytes padding] + [0x4017c0 in little endian]
```
The following input hex format follows:
```
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00     # 40 bytes to fill buf
c0 17 40 00 00 00 00 00                     # address of touch1 (0x4017c0)
```

instr: `ret` then pops 0`x4017c0` into `%rip` instead of the original return address inside `fcn: test`.

This means it must be the case that `fcn: touch1` executes and the phase1 exploit succeeds.

Its therefore clear that in order for a crash or incorrect path to not happen,\
Rule2: `exploit payload must pad exactly 40 bytes before injecting the target function address`

Thus Rule1 and Rule2 conclude:\
Thus the exploit hex string targets the exact byte layout required to hijack control flow.

This completes the analysis of phase1
