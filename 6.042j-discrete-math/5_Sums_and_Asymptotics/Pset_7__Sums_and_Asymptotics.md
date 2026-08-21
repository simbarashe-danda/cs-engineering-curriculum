# Problem Set 7

### Problem 1

> **Question:** Express $\sum_{i=0}^{n} i^{2}x^{i}$ as a closed-form function of $n$.[cite: 1]

**Solution:**
We know that the sum of a geometric series is given by:
$$ \sum_{i=0}^{n} x^{i} = \frac{1-x^{n+1}}{1-x} $$
Taking the derivative of both sides with respect to $x$:[cite: 2]
$$ \frac{d}{dx} \left( \sum_{i=0}^{n} x^{i} \right) = \frac{d}{dx} \left( \frac{1-x^{n+1}}{1-x} \right) $$
**LHS:**
$$ \sum_{i=0}^{n} \frac{d}{dx} (x^{i}) = \sum_{i=0}^{n} i x^{i-1} $$
**RHS:**
$$ \frac{d}{dx} \left( \frac{1-x^{n+1}}{1-x} \right) = \frac{-(n+1)x^{n}(1-x) - (1-x^{n+1})(-1)}{(1-x)^{2}} = \frac{1 - (n+1)x^{n} + n x^{n+1}}{(1-x)^{2}} $$
Multiplying both sides by $x$, we get:
$$ \sum_{i=0}^{n} i x^{i} = \frac{x - (n+1)x^{n+1} + n x^{n+2}}{(1-x)^{2}} $$
Differentiating both sides again:
**LHS:**
$$ \frac{d}{dx} \left( \sum_{i=0}^{n} i x^{i} \right) = \sum_{i=0}^{n} i^{2} x^{i-1} $$
**RHS:**
$$ \frac{d}{dx} \left( \frac{x - (n+1)x^{n+1} + n x^{n+2}}{(1-x)^{2}} \right) $$
Expanding the numerator and grouping terms from the quotient rule yields:
$$ \frac{1 + x - (n+1)^{2}x^{n} + (2n^{2}+2n-1)x^{n+1} - n^{2}x^{n+2}}{(1-x)^{3}} $$
Multiplying by $x$ once more gives the final closed form:
$$ \sum_{i=0}^{n} i^{2}x^{i} = \frac{x + x^{2} - (n+1)^{2}x^{n+1} + (2n^{2}+2n-1)x^{n+2} - n^{2}x^{n+3}}{(1-x)^{3}} $$
[cite: 2]

---

### Problem 2

> **Question 2(a):** What is the product of the first $n$ odd powers of two: $\prod_{k=1}^{n} 2^{2k-1}$?[cite: 1]

**Solution 2(a):**
Using the exponent law $a^{b} \cdot a^{c} = a^{b+c}$:[cite: 2]
$$ \prod_{k=1}^{n} 2^{2k-1} = 2^{\sum_{k=1}^{n} (2k-1)} $$
Evaluating the exponent sum:
$$ \sum_{k=1}^{n} (2k-1) = 2 \sum_{k=1}^{n} k - \sum_{k=1}^{n} 1 $$
$$ = 2 \left( \frac{n(n+1)}{2} \right) - n $$
$$ = n^{2} + n - n = n^{2} $$
Therefore, the product is:
$$ \prod_{k=1}^{n} 2^{2k-1} = 2^{n^{2}} $$
*(Note: An alternative method using integration to find closed-form bounds was also explored by taking $\ln(P) = \sum_{k=1}^{n} \ln(2^{2k-1})$ and bounding the sum with integrals, yielding the bounds $2^{n^2-n}+2 \le \prod_{k=1}^n 2^{2k-1} \le 2^{n^2-n} + 2^{2n-1}$.)*[cite: 2]

> **Question 2(b):** Find a closed expression for $\sum_{i=0}^{n} \sum_{j=0}^{m} 3^{i+j}$[cite: 1]

**Solution 2(b):**
Evaluating the inner sum first:[cite: 2]
$$ \sum_{j=0}^{m} 3^{i+j} = 3^{i} \sum_{j=0}^{m} 3^{j} $$
Using the geometric series formula $S_{n} = a \frac{r^{k}-1}{r-1}$ with $a=1$, $r=3$, and $k=m+1$:
$$ \sum_{j=0}^{m} 3^{j} = \frac{3^{m+1}-1}{2} $$
Substituting this back into the outer sum:
$$ \sum_{i=0}^{n} \sum_{j=0}^{m} 3^{i+j} = \sum_{i=0}^{n} 3^{i} \left( \frac{3^{m+1}-1}{2} \right) $$
$$ = \left( \frac{3^{m+1}-1}{2} \right) \left( \sum_{i=0}^{n} 3^{i} \right) $$
$$ = \left( \frac{3^{m+1}-1}{2} \right) \left( \frac{3^{n+1}-1}{2} \right) $$
$$ = \frac{3^{m+n+2} - 3^{m+1} - 3^{n+1} + 1}{4} $$
[cite: 2]

