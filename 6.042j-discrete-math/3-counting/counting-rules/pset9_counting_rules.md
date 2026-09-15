# Problem Set 9

### Problem 1(a)
**Question:**
Show that of any $n+1$ distinct numbers chosen from the set $\{1, 2, \dots, 2n\}$, at least 2 must be relatively prime. *(Hint: $\gcd(k, k+1) = 1$.)*

**Proof:**

Let $U = \{1, 2, \dots, 2n\}$. Consider partitioning $U$ into $n$ disjoint subsets $H_1, H_2, \dots, H_n$ such that $H_i = \{2i-1, 2i\}$ for $1 \le i \le n$.

Let $X$ be the set of all $n+1$ integers selected from $U$. Let $Y$ be the set of all disjoint subsets of $U$, defined as:

$$Y = \{\{1, 2\}, \{3, 4\}, \dots, \{2n-1, 2n\}\}$$

Define a mapping $f: X \to Y$ that maps an arbitrary $x \in X$ to a subset $y \in Y$ if $x \in y$. Since $|X| = n+1$ and $|Y| = n$, by the pigeonhole principle, at least 2 different elements of $X$ are mapped to the same element $y \in Y$.\
\
That is to say, $\exists H_i \in Y$ such that $H_i \subset X$. Thus, two consecutive numbers $2i-1$ and $2i \in X$. Since $\gcd(2i-1, 2i) = 1$, they are relatively prime.\
\
This completes the proof. $\blacksquare$

---

### Problem 1(b)
**Question:**
Show that any finite connected undirected graph with $n \ge 2$ vertices must have 2 vertices with the same degree.

**Proof:**

Let $X$ be the set of all $n$ vertices ($|X| = n \ge 2$). Let $Y$ be the set of possible degrees for any vertex. Since the graph is connected, every node must have a degree of at least $1$. Since there are $n$ nodes, a node can have a degree of at most $n-1$. This follows from the structure of a connected undirected graph.\
\
Thus, $Y = \{1, 2, \dots, n-1\}$, which means $|Y| = n-1$. Define a mapping $f: X \to Y$ that maps a vertex to its degree in the graph. Since $|X| = n$ and $|Y| = n-1$, then by the pigeonhole principle, at least 2 vertices $v_1, v_2 \in X$ are mapped to the same degree $d \in Y$.\
\
That is, $\exists v_1, v_2 \in X$ such that $f(v_1) = f(v_2)$.\
\
This completes the proof. $\blacksquare$

---

### Problem 2: Under Siege!
**Question:**
How many 10-digit passwords can be picked that don't contain forbidden consecutive sequences "18062", "6042" or "35876" if each number $0, 1, \dots, 9$ can only be chosen once (i.e. without replacement)?

**Solution:**

Let $U$ be the set of all possible 10-digit passwords, including the forbidden ones. We know that $|U| = 10!$.\
\
Let $F_1$ be the set of all 10-digit passwords that contain the sequence `18062`. We can treat `18062` as a single digit, such that a password $P_i = (18062, 3, 4, 5, 7, 9)$ where $P_i \in F_1$. It then follows that $|F_1| = 6!$.\
\
Let $F_2$ be the set of all 10-digit passwords containing `35876`. By symmetry, $|F_2| = |F_1| = 6!$.\
\
Let $F_3$ be the set of all 10-digit passwords containing `6042`. Treating `6042` as a single digit, a password $P = (6042, 1, 3, 5, 7, 8, 9)$ where $P \in F_3$. It then follows that $|F_3| = 7!$.\
\
Let $A$ be the set of valid 10-digit passwords, that is, $P \in A \implies P \notin F_1 \cup F_2 \cup F_3$. By the Principle of Inclusion-Exclusion:

$$|A| = |U| - (|F_1| + |F_2| + |F_3| - |F_1 \cap F_2| - |F_1 \cap F_3| - |F_2 \cap F_3| + |F_1 \cap F_2 \cap F_3|)$$

Notice that $F_1 \cap F_2 = \emptyset$. Since we are choosing without replacement, no 10-digit sequence has both `18062` and `35876` consecutive in it. Thus $|F_1 \cap F_2| = 0$.\
\
Also notice that no 10-digit sequence has both `18062` and `6042` consecutive in it. Thus $|F_1 \cap F_3| = 0$.\
\
Notice that a password $P_i \in F_2 \cap F_3$ has the structure $P_i = (35876042, 1, 9)$. Then $|F_2 \cap F_3| = 3!$.\
\
Notice that no 10-digit sequence has `18062`, `6042`, and `35876` consecutive to each other in it. Then $F_1 \cap F_2 \cap F_3 = \emptyset \implies |F_1 \cap F_2 \cap F_3| = 0$.\
\
Then:

