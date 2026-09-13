Phase1 Reverse Engineering Analysis
instr: instruction
fcn : function

A hex value, which i will call hval is stored in %esi via instr: mov hval,%esi 

A call to fcn:strings_not_equal is then made, which means %esi is passed as argument

As the name of fcn:strings_not_equal suggests, if two strings are not equal

It then must be the case that fcn:strings_not_equal compares %esi and the input string

For sure instr:test %eax,%eax is executed after calling fcn:strings_not_equal,

If not equal, fcn:explode_bomb is called; otherwise, phase1 is passed

It then must be the case that,

hval is an address to the bomb string -> %esi is a pointer to the bomb string.

Hence, in gdb, (gdb) x/s ($esi) reveals the bomb string, that is after the instr: mov hval,%esi

(gdb) x/s ADDR also reveals string right away

Which is the case

This completes analysis of phase1