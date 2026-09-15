# Problem Set 8: Divide-and-Conquer & Linear Recurrences 

## Notes: Akra-Bazzi Theorem (Strong Form)

Suppose that $T(x) = \sum_{i=1}^{k} a_i T(b_i x + h_i(x)) + g(x)$ for $x > x_0$ where:
 
*   $a_1, a_2, \dots, a_k$ are positive constants
*   $b_1, b_2, \dots, b_k$ are constants between 0 and 1
*   $x_0$ is "large enough"
*   $|g'(x)| = O(x^c)$ for some $c \in \mathbb{N}$
*   $|h_i(x)| = O(x / \log^2 x)$

Then

$$T(x) = \Theta\left(x^p \left(1 + \int_{1}^{x} \frac{g(u)}{u^{p+1}} du\right)\right)$$

where $p$ satisfies the equation $\sum_{i=1}^{k} a_i b_i^p = 1$.

---

## Problem 1

Find $\Theta$ bounds for the following divide-and-conquer recurrences. Assume $T(1) = 1$ in all cases. Show your work.

### Part (a)

> $T(n) = 8T(\lfloor n/2 \rfloor) + n$

**Solution:**

$a_1 = 8$, $b_1 = \frac{1}{2}$, `g(n) = n`.

$$a_1 = 8$$
$$b_1 = \frac{1}{2}$$
$$g(n) = n$$

$g'(n) = 1 \implies g'(n) = O(x^0)$.
$h_1(x) = \lfloor \frac{n}{2} \rfloor - \frac{n}{2} \le 1$.

We find $p$ such that $\sum_{i=1}^{k} a_i b_i^p = 1$.

$$8 \cdot \left(\frac{1}{2}\right)^p = 1$$
$$p = 3$$

Then by Akra-Bazzi:

$$T(x) = \Theta\left(x^3 \left(1 + \int_{1}^{x} \frac{u}{u^4} du\right)\right)$$

Integrating:

$$\int_{1}^{x} u^{-3} du = \left[ \frac{u^{-2}}{-2} \right]_{1}^{x} = \left(-\frac{1}{2x^2}\right) - \left(-\frac{1}{2(1)^2}\right) = -\frac{1}{2x^2} + \frac{1}{2}$$

Then:

$$T(x) = \Theta\left(-\frac{x}{2} + \frac{1}{2}x^3\right)$$

Dropping linear growth terms and constants: $T(x) = \Theta(x^3)$.

Thus, $T(n) = \Theta(n^3)$.

$$\boxed{T(n) = \Theta(n^3)}$$

$\square$

### Part (b)

> $T(n) = 2T(\lfloor n/8 \rfloor + 1/n) + n$

**Solution:**

$a_1 = 2$, $b_1 = \frac{1}{8}$, `g(x) = n`.

$$a_1 = 2$$
$$b_1 = \frac{1}{8}$$
$$g(x) = n$$

Notice that $h_1(x) = \lfloor \frac{n}{8} \rfloor - \frac{n}{8} + \frac{1}{n} \le 1, \forall n \ge 1$.

We want $p$ such that $2 \cdot \left(\frac{1}{8}\right)^p = 1$.

**Theorem from lecture:** If $g(x) = \Theta(x^t)$ for $t > 0$ and $\sum_{i=1}^{k} a_i b_i^t < 1$, then $T(x) = \Theta(g(x))$.

Since $2 \cdot \left(\frac{1}{8}\right)^1 = \frac{1}{4} < 1$, it follows that:

$$T(n) = \Theta(n)$$

$$\boxed{T(n) = \Theta(n)}$$

$\square$

### Part (c)

> $T(n) = 7T(\lfloor n/20 \rfloor) + 2T(\lfloor n/8 \rfloor) + n$

**Solution:**

$a_1 = 7$, $a_2 = 2$, $b_1 = \frac{1}{20}$, $b_2 = \frac{1}{8}$, `g(x) = n`.

$$a_1 = 7, \quad a_2 = 2$$
$$b_1 = \frac{1}{20}, \quad b_2 = \frac{1}{8}$$
$$g(x) = n$$

We want $p$ such that $7 \cdot \left(\frac{1}{20}\right)^p + 2 \cdot \left(\frac{1}{8}\right)^p = 1$.