$$|A| = 10! - (6! + 6! + 7! - 3!)$$

Thus $|A| = 3,622,326$ valid passwords. $\blacksquare$

---

### Problem 3(a)
**Question:**
How many 5-card hands have a single pair and no 3-of-a-kind or 4-of-a-kind?

**Solution:**

To guarantee exactly one pair and prevent any other matches, the structural pattern is strictly: `A A B C D`.\
\
Consider selecting a rank for the pair; there are $\binom{13}{1}$ choices. Then for the suits for the pair, there are $\binom{4}{2}$ choices. To prevent forming pairs, consider selecting ranks for the remaining 3 cards. There are $\binom{12}{3}$ rank choices. For selecting their suits, there are $\binom{4}{1}\binom{4}{1}\binom{4}{1}$ suit choices.\
\
Thus, there are:

$$\binom{13}{1}\binom{4}{2} \cdot \binom{12}{3} \cdot \binom{4}{1}^3 = 1,098,240$$

5-card hands with a single pair and no 3-of-a-kind or 4-of-a-kind. $\blacksquare$

---

### Problem 3(b)
**Question:**
For fixed positive integers $n$ and $k$, how many nonnegative integer solutions $x_0, x_1, \dots, x_k$ are there to the following equation? $\sum_{i=0}^k x_i = n$

**Solution:**

Let $S$ be the set of non-negative integer solutions:

$$S = \left\{(x_0, x_1, \dots, x_k) \in \mathbb{Z}^{k+1} \mid x_0 + x_1 + \dots + x_k = n\right\}$$

Let $B$ be the set of binary bitstrings of length $n+k$ containing exactly $k$ ones. We define a mapping $f: S \to B$ that takes a tuple $(x_0, x_1, \dots, x_k)$ and converts it into a string of bits $0^{x_0}10^{x_1}1 \dots 10^{x_k}$, where $0^{x_i}$ represents a string of exactly $x_i$ consecutive zeros. When $x_i = 0$, it is an empty string.\
\
Since $f$ is a bijection, and we know that $|B| = \binom{n+k}{k}$, it then follows that $|S| = \binom{n+k}{k}$. $\blacksquare$

---

### Problem 3(c)
**Question:**
For fixed positive integers $n$ and $k$, how many nonnegative integer solutions $x_0, x_1, \dots, x_k$ are there to the following equation? $\sum_{i=0}^k x_i \le n$

**Solution:**

Let $x_{k+1} = n - \sum_{i=0}^k x_i$. Since $\sum_{i=0}^k x_i \le n$ and $n \in \mathbb{Z}$, then $x_{k+1} \ge 0$.\
\
It then follows that $n = \sum_{i=0}^k x_i + x_{k+1}$, which means $n = \sum_{i=0}^{k+1} x_i$. Using the result from (b), it follows that there are $\binom{n+k+1}{k+1}$ solutions to $\sum_{i=0}^k x_i \le n$. $\blacksquare$

---

### Problem 3(d)
**Question:**
How many simple undirected graphs are there with $n$ vertices?

**Solution:**

We know that for any $n$-vertex simple undirected graph, there are at most $\frac{n(n-1)}{2} = \binom{n}{2}$ edges. Since the number of vertices $n$ is fixed, consider forming a specific graph from the $\binom{n}{2}$ edges.\
\
For each of the edges, we have two choices: $\{0, 1\}$ to represent include or not include. By the product rule, there are $2^{\binom{n}{2}}$ simple undirected graphs with $n$ vertices. $\blacksquare$

---

### Problem 3(e)
**Question:**
How many directed graphs are there with $n$ vertices (self loops allowed)?

**Solution:**

Since a directed graph can have bidirectional edges and self loops, the maximum number of directed edges is:

$$2\binom{n}{2} + n = \frac{2n(n-1)}{2} + n = n(n-1) + n = n^2$$

To form a directed graph on $n$ vertices, for every single possible edge, we have 2 independent choices: $\{0, 1\}$ to include or not include. Then by the product rule, there are $2^{n^2}$ directed graphs with $n$ vertices. $\blacksquare$

---

### Problem 3(f)
**Question:**
How many tournament graphs are there with $n$ vertices?

**Solution:**

