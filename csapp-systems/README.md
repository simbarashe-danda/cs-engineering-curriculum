# CS:APP Labs

Self-study implementations and writeups for the CS:APP\
(Computer Systems: A Programmer's Perspective) lab sequence,\
completed as part of an independent MIT 6-3 curriculum study.

## Labs Completed


| Lab | Description | Status |
|-----|-------------|--------|
| Data Lab | Bit manipulation puzzles | ✓ |
| Bomb Lab | Binary reverse engineering, 6 phases | ✓ |
| Attack Lab | Buffer overflow exploitation, ROP | ✓ |
| Performance Lab | Cache-aware optimization, 84.5x smooth speedup | ✓ |
| Cache Lab | In progress | ... |
| Shell Lab | Pending | ... |
| Malloc Lab | Pending | ... |


## Methodology

**Bomb and Attack Lab:** Paper-first reverse engineering.\
Full assembly analysis on paper before touching GDB.\
GDB used for hypothesis verification only, not exploration.

**Performance Lab:** Iterative profiling with explicit reasoning\
about cache behavior, function call cost, and memory access patterns\
before each optimization attempt.

## Environment

- OS: Ubuntu 22.04 (WSL2)\
- Hardware: ThinkPad E16 Core i5 13th gen\
- Compiler: GCC 11, flags per lab specification

## Attribution

The lab infrastructure, binaries, driver programs, and baseline\
implementations in this repository are the work of:

**Randal E. Bryant and David R. O'Hallaron**
*Computer Systems: A Programmer's Perspective, 3rd Edition*
Carnegie Mellon University\
https://csapp.cs.cmu.edu

All reverse engineering writeups, optimization implementations,\
analysis documents, and methodology descriptions are original work\
produced through independent study.

Shared for educational purposes. No lab solutions are provided\
in a form that trivially bypasses the learning objective.

## License

Original lab infrastructure: copyright Bryant & O'Hallaron,\
Carnegie Mellon University. Used under academic fair use.

Original work in this repository (writeups, optimized kernels,\
analysis): MIT License.