> **Question 2(c):** Find a closed expression for $\sum_{i=1}^{n} \sum_{j=1}^{n} (i+j)$[cite: 1]

**Solution 2(c):**
Evaluating the inner sum:[cite: 2]
$$ \sum_{j=1}^{n} (i+j) = \sum_{j=1}^{n} i + \sum_{j=1}^{n} j = ni + \frac{n(n+1)}{2} $$
Substituting back into the outer sum:
$$ \sum_{i=1}^{n} \left( ni + \frac{n(n+1)}{2} \right) = n \sum_{i=1}^{n} i + \sum_{i=1}^{n} \frac{n(n+1)}{2} $$
$$ = n \left( \frac{n(n+1)}{2} \right) + n \left( \frac{n(n+1)}{2} \right) $$
$$ = \frac{n^{2}(n+1)}{2} + \frac{n^{2}(n+1)}{2} = n^{2}(n+1) $$
[cite: 2]

> **Question 2(d):** Find a closed expression for $\prod_{i=1}^{n} \prod_{j=1}^{n} 2^{i} \cdot 3^{j}$[cite: 1]

**Solution 2(d):**
Using the exponent rule $a^{b} \cdot a^{c} = a^{b+c}$:[cite: 2]
$$ \prod_{j=1}^{n} 2^{i} \cdot 3^{j} = 2^{\sum_{j=1}^{n} i} \cdot 3^{\sum_{j=1}^{n} j} $$
Evaluating the exponents:
$$ \sum_{j=1}^{n} i = ni \quad \text{and} \quad \sum_{j=1}^{n} j = \frac{n(n+1)}{2} $$
Then:
$$ \prod_{i=1}^{n} \prod_{j=1}^{n} 2^{i} \cdot 3^{j} = \prod_{i=1}^{n} \left( 2^{ni} \cdot 3^{\frac{n(n+1)}{2}} \right) $$
$$ = 2^{\sum_{i=1}^{n} ni} \cdot 3^{\sum_{i=1}^{n} \frac{n(n+1)}{2}} $$
$$ = 2^{n \frac{n(n+1)}{2}} \cdot 3^{n \frac{n(n+1)}{2}} $$
$$ = 2^{\frac{n^{2}(n+1)}{2}} \cdot 3^{\frac{n^{2}(n+1)}{2}} = 6^{\frac{n^{2}(n+1)}{2}} $$
[cite: 2]

---

### Problem 3

> **Question 3(a):** Use integration to find upper and lower bounds that differ by at most 0.1 for the following sum: $\sum_{i=1}^{\infty} \frac{1}{(2i+1)^{2}}$[cite: 1]

**Solution 3(a):**
By splitting the sum:[cite: 2]
$$ \sum_{i=1}^{\infty} \frac{1}{(2i+1)^{2}} = \left( \sum_{i=1}^{k} \frac{1}{(2i+1)^{2}} \right) + \sum_{i=k+1}^{\infty} \frac{1}{(2i+1)^{2}} $$
Let $f(x) = \frac{1}{(2x+1)^{2}}$. Because $f(x)$ is a monotonically decreasing function, we can trap the infinite tail between upper and lower integral bounds:
$$ \int_{k+1}^{\infty} f(x) dx \le \sum_{i=k+1}^{\infty} \frac{1}{(2i+1)^{2}} \le \int_{k}^{\infty} f(x) dx $$
Let the total upper bound $U(k)$ be:
$$ U(k) = \sum_{i=1}^{k} \frac{1}{(2i+1)^{2}} + \int_{k}^{\infty} \frac{1}{(2x+1)^{2}} dx $$
Let the total lower bound $L(k)$ be:
$$ L(k) = \sum_{i=1}^{k} \frac{1}{(2i+1)^{2}} + \int_{k+1}^{\infty} \frac{1}{(2x+1)^{2}} dx $$
Isolating the difference:
$$ U(k) - L(k) = \int_{k}^{\infty} \frac{1}{(2x+1)^{2}} dx - \int_{k+1}^{\infty} \frac{1}{(2x+1)^{2}} dx $$
Computing the integral $\int_{k}^{\infty} \frac{1}{(2x+1)^{2}} dx$:
$$ \lim_{t \to \infty} \int_{k}^{t} \frac{1}{(2x+1)^{2}} dx $$
Let $u = 2x+1 \implies du = 2 dx$. Boundaries become $2k+1$ to $2t+1$.
$$ \frac{1}{2} \lim_{t \to \infty} \int_{2k+1}^{2t+1} u^{-2} du = \frac{1}{2} \lim_{t \to \infty} \left[ -\frac{1}{u} \right]_{2k+1}^{2t+1} $$
$$ = \frac{1}{2} \lim_{t \to \infty} \left( -\frac{1}{2t+1} + \frac{1}{2k+1} \right) = \frac{1}{2(2k+1)} = \frac{1}{4k+2} $$
Computing $\int_{k+1}^{\infty} \frac{1}{(2x+1)^{2}} dx$:
Using the same steps with new boundaries $2k+3$ to $2t+1$:
$$ \frac{1}{2} \lim_{t \to \infty} \left( -\frac{1}{2t+1} + \frac{1}{2k+3} \right) = \frac{1}{2(2k+3)} = \frac{1}{4k+6} $$
[cite: 2]

