# Performance Lab — Optimization Analysis

## Overview

Implementation and optimization of image rotate and smooth kernels
for the CS:APP Performance Lab. All optimizations applied on top of
gcc -O2 baseline.

## Hardware

- Machine: ThinkPad E16 Core i5 13th gen
- Cache line size: 64 bytes
- Compiler flags: gcc -Wall -O2 -m32

## Rotate Optimizations

### Problem

90-degree rotation accesses destination memory non-sequentially —
one dimension steps by full row width, producing cache misses at
large dimensions.

### Approach

**Block tiling (16x16):** Process 16x16 sub-matrices to exploit
spatial locality. Block size chosen to fit within L1 cache based
on 64-byte cache lines × 4 bytes per int = 16 elements per line.

**Eliminate boundary function calls:** Removed min/max calls from
hot loop by handling boundary regions separately.

### Results

| Dim | Naive CPE | Optimized CPE | Speedup |
|-----|-----------|---------------|---------|
| 64  | 1.0       | 1.1           | 13.1x   |
| 128 | 1.4       | 1.2           | 34.6x   |
| 256 | 4.0       | 1.3           | 36.8x   |
| 512 | 5.1       | 1.5           | 42.6x   |
| 1024| 8.3       | 2.3           | 40.8x   |
| **Mean** |  |  | **31.1x** |

## Smooth Optimizations

### Problem

Naive smooth calls avg() per pixel — 9 function calls per interior
pixel, each with stack setup, struct allocation, and boundary checking.

### opt1 Approach

- Separate boundary regions (corners, edges, interior) to eliminate
  min/max boundary checks from hot loop
- Remove pixel_sum struct and accumulate_sum abstraction
- Eliminate pixel and pixel_sum creation inside loop

**Result: 50.0x mean speedup**

### opt2 Approach (on top of opt1)

- Fully inline all pixel accumulation — zero function calls in hot loop
- Replace struct field access via function with direct field arithmetic
- Eliminate multiplication in indexing — use additive offset arithmetic
  (src[i+dim], src[i-dim]) instead of RIDX(i±1, j±1, dim)
- Direct RGB channel accumulation into int locals kept in registers
- Only remaining operation cost: division by 9 (compiler converts
  to reciprocal multiply at -O2)

**Result: 84.5x mean speedup**

### Results

| Dim | Naive CPE | opt1 CPE | opt2 CPE | Best Speedup |
|-----|-----------|----------|----------|--------------|
| 32  | 23.9      | 14.2     | 8.0      | 84.9x        |
| 64  | 24.6      | 14.9     | 10.0     | 68.9x        |
| 128 | 23.4      | 13.8     | 8.0      | 86.3x        |
| 256 | 19.7      | 13.8     | 8.2      | 86.5x        |
| 512 | 19.8      | 13.9     | 7.8      | 92.5x        |
| **Mean** |  |  |  | **84.5x** |

## Key Lessons

1. Cache line alignment determines optimal block size — not arbitrary
2. Abstraction layers (functions, structs) have measurable cost in
   performance-critical loops
3. Compiler (-O2) handles instruction scheduling and register allocation;
   memory access patterns and function call elimination are left to the
   programmer
4. Boundary region separation trades code length for branch elimination
   in the hot path