# Recitation 16: Combinatorics and Proofs

### Question 2: Triangles
**Question:**
Let $T = \{X_1, \dots, X_t\}$ be a set whose elements $X_i$ are themselves sets such that each $X_i$ has size 3 and is $\subseteq \{1, 2, \dots, n\}$. We call the elements of $T$ "triangles". Suppose that for all "edges" $E \subseteq \{1, 2, \dots, n\}$ with $|E|=2$ there are exactly $\lambda$ triangles $X \in T$ with $E \subseteq X$.\
\
Prove $\lambda \frac{n(n-1)}{2} = 3t$ by counting the set $C = \{(E,X) : X \in T, E \subseteq X, |E|=2\}$ in two different ways.

**Proof:**

We count the size of the set $C$ in two different ways.\
\
**Method A: Counting by Triangles ($X \in T$)**\
\
For every triangle $X \in T$, we count the number of valid pairs $(E, X)$ it contributes to $C$.\
\
We know that the total number of triangles is $|T| = t$. For every $X_i \in T$, $X_i$ has exactly $\binom{3}{2} = 3$ two-element subsets (edges). Hence, each $X_i \in T$ forms pairs with exactly $3$ edges, contributing exactly $3$ elements to $C$.\
\
It then follows that:

$$|C| = |T| \cdot \binom{3}{2}$$
$$|C| = 3t$$

**Method B: Counting by Edges ($E$)**\
\
For each edge, we count the number of valid pairs $(E, X)$ it contributes to $C$.\
\
By the subset rule, there are $\binom{n}{2}$ edges $E$ of size $2$ that can be constructed from the base set of $n$ vertices. We know that each edge $E$ is in exactly $\lambda$ triangles $X \in T$ with $E \subseteq X$. Thus, each edge $E$ forms pairs with exactly $\lambda$ triangles, contributing $\lambda$ elements to $C$.\
\
Since there are $\binom{n}{2}$ edges, we have:

$$|C| = \lambda \cdot \binom{n}{2}$$

By the definition of the binomial coefficient:

$$\binom{n}{2} = \frac{n!}{2!(n-2)!} = \frac{n(n-1)(n-2)!}{2(n-2)!} = \frac{n(n-1)}{2}$$

Substituting this back yields:

$$|C| = \lambda \frac{n(n-1)}{2}$$

**Conclusion:**\
\
Equating the results from Method A and Method B, it directly follows that:

$$\lambda \frac{n(n-1)}{2} = 3t$$

This completes the proof. $\blacksquare$

---

### Question 4: 5-Card Hands
**Question:**
Find the number of 5-card hands in which every suit appears at most twice.

**Solution:**

Let $x_1, x_2, x_3, x_4$ represent the number of cards drawn from each of the $4$ suits. We must satisfy the equation:

$$x_1 + x_2 + x_3 + x_4 = 5$$

Subject to the constraint $x_i \le 2$ for all $i \in \{1, 2, 3, 4\}$.\
\
Listing all valid integer partitions summing to 5 that satisfy the constraint, we get two multiset patterns: $\{0, 1, 2, 2\}$ and $\{1, 1, 1, 2\}$.\
\
Consider assigning these values to the $4$ distinct suits (Spades, Hearts, Diamonds, Clubs). For example, $(0, 1, 2, 2)$ represents $0$ Spades, $1$ Heart, $2$ Diamonds, and $2$ Clubs.\
\
**Case A: The partition $\{0, 1, 2, 2\}$**\
\
Let $A = \{0, 1, 2, 2\}$. Let $X$ be the set of all possible multiset arrangements of $A$ among the suits. By multiset counting, we know:

$$|X| = \frac{4!}{2!} = 12 \text{ arrangements}$$

Since the order of selection for the cards themselves does not matter, we compute the combinations for drawing from $13$-card suits. There are:

$$\binom{13}{0} \cdot \binom{13}{1} \cdot \binom{13}{2} \cdot \binom{13}{2} \text{ card combinations per arrangement}$$

**Case B: The partition $\{1, 1, 1, 2\}$**\
\
Let $B = \{1, 1, 1, 2\}$. Let $Y$ be the set of all possible multiset arrangements of $B$ among the suits. By multiset counting:

$$|Y| = \frac{4!}{3!} = 4 \text{ arrangements}$$

The number of card combinations for this partition is:

$$\binom{13}{1} \cdot \binom{13}{1} \cdot \binom{13}{1} \cdot \binom{13}{2} \text{ card combinations per arrangement}$$