> **Question 3(b):** Assume $n$ is an integer larger than 1. Which of the following inequalities, if any, hold.[cite: 1]
> 1. $\sum_{i=1}^{n} \ln(i+1) \le \int_{0}^{n} \ln(x+2) dx$ 
> 2. $\sum_{i=1}^{n} \ln(i+1) \le \ln 2 + \int_{1}^{n} \ln(x+1) dx$ 

**Solution 3(b):**
**Determining if Inequality 1 holds:**[cite: 2]
Let $i$ be an arbitrary integer such that $1 \le i \le n$. Define the continuous subinterval for integration as $x \in [i-1, i]$. Because $f(x) = \ln(x)$ is a strictly increasing function across its domain, if $a \ge b$, then $f(a) \ge f(b)$.
Within this interval, it must be the case that $\ln(i+1) \le \ln(x+2)$.
Integrating both sides with respect to $x$:
$$ \int_{i-1}^{i} \ln(i+1) dx \le \int_{i-1}^{i} \ln(x+2) dx $$
Evaluating the LHS: $\ln(i+1) \int_{i-1}^{i} 1 dx = \ln(i+1)$. Thus, $\ln(i+1) \le \int_{i-1}^{i} \ln(x+2) dx$.
Applying summation to both sides:
$$ \sum_{i=1}^{n} \ln(i+1) \le \sum_{i=1}^{n} \int_{i-1}^{i} \ln(x+2) dx $$
By the additivity property of definite integrals, the sum of these adjacent integrals equals the integral over the entire range:
$$ \sum_{i=1}^{n} \ln(i+1) \le \int_{0}^{n} \ln(x+2) dx $$
Therefore, the original inequality **HOLDS**.

**Determining if Inequality 2 holds:**
$$ \sum_{i=1}^{n} \ln(i+1) \le \ln 2 + \int_{1}^{n} \ln(x+1) dx $$
Subtracting $\ln 2$ from both sides simplifies the LHS sum:
$$ \sum_{i=2}^{n} \ln(i+1) \le \int_{1}^{n} \ln(x+1) dx $$
Let $i$ be an arbitrary integer such that $2 \le i \le n$. Define the interval as $x \in [i-1, i]$. Because $\ln(x)$ is strictly increasing, $\ln(x+1) \le \ln(i+1)$.
Integrating both sides:
$$ \int_{i-1}^{i} \ln(x+1) dx \le \ln(i+1) $$
Summing both sides:
$$ \sum_{i=2}^{n} \int_{i-1}^{i} \ln(x+1) dx \le \sum_{i=2}^{n} \ln(i+1) $$
Consolidating the integrals gives $\int_{1}^{n} \ln(x+1) dx \le \sum_{i=2}^{n} \ln(i+1)$.
Because the inequality bounds in the opposite direction, the original inequality **DOES NOT HOLD**.
[cite: 2]

---

### Problem 4

> **Question 4(a):** There is a bug on the edge of a 1-meter rug. It crawls at 1 cm per second. At the end of each second the rug stretches uniformly by 1 meter. During second $i$, what fraction of the rug does the bug cross?[cite: 1]

