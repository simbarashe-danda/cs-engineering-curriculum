# Data Lab — Bit Manipulation Analysis

## Overview

Implementation of integer and floating-point functions using
restricted operator sets, as specified by the CS:APP Data Lab.

## Constraints

- Integer puzzles: limited operators (`! ~ & ^ | + << >>`), no loops,
  no conditionals, operator count limit per puzzle
- Floating-point puzzles: relaxed constraints, no integer division

## Approach

Each puzzle requires reasoning about the bit-level representation
of values directly from CS:APP Chapter 2 — two's complement integers,
IEEE 754 floating point, and boolean algebra.

Key principles applied:

**Two's complement arithmetic:**
Negation via `~x + 1`. Sign bit isolation via arithmetic right shift.
Overflow detection via sign bit analysis.

**Bit masking:**
Constructing masks from shift operations to isolate or manipulate
specific bit ranges without using disallowed operators.

**IEEE 754 structure:**
Separating sign (bit 31), exponent (bits 30-23), and mantissa
(bits 22-0) via masking and shifting for floating-point puzzles.

## Key Insight

The operator restrictions force reasoning at the level the CPU
actually operates — no arithmetic shortcuts, no conditionals hiding
branch instructions. Every solution is a proof that the bit
manipulation produces the correct result for all inputs.

## Environment

- Compiler: gcc -O1
- Verified with: `./btest` (correctness), `./dlc` (operator compliance)