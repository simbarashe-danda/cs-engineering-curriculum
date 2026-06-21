# Recitation 12: Solutions

## 1. The L-Tower Problem

> **Question:** Observe the structures shown in Figure 1. One has 2 L-shapes, the other 5 L-shapes. Consider a tower with $k$ L-shapes. Assume that the blocks are all of size $x \times 1$ where $x > 1$. As the picture indicates, if $k$ is too small then the tower falls to the left. On the other hand, if $k$ is too large the tower would fall to the right. Will the tower be stable for some $k$? Prove there is at least one value of $k$ for which the L-tower is stable. Assume that a structure is stable if and only if its center of gravity is not hanging in the air horizontally. The L-tower is stable if and only if each of its subparts is stable.
>
> *Hint: Show the tower is stable if and only if $\frac{3x-3}{2} \le k \le \frac{3x-1}{2}$.*

### Solution

Assume a vertical and horizontal block is $x \times 1$.

1. Let $L_0$ be the first bottom L-shape.
2. Let the x-axis range of the horizontal block of $L_0$ be $[-x, 0]$.
3. Since the vertical block of $L_0$ starts at $-x$, let the range of the vertical block of $L_0$ be $[-x, -x+1]$.
4. It follows that the center of mass of $L_0$ is:
   $$X_{com} = \frac{-3x+1}{4}$$
   (using COMs of vertical and horizontal block).
5. Since the base vertical block ends at 0, let the range of the Base be $[-1, 0]$.

**Claim:** If $k$ is too small, then the tower falls to the left.
Let $k=1$ and $x=4$.
Then $X_{com} = -11/4$.
Since $-11/4 < -1$, $X_{com}$ is strictly to the left of the edge of the Base. It follows that the tower will truly fall to the left.

Let the center of mass of $k$ L-shapes be $X_{com}(k)$.
First, notice that as we stack the L-shapes, they are shifted to the right relative to the one below.
Then:
$L_1: [-x+1, 1]$ (horizontal)
$L_2: [-x+1, 2]$ (horizontal)
...
$L_n: [-x+n, n]$ (horizontal)

Consequently, the COM of each L-shape is also shifted right by 1 relative to the L below.
Let $C_0$ be COM of $L_0$.
Then:
$C_1 = C_0 + 1$
$C_2 = C_0 + 2$
...
$C_n = C_0 + n$

Then:
$$X_{com}(k) = \frac{1}{k} (C_0 + C_0 + 1 + C_0 + 2 + \dots + C_0 + k)$$
$$X_{com}(k) = \frac{1}{k} \left( k \cdot C_0 + \sum_{i=1}^{k-1} i \right)$$

Using summation formula, then:
$$X_{com}(k) = C_0 + \frac{k-1}{2}$$
From (3), then:
$$X_{com}(k) = \frac{2k - 3x + 1}{4}$$

From (4), then:
$$-1 \le \frac{2k - 3x + 1}{4} \le 0$$
Then $-4 + 3x + 1 \le 2k \Rightarrow 3x - 3 \le 2k$.
Then:
$$\frac{3x-3}{2} \le k$$

Because the L-tower is stable if each of its subparts is stable, if $k$ becomes too large, the tower falls to the right. The pivot point for falling here, however, is the right edge of $L_0$.
Then the top $k-1$ sitting on $L_0$ need to be stable.
Then $X_{com}(\text{top } k-1) = \sum_{i=1}^{k-1} (C_0 + i)$
Then $X_{com}(\text{top } k-1) = \frac{(k-1)C_0 + \frac{k(k-1)}{2}}{k-1} = C_0 + \frac{k}{2}$.
For the top $k-1$ to be stable, $X_{com}(\text{top } k-1)$ must not exceed the right edge of $L_0$, which is 0.
Then $C_0 + \frac{k}{2} \le 0$.
From (3): $-3x + 1 + 2k \le 0$.
Thus:
$$k \le \frac{3x-1}{2}$$

---

## 2. Double Sums

> **Question:** Evaluate the following summations:
> 1. $\sum_{i=1}^{n} \sum_{j=1}^{i} j$
> 2. $\sum_{k=1}^{n} H_k$ (where $H_k = \sum_{j=1}^k \frac{1}{j}$)

### Solution (Part 1)

**Summation Table:**
$i$ ranges from $1$ to $n$.
$j$ ranges from $1$ to $i$.

We can write out the sum:
$\sum_{i=1}^n \frac{i(i+1)}{2}$
$= \frac{1}{2} \sum_{i=1}^n (i^2 + i)$
$= \frac{1}{2} \left[ \frac{n(n+1)(2n+1)}{6} + \frac{n(n+1)}{2} \right]$
$= \frac{n(n+1)}{4} \left[ \frac{2n+1}{3} + 1 \right]$
$= \frac{n(n+1)}{4} \left[ \frac{2n+4}{3} \right]$
$= \frac{n(n+1)(2n+4)}{12}$
$= \frac{n(n+1)(n+2)}{6}$

### Solution (Part 2)

**Harmonic Sums:**
Because the $k$-th harmonic number is $H_k = \sum_{j=1}^k \frac{1}{j}$,
Then $\sum_{k=1}^n H_k = \sum_{k=1}^n \sum_{j=1}^k \frac{1}{j}$.

From the table:
We can conclude that the term $\frac{1}{j}$ appears $n - j + 1$ times.
We know that $\sum_{k=1}^n H_k = \sum_{k=1}^n \sum_{j=1}^k \frac{1}{j}$ is summing each row then adding the row sums.
However, by summing columns then adding column sums, we get:
$\sum_{k=1}^n H_k = \sum_{j=1}^n \sum_{k=j}^n \frac{1}{j}$.
This follows (1). Hence the above sum is summing the term $\frac{1}{j}$, $n - j + 1$ times.

It then follows that:
$$\sum_{k=1}^n H_k = \sum_{j=1}^n \frac{1}{j} (n - j + 1)$$
$$= \sum_{j=1}^n \frac{n+1}{j} - \sum_{j=1}^n 1$$
$$= \sum_{j=1}^n \frac{n+1}{j} - n$$
$$= (n+1) \sum_{j=1}^n \frac{1}{j} - n$$

Because $H_n = \sum_{j=1}^n \frac{1}{j}$,
Then:
$$\sum_{k=1}^n H_k = (n+1)H_n - n$$