# CS Engineering Foundation — Year 1

**Engineer:** Simbarashe Danda
**Year:** 1 of 4
**Location:** Zimbabwe
**Curriculum:** Self-directed MIT 6-3 (EECS) — independent study

## Overview

This repository is the verifiable record of my foundational computer
science and engineering studies, following the MIT 6-3 curriculum
independently. Focus areas: low-level systems programming, memory
management, algorithm design and correctness, and the discrete
mathematics that underlies computational theory.

## Repository Structure

### Systems Engineering

**`csapp-systems/`** — C and x86-64 assembly, following
*Computer Systems: A Programmer's Perspective* (Bryant & O'Hallaron)

| Directory | Content |
|-----------|---------|
| `1-data-lab/` | Bit manipulation, integer and floating-point representation |
| `2-bomb-lab/` | Binary reverse engineering, assembly analysis, GDB |
| `3-attack-lab/` | Buffer overflow exploitation, return-oriented programming |
| `4-performance-lab/` | Cache-aware optimization, CPE benchmarking |
| `5-cache-lab/` | Cache simulator, matrix transpose optimization |
| `6-hell-lab/` | Unix shell implementation |
| `7-malloc-lab/` | Dynamic memory allocator |

**`c-k&r/`** — Problem sets from *The C Programming Language*
(Kernighan & Ritchie)

| Directory | Content |
|-----------|---------|
| `io-parsing/` | Character I/O, text parsing, syntax validation |
| `memory-pointers/` | Pointer arithmetic, array-pointer duality |
| `control-flow/` | Bitwise operations, loop invariants |

**`cpp-primer/`** — C++ and object-oriented systems

| Directory | Content |
|-----------|---------|
| `object-oriented/` | Classes, inheritance, polymorphism |
| `memory-management/` | RAII, smart pointers, dynamic allocation |
| `stl-structures/` | Generic programming, iterators, containers |

---

### Theoretical Computer Science & Mathematics

**`6.042j-discrete-math/`** — Formal proofs and discrete theory,
following MIT 6.042J (Leighton, 2010)

| Directory | Content |
|-----------|---------|
| `1-proofs/` | Induction, number theory, proof techniques, state machines |
| `2-structures/` | Graph theory, relations, partial orders |
| `3-counting/` | Sums, asymptotics, recurrences |
| `4-probability-theory/` | Random variables, expectation, deviation bounds |

**`18.01-calculus/`** — Single-variable calculus (MIT 18.01SC)

| Directory | Content |
|-----------|---------|
| `1-differentiation/` | Limits, derivatives, optimization |
| `2-integration/` | Fundamental theorem, Riemann sums |

**`8.01-physics/`** — Classical mechanics (Lewin + Ohanian)

| Directory | Content |
|-----------|---------|
| `1-kinematics-dynamics/` | Newtonian mechanics, force analysis |
| `2-conservation-laws/` | Work, energy, momentum |
| `3-rotational-mechanics/` | Torque, angular momentum |

---

### Algorithmic Problem Solving

**`6.1010-python-labs/`** — Algorithm design and implementation,
MIT 6.1010: Fundamentals of Programming

| Directory | Content |
|-----------|---------|
| Labs | Image processing, graph search, state-space search, SAT solver |

---

## Standards

**Correctness:** Every non-trivial algorithm includes a stated
invariant and time/space complexity justification under the RAM model.

**Systems verification:** C code validated with `valgrind`,
`gcc -Wall -Wextra -Werror`, and `gdb` under WSL2/Ubuntu.

**Proof discipline:** Discrete mathematics proofs constructed from
first principles — base case, inductive hypothesis, and inductive
step stated explicitly. No hand-waving accepted.

## Attribution

Course materials, lab infrastructure, and textbook content referenced
throughout this repository are the intellectual property of their
respective authors and institutions. See individual module READMEs
for specific attribution.

All implementations, proofs, writeups, and analysis are original work
unless explicitly noted.