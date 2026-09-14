**Phase4 Reverse Engineering Analysis**

*see*:\
*`instruction_encoding.s`*\
*`gadget_farm.s`*\
*`target_disassembly_annotated.s`*
  

instr: instruction\
fcn : function\
cookie: `0x59b997fa`

Overview:\
Phase 4 involves a Return-Oriented Programming (ROP) attack executed on the `RTARGET` binary./
The objective is identical to Phase 2: redirect execution to `fcn: touch2` while successfully loading the specific cookie value `0x59b997fa` into the first argument register `%rdi`. However, because` RTARGET` enforces data execution prevention `(DEP/NX)` and uses randomized stack locations, direct shellcode injection is impossible. Instead, existing instruction sequences ending in a return instruction (gadgets) must be found within the executable region of the text section and chained together on the stack.

To pop a value from the stack into %rdi using the permitted first 8 registers, the target gadgets must execute code corresponding to:
```
popq    %rax / %rdi
movq    %rax, %rdi (if popped into rax first)
```

Analyzing the provided exploit chain string reveals the following gadget locations and values sequence:

1. The return address of` fcn: getbuf` is overwritten with the first gadget address: 0x4019ab. This gadget contains the instruction sequence: `popq %rax` followed by ret (encoded as `58 c3`).
2. The next 8 bytes on the stack hold the raw cookie constant value: `0x59b997fa`. The `popq %rax` instruction extracts this constant into `%rax`.
3. The next 8 bytes contain the second gadget address: `0x4019c5`. This gadget contains the instruction sequence: `movq %rax, %rdi` followed by `ret` (encoded as `48 89 c7 c3` based `instruction_encoding.s`). This transfers the cookie value from `%rax` directly into the required argument register `%rdi`.
4. The final 8 bytes contain the entry point of the target function: `0x4017ec (<touch2>)`.

Let the buffer allocated by `fcn: getbuf` be 40 bytes. Since all code execution occurs via stack jumping rather than direct injection, the buffer itself is simply filled with 40 bytes of arbitrary padding to reach the return address slot.

That is, 
```
exploit string = [40 bytes padding] + [Gadget 1 address] + [Cookie constant] + [Gadget 2 address] + [touch2 address]
```

The following input hex format follows:
```
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00     # 40 bytes to fill buf
ab 19 40 00 00 00 00 00                         # Address of popq %rax gadget (0x4019ab)
fa 97 b9 59 00 00 00 00                         # Cookie constant value parameter (0x59b997fa)
c5 19 40 00 00 00 00 00                         # Address of movq %rax, %rdi gadget (0x4019c5)
ec 17 40 00 00 00 00 00                         # Address of target function touch2 (0x4017ec)
```

When `fcn: getbuf` returns, it jumps to 0x4019ab, popping the cookie value into `%rax`. The subsequent ret instruction inside the gadget pops the next stack element, transferring execution to `0x4019c5`. This gadget shifts the cookie to` %rdi` and executes its own ret, forcing a final clean entry directly into `fcn: touch2` with the valid parameter established.

This means it must be the case that `fcn: touch2` finds the valid cookie parameter inside `%rdi` and the phase4 exploit succeeds.

Its therefore clear that in order for a validation misfire or crash to not happen,\
*Rule1: ROP gadgets must utilize verified code alignments matching byte patterns in the text section*\
*Rule2: The ordered stack payload structure must strictly align data constants directly below their corresponding pop instructions*

Thus Rule1 and Rule2 conclude:/
Thus the exploit hex string constructs an alternative runtime path without requiring executable memory allocations.

This completes the analysis of phase4