**Solution 4(a):**
Let $L_{0}$ be the initial length of the rug ($L_{0} = 100 \text{ cm}$). Let $i$ be an arbitrary second in the future ($i \in [1, \infty)$). Then the total length of the rug at second $i$ is $L = L_{0}i$.[cite: 2]
Because for all $i$, the bug crawls exactly 1 cm, the fraction of the rug the bug crosses during second $i$ is:
$$ \frac{1}{L} = \frac{1}{L_{0}i} = \frac{1}{100i} $$
[cite: 2]

> **Question 4(b):** Over the first $n$ seconds, what fraction of the rug does the bug cross altogether? Express your answer in terms of the Harmonic number $H_{n}$[cite: 1]

**Solution 4(b):**
The total fraction crossed over the first $n$ seconds is the sum of fractions crossed during each second:[cite: 2]
$$ \sum_{i=1}^{n} \frac{1}{L_{0}i} = \frac{1}{L_{0}} \sum_{i=1}^{n} \frac{1}{i} = \frac{1}{L_{0}} H_{n} = \frac{H_{n}}{100} $$
where $H_{n}$ is the $n$-th harmonic number. *(Note: Because the stretch is uniform, the stretch itself does not change the fraction of the rug the bug has already crossed.)*[cite: 2]

> **Question 4(c):** Approximately how many seconds does the bug need to cross the entire rug?[cite: 1]

**Solution 4(c):**
For the bug to cross the entire rug, the total fraction crossed must be 1.[cite: 2]
$$ \frac{H_{n}}{100} = 1 \implies H_{n} = 100 $$
We know that $H_{n} \approx \ln(n)$.
$$ \ln(n) \approx 100 \implies n \approx e^{100} $$
Therefore, it takes approximately $e^{100}$ seconds.
[cite: 2]

---

### Problem 5

> **Question:** For each of the following pairs of functions, state which order-of-growth relations hold ($o, O, \omega, \Omega, \Theta, \sim$):[cite: 1]

**Solution:**
Definitions used:[cite: 2]
*   $f = o(g)$ if $\lim_{x \to \infty} f(x)/g(x) = 0$
*   $f = O(g)$ if $\exists c > 0, x_{0}$ s.t. $\forall x > x_{0}, |f(x)| \le c|g(x)|$
*   $f = \Omega(g)$ if $\exists c > 0, x_{0}$ s.t. $\forall x > x_{0}, |f(x)| \ge c|g(x)|$
*   $f = \omega(g)$ if $\lim_{x \to \infty} g(x)/f(x) = 0$
*   $f = \Theta(g)$ if $f = O(g)$ and $f = \Omega(g)$
*   $f \sim g$ if $\lim_{x \to \infty} f(x)/g(x) = 1$

**(a) $f(n) = \log_{2} n, \quad g(n) = \log_{10} n$**
$$ \log_{2} n = \frac{\log_{10} n}{\log_{10} 2} $$
Taking the limit of the ratio:
$$ \lim_{n \to \infty} \frac{\log_{2} n}{\log_{10} n} = \lim_{n \to \infty} \frac{\frac{\log_{10} n}{\log_{10} 2}}{\log_{10} n} = \frac{1}{\log_{10} 2} \approx 3.32 $$
Since the limit is a non-zero constant, $f = O(g)$, $f = \Omega(g)$, and $f = \Theta(g)$ all hold.

**(b) $f(n) = 2^{n}, \quad g(n) = 10^{n}$**
$$ \lim_{n \to \infty} \frac{2^{n}}{10^{n}} = \lim_{n \to \infty} \left( \frac{2}{10} \right)^{n} = 0 $$
Since the limit is 0, $f = o(g)$ and $f = O(g)$ hold.

**(c) $f(n) = 0, \quad g(n) = 17$**
$$ \lim_{n \to \infty} \frac{0}{17} = 0 $$
Since the limit is 0, $f = o(g)$ and $f = O(g)$ hold.

**(d) $f(n) = 1 + \cos(\frac{\pi n}{2}), \quad g(n) = 1 + \sin(\frac{\pi n}{2})$**
Using limits, $\lim_{n \to \infty} f(n)/g(n)$ does not exist.
Checking $f = O(g)$ definition: We need $c > 0$ such that $1 + \cos(\frac{\pi n}{2}) \le c(1 + \sin(\frac{\pi n}{2}))$.
This constant $c$ does not exist when $n \equiv 3 \pmod 4$, because $\sin(\frac{3\pi}{2}) = -1$ (making $g(n)=0$) while $\cos(\frac{3\pi}{2}) = 0$ (making $f(n)=1$). $1 \le c(0)$ fails. So $O$ and $o$ do not hold.
Checking $f = \Omega(g)$: Fails when $n \equiv 2 \pmod 4$ because $\cos(\pi) = -1$ (making $f(n)=0$) while $\sin(\pi) = 0$ (making $g(n)=1$). $0 \ge c(1)$ fails. So $\Omega$ and $\omega$ do not hold.
Hence, **none of the relations hold**.

