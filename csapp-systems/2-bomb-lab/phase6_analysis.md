**Phase6 Reverse Engineering Analysis**

*see phase6_asm.s for commented assembly code*

instr: instruction/
fcn : function

instr: `sub $0x50, %rsp` allocates 80 bytes on stack\
instr: `mov %rsp, %rsi` means `%rsi` points to the top of the stack\

fcn: read_six_numbers is then called, which means 80 bytes allocated on stack are for storing 6 ints from input,\
 and `%rsi` is pointer to the array when reading the 6 ints from input\
We can therefore, Let `intArr be %rsp`,\
That is , `intArr = [rsp, rsp+4 ,.., rsp+20]`, notice that int is 4 bytes

The following instructions follow:
```
41 8b 45 00             mov    0x0(%r13),%eax
83 e8 01                sub    $0x1,%eax
83 f8 05                cmp    $0x5,%eax
76 05                   jbe    401128 <phase_6+0x34>
e8 12 03 00 00          call   40143a <explode_bomb>
```

This sequence of instructions enforces that each value in the array minus 1 must be between 0 and 5, meaning each input must be in the range.\
Nested loop instructions at 401135 compare every element against all subsequent elements, exploding the bomb if a duplicate is found.

Rule1: intArr contains a permutation of the integers from 1 to 6 (no duplicates)

The following instructions follow:
```
48 8d 74 24 18          lea    0x18(%rsp),%rsi
4c 89 f0                mov    %r14,%rax
b9 07 00 00 00          mov    $0x7,%ecx
89 ca                   mov    %ecx,%edx
2b 10                   sub    (%rax),%edx
89 10                   mov    %edx,(%rax)
```

This loop modifies each entry in the input array by transforming `val_i = 7 - val_i`.\
Given the target solution input array, the transformed array becomes:\
`intArr = [7-4, 7-3, 7-2, 7-1, 7-6, 7-5] = [3, 4, 5, 6, 1, 2]`

Rule2: The values are transformed as `val_i = 7 - val_i`

The program then uses the numbers in the transformed intArr as indices to reorder a singly-linked list of 6 nodes starting at node structure address `0x6032d0`. Each node has an integer value at offset 0 and a next pointer at offset 8. The code dynamically builds a reordered array of node pointers at `0x20(%rsp)` matching the indices in `intArr`, and then links them together.

The following validation loop executes starting at `4011df`:
```
4011df: 48 8b 43 08     mov     0x8(%rbx),%rax
8b 00                   mov     (%rax),%eax
39 03                   cmp     %eax,(%rbx)
7d 05                   jge     4011ee <phase_6+0xfa>
e8 4c 02 00 00          call    40143a <explode_bomb>
```
instr: `cmp %eax, (%rbx)` then compares the integer value inside the current node with the integer value of the next node.\
instr: `call 40143a <explode_bomb>` is called if the value of the current node is strictly less than the next node's value.

This means it must be the case that the linked list values are sorted in descending order after reordering.

Since the final sorted node order must correspond to the transformed indices, the nodes themselves are sorted by value in that sequence.\
Undoing the transformation step (`val_i = 7 - transformed_val_i`) yields the final correct input sequence.

if the list is correctly sorted, the program proceeds out of the validation loop, frees the stack space via instr: `add $0x50, %rsp`, and ends.

Its therefore clear that in order for a call to fcn: explode_bomb to not be called,\
Rule3: The input permutation must rearrange the linked list nodes into descending order by value

Thus Rule1, Rule2 and Rule3 conclude:\
Thus intArr has the permutation series : `[4, 3, 2, 1, 6, 5]`

This completes the analysis of phase6
