# CS:APP — Computer Systems

Labs following *Computer Systems: A Programmer's Perspective,
3rd Edition* (US), Randal E. Bryant and David R. O'Hallaron,
Carnegie Mellon University.

ICS+ course sequence (CMU 15-213). Chapter 4 skipped —
covered separately via 6.004/6.1910.

## Labs

| Lab | Description | Status |
|-----|-------------|--------|
| 1-data-lab | Bit manipulation, integer and float representation | ✓ |
| 2-bomb-lab | Binary reverse engineering, 6 phases | ✓ |
| 3-attack-lab | Code injection and ROP exploitation | ✓ |
| 4-performance-lab | Cache-optimized kernels, 84.5x smooth speedup | ✓ |
| 5-cache-lab | Cache simulator, matrix transpose optimization | ... |
| 6-shell-lab | Unix shell with job control | ... |
| 7-malloc-lab | Dynamic memory allocator | ... |
| 8-proxy-lab | Concurrent web proxy | ... |

## Methodology

**Reverse engineering:** Full assembly analysis on paper before
touching GDB. GDB used for hypothesis verification only.

**Optimization:** Explicit reasoning about cache behavior and
memory access patterns before each optimization attempt.

## Environment

- OS: Ubuntu 24.04.4 LTS (WSL2)
- Compiler: GCC 13.3.0
- Tools: GDB, Valgrind, gcc -Wall -Wextra -Werror

## Attribution and License

Lab infrastructure, binaries, driver programs, and baseline
implementations are copyright © Randal E. Bryant and David R.
O'Hallaron, Carnegie Mellon University. All rights reserved.
https://csapp.cs.cmu.edu

The CS:APP labs are distributed for educational use.
This repository does not redistribute lab binaries or
copyrighted course materials. Only original work is included:
reverse engineering writeups, optimized kernel implementations,
and analysis documents.

Original work in this module is licensed under the MIT License.
See `LICENSE` in this directory.

This repository is not affiliated with or endorsed by
Carnegie Mellon University.