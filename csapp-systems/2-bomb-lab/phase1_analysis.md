**Phase1 Reverse Engineering Analysis**

*see phase1_asm.s for commented assembly code*

instr: instruction\
fcn : function

`$0x402400` is stored in` %esi` via instr: `mov $0x402400,%esi`

A call to fcn: `strings_not_equal` is then made, which means `%esi` is passed as argument

As the name of fcn: `strings_not_equal` suggests, if two strings are not equal

It then must be the case that fcn: `strings_not_equal` compares `%esi` and the input string

For sure instr: `test %eax,%eax` is executed after calling fcn: `strings_not_equal`,

If not equal, fcn: `explode_bomb` is called; otherwise, phase1 is passed

It then must be the case that,

`$0x402400` is an address to the bomb string -> `%esi` is a pointer to the bomb string.

Hence, in gdb, `(gdb) x/s ($esi) `reveals the bomb string, that is after instr: `mov $0x402400,%esi`

`(gdb) x/s 0x402400` also reveals string right away

Which is the case

This completes analysis of phase1