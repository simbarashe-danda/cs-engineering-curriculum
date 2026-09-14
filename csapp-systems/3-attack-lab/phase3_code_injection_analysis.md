**Phase3 Reverse Engineering Analysis**

*see*:\
*`target_disassembly_annotated.s`*\
*`phase3_exploit_code.s`*

instr: instruction\
fcn : function\
cookie: `0x59b997fa`

Overview:\
Phase 3 involves a code injection attack on `CTARGET` where the objective is to redirect execution to `fcn: touch3` instead of returning to `fcn: test`. Function `touch3` requires a pointer to a string character array `(char *sval)` containing the ASCII hex representation of the cookie value `0x59b997fa (that is, "59b997fa")`. Since x86-64 passes the first argument via register `%rdi`, the injected code must place a pointer to this string representation into `%rdi` before transferring execution flow to `fcn: touch3`.

A critical constraint is introduced by `fcn: hexmatch`, which uses `fcn: random()` to allocate a string buffer dynamically on the stack. If the string representation is stored within the standard 40-byte buffer area of `fcn: getbuf`, it will be corrupted when `fcn: hexmatch` overwrites stack memory during validation execution. To prevent this data corruption, the exploit string representation is safely appended after the injected code payload on the stack.

The injected assembly instructions are structured as follows:
```
movq    %rsp, %rdi          # point %rdi to the cookie string location on the stack
pushq   $0x4018fa           # push target entry address of touch3 onto stack
ret                         # transfer execution flow to touch3
```

The byte sequence generated from assembling these instructions yields:
```
48 89 e7 68 fa 18 40 00 c3
```

This injected code occupies exactly 9 bytes.

Let the buffer allocated by `fcn: getbuf` be 40 bytes. The 9 bytes of injected code are positioned at the absolute start of this buffer. To bridge the gap to the saved return address slot, padding must be applied.

The required padding size inside the buffer is:
```
Padding = 40 bytes - 9 bytes = 31 bytes
```

Let the buffer start address found via GDB be `0x5561dc78`. The return address slot immediately following the padding must be overwritten with this address in little-endian format to trigger the payload.

Following the return address slot (which takes up 8 bytes), the cookie text string must be placed. The instruction `movq %rsp, %rdi` reads the stack pointer exactly at the point when the execution enters the injected payload. Because `fcn: getbuf` frees its stack frame with `add $0x28, %rsp` before executing `ret`, the stack pointer `%rsp` will point directly to the memory address immediately following the injected return address slot.

Let the hex values for the ASCII characters of the cookie string "59b997fa" accompanied by a null terminator be:
```
35 39 62 39 39 37 66 61 00
```

That is, 

```
exploit string = [9 bytes injected code] + [31 bytes padding] + [0x5561dc78 in little endian] + [9 bytes cookie ASCII string]
```

The following input hex format follows:
```
48 89 e7 68 fa 18 40 00 c3      # 9 bytes injected code
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00    # 31 bytes to fill rest of buf
78 dc 61 55 00 00 00 00         # address of start of stack buffer (0x5561dc78)
35 39 62 39 39 37 66 61 00      # ASCII string representation of cookie "59b997fa\0"
```

When `fcn: getbuf` finishes execution, the return pointer directs control back to the injected payload at` 0x5561dc78`. The register `%rdi` is populated with the pointer to the cookie string residing safely beyond the stack frame footprint, and execution transitions cleanly into `fcn: touch3`.

This means it must be the case that `fcn: touch3` receives a valid matching hex string reference and the phase3 exploit succeeds.

Its therefore clear that in order for a crash or data corruption to not happen,\
*Rule1: injected code must dynamically map the stack data reference address into the pointer register*\
*Rule2: exploit payload string variables must sit outside volatile stack frame boundary spaces to avoid corruption*

Thus Rule1 and Rule2 conclude:
Thus the exploit hex string coordinates pointer layout safely alongside control flow redirection variables.

This completes the analysis of phase3