**(e) $f(n) = 1.00000000001^{n}, \quad g(n) = n^{100000000000}$**
Because any exponential function where the base $> 1$ will eventually strictly outgrow any polynomial $n^{k}$:
$$ \lim_{n \to \infty} \frac{c^{n}}{n^{k}} = \infty $$
Therefore, $f = \omega(g)$ and $f = \Omega(g)$ hold.
[cite: 2]

---

### Problem 6

> **Question 6(a):** Evaluate the asymptotic relations for $n!$ and $(n+1)!$.[cite: 1]

**Solution 6(a):**
Taking the limit of their ratio:[cite: 2]
$$ \lim_{n \to \infty} \frac{n!}{(n+1)!} = \lim_{n \to \infty} \frac{1}{n+1} = 0 $$
Since the limit is 0, $n! = o((n+1)!)$ and $n! = O((n+1)!)$ hold. The other statements ($\Omega, \omega, \Theta$) do not hold.[cite: 2]

> **Question 6(b):** Show that $n! = \omega \left( \left(\frac{n}{3}\right)^{n+e} \right)$[cite: 1]

**Solution 6(b):**
To show this, we need to prove that:[cite: 2]
$$ \lim_{n \to \infty} \frac{\left( \frac{n}{3} \right)^{n+e}}{n!} = 0 $$
By Stirling's approximation, $n! \sim \sqrt{2\pi n} \left( \frac{n}{e} \right)^{n}$.
$$ \lim_{n \to \infty} \frac{\left( \frac{n}{3} \right)^{n+e}}{\sqrt{2\pi n} \left( \frac{n}{e} \right)^{n}} = \lim_{n \to \infty} \frac{1}{\sqrt{2\pi n}} \left( \left(\frac{n}{3}\right)^{n+e} \cdot \left(\frac{e}{n}\right)^{n} \right) $$
Grouping by base and canceling $n^{n}$:
$$ \lim_{n \to \infty} \frac{1}{\sqrt{2\pi n}} \left( n^{e} \cdot \frac{1}{3^{n+e}} \cdot e^{n} \right) = \lim_{n \to \infty} \left( \frac{n^{e}}{\sqrt{n}} \cdot \frac{1}{3^{n+e}} \cdot e^{n} \right) \frac{1}{\sqrt{2\pi}} $$
Since $3^{e}$ is a constant:
$$ \lim_{n \to \infty} \left( n^{e - \frac{1}{2}} \cdot \left(\frac{e}{3}\right)^{n} \right) \frac{1}{3^{e}\sqrt{2\pi}} $$
Evaluating the limits of the individual parts: $e/3 \approx 0.906$, so $(e/3)^{n} \rightarrow 0$. $n^{e - 0.5} \approx n^{2.218} \rightarrow \infty$.
We know that any exponential decay $(c^{n}$ for $c < 1)$ will eventually dominate polynomial growth, therefore:
$$ \lim_{n \to \infty} \left( n^{2.218...} \cdot 0.906...^{n} \right) = 0 $$
This completes the proof.[cite: 2]

> **Question 6(c):** Show that $n! = \Omega(2^{n})$[cite: 1]

**Solution 6(c):**
For $f = \Omega(g)$, we need to show that there exists $c > 0$ and $n_{0}$ such that $n! \ge c 2^{n}$ for all $n > n_{0}$.[cite: 2]
We can express $n!$ as a product:
$$ n! = \prod_{k=1}^{n} k = 1 \cdot \prod_{k=2}^{n} k $$
For all terms $k$ in the remaining product, $k \ge 2$. Thus, we can establish a strict lower bound:
$$ \prod_{k=2}^{n} k \ge \prod_{k=2}^{n} 2 = 2^{n-1} $$
Substituting this back into the original expression:
$$ n! \ge 1 \cdot 2^{n-1} $$
Which simplifies to:
$$ n! \ge \frac{1}{2} 2^{n} $$
We have shown that $n! \ge c 2^{n}$ for $c = \frac{1}{2}$, confirming $n! = \Omega(2^{n})$.[cite: 2]