Since we know $g(x) = \Theta(x^t)$ and we want to check if $\sum_{i=1}^{k} a_i b_i^t < 1$:

Let $t=1$: $7\left(\frac{1}{20}\right) + 2\left(\frac{1}{8}\right) = 0.35 + 0.25 = 0.6 < 1$.

Hence, with $t=1$, the theorem holds.

It follows that $T(n) = \Theta(g(x)) = \Theta(n)$.

$$\boxed{T(n) = \Theta(n)}$$

$\square$

### Part (d)

> $T(n) = 2T(\lfloor n/4 \rfloor + 1) + n^{1/2}$

**Solution:**

$a_1 = 2$, $b_1 = \frac{1}{4}$, `g(x) = n^(1/2)`.

$$a_1 = 2$$
$$b_1 = \frac{1}{4}$$
$$g(x) = n^{1/2}$$

$h_1(x) = \lfloor \frac{n}{4} \rfloor - \frac{n}{4} + 1 \le 1$.

Thus $h_1(x) = O(x / \log^2 x)$.

We want $p$ such that $2 \cdot \left(\frac{1}{4}\right)^p = 1$.

$2 \cdot \left(\frac{1}{4}\right)^{\frac{1}{2}} = 1$, so $p = \frac{1}{2}$.

Then:

$$T(x) = \Theta\left(x^{\frac{1}{2}} \left(1 + \int_{1}^{x} \frac{u^{\frac{1}{2}}}{u^{\frac{1}{2}+1}} du\right)\right)$$

Integrating:

$$\frac{u^{\frac{1}{2}}}{u^{\frac{3}{2}}} = u^{-1}$$
$$\int \frac{1}{u} du = \ln|u|$$
$$[\ln|u|]_{1}^{x} = \ln|x| - \ln(1) = \ln|x|$$

Then $T(x) = \Theta(x^{\frac{1}{2}} \ln|x| + x^{\frac{1}{2}})$.

Dropping low growth terms:

$$T(n) = \Theta(\sqrt{n} \log n)$$

$$\boxed{T(n) = \Theta(\sqrt{n} \log n)}$$

$\square$

### Part (e)

> $T(n) = 3T(\lfloor n/9 + n^{1/9} \rfloor) + 1$

**Solution:**

$a_1 = 3$, $b_1 = \frac{1}{9}$, `g(x) = 1`.

$$a_1 = 3$$
$$b_1 = \frac{1}{9}$$
$$g(x) = 1$$

$h_1(x) = \lfloor \frac{n}{9} \rfloor - \frac{n}{9} + n^{1/9}$.

Verification that $h_1(x) = O(x/\log^2 x)$:

$$\lim_{x \to \infty} \frac{\lfloor x/9 \rfloor - x/9 + x^{1/9}}{x / \log^2 x} = \lim_{x \to \infty} \frac{\log^2 x \cdot (\lfloor x/9 \rfloor - x/9) + \log^2 x \cdot x^{1/9}}{x}$$

Notice that $\lfloor x/9 \rfloor - x/9 \le 1 \ \forall x \ge 0$.

Let $S(x) = \lfloor x/9 \rfloor - \frac{x}{9}$.

$$\lim_{x \to \infty} \frac{\log^2 x \cdot S(x)}{x} + \frac{\log^2 x \cdot x^{1/9}}{x}$$

For both fractions, $x$ grows faster. Hence the limit approaches $0$.

Thus $h_1(x) = O(x / \log^2 x)$.

We want $p$ such that $3 \cdot \left(\frac{1}{9}\right)^p = 1$.

Therefore $p = \frac{1}{2}$, since $3 \cdot \left(\frac{1}{9}\right)^{\frac{1}{2}} = 1$.

Then:

$$T(x) = \Theta\left(x^{\frac{1}{2}} \left(1 + \int_{1}^{x} \frac{1}{u^{3/2}} du\right)\right)$$

Integrating:

$$\int u^{-3/2} du = \frac{u^{-1/2}}{-1/2} = -2u^{-1/2} = -\frac{2}{\sqrt{u}}$$
$$\left[ -\frac{2}{\sqrt{x}} \right]_{1}^{x} = \left(-\frac{2}{\sqrt{x}}\right) - (-2) = 2 - \frac{2}{\sqrt{x}}$$

$T(x) = \Theta(3x^{\frac{1}{2}} - 2)$.

Dropping constants:

$$T(n) = \Theta(n^{\frac{1}{2}}) = \Theta(\sqrt{n})$$

$$\boxed{T(n) = \Theta(\sqrt{n})}$$

$\square$

---

## Problem 2

It is easy to misuse induction when working with asymptotic notation.
**False Claim:** If $T(1) = 1$ and $T(n) = 4T(n/2) + n$, then $T(n) = O(n)$.

### Part (a)

> Identify the flaw in the proof.

**Solution:**

By definition $f = O(g)$ if there is a constant $c > 0$ such that $\forall n \ge n_0, f(n) \le c \cdot g(n)$.

If $T(n) = O(n)$ then we know $|T(n)| \le c \cdot n$ (using the fixed constant).

Notice that the inductive hypothesis assumes $T(n/2) = O(n/2) \implies T(n/2) \le c(n/2)$.

Because $T(n) = 4T(n/2) + n$:

$$T(n) \le 4c(n/2) + n \implies T(n) \le (2c + 1)n$$

Because $c \neq 2c + 1$ for any $c > 0$, this does not prove $T(n) = O(n)$.

*(Note: If $n=1, n_0=1$, then $n/2 < n_0$, so it cannot be legally invoked. Assume $n \ge 2n_0$ so that $P(n/2)$ can be legally applied).*

$\square$

### Part (b)

> A simple attempt to prove $T(n) \neq O(n)$ via induction ultimately fails. We assume for sake of contradiction that $T(n) = O(n)$. Then there exists positive integer $n_0$ and positive real number $c$ such that for all $n \ge n_0$, $T(n) \le cn$. We then define $P(n)$ as the proposition that $T(n) \le cn$. Fill in the rest of this proof attempt, and explain why it doesn't work.

**Solution:**

We know that $T(n) = 4T(n/2) + n$.

Then by $P(n/2)$:

$$T(n) \le 4c(n/2) + n$$
$$T(n) \le (2c + 1)n$$

We need to find a contradiction that $T(n) \le cn$.

Since by our assumption $c > 0$, then $T(n) \le (2c + 1)n$ is a true statement.

We can't establish a contradiction from it.

$\square$

### Part (c)

> Using Akra-Bazzi theorem, find the correct asymptotic behavior of this recurrence.

**Solution:**

Using the Akra-Bazzi theorem, $a_1 = 4$, $b_1 = \frac{1}{2}$, `g(n) = n`.

$$a_1 = 4$$
$$b_1 = \frac{1}{2}$$
$$g(n) = n$$

We need $p$ such that $4 \cdot \left(\frac{1}{2}\right)^p = 1$. Then $p = 2$.

By Akra-Bazzi:

$$T(x) = \Theta\left(x^2 \left(1 + \int_{1}^{x} \frac{u}{u^3} du\right)\right)$$

Integrating: $\frac{u}{u^3} = u^{-2}$

$$\int u^{-2} du = -\frac{1}{u}$$
$$\left[ -\frac{1}{u} \right]_{1}^{x} = \left(-\frac{1}{x}\right) - (-1) = 1 - \frac{1}{x}$$

Then $T(x) = \Theta(x^2(2 - 1/x)) = \Theta(2x^2 - x)$.

Dropping linear terms, thus $T(n) = \Theta(n^2)$.

$$\boxed{T(n) = \Theta(n^2)}$$

$\square$

### Part (d)

> Find the relationship between $a$ and $b$ that yields $T(n) = O(n)$ for $T(n) = aT(\lfloor n/b \rfloor) + n$, and prove that this is sufficient.

**Solution:**

Claim: For a recurrence of the form $aT(\lfloor n/b \rfloor) + n$ to yield $T(n) = O(n)$, it must be the case that $a < b$.

**Proof:**

Notice that $a_1 = a$, $b_1 = \frac{1}{b}$, `g(n) = n` for `T(⌊n/b⌋) + n`.

$$a_1 = a$$
$$b_1 = \frac{1}{b}$$
$$g(n) = n$$

$h_1(n) = \lfloor n/b \rfloor - n/b \le 1$, where $a$ and $b$ are positive constants.

Notice that, if $a < b$, then $a \cdot (1/b) < 1$.

**Theorem (from lecture):** If $g(x) = \Theta(x^t)$ for $t > 0$ and $\sum_{i=1}^{k} a_i b_i^t < 1$, then $T(x) = \Theta(g(x))$.

