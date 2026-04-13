# Core Systems Engineering Foundation

**Engineer:** Simbarashe Danda  
**Location:** Zimbabwe 
**Objective:** A rigorous, self-directed 4-year Computer Science and Engineering curriculum.

## Overview
This repository serves as the central, verifiable proof-of-work for my foundational engineering studies. My primary focus is on low-level systems programming, strict memory management, algorithm complexity, and the discrete mathematical proofs that govern computational theory. I prioritize raw execution and theoretical mastery over high-level abstractions.

## Curriculum Architecture

The repository is strictly structured by mathematical and engineering domains:

### ⚙️ Systems Engineering & Architecture
* **`csapp-systems/`**: C and x86-64 assembly implementations. Includes bit-level manipulations (Data Lab) and executable reverse engineering (Bomb Lab).
* **`c-k&r/`**: Rigorous problem sets from *The C Programming Language* (K&R), focusing on memory safety, pointers, and custom text parsing.
* **`cpp-primer/`**: Object-oriented systems and standard template library (STL) mastery.

### 📐 Theoretical Computer Science & Mathematics
* **`6.042j-discrete-math/`**: Formal mathematical proofs.
  * `/number-theory/`: Modular arithmetic, primality.
  * `/graph-theory/`: Coloring, matching, bipartite graphs.
  * `/state-machines/`: Invariant derivation and finite state modeling.
* **`18.01-calculus-1/`**: Single-variable calculus, limits, and derivatives.
* **`8.01-physics-1/`**: Classical mechanics, conservation laws, and mathematical physics.

### 🐍 Algorithmic Problem Solving
* **`6.1010-python-labs/`**: Algorithmic labs and core data structure implementations.

## Execution Standards
1. **Mathematical Rigor:** No algorithm is considered complete without a stated invariant, and tight-bound time/space complexity under the standard RAM model.
2. **Systems Realism:** C code must be validated against memory leaks, undefined behavior, and segfaults using `valgrind`, `gdb`, and `strace` in a WSL2/Ubuntu environment.
3. **Proof Strategy:** Discrete math proofs rely on first principles, strong induction, and formal state machine invariants. 

---
*Committing to high-performance engineering for global execution.*
