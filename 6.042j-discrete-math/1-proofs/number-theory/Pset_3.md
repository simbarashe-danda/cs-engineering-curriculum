# Problem Set 3

## Problem 3

**(a)** An integer $n$ is a square modulo $p$ if there exists another integer $x$ such that $n \equiv x^2 \pmod{p}$. Prove that $x^2 \equiv y^2 \pmod{p}$ if and only if $x \equiv y \pmod{p}$ or $x \equiv -y \pmod{p}$.

### Proof

**Case 1 $(\Rightarrow)$:** Prove $x^2 \equiv y^2 \pmod{p} \implies x \equiv y \pmod{p}$ or $x \equiv -y \pmod{p}$.

$x^2 \equiv y^2 \pmod{p}$ means $p \mid (x^2 - y^2)$. Factoring:

$$p \mid (x+y)(x-y)$$

By Euclid's lemma, since $p$ is prime:

$$p \mid (x+y) \quad \text{or} \quad p \mid (x-y)$$

$$\therefore \quad x \equiv -y \pmod{p} \quad \text{or} \quad x \equiv y \pmod{p}$$

---

**Case 2 $(\Leftarrow)$:** Prove $x \equiv y \pmod{p}$ or $x \equiv -y \pmod{p} \implies x^2 \equiv y^2 \pmod{p}$.

We know $p \mid (x-y)$ or $p \mid (x+y)$. If $p$ divides at least one, then $p$ divides their product:

$$(x-y)(x+y) = x^2 - y^2$$

$$\therefore \quad p \mid (x^2 - y^2) \implies x^2 \equiv y^2 \pmod{p}$$

Both directions proved. $\blacksquare$

---

**(b)** **Theorem 1 (Euler's Criterion).**

1. If $n$ is a square modulo $p$ then $n^{\frac{p-1}{2}} \equiv 1 \pmod{p}$.
2. If $n$ is not a square modulo $p$ then $n^{\frac{p-1}{2}} \equiv -1 \pmod{p}$.

Prove part (1).

### Proof

Since $n$ is a square mod $p$, $\exists\, x$ such that $n \equiv x^2 \pmod{p}$. Raise both sides to the power $\frac{p-1}{2}$:

$$n^{\frac{p-1}{2}} \equiv x^{2 \cdot \frac{p-1}{2}} \equiv x^{p-1} \pmod{p}$$

By Fermat's Little Theorem, if $p$ is prime and $\gcd(x, p) = 1$, then $x^{p-1} \equiv 1 \pmod{p}$.

**Sub-proof: $\gcd(x, p) = 1$ (by contradiction).**

Assume $p \mid x$. Then $x^2 \equiv 0 \pmod{p}$, so $n \equiv 0 \pmod{p}$. But Euler's Criterion requires $\gcd(n, p) = 1$, so $n \not\equiv 0 \pmod{p}$. Contradiction. Hence $\gcd(x, p) = 1$.

$$\therefore \quad x^{p-1} \equiv 1 \pmod{p} \implies n^{\frac{p-1}{2}} \equiv 1 \pmod{p}$$

$\blacksquare$

---

**(c)** Assume $p \equiv 3 \pmod{4}$ and $n \equiv x^2 \pmod{p}$. Given $n$ and $p$, find one possible value of $x$.

### Proof

Since $p \equiv 3 \pmod{4}$, write $p = 4k+3$. By Euler's Criterion (part 1):

$$n^{\frac{p-1}{2}} \equiv 1 \pmod{p}$$

**Algebraic manipulation:**

$$n^{\frac{(4k+3)-1}{2}} = n^{\frac{4k+2}{2}} \equiv 1 \pmod{p}$$

Multiply both sides by $n$:

$$n^{\frac{4k+4}{2}} \equiv n \pmod{p}$$

Since $n \equiv x^2 \pmod{p}$:

$$n^{\frac{4k+4}{2}} \equiv x^2 \pmod{p}$$

**Factor the exponent using $p = 4k+3 \implies k = \frac{p-3}{4}$:**

$$n^{2 \cdot \frac{2k+2}{2}} = n^{2 \cdot \frac{p+1}{4}} \equiv x^2 \pmod{p}$$

By part (a), one valid solution is:

$$\boxed{x \equiv n^{\frac{p+1}{4}} \pmod{p}}$$

$\blacksquare$

---

## Problem 4

Prove that for any prime $p$ and integer $k \ge 1$:

$$\phi(p^k) = p^k - p^{k-1}$$

where $\phi$ is Euler's totient function.

### Proof

An integer $m \in \{0, 1, \ldots, p^k - 1\}$ satisfies $\gcd(m,\, p^k) > 1$ if and only if $p \mid m$ (since $p$ is the only prime factor of $p^k$). The multiples of $p$ in this range are:

$$p,\quad 2p,\quad 3p,\quad \ldots,\quad p^{k-1} \cdot p = p^k$$

There are exactly $p^{k-1}$ such multiples. The remaining $p^k - p^{k-1}$ integers are coprime to $p^k$, so:

$$\phi(p^k) = p^k - p^{k-1}$$

$\blacksquare$
