# Core Systems Engineering Foundation

**Engineer:** Simbarashe Danda  
**Grade:** Year 1  
**Location:** Zimbabwe  
**Objective:** A rigorous, self-directed 4-year Computer Science and Engineering curriculum.

## Overview
This repository serves as the central, verifiable proof-of-work for my foundational engineering studies. My primary focus is on low-level systems programming, strict memory management, algorithm complexity, and the discrete mathematical proofs that govern computational theory. I prioritize raw execution and theoretical mastery over high-level abstractions.

## Curriculum Architecture

The repository is strictly structured by mathematical and engineering domains, with explicit conceptual scopes for Year 1:

### ⚙️ Systems Engineering & Architecture
* **`csapp-systems/`**: C and x86-64 assembly implementations. 
  * `/data-lab/`: Bit-level manipulations, integer/floating-point representation limits.
  * `/bomb-lab/`: Executable reverse engineering, x86-64 assembly, program counter tracing.
  * `/machine-programming/`: Stack frames, procedure calls, and memory layouts.
* **`c-k&r/`**: Rigorous problem sets from *The C Programming Language* (K&R).
  * `/io-parsing/`: Character I/O, state-machine text parsing, syntax validation.
  * `/memory-pointers/`: Direct memory addressing, array/pointer duality, manual block allocation.
  * `/control-flow/`: Bitwise operations, low-level data structures, and loop invariants.
* **`cpp-primer/`**: Object-oriented systems and standard template library (STL) mastery.
  * `/memory-management/`: RAII principles, smart pointers, and dynamic allocation.
  * `/object-oriented/`: Class abstractions, inheritance, and polymorphism.
  * `/stl-structures/`: Generic programming, iterators, and container implementations.

### 📐 Theoretical Computer Science & Mathematics
* **`6.042j-discrete-math/`**: Formal mathematical proofs and discrete computational theory.
  * `/01-proofs/`: Propositions, proof patterns, mathematical induction, and number theory.
  * `/02-structures/`: Graph theory, directed graphs, relations, partial orders, and state machines.
  * `/03-counting/`: Sums, asymptotics, recurrences, cardinality rules, generating functions, and infinite sets.
  * `/04-probability/`: Events, probability spaces, conditional probability, independence, random variables, expectation, deviations, and random walks.
* **`18.01-calculus-1/`**: Single-variable calculus.
  * `/differentiation/`: Limits, derivatives, rates of change, optimization.
  * `/integration/`: Fundamental Theorem of Calculus, Riemann sums, areas.
  * `/series-approximations/`: Taylor series, asymptotic behavior.
* **`8.01-physics-1/`**: Classical mechanics and mathematical physics.
  * `/kinematics-dynamics/`: Newtonian mechanics, reference frames, force analysis.
  * `/conservation-laws/`: Work, mechanical energy, linear momentum.
  * `/rotational-mechanics/`: Torque, angular momentum, rigid body dynamics.

### 🐍 Algorithmic Problem Solving
* **`6.1010-python-labs/`**: Algorithmic labs and core data structure implementations.
  * `/environment-model/`: Variable scoping, memory frames, aliasing, and mutability.
  * `/recursive-structures/`: Tree traversals, graph search, and recursive reduction.
  * `/complexity-analysis/`: Asymptotic bounds, algorithm timing, optimization.

## Execution Standards
1. **Mathematical Rigor:** No algorithm is considered complete without a stated invariant, and tight-bound time/space complexity under the standard RAM model.
2. **Systems Realism:** C code must be validated against memory leaks, undefined behavior, and segfaults using `valgrind`, `gdb`, and `strace` in a WSL2/Ubuntu environment.
3. **Proof Strategy:** Discrete math proofs rely on first principles, strong induction, and formal state machine invariants. 

---
*Committing to high-performance engineering for global execution.*
