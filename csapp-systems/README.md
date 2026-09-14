# CS:APP — Computer Systems

Labs and implementations from
*Computer Systems: A Programmer's Perspective, 3rd Edition*
Bryant & O'Hallaron, Carnegie Mellon University.

Following the ICS+ course sequence (15-213).
Chapter 4 skipped — covered separately in 6.004/6.1910.

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

**Reverse engineering:** Paper-first analysis before GDB.
Full assembly read on paper, hypothesis formed, GDB used
for verification only.

**Optimization:** Explicit reasoning about cache behavior,
function call cost, and memory access patterns before each
optimization attempt.

## Environment

- OS: Ubuntu 24.04.4 LTS (WSL2)
- Compiler: GCC 13.3.0
- Tools: GDB, Valgrind, gcc -Wall -Wextra -Werror

## Attribution

Lab infrastructure, binaries, baseline implementations, and
driver programs are copyright Randal E. Bryant and David R.
O'Hallaron, Carnegie Mellon University.
https://csapp.cs.cmu.edu

All writeups, optimized implementations, and analysis are
original work.