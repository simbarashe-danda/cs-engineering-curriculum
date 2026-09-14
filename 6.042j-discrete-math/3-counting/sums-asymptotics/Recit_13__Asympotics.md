### 1. Asymptotic Notation

**Question:**
Which of these symbols can go in these boxes?
1. $2n + \log n = \square(n)$
2. $\log n = \square(n)$
3. $\sqrt{n} = \square(\log^{300} n)$
4. $n2^n = \square(n)$

**Solution:**
1. $2n + \log n = \Theta(n), \Omega(n)$
2. $\log n = O(n), o(n)$
3. $\sqrt{n} = \Omega(\log^{300} n), \omega(\log^{300} n)$
4. $n2^n = \Omega(n), \omega(n)$

---

### 2. Asymptotic Equivalence
Suppose $f, g: \mathbb{Z}^+ \rightarrow \mathbb{Z}^+$ and $f \sim g$.

#### 2.1 Prove that $2f \sim 2g$
**Question:** Prove that $2f \sim 2g$.

**Proof:**
By definition, for functions $f, g: \mathbb{R} \rightarrow \mathbb{R}$, we say $f(x) \sim g(x)$ if $\lim_{x \rightarrow \infty} \frac{f(x)}{g(x)} = 1$.

$$\lim_{x \rightarrow \infty} \frac{2f(x)}{2g(x)} = \lim_{x \rightarrow \infty} \frac{f(x)}{g(x)} = 1$$

Since the limit is $1$, $2f \sim 2g$. $\blacksquare$

#### 2.2 Prove that $f^2 \sim g^2$
**Question:** Prove that $f^2 \sim g^2$.

**Proof:**

$$\lim_{x \rightarrow \infty} \frac{(f(x))^2}{(g(x))^2} = \lim_{x \rightarrow \infty} \left( \frac{f(x)}{g(x)} \cdot \frac{f(x)}{g(x)} \right)$$

Since $\lim_{x \rightarrow \infty} \frac{f(x)}{g(x)} = 1$:

$$\frac{1}{1} = 1$$

Therefore, $f^2 \sim g^2$. $\blacksquare$

#### 2.3 Give examples of $f$ and $g$ such that $2^f \not\sim 2^g$
**Question:** Give examples of $f$ and $g$ such that $2^f \not\sim 2^g$.

**Proof:**
Let $f(x) = x + 1$ and $g(x) = x$.

$f \sim g$ because $\lim_{x \rightarrow \infty} \frac{x + 1}{x} = 1$.

However, $2^{x+1} \not\sim 2^x$ because:

$$\lim_{x \rightarrow \infty} \frac{2^{x+1}}{2^x} = 2 \neq 1$$

*(Note: This logic is also the same for $x^2 + x$ and $x^2$, or $x^n + x^{n-1}$ and $x^n$. For instance, $\lim_{x \rightarrow \infty} \frac{2^{x^n + x^{n-1}}}{2^{x^n}} = \lim_{x \rightarrow \infty} 2^{x^{n-1}} = \infty$.)*

$\blacksquare$

#### 2.4 Show that $\sim$ is an equivalence relation
**Question:** Show that $\sim$ is an equivalence relation.

**Proof:**
To show that $\sim$ is an equivalence relation, we need to show that for all $f, g, z: \mathbb{Z}^+ \rightarrow \mathbb{Z}^+$:
1. $f \sim f$ (Reflexive)
2. $f \sim g \implies g \sim f$ (Symmetric)
3. $f \sim g \text{ and } g \sim z \implies f \sim z$ (Transitive)

**Proof of Reflexivity:**

$$\lim_{x \rightarrow \infty} \frac{f(x)}{f(x)} = 1$$

Because the limit is $1$, $f \sim f$.

**Proof of Symmetry:**
If $f \sim g$, then $\lim_{x \rightarrow \infty} \frac{f(x)}{g(x)} = 1$.

$$\lim_{x \rightarrow \infty} \frac{g(x)}{f(x)} = \lim_{x \rightarrow \infty} \frac{1}{\left(\frac{f(x)}{g(x)}\right)} = \frac{1}{1} = 1$$

Therefore, $f \sim g \implies g \sim f$.

**Proof of Transitivity:**
If $f \sim g$ and $g \sim z$, then:

$$\lim_{x \rightarrow \infty} \frac{f(x)}{g(x)} = 1 \quad \text{and} \quad \lim_{x \rightarrow \infty} \frac{g(x)}{z(x)} = 1$$

We must show that $\lim_{x \rightarrow \infty} \frac{f(x)}{z(x)} = 1$:

$$\lim_{x \rightarrow \infty} \frac{f(x)}{z(x)} = \lim_{x \rightarrow \infty} \left( \frac{f(x)}{g(x)} \cdot \frac{g(x)}{z(x)} \right) = 1 \cdot 1 = 1$$

Therefore, $f \sim z$. $\blacksquare$

#### 2.5 Show that $\Theta$ is an equivalence relation
**Question:** Show that $\Theta$ is an equivalence relation.

**Proof:**
Assume that $f = O(g)$ if $\lim_{x \rightarrow \infty} \frac{f(x)}{g(x)} < \infty$.