Let $T$ be the tournament graph, $T = (V, E)$ where $|V| = n$. Let $E$ be the set of all edges. Since $T$ is a tournament graph, we know that for any pair of vertices $v_i, v_j \in V$, there exists exactly one directed edge. Thus $|E| = \binom{n}{2}$.\
\
Since for any pair of vertices $v_i, v_j$, we must choose exactly one direction between $(v_i, v_j)$ and $(v_j, v_i)$ (not both), there are two independent choices for each vertex pair. It follows by the product rule that there are $2^{\binom{n}{2}}$ tournament graphs on $n$ vertices. $\blacksquare$

---

### Problem 3(g)
**Question:**
How many acyclic tournament graphs are there with $n$ vertices?

**Solution:**

Let $G = (V, E)$ be an acyclic tournament graph with $|V| = n$. We know the fundamental property that at least one vertex must have an out-degree of $n-1$ (the source) and one vertex must have an in-degree of $n-1$ (the sink).\
\
**Lemma:** There is exactly one source in $G$.\
\
**Proof of Lemma:** Assume that there is not exactly one source in $G$. Without loss of generality, assume there are 2 vertices $v_1$ and $v_2$ that both have an out-degree of $n-1$. This implies that $v_1$ connects to all other vertices, and $v_2$ connects to all other vertices. This means $v_1$ connects to $v_2$, and $v_2$ connects to $v_1$. This contradicts the assumption that there are no cycles. Thus there is exactly one source. By symmetry, the sink must also be exactly one. $\blacksquare$\
\
Consider removing the source vertex $v_s$ from $G$. Notice that a subgraph $G' = (V \setminus \{v_s\}, E')$ has $n-1$ vertices, and since $G$ is acyclic, any subgraph of $G$ is also acyclic. Let $A(n)$ represent the total number of acyclic tournament graphs on $n$ vertices.\
\
Consider selecting the source node from $n$ choices. Notice that all the out-going edges of the source node are fixed, and there are $A(n-1)$ configurations for the remaining sub-graph. It follows that:

$$A(n) = n \cdot A(n-1)$$

**Base case:** $A(1) = 1$ since there is exactly one valid acyclic tournament graph with a single node.\
\
Solving the recurrence $A(n) = n A(n-1)$, notice that $A(n) = n \cdot (n-1) \cdot (n-2) \dots = n!$. It follows that there are $n!$ acyclic tournament graphs. $\blacksquare$

---

### Problem 3(h)
**Question:**
How many numbers are there that are in the range $[1..700]$ which are divisible by 2, 5 or 7?

**Solution:**

Let $A = \{a \mid a \in [1, 700] \text{ and } a \equiv 0 \pmod 2\}$\
\
Let $B = \{b \mid b \in [1, 700] \text{ and } b \equiv 0 \pmod 5\}$\
\
Let $C = \{c \mid c \in [1, 700] \text{ and } c \equiv 0 \pmod 7\}$\
\
We know that:

$$|A| = \lfloor 700/2 \rfloor = 350$$
$$|B| = \lfloor 700/5 \rfloor = 140$$
$$|C| = \lfloor 700/7 \rfloor = 100$$

Let $U$ be the set of all numbers in $[1, 700]$ which are divisible by 2 or 5 or 7. By Inclusion-Exclusion:

$$|U| = |A| + |B| + |C| - |A \cap B| - |A \cap C| - |B \cap C| + |A \cap B \cap C|$$

Since $C = \{7, 14, 21, \dots, 700\}$ and $A = \{2, 4, \dots, 700\}$, then $|A \cap C| = \lfloor |C|/2 \rfloor = 50$.\
\
By symmetry, $|A \cap B| = \lfloor |B|/2 \rfloor = 70$.\
\
$|B \cap C| = \lfloor |C|/5 \rfloor = 20$.\
\
Since $A \cap B \cap C = A \cap (B \cap C)$, and $B \cap C = \{35, 70, 105, \dots, 700\}$, then $|A \cap B \cap C| = \lfloor |B \cap C|/2 \rfloor = 10$.\
\
Then:

$$|U| = (350 + 140 + 100) - (70 + 50 + 20) + 10$$

Thus $|U| = 460$. $\blacksquare$

---

### Problem 3(i)
**Question:**
In how many ways can you arrange $n$ books on $k$ bookshelves (assuming the order of books on a shelf matters)?

**Solution:**

