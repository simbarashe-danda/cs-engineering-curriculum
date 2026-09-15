# C — The C Programming Language

Exercises from *The C Programming Language, 2nd Edition*
Kernighan & Ritchie, Prentice Hall, 1988.

## Structure

| Module | Content |
|--------|---------|
| control-flow | Loops, conditionals, bitwise operations, loop invariants |
| io-parsing | Character I/O, state-machine text parsing, syntax validation |
| memory-pointers | Pointer arithmetic, array-pointer duality, manual allocation |

## Verification Standards

All programs validated with:
- `gcc -Wall -Wextra -Werror`
- `valgrind --leak-check=full`
- `gdb` for non-trivial debugging

## Attribution

Exercise problems are from Kernighan & Ritchie,
*The C Programming Language, 2nd Edition*.
Copyright © Brian W. Kernighan and Dennis M. Ritchie.
Used for self-study reference.

All implementations are original work.

This repository is not affiliated with or endorsed by
the authors or Prentice Hall.