**Total Combinations:**\
\
By the sum rule, we combine the arrangements and their respective card selections. Knowing that $\binom{13}{2} = 78$ and $\binom{13}{1} = 13$:

$$|Total| = \left( 13 \cdot 78^2 \cdot 12 \right) + \left( 13^3 \cdot 78 \cdot 4 \right)$$
$$|Total| = 948,792 + 685,776 = 1,634,568$$

There are $1,634,568$ possible 5-card hands where every suit appears at most twice. $\blacksquare$

---

### Question 6: Dice Sums
**Question:**
In how many different ways can the numbers shown on a red die, a green die, and a blue die total up to 15? Assume that these are ordinary, 6-sided dice.

**Solution:**

Let $d_0, d_1, d_2$ represent the red, green, and blue die outcomes, respectively, where:

$$d_0 + d_1 + d_2 = 15 \quad \text{and} \quad 1 \le d_i \le 6 \text{ for all } i \in \{0, 1, 2\}$$

By non-negative integer compositions (Stars and Bars), the number of distinct $k$-tuples $(x_1, \dots, x_k)$ of non-negative integers such that $\sum x_i = n$ is given by $\binom{n+k-1}{k-1}$. Since our system has strict bounds ($1 \le d_i \le 6$), we apply transformations and the Principle of Inclusion-Exclusion.\
\
**Step 1: Shift to lower bounds**\
\
Pre-allocate $1$ unit to each $d_i$ so the lower bound is met. Let $x_i = d_i - 1$.

$$(x_0 + 1) + (x_1 + 1) + (x_2 + 1) = 15 \implies x_0 + x_1 + x_2 = 12$$

where $0 \le x_i \le 5$ for all $i \in \{0, 1, 2\}$.\
\
Let $U$ be the set of all solutions to $x_0 + x_1 + x_2 = 12$ assuming $x_i \ge 0$.

$$|U| = \binom{12+3-1}{3-1} = \binom{14}{2}$$

**Step 2: Inclusion-Exclusion for upper bounds**\
\
Let $A_i$ be the set of solutions where variable $x_i$ violates the upper bound ($x_i \ge 6$).\
\
Consider $A_0$: we pre-allocate $6$ units to $x_0$. Let $x_0' = x_0 - 6$.

$$x_0' + x_1 + x_2 = 6$$
$$|A_0| = \binom{6+3-1}{3-1} = \binom{8}{2}$$

By symmetry, $|A_0| = |A_1| = |A_2| = \binom{8}{2}$.\
\
Let $A_i \cap A_j$ be the set where $2$ variables simultaneously violate the upper bound.\
\
Consider $A_0 \cap A_1$: pre-allocate $6$ units to both $x_0$ and $x_1$. Let $x_0' = x_0 - 6$ and $x_1' = x_1 - 6$.

$$x_0' + x_1' + x_2 = 0$$
$$|A_0 \cap A_1| = \binom{0+3-1}{3-1} = \binom{2}{2} = 1$$

By symmetry, $|A_0 \cap A_1| = |A_0 \cap A_2| = |A_1 \cap A_2| = 1$.\
\
Let $A_0 \cap A_1 \cap A_2$ be the set where all $3$ variables violate the bound. Since $6+6+6 = 18 > 12$, this scenario is impossible. Thus, $|A_0 \cap A_1 \cap A_2| = 0$.\
\
**Step 3: Calculate valid configurations**\
\
Let $S$ be the set of all 3-tuples that satisfy the strict bounds $0 \le x_i \le 5$. By Inclusion-Exclusion:

$$|S| = |U| - \binom{3}{1}|A_i| + \binom{3}{2}|A_i \cap A_j| - \binom{3}{3}|A_0 \cap A_1 \cap A_2|$$
$$|S| = \binom{14}{2} - 3\binom{8}{2} + 3(1) - 0$$
$$|S| = 91 - 3(28) + 3$$
$$|S| = 91 - 84 + 3 = 10$$

There are $10$ valid ways to roll a sum of $15$. $\blacksquare$

---

### Question 8: Bounded Paths
**Question:**
How many paths are there from point $(0,0)$ to $(50,50)$ if every step increments one coordinate and leaves the other unchanged and there are impassable boulders sitting at points $(10,10)$ and $(20,20)$?

**Solution:**