Let $b_1, b_2, \dots, b_n$ represent the distinct books. Let $0$s represent bookshelf dividers. Since there are $k$ shelves, there are $k-1$ dividers.\
\
Let $A$ be the set of all $n+k-1$ length sequences that represent arrangements on a $k$-shelf where the order of books matters. Consider generating all the sequences by choosing the $n$ distinct books and $k-1$ dividers. By the product rule, $|A| = n! \cdot \binom{n+k-1}{k-1}$. $\blacksquare$

---

### Problem 3(j)
**Question:**
How about if there has to be at least 1 book at each bookshelf?

**Solution:**

It follows by the product rule that there are $n! \binom{n-1}{k-1}$ arrangements. $\blacksquare$

---

### Problem 4
**Question:**
Give a combinatorial proof of the following theorem: $n2^{n-1} = \sum_{k=1}^n k \binom{n}{k}$

**Proof:**

Let $S$ be the set of all length-$n$ sequences of `0`s, `1`s, and a single `*`.\
\
**LHS:** Consider constructing such a sequence from scratch. Notice that there are $n$ choices for the position of the single `*`. For the remaining $n-1$ positions, there are two choices for each slot: $\{0, 1\}$. There are $2^{n-1}$ possibilities for the rest. Then by the product rule, $|S| = n2^{n-1}$.\
\
**RHS:** Consider disjoint sets $A_k$. We allocate an arbitrary $k$ slots from $n$ to represent choosing the `1`s and the `*`. We dedicate $1$ slot from the $k$ slots to the `*` and the remaining $k-1$ slots to the `1`s. The remaining $n-k$ slots are allocated `0`s. This guarantees $A_i \cap A_j = \emptyset$ for $i \neq j$. By the product rule, this is $\binom{n}{k}\binom{k}{1} = k\binom{n}{k}$.\
\
It then follows by the sum rule that:

$$|S| = |A_1 \cup A_2 \cup \dots \cup A_n| = \binom{n}{1} + 2\binom{n}{2} + \dots + n\binom{n}{n}$$

Thus, $|S| = \sum_{k=1}^n k\binom{n}{k}$.\
\
Since $|S| = n2^{n-1} = \sum_{k=1}^n k\binom{n}{k}$, this completes the proof of the theorem. $\blacksquare$

---

### Problem 5
**Question:**
At a congressional hearing, there are $2n$ members present. Exactly $n$ of them are Democrats and $n$ of them are Republicans. The members want to select a smaller subcommittee of size $n$ from within those present at the hearing. However, since the Democrats currently hold majority, they want there to be more Democrats than Republicans in the committee. In how many ways can you select such a committee? *(Hint: Consider two cases: $n$ odd and $n$ even.)*

**Solution:**

Let $r$ be Republicans, and $d$ be Democrats. We want $d + r = n$ and $r < d$. This implies $r < n/2$.\
\
Let $U$ be the set of all possible subcommittees of size $n$ that can be formed from the $2n$ members, disregarding constraints. $|U| = \binom{2n}{n}$.\
\
Let $M_D$ be the set of subcommittees which have a Democrats majority. Let $M_R$ be the set of subcommittees where Republicans have a majority. Let $T$ be the set of subcommittees where there is a tie. Notice that $M_D, M_R, T$ are mutually exclusive, and by the symmetry of the initial pool, $|M_D| = |M_R|$.\
\
Also notice that $|U| = |M_D| + |M_R| + |T|$. Since $|M_D| = |M_R|$, $|U| = 2|M_D| + |T|$. Then:

$$\binom{2n}{n} = 2|M_D| + |T|$$

**Case 1: $n$ is odd.**\
\
A tie cannot happen. Then $|T| = 0$.

$$|M_D| = \frac{1}{2}\binom{2n}{n}$$

**Case 2: $n$ is even.**\
\
A tie can happen. Then $|T| = \binom{n}{n/2}\binom{n}{n/2} = \binom{n}{n/2}^2$.

Then $\binom{2n}{n} = 2|M_D| + \binom{n}{n/2}^2$.

$$|M_D| = \frac{1}{2}\binom{2n}{n} - \frac{1}{2}\binom{n}{n/2}^2$$

Therefore, the number of ways is:

$$
|M_D| = \begin{cases}
\dfrac{1}{2}\binom{2n}{n} & \text{if } n \text{ is odd} \\[0.5em]
\dfrac{1}{2}\binom{2n}{n} - \dfrac{1}{2}\binom{n}{n/2}^2 & \text{if } n \text{ is even}
\end{cases}
$$

$\blacksquare$