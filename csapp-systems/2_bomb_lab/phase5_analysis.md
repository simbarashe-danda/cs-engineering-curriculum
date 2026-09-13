**Phase5 Reverse Engineering Analysis**

*see phase5_asm.s for commented assembly code*

instr: instruction\
fcn : function

instr: `sub $0x20, %rsp` allocates 32 bytes on stack\
instr: `mov %fs:0x28, %rax` sets up a stack canary for buffer overflow protection\
instr: `call 40131b <string_length>` gets the length of the input string

```
cmp    $0x6,%eax                    # if length == 6
je     4010d2 <phase_5+0x70>`       # go to loop setup (via jump to 4010d2 then 40108b)
call   40143a <explode_bomb>`       # else explode bomb
```
This sequence indicates the input string must be exactly 6 characters long.

Rule1: `length(input) = 6`

The code then enters a loop that transforms the input string.\
Let the input string be `S`.\
The loop runs 6 times (rax from 0 to 5).

```
40108b: movzbl  (%rbx,%rax,1),%ecx      # load char S[i] into ecx
401096: and     $0xf,%edx               # isolate lower 4 bits: val = S[i] & 0xF
401099: movzbl  0x4024b0(%rdx),%edx     # look up char in table at 0x4024b0 using val as index
4010a0: mov     %dl,0x10(%rsp,%rax,1)   # store mapped char in new buffer at rsp+16
```
The transformation maps the low-order nibble of each input character to a character from the lookup table `"maduiersnfotvbyl"`.\
Let generated string be `S'`.\
```
S'[i] = Table[ S[i] & 0xF ]
```

After the loop:\
```
4010b3: mov    $0x40245e,%esi               # esi points to target string "flyers"
4010b8: lea    0x10(%rsp),%rdi              # rdi points to S'
4010bd: call   401338 <strings_not_equal>   # compare S' and "flyers"
```
instr: `test %eax, %eax` checks if the strings are identical.
instr:` call 40143a <explode_bomb>` is called if strings are not equal.

This means `S'` must be `"flyers"`.\
We must find input characters whose low nibbles index to `'f', 'l', 'y', 'e', 'r', 's'` in the table `"maduiersnfotvbyl"`.


Table Mapping:
```
Index 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
Char  m a d u i e r s n f o  t  v  b  y  l
```

Target "flyers":
```
'f' is at index 9  -> S & 0xF = 9
'l' is at index 15 -> S & 0xF = 15 (0xF)
'y' is at index 14 -> S & 0xF = 14 (0xE)
'e' is at index 5  -> S & 0xF = 5
'r' is at index 6  -> S & 0xF = 6
's' is at index 7  -> S & 0xF = 7
```

We need characters with low nibbles `9, 15 (0xF), 14 (0xE), 5, 6, 7`.\
Using standard printable ASCII characters:
```
0x39 ('9') & 0xF = 9
0x3F ('?') & 0xF = 15
0x3E ('>') & 0xF = 14
0x35 ('5') & 0xF = 5
0x36 ('6') & 0xF = 6
0x37 ('7') & 0xF = 7
```

Rule2: input string must map to `"flyers"`

Thus Rule1 and Rule2 conclude:\
The required input string is: `"9?>567"`

This completes the analysis of phase5