Let $U$ be the set of all unrestricted paths from the origin to $(50,50)$. Every path step can be represented as an increment in X or Y (e.g., $X, X, X, Y, Y$ to reach $(3,2)$, which has $\binom{5}{3} = \binom{5}{2}$ possible paths).\
\
In general, paths from $(0,0)$ to $(x,y)$ are given by $\binom{x+y}{x}$.\
\
Therefore, $|U| = \binom{100}{50}$.\
\
Let $A$ be the set of paths passing through the boulder at $(10,10)$. This requires paths from $(0,0) \to (10,10) \to (50,50)$.

$$|A| = \binom{20}{10} \cdot \binom{80}{40}$$

Let $B$ be the set of paths passing through the boulder at $(20,20)$. This requires paths from $(0,0) \to (20,20) \to (50,50)$.

$$|B| = \binom{40}{20} \cdot \binom{60}{30}$$

Notice that $A \cap B$ represents paths passing through *both* boulders in sequence: $(0,0) \to (10,10) \to (20,20) \to (50,50)$.

$$|A \cap B| = \binom{20}{10} \cdot \binom{20}{10} \cdot \binom{60}{30}$$

Let $S$ be the set of all paths avoiding both $(10,10)$ and $(20,20)$. By the Principle of Inclusion-Exclusion:

$$|S| = |U| - (|A| + |B| - |A \cap B|)$$
$$|S| = |U| - |A| - |B| + |A \cap B|$$

Substituting the combinations:

$$|S| = \binom{100}{50} - \binom{20}{10}\binom{80}{40} - \binom{40}{20}\binom{60}{30} + \binom{20}{10}\binom{20}{10}\binom{60}{30}$$

$\blacksquare$

---

### Question 9: There's more than one way...
**Theorem:**
$\sum_{i=0}^n \binom{k+i}{k} = \binom{k+n+1}{k+1}$

**Proof by Induction:**

Let $P(n)$ be the proposition that $\sum_{i=0}^n \binom{k+i}{k} = \binom{k+n+1}{k+1}$.\
\
**Base Case:** $P(0)$

$$\sum_{i=0}^0 \binom{k+i}{k} = \binom{k}{k} = 1$$
$$\binom{k+0+1}{k+1} = \binom{k+1}{k+1} = 1$$

Since $1 = 1$, the base case $P(0)$ holds.\
\
**Inductive Step:**\
\
Assume the Inductive Hypothesis $P(n)$ holds for some integer $n \ge 0$. That is:

$$\sum_{i=0}^n \binom{k+i}{k} = \binom{k+n+1}{k+1}$$

Consider $P(n+1)$. We want to show that $\sum_{i=0}^{n+1} \binom{k+i}{k} = \binom{k+n+2}{k+1}$.\
\
By peeling off the last term of the summation and applying our hypothesis $P(n)$, we obtain:

$$\sum_{i=0}^{n+1} \binom{k+i}{k} = \sum_{i=0}^n \binom{k+i}{k} + \binom{k+n+1}{k} = \binom{k+n+1}{k+1} + \binom{k+n+1}{k}$$

We know that by definition $\binom{n}{k} = \frac{n!}{k!(n-k)!}$. Expanding both binomial coefficients yields:

$$\binom{k+n+1}{k+1} + \binom{k+n+1}{k} = \frac{(k+n+1)!}{(k+1)!n!} + \frac{(k+n+1)!}{k!(n+1)!}$$

To combine the fractions, we establish a common denominator of $(k+1)!(n+1)!$:

$$\frac{(k+n+1)!}{(k+1)!n!} + \frac{(k+n+1)!}{k!(n+1)!} = \frac{(k+n+1)!(n+1)}{(k+1)!(n+1)!} + \frac{(k+n+1)!(k+1)}{(k+1)!(n+1)!}$$

$$= \frac{(k+n+1)!(n+1) + (k+n+1)!(k+1)}{(k+1)!(n+1)!}$$

$$= \frac{(k+n+1)! \cdot (n+1+k+1)}{(k+1)!(n+1)!}$$

$$= \frac{(k+n+1)! \cdot (k+n+2)}{(k+1)!(n+1)!}$$

$$= \frac{(k+n+2)!}{(k+1)!(n+1)!}$$

By definition, this fraction is exactly:

$$\binom{k+n+2}{n+1} = \binom{k+n+2}{k+1}$$

This completes the inductive step, and the proof of the theorem follows by the principle of mathematical induction. $\blacksquare$