Note that $f = \Theta(g)$ if $f = O(g)$ and $g = O(f)$.

Thus, $f = \Theta(g)$ if $\lim_{x \rightarrow \infty} \frac{f(x)}{g(x)} < \infty$ and $\lim_{x \rightarrow \infty} \frac{g(x)}{f(x)} < \infty$.

To prove it is an equivalence relation, we must show reflexivity, symmetry, and transitivity.

**Proof of Reflexivity:**

$$\lim_{x \rightarrow \infty} \frac{f(x)}{f(x)} = 1 < \infty$$

Then $\forall f: \mathbb{Z}^+ \rightarrow \mathbb{Z}^+$, $f = O(f) \implies f = \Theta(f)$.

**Proof of Symmetry:**
If $f = \Theta(g)$, then by definition $f = O(g)$ and $g = O(f)$.

This logically implies $g = O(f)$ and $f = O(g) \implies g = \Theta(f)$.

**Proof of Transitivity:**
If $f = \Theta(g)$ and $g = \Theta(z)$, then:

$$\lim_{x \rightarrow \infty} \frac{f(x)}{g(x)} < \infty, \quad \lim_{x \rightarrow \infty} \frac{g(x)}{f(x)} < \infty, \quad \lim_{x \rightarrow \infty} \frac{g(x)}{z(x)} < \infty, \quad \lim_{x \rightarrow \infty} \frac{z(x)}{g(x)} < \infty$$

It then follows that:

$$\lim_{x \rightarrow \infty} \frac{f(x)}{z(x)} = \lim_{x \rightarrow \infty} \left( \frac{f(x)}{g(x)} \cdot \frac{g(x)}{z(x)} \right) < \infty$$

And similarly, $\lim_{x \rightarrow \infty} \frac{z(x)}{f(x)} < \infty$.

Thus, $f = \Theta(z)$. $\blacksquare$

---

### 3. More Asymptotic Notation

#### 3.1 Show that $(an)^{1/n} \sim 1$
**Question:** Show that $(an)^{1/n} \sim 1$ where $a, n$ are positive constants. *(Hint: $an = a2^{\log_2 n}$)*

**Proof:**
By definition of $\sim$, we need to show that $\lim_{n \rightarrow \infty} (an)^{1/n} = 1$.

Using the hint, $an = a \cdot 2^{\log_2 n}$.

$$\lim_{n \rightarrow \infty} (an)^{1/n} = \lim_{n \rightarrow \infty} \left( a^{1/n} \cdot 2^{\frac{\log_2 n}{n}} \right)$$

Because $\frac{1}{n} \rightarrow 0$ and $\frac{\log_2 n}{n} \rightarrow 0$ as $n \rightarrow \infty$:

$$\lim_{n \rightarrow \infty} a^{1/n} \cdot 2^{\frac{\log_2 n}{n}} = a^0 \cdot 2^0 = 1 \cdot 1 = 1$$

This completes the proof that $(an)^{1/n} \sim 1$. $\blacksquare$

#### 3.2 Show that $\sqrt[n]{n!} = \Theta(n)$
**Question:** Show that $\sqrt[n]{n!} = \Theta(n)$. *(You may assume that if $f(n) \ge 1$ and $g(n) \ge 1$ for all $n$, then $f \sim g \implies f^{1/n} \sim g^{1/n}$.)*

**Proof:**
We need to prove that $\sqrt[n]{n!} = \Theta(n)$, which means $(n!)^{1/n} = \Theta(n)$.

By Stirling's approximation, $n! \sim \sqrt{2\pi n} \left(\frac{n}{e}\right)^n$.

Then, using the assumption:

$$(n!)^{1/n} \sim (2\pi n)^{\frac{1}{2n}} \cdot \left(\frac{n}{e}\right)$$

From 3.1, we know $(an)^{1/n} \sim 1$. Let $a = 2\pi$ and apply it, we get $(2\pi n)^{\frac{1}{2n}} \sim 1$.

Then:

$$(n!)^{1/n} \sim 1 \cdot \frac{n}{e} = \frac{n}{e}$$

This means:

$$\lim_{n \rightarrow \infty} \frac{(n!)^{1/n}}{n/e} = 1 \quad \text{--- (1)}$$

To prove $(n!)^{1/n} = \Theta(n)$, we need to show $(n!)^{1/n} = O(n)$ and $n = O((n!)^{1/n})$.

Note that:

$$\lim_{n \rightarrow \infty} \frac{(n!)^{1/n}}{n} = \lim_{n \rightarrow \infty} \left( \frac{(n!)^{1/n}}{n/e} \cdot \frac{1}{e} \right)$$

From (1), this evaluates to $1 \cdot \frac{1}{e} = \frac{1}{e}$.

Since $\frac{1}{e} < \infty$, then $(n!)^{1/n} = O(n)$.

Now evaluate:

$$\lim_{n \rightarrow \infty} \frac{n}{(n!)^{1/n}} = \lim_{n \rightarrow \infty} \left( \frac{n/e}{(n!)^{1/n}} \cdot e \right) = 1 \cdot e = e$$

Since $e < \infty$, then $n = O((n!)^{1/n})$.

Therefore, $\sqrt[n]{n!} = \Theta(n)$. $\blacksquare$