We know $g(n) = \Theta(n)$ where $t = 1$.

Hence for $k=1$ and $t=1$, $a \cdot (1/b) < 1$.

It follows that $T(n) = \Theta(n)$.

Thus $a < b$ is sufficient. This completes the proof.

$\square$

---

## Problem 3

> Define the sequence of numbers $A_i$ by: $A_0 = 2$, $A_{n+1} = A_n/2 + 1/A_n$ (for $n \ge 1$). Prove that $A_n \le \sqrt{2} + 1/2^n$ for all $n \ge 0$.

**Solution:**

Proof by Induction. Let $P(n)$ be the proposition.

**Base Case:** $P(0)$

$A_0 = 2 \le \sqrt{2} + 1/2^0 = \sqrt{2} + 1$. Holds.

**Inductive Step:**

Assume $P(n)$ holds. For the purpose of induction substitution, we need a lower bound $A_{low}$ such that $A_{low} \le A_{n-1} \implies \frac{1}{A_{low}} \ge \frac{1}{A_n}$.

Using the Arithmetic-Geometric Mean (AM-GM) inequality for non-negative real numbers $x + y \ge 2\sqrt{xy}$:

Let $x = A_{n-1}/2$ and $y = 1/A_{n-1}$.

Then $A_n = \frac{A_{n-1}}{2} + \frac{1}{A_{n-1}} \ge 2\sqrt{\left(\frac{A_{n-1}}{2} \cdot \frac{1}{A_{n-1}}\right)}$.

Then $A_n \ge 2\frac{1}{\sqrt{2}} = \sqrt{2}$.

Thus $\sqrt{2}$ is a lower bound.

Then $\sqrt{2} \le A_n \le \sqrt{2} + \frac{1}{2^n}$ by $P(n)$ and the lower bound.

We now show $P(n+1)$:

$$A_{n+1} = \frac{A_n}{2} + \frac{1}{A_n}$$
$$A_{n+1} \le \frac{\sqrt{2} + \frac{1}{2^n}}{2} + \frac{1}{\sqrt{2}} \quad \text{(Since } A_n \ge \sqrt{2} \implies \frac{1}{A_n} \le \frac{1}{\sqrt{2}}\text{)}$$
$$A_{n+1} \le \frac{\sqrt{2}}{2} + \frac{1}{2^{n+1}} + \frac{\sqrt{2}}{2}$$
$$A_{n+1} \le \sqrt{2} + \frac{1}{2^{n+1}}$$

$\implies P(n+1)$. This completes the Inductive Step and the proof follows from it.

$\square$

---

## Problem 4

Find closed-form solutions to the following linear recurrences.

### Part (a)

> $x_n = 4x_{n-1} - x_{n-2} - 6x_{n-3}$ with initial conditions `x_0 = 3`, `x_1 = 4`, `x_2 = 14`.

**Solution:**

Try $x_n = \alpha^n$ for a constant $\alpha$.

Then:

$$\alpha^n - 4\alpha^{n-1} + \alpha^{n-2} + 6\alpha^{n-3} = 0$$

Dividing by $\alpha^{n-3}$:

$$\alpha^3 - 4\alpha^2 + \alpha + 6 = 0$$

One of the roots is $\alpha = 2$ since $2^3 - 4(2)^2 + 2 + 6 = 0$.

Finding other roots by polynomial division:

$$(\alpha^3 - 4\alpha^2 + \alpha + 6) / (\alpha - 2) = \alpha^2 - 2\alpha - 3$$

Therefore:

$$(\alpha - 2)(\alpha^2 - 2\alpha - 3) = 0$$

Factorizing:

$$\alpha^2 - 2\alpha - 3 = (\alpha - 3)(\alpha + 1)$$

The roots are:

$$\alpha_1 = 2, \quad \alpha_2 = 3, \quad \alpha_3 = -1$$

We know that if $f(n) = \alpha^n$ is a solution, then $x_n = C_1(2)^n + C_2(3)^n + C_3(-1)^n$ is also a solution.

Using boundary conditions:

$$x_0 = 3 \implies C_1 + C_2 + C_3 = 3 \quad \text{(Eq 1)}$$
$$x_1 = 4 \implies 2C_1 + 3C_2 - C_3 = 4 \quad \text{(Eq 2)}$$
$$x_2 = 14 \implies 4C_1 + 9C_2 + C_3 = 14 \quad \text{(Eq 3)}$$

Solving the system:

Adding Eq 1 and Eq 2:

$$(C_1 + C_2 + C_3) + (2C_1 + 3C_2 - C_3) = 3 + 4$$
$$3C_1 + 4C_2 = 7 \quad \text{(Eq A)}$$

Adding Eq 2 and Eq 3:

$$(2C_1 + 3C_2 - C_3) + (4C_1 + 9C_2 + C_3) = 4 + 14$$
$$6C_1 + 12C_2 = 18$$
$$C_1 + 2C_2 = 3 \quad \text{(Eq B)}$$

Solving for $C_1$ and $C_2$:

Multiplying Eq B by 2 gives:

$$2C_1 + 4C_2 = 6$$

Subtracting from Eq A:

$$(3C_1 + 4C_2) - (2C_1 + 4C_2) = 7 - 6$$
$$C_1 = 1$$

Substituting into Eq B:

$$1 + 2C_2 = 3$$
$$C_2 = 1$$

Substituting into Eq 1:

$$1 + 1 + C_3 = 3$$
$$C_3 = 1$$

Thus:

$$\boxed{x_n = 2^n + 3^n + (-1)^n}$$

$\square$

### Part (b)

> $x_n = -x_{n-1} + 2x_{n-2} + n$ with initial conditions `x_0 = 5`, `x_1 = -4/9`.

**Solution:**

Finding homogenous solutions:

Solving $x_n + x_{n-1} - 2x_{n-2} = 0$. Try $x_n = \alpha^n$.

Then:

$$\alpha^n + \alpha^{n-1} - 2\alpha^{n-2} = 0$$

Dividing by $\alpha^{n-2}$:

$$\alpha^2 + \alpha - 2 = 0$$

The roots are:

$$\alpha_1 = -2 \quad \text{and} \quad \alpha_2 = 1$$

Then:

$$x_n^{(h)} = C_1(-2)^n + C_2(1)^n$$

Finding particular solutions to $x_n = -x_{n-1} + 2x_{n-2} + n$:

Since $f(n) = n$ is a polynomial of degree 1, the standard base guess is $an+b$.

By the multiplicity rule, since 1 is a root of the characteristic equation with multiplicity 1, we must multiply our guess by $n$.

Guess:

$$x_n^{(p)} = n(an+b) = an^2 + bn$$

Then:

$$an^2 + bn = -[a(n-1)^2 + b(n-1)] + 2[a(n-2)^2 + b(n-2)] + n$$

Expanding:

$$an^2 + bn = -(an^2 - 2an + a + bn - b) + 2(an^2 - 4an + 4a + bn - 2b) + n$$

Simplifying:

$$an^2 + bn = -an^2 + 2an - a - bn + b + 2an^2 - 8an + 8a + 2bn - 4b + n$$
$$an^2 + bn = an^2 + (2a - 8a - b + 2b + 1)n + (-a + b + 8a - 4b)$$
$$bn = n(-6a + b + 1) + (7a - 3b)$$

Equating coefficients:

$$b = -6a + b + 1 \implies 6a = 1 \implies a = 1/6 = 3/18$$
$$0 = 7a - 3b \implies 3b = 7(1/6) \implies b = 7/18$$

Thus:

$$x_n^{(p)} = \frac{3n^2 + 7n}{18}$$

Adding particular and homogenous solutions gives the General Solution:

$$x_n = C_1(-2)^n + C_2 + \frac{3n^2 + 7n}{18}$$

Using boundary conditions:

$$x_0 = C_1 + C_2 = 5 \implies C_2 = 5 - C_1 \quad \text{(Eq 1)}$$

$$x_1 = -2C_1 + C_2 + \frac{3+7}{18} = -4/9$$
$$-2C_1 + C_2 + 10/18 = -8/18$$
$$-2C_1 + C_2 = -1 \quad \text{(Eq 2)}$$

From (1) and (2):

$$-2C_1 + (5 - C_1) = -1$$
$$-3C_1 = -6$$
$$C_1 = 2$$

$$C_2 = 5 - 2 = 3$$

Thus:

$$\boxed{x_n = 3 + 2(-2)^n + \frac{3n^2 + 7n}{18}}$$

$\square$
