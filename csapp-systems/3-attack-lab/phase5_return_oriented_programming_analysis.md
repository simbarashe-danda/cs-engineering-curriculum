**Phase5 Reverse Engineering Analysis**

*see*:\
*`instruction_encoding.s`*\
*`gadget_farm.s`*\
*`target_disassembly_annotated.s`*


instr: instruction  
fcn: function  
cookie: `"59b997fa"`

Overview:  
Phase 5 involves an advanced Return-Oriented Programming (ROP) attack executed on the `RTARGET` binary.  
The objective is to redirect execution to `fcn: touch3` while successfully passing a pointer to the string representation of the cookie (`"59b997fa"`) into the first argument register `%rdi`. Because `RTARGET` enforces data execution prevention `(DEP/NX)` and utilizes Stack Randomization (ASLR), the exact memory address of the injected string is unpredictable. Therefore, the exploit cannot rely on hardcoded absolute addresses. Instead, the stack pointer (`%rsp`) must be dynamically read at runtime, an exact byte offset must be added to it, and this computed address must be routed into `%rdi` prior to invoking `touch3`.

To dynamically calculate the string pointer and pass it to `%rdi` using the restricted gadget farm, the target gadgets execute code corresponding to the following sequence:
```assembly
movq    %rsp, %rax
movq    %rax, %rdi
popq    %rax
xchg    %eax, %ecx
movl    %ecx, %esi
leaq    (%rdi,%rsi,1), %rax
movq    %rax, %rdi
ret                      # A8 alignment gadget (c3)

```

Analyzing the provided exploit structure reveals the following exact stack layout and data flow:

`[Padding] + [A1, A2, A3, k', A4, A5, A6, A7, A8, Touch3, string]`

1. **A1 (`movq %rsp, %rax`)**: The return address of `fcn: getbuf` is overwritten with the first gadget address `A1`. This gadget captures the current stack pointer into `%rax`.
2. **A2 (`movq %rax, %rdi`)**: This gadget takes the captured stack pointer from `%rax` and establishes it as the base address inside `%rdi`.
3. **A3 (`popq %rax`)**: This gadget pops the next sequential item on the stack into `%rax`.
4. **`k'` (Offset Constant)**: The raw byte offset (`k' = k + 8`) sits directly underneath `A3`. The previous `popq` instruction extracts this mathematical offset into `%rax`. Because an extra gadget (`A8`) was inserted into the chain, the target string is pushed down by an additional 8 bytes, requiring the offset to be incremented.
5. **A4 (`xchg %eax, %ecx`)**: The first routing gadget exchanges the contents of `%eax` and `%ecx`, shifting the offset value into `%ecx`.
6. **A5 (`movl %ecx, %esi`)**: The second routing gadget transfers the offset from `%ecx` into `%esi`. The offset is now correctly positioned in the index register for address calculation.
7. **A6 (`leaq (%rdi,%rsi,1), %rax`)**: This gadget performs the critical mathematical computation. It takes the base stack pointer (`%rdi`), adds the exact offset (`%rsi`), and stores the absolute memory address of the target string into `%rax`.
8. **A7 (`movq %rax, %rdi`)**: This gadget executes a final transfer, moving the computed absolute string pointer from `%rax` into the required argument register `%rdi`.

9.  **A8 (`ret` - `c3`)**: Stack alignment padding. The System V AMD64 ABI specification requires strict 16-byte stack alignment at specific execution boundaries. Because standard function calls push an 8-byte return address, simulating a call via a ROP chain can misalign the stack. Injecting this single `ret` gadget consumes 8 bytes, shifting the stack pointer to satisfy the ABI alignment constraint. As verified in GDB, upon entering `touch3` (`$rip = 0x4018fa`), the stack pointer is correctly aligned ending in 0 (`$rsp = 0x7ffffffc0ed0`).

10. **`Touch3`**: The entry point of the target function `fcn: touch3`.
11. **`string`**: The ASCII hex representation of the cookie string (`"59b997fa"`).

When `fcn: getbuf` returns, it initiates the chain by capturing `%rsp` at `A1`. At this exact moment of execution, the stack pointer points to the *next* return address slot on the stack (which holds `A2`). By routing and adding the precise byte offset `k'` to this captured base address, the `leaq` instruction exactly resolves the memory location where the ASCII string resides at the bottom of the payload. The chain finishes by shifting this dynamically calculated absolute pointer into `%rdi`, stepping through `A8` to fix alignment, and finally jumping into `fcn: touch3`.

This means it must be the case that `fcn: touch3` finds the valid string pointer parameter inside `%rdi`, dynamically bypassing ASLR, and the phase5 exploit succeeds.

It is therefore clear that in order for a validation misfire or crash to not happen,

*Rule1: ROP gadgets must utilize verified code alignments matching byte patterns in the text section to circumvent DEP/NX*

*Rule2: The mathematical offset `k'` must be strictly precise to dynamically resolve injected stack data addresses against unpredictable ASLR boundaries*

*Rule3: The stack must satisfy System V AMD64 ABI 16-byte alignment constraints before transferring execution to target functions requiring aligned memory access*

Thus Rule1, Rule2, and Rule3 conclude:

Thus the exploit constructs a deterministic runtime address computation without requiring executable memory allocations or fixed stack locations, while strictly adhering to hardware ABI constraints.

This completes the analysis of phase5
