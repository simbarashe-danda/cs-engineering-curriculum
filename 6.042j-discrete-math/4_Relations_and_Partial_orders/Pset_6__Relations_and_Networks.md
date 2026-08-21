# 6.042/18.062J Mathematics for Computer Science

**Assignment:** Problem Set 6

---

## **Problem 1** For each of the following, either prove that it is an equivalence relation and state its equivalence classes, or give an example of why it is not an equivalence relation.

### **Part (a)**

> **Question:** $R_n := \{(x,y) \in \mathbb{Z} \times \mathbb{Z} \text{ s.t. } x \equiv y \pmod n\}$

**Solution:**
**Claim:** $R_n$ is an equivalence relation.

* **Reflexivity:**
  
  $R_n$ is reflexive since $\forall x \in \mathbb{Z}$, $x \equiv x \pmod n$.
  
  This holds because $\forall n \in \mathbb{Z}$ where $n \neq 0$, $n \mid (x - x) \implies n \mid 0$.
  
* **Symmetry:**
  
  If $n \mid (x - y)$, then $n \mid (y - x)$.

  Therefore, $\forall x, y \in \mathbb{Z}$, $x \equiv y \pmod n \implies y \equiv x \pmod n$.
  
* **Transitivity:**
  
   We need to prove that $x \equiv y \pmod n$ and $y \equiv z \pmod n \implies x \equiv z \pmod n$ for all $x, y, z \in \mathbb{Z}$ and $n > 1$.

  By the definition of congruency:

$$n \mid (x - y) \quad \text{and} \quad n \mid (y - z)$$

By divisibility rules, if $a \mid b$ and $a \mid c$, then $a \mid (b + c)$:

$$n \mid (x - y) + (y - z) \implies n \mid (x - z)$$

Thus, $x \equiv z \pmod n$.

We have shown that $R_n$ is reflexive, symmetric, and transitive; therefore, $R_n$ is an equivalence relation.

**Equivalence Classes:**
The equivalence classes of $R_n$ are:

* $\{\dots, -n, 0, n, 2n, 3n, \dots\}$
* $\{\dots, -n+1, 1, n+1, 2n+1, 3n+1, \dots\}$
* $\vdots$
* $\{\dots, -1, n-1, 2n-1, 3n-1, \dots\}$

### **Part (b)**

> **Question:** $R := \{(x,y) \in P \times P \text{ s.t. } x \text{ is taller than } y\}$ where $P$ is the set of all people in the world today.

**Solution:**
**Claim:** $R$ is not an equivalence relation.

It is not an equivalence relation since $\forall x \in P$, $x \not R x$, meaning that no person is taller than themselves.

It fails the reflexivity property.

### **Part (c)**

> **Question:** $R := \{(x,y) \in \mathbb{Z} \times \mathbb{Z} \text{ s.t. } \gcd(x,y) = 1\}$

**Solution:**
**Claim:** $R$ is not an equivalence relation.

It is not an equivalence relation because it is not reflexive. For example, $\forall x \in \mathbb{Z} \setminus \{ -1, 1 \}$ :

$$\gcd(x, x) = |x| \quad \text{and} \quad |x| \neq 1$$

### **Part (d)**

> **Question:** $R_G := \text{the set of } (x,y) \in V \times V \text{ such that } V \text{ is the set of vertices of a graph } G, \text{ and there is a path } x, v_1, \dots, v_k, y \text{ from } x \text{ to } y \text{ along the edges of } G.$

**Solution:**
**Claim:** $R_G$ is an equivalence relation.

* **Reflexivity:**

  Holds since, by the graph theory definition of a path, $\forall x \in V$, there is a path from $x$ to $x$.
  
* **Symmetry:**
  
  Since a path is undirected, if a path from $x$ to $y$ exists, then a path from $y$ to $x$ exists. $\forall x, y \in V$.
  
* **Transitivity:**
  
  If a path $x \to y$ exists and a path $y \to z$ exists, then logically, a path $x \to z$ exists. The path can utilize $x \to \dots \to y \to \dots \to z$.

We have shown that $R_G$ is reflexive, symmetric, and transitive; therefore, $R_G$ is an equivalence relation.

**Equivalence Classes:**
Let $C \subseteq G$ be a connected component of $G$ such that $x, y \in C$.

Then $C$ is an equivalence class of $G$ since there is a path connecting all nodes in $C$.

The equivalence classes are all the connected components $C_1, C_2, \dots$ of $G$.

---

## **Problem 2**

Every function has some subset of these properties: injective, surjective, bijective. Determine the properties of the functions below, and briefly explain your reasoning.

### **Part (a)**

> **Question:** The function $f : \mathbb{R} \to \mathbb{R}$ defined by $f(x) = x \sin(x)$.

**Solution:**
**Injectivity:**

Consider $x = 0$ and $x = \pi$:

$$f(0) = 0 \sin(0) = 0$$

$$f(\pi) = \pi \sin(\pi) = 0$$

But $0 \neq \pi$.

It is not the case that $\forall x_1, x_2 \in \mathbb{R}, f(x_1) = f(x_2) \implies x_1 = x_2$.

Therefore, $f(x)$ is **not injective**.

**Surjectivity:**

First, checking continuity,

Because $x$ and $\sin(x)$ are continuous, and the product of two continuous functions is continuous, $x \sin(x)$ is continuous for all $x \in \mathbb{R}$.

Let $C \in \mathbb{R}$ be an arbitrary real number.

To prove surjectivity, we must show there exists some $c \in \mathbb{R}$ such that $f(c) = C$.

Let $x_n = \frac{\pi}{2} + 2\pi n$ and $y_n = \frac{3\pi}{2} + 2\pi n$ for $n \in \mathbb{N}$.

$$f(x_n) = \left(\frac{\pi}{2} + 2\pi n\right) \sin\left(\frac{\pi}{2} + 2\pi n\right) = \frac{\pi}{2} + 2\pi n$$

$$f(y_n) = \left(\frac{3\pi}{2} + 2\pi n\right) \sin\left(\frac{3\pi}{2} + 2\pi n\right) = -\left(\frac{3\pi}{2} + 2\pi n\right)$$

Taking limits:

$$\lim_{n \to \infty} f(x_n) = \infty \quad \text{and} \quad \lim_{n \to \infty} f(y_n) = -\infty$$

Because the output diverges to $+\infty$ and $-\infty$, and $C$ is finite, there must exist $N \in \mathbb{N}$ such that $f(y_N) < C < f(x_N)$.

Since $f$ is continuous on the closed interval $[y_N, x_N]$,

the Intermediate Value Theorem guarantees that $\exists c \in [y_N, x_N]$ such that $f(c) = C$.

Thus, $\forall y \in \mathbb{R}, \exists x \in \mathbb{R} \text{ s.t. } f(x) = y$. $f(x)$ is **surjective**.

### **Part (b)**

> **Question:** The function $f : \mathbb{R} \to \mathbb{R}$ defined by $f(x) = 99x^{99}$.

**Solution:**
**Injectivity:**

Assume $f(a) = f(b)$. Then:

$$99a^{99} = 99b^{99} \implies a^{99} = b^{99} \implies a = b$$

Therefore, $f(x)$ is **injective** since $\forall x_1, x_2 \in \mathbb{R}, f(x_1) = f(x_2) \implies x_1 = x_2$.

**Surjectivity:**

Let $f(x) = y$ where $y \in \mathbb{R}$.Then:

$$99x^{99} = y \implies x^{99} = \frac{y}{99} \implies x = \left(\frac{y}{99}\right)^{1/99}$$

Since $y \in \mathbb{R}$, then $\left(\frac{y}{99}\right)^{1/99} \in \mathbb{R} \implies x \in \mathbb{R}$.

Since $\forall y \in \mathbb{R}, \exists x \in \mathbb{R} \text{ s.t. } f(x) = y$, $f(x)$ is **surjective**.

**Bijectivity:**

Since $f(x)$ is injective and surjective, it is **bijective**.

### **Part (c)**

> **Question:** The function $f : \mathbb{R} \to \mathbb{R}$ defined by $f(x) = \tan^{-1}(x)$.

**Solution:**
**Injectivity:**

Taking the derivative:

Let $y = \tan^{-1}(x) \implies x = \tan(y)$

By implicit differentiation:

$$\frac{d}{dx}(x) = \frac{d}{dx}(\tan(y))$$

$$1 = \sec^2(y) \cdot \frac{dy}{dx} \implies \frac{dy}{dx} = \frac{1}{\sec^2(y)}$$

Using the trigonometric identity $\sec^2(y) = 1 + \tan^2(y)$:

$$\frac{dy}{dx} = \frac{1}{1 + \tan^2(y)} = \frac{1}{1 + x^2}$$

Set $f'(x) = 0$:

$$\frac{1}{1+x^2} = 0$$

Inverting both sides gives $1+x^2 = \text{undefined}$, so $f'(x)$ never equals **0**.

It follows that $f'(x)$ is either always positive or negative.

Checking $x=0 \implies f'(0) = 1$.

Therefore $f'(x) > 0$ for all $x$.

It then follows that $\forall x_1, x_2 \in \mathbb{R}, f(x_1) = f(x_2) \implies x_1 = x_2$.

The function is strictly increasing, so it is **injective**.

**Surjectivity:**

Counterexample: $y = \pi$.

$$\nexists x \in \mathbb{R} \text{ s.t. } \tan^{-1}(x) = \pi$$

Therefore, $f(x)$ is **not surjective**.

As a result, it is also **not bijective**.

### **Part (d)**

> **Question:** The function $f : \mathbb{N} \to \mathbb{N}$ defined by $f(x) = \text{the number of numbers that divide } x$. For example, $f(6) = 4$ because $1, 2, 3, 6$ all divide $6$.
>
> Note: $\mathbb{N}$ is defined here as positive integers.

**Solution:**

**Injectivity:** Counterexample: $f(3) = 2$ because $\{1,3\}$ divide $3$.

$f(2) = 2$ because $\{1,2\}$ divide $2$. But $2 \neq 3$.  

Therefore, $f$ is not injective.

**Surjectivity:** Proof that for every natural number $n$, we can find $x \in \mathbb{N}$ that has $n$ divisors.

Notice the pattern for powers of $2$:  
$x = 1 \implies 1$ divisor  
$x = 2 \implies 2$ divisors  
$x = 4 \implies 3$ divisors  
$x = 8 \implies 4$ divisors  

Claim $P(k)$: $2^{k-1}$ has exactly $k$ divisors for an arbitrary $k \in \mathbb{N}$.

Proof by induction:

- **Base case $k=1$:** $2^{1-1}=1$ has exactly one divisor ($1$), so $P(1)$ holds.

- **Inductive step:**

  Assume $P(k)$ is true: $2^{k-1}$ has $k$ divisors, namely $1, 2, 2^2, \dots, 2^{k-1}$.
  
  To prove $P(k+1)$, we must show $2^{(k+1)-1} = 2^k$ has $k+1$ divisors.
  
  $$2^k = 2^{k-1} \cdot 2$$
  
  Multiplying $2^{k-1}$ by $2$ turns each existing divisor $2^i$ into $2^{i+1}$, giving $2, 2^2, \dots, 2^{k-1}, 2^k$.

  Together with the original divisors, the only genuinely new divisor added is $2^k$.

  Hence $2^k$ has exactly $k+1$ divisors.

  $P(k) \implies P(k+1)$.

Since there always exists $x = 2^{k-1}$ that produces exactly $k$ divisors, the function is surjective.

**Bijectivity:** Since $f$ is surjective and not injective, it is not bijective.

---

## **Problem 3**

> **Context:**
> In this problem we study partial orders (posets). Recall that a weak partial order $\preceq$ on a set $X$ is reflexive ($x \preceq x$), anti-symmetric ($x \preceq y \land y \preceq x \to x = y$), and transitive ($x \preceq y \land y \preceq z \to x \preceq z$). Note that it may be the case that neither $x \preceq y$ nor $y \preceq x$. A chain is a list of *distinct* elements $x_1, \dots, x_i$ in $X$ for which $x_1 \preceq x_2 \preceq \dots \preceq x_i$. An antichain is a subset $S$ of $X$ such that for all distinct $x, y \in S$, neither $x \preceq y$ nor $y \preceq x$.
>
> (The problem requires proving properties regarding a sequence of length $(n-1)(m-1)+1$ using Dilworth's theorem and the relation $i \preceq j \iff i \le j \land a_i \le a_j$.)

### **Part (a): Proving the Weak Partial Order**

**Solution:**
Let $W_{\preceq}$ be the given partial order defined as $i \preceq j \iff i \le j \land a_i \le a_j$.

To prove $W_{\preceq}$ is a weak poset, we prove reflexivity, anti-symmetry, and transitivity.

**Claim: $W_{\preceq}$ on set $X = \{1, 2, \dots, (n-1)(m-1)+1\}$ is reflexive.**

Let $i \in X$.

By the definition of the relation, to prove $i \preceq i$ we must prove $i \le i \land a_i \le a_i$. Since $i - i \le 0$ and $a_i - a_i \le 0$, then $i \le i \land a_i \le a_i \equiv \text{True}$.

**Claim: $W_{\preceq}$ on set $X$ is anti-symmetric.**

That is, $i \preceq j \land j \preceq i \implies i = j$.

Assume the premise is true for arbitrary $i, j \in X$.

By definition of the relation, then:

$$(i \le j \land a_i \le a_j) \land (j \le i \land a_j \le a_i)$$

Because $\land$ is commutative and associative:

$$(i \le j \land j \le i) \land (a_i \le a_j \land a_j \le a_i)$$

From the first conjuncture $i \le j \land j \le i$, we conclude $i = j$ because $\le$ on a set of integers is already a partial order $\implies$ anti-symmetry $\implies i = j$. Since the conjuncture forces $i=j$, the conclusion is reached.

**Claim: $W_{\preceq}$ on set $X$ is transitive.**

That is, $i \preceq j \land j \preceq k \implies i \preceq k$.

Assume $i, j, k \in X$ such that $i \preceq j$ and $j \preceq k$.

By definition of the relation, then:

$$(i \le j \land a_i \le a_j) \land (j \le k \land a_j \le a_k)$$

By commutativity and associativity:

$$(i \le j \land j \le k) \land (a_i \le a_j \land a_j \le a_k)$$

Since $\le$ is already a partial order $\implies$ transitive $\implies i \le k$.

It also follows from the property of $\le$ that $a_i \le a_k$.

Since $i \le k \land a_i \le a_k$, therefore $i \preceq k$.

### **Part (b): Application of Dilworth's Theorem**

**Solution:**
From the structure established in Part (a):

* **Chain:** Non-decreasing subsequence ($i_1 \le i_2 \dots \implies a_{i_1} \le a_{i_2} \dots$)
  
* **Anti-chain:** Strictly decreasing subsequence (If $i < j$ and neither $i \preceq j$ nor $j \preceq i$, it forces $a_i > a_j$).

**Dilworth's Theorem:** The maximum size of an antichain is equal to the minimum number of chains required to partition the set.

Let $N = (n-1)(m-1)+1$ be the total number of elements in the poset.

Assume the sequence does not contain a strictly decreasing subsequence of length $m$. Therefore, the maximum size of an antichain (let's call it $r$) is strictly bounded by $m-1$.

It follows from our assumption that $r \le m-1$.

Let $C$ be the minimum number of chains required to partition the set.

By Dilworth's theorem, $r = C$. Then $C \le m-1$.

Consider partitioning $N$ elements into $C \le m-1$ chains.

By the Pigeonhole Principle, at least one chain $C_i$ has at least:

$$\left\lceil \frac{(n-1)(m-1)+1}{m-1} \right\rceil$$ elements.

This simplifies to:

$$(n-1) + \frac{1}{m-1}$$

Thus, bounding the lower limit:

$$\left\lceil \frac{N}{C} \right\rceil \ge \left\lceil (n-1) + \frac{1}{m-1} \right\rceil$$

Because $m > 1$ (otherwise a decreasing subsequence of length 1 is trivial), we know $\frac{1}{m-1} > 0$.

Then:

$$\left\lceil (n-1) + \frac{1}{m-1} \right\rceil = n$$

Thus, at least one chain contains a minimum of $n$ elements.

Because a chain under $\le$ strictly maps to a non-decreasing sequence, the sequence must contain a non-decreasing subsequence of length $n$.

This completes the proof. $\blacksquare$

### **Part (c): Explicit Construction**

**Solution:**
Let $S$ be a generic sequence of exactly $(n-1)(m-1)$ integers such that $S = \{a_1, a_2, \dots, a_{(n-1)(m-1)}\}$.

We want to construct a sequence of exactly $(n-1)(m-1)$ distinct integers explicitly designed to prevent a non-decreasing subsequence of length $n$ and a strictly decreasing subsequence of length $m$.

**1. Total number of Blocks:**

Partition the sequence into exactly $n-1$ contiguous blocks,

$$B_1, B_2, \dots, B_{n-1}$$

**2. Elements per Block:**

Each block $B_k$ contains exactly $m-1$ integers.

**3. Intra-Block Structure (Strictly decreasing):**

Define elements of an arbitrary block $B_k$ to be

$$B_k = (k(m-1), k(m-1)-1, k(m-1)-2, \dots, (k-1)(m-1)+1)$$

where $k \in \{1, 2, \dots, n-1\}$.

**4. Inter-Block Structure (Strictly Increasing):**

* Maximum element in $B_k$ is its first term $k(m-1)$.
  
* Minimum element of the next block $B_{k+1}$ is its last element $k(m-1)+1$.

Because $k(m-1)+1 > k(m-1)$, the min value of the next block exceeds the maximum value of the current block.

It then follows that any strictly decreasing subsequence has length at most block size, which is $m-1$.

The maximum non-decreasing subsequence is at most $n-1$ because any non-decreasing subsequence can select at most one element from each block.

There are $n-1$ blocks $\implies$ max possible length $= n-1$.

Because this sequence of length $(n-1)(m-1)$ avoids both threshold conditions, $(n-1)(m-1)+1$ from (b) is the best possible bound. $\blacksquare$

---

## **Problem 4**

### **Solution / Derivations for Network Models**

From lecture we know:

**Butterfly**

* **Diameter:** $2 + \log N$
* **Switch size:** $2 \times 2$
* **Number of switches:** $N(1 + \log N)$
* **Congestion:** $\sqrt{N}$ or $\frac{\sqrt{N}}{2}$

**Benes**

* **Diameter:** $1 + 2\log N$
* **Switch size:** $2 \times 2$
* **Number of switches:** $2N\log N$
* **Congestion:** $1$

**Reasoner-net** adds a new column of switches at the very beginning and very end.

* **Layer 0:** $N$ Reasoner net input switches. Let's call them $R_0, R_1, \dots, R_{N-1}$
* **Layer 1 (Benes top block):** $N$ switches $a_0, a_1, \dots, a_{N-1}$
* **Layer 1 (Butterfly bottom block):** $N$ switches $b_0, b_1, \dots, b_{N-1}$

The same logic applies for the transition from $N$ Benes + $N$ butterfly switches to $N$ reasoner-net output switches.

Each Reasoner input switch has exactly two outgoing edges and each reasoner output switch has exactly two incoming edges.

Then total switches are:

$$2N \text{ from reasoner } (N \text{ inputs } + N \text{ outputs})$$

$$+ N(1 + \log N) \text{ Butterfly } + 2N\log N \text{ Benes}$$

Therefore, the total switches: $3N(1 + \log N)$. $\blacksquare$

All the reasoner-net switches are $1 \times 2$ and $2 \times 1$. Since this is less than the maximum $2 \times 2$ for Benes and butterfly, the overall switch size remains $2 \times 2$.

**Reasoner-Net Model Structure:**

`[N Terminals]` $\xrightarrow{\text{2 edges}}$ `[N input switches]` $\xrightarrow{\text{2 edges out}}$ `[N butterfly + N benes]` $\xrightarrow{\text{2 incoming edges per switch}}$ `[N output switches]` $\to$ `[N terminals]`

That means from the Benes and Butterfly point of view, exactly two edges were added. One from the input switch, one from the output switch. Only the longest path contributes to diameter, and that is the path of Benes.

New Diameter: $1 + 2\log N + 2 = 3 + 2\log N$. $\blacksquare$

**Congestion:**

If a routing algorithm is going to choose the best possible congestion, then it always chooses Benes. Since for Benes, congestion $= 1$ for all possible permutations.

Congestion: $1$.

**Latency for min-congestion (LMC):**

To achieve minimum possible congestion (1), the algorithm must force all traffic through Benes.

Hence a latency of $3 + 2\log N$. $\blacksquare$

**Congestion for min-latency (CML):**

For any meaningful network size $N > 4$, the butterfly latency $4 + \log N < 3 + 2\log N$ (the Benes network, including reasoner edges).

Butterfly has a worst congestion of $\sqrt{N}$.

Hence CML = $\sqrt{N}$. $\blacksquare$

| Network | Diameter | Switch size(s) | # switches | Congestion | LMC | CML |
| --- | --- | --- | --- | --- | --- | --- |
| **Reasoner-net** | $3+2\log N$ | $2 \times 2$ | $3N(1+\log N)$ | $1$ | $3+2\log N$ | $\sqrt{N}$ |

---

## **Problem 5**

> Let $B_n$ denote the butterfly network with $N = 2^n$ inputs and $N$ outputs, as defined in Notes 6.3.8.
>
> We will show that the congestion of $B_n$ is exactly $\sqrt{N}$ when $n$ is even.
>
> *Hints:*
>
> * For the butterfly network, there is a unique path from each input to each output, so the congestion is the maximum number of messages passing through a vertex for any matching of inputs to outputs.
> * If $v$ is a vertex at level $i$ of the butterfly network, there is a path from exactly $2^i$ input vertices to $v$ and a path from $v$ to exactly $2^{n-i}$ output vertices.
> * At which level of the butterfly network must the congestion be worst? What is the congestion at the node whose binary representation is all $0$s at that level of the network?

### **Part (a)**

> **Question:** Show that the congestion of $B_n$ is at most $\sqrt{N}$ when $n$ is even.

**Solution:**

Let $v$ be an arbitrary vertex at level $i$ in the butterfly network $B_n$, where $0 \le i \le n$.

Let $S_v$ be the set of input vertices that have a directed path to $v$.

Let $T_v$ be the set of output vertices that have a directed path from $v$.

From the provided hints we know that $|S_v| = 2^i$ and $|T_v| = 2^{n-i}$.

A valid message routing assignment is a bijection $\pi: \text{Inputs} \to \text{Outputs}$.

Since $\pi$ is bijective then we know,

$\forall p_1, p_2 \in S_v$, $\pi(p_1) = \pi(p_2) \implies p_1 = p_2$.

Meaning no inputs map to the same output.

We also know that $\forall o \in T_v$, $\exists p \in S_v \text{ s.t. } \pi(p) = o$.

Meaning each output has an input.

Therefore we conclude each input has exactly one output and vice versa.

It then follows that the absolute maximum number of packets that can pass through $v$ is given by:

$$m = \min(2^i, 2^{n-i})$$

$$\implies m = \min(|S_v|, |T_v|)$$

Since $N = 2^n$ and $n$ is an even integer, it follows that the absolute possible max value $m_{max}$ happens when $i = n/2$.

Since $n \equiv 0 \pmod 2 \implies n/2 \in \mathbb{Z}$, then $m_{max} = 2^{n/2}$.

Expressing in terms of $N$:

We know $N = 2^n$. Raising both sides to the power $1/2$ gives:

$$N^{1/2} = 2^{n/2}$$

Thus, $m_{max} = \sqrt{N}$.

Therefore, the congestion of $B_n$ is at most $\sqrt{N}$ when $n$ is even.

This completes the proof. $\blacksquare$

### **Part (b)**

> **Question:** Show that the congestion achieves $\sqrt{N}$ somewhere in the network and conclude that the congestion of $B_n$ is exactly $\sqrt{N}$ when $n$ is even.

**Solution:**

The structure of a butterfly network guarantees that the unique path from an input of $n$ bits to the output replaces bits layer by layer.

Representing the binary sequence from Most Significant Bit (MSB) to Least Significant Bit (LSB) as $x_n, x_{n-1}, \dots, x_1$, the path structure from input $X$ to output $Y$ is:

$$[x_n, x_{n-1}, \dots, x_2, x_1], \text{ level } 0$$

$$\downarrow$$

$$[x_n, x_{n-1}, \dots, x_2, y_1], \text{ level } 1$$

$$\downarrow$$

$$[x_n, x_{n-1}, \dots, y_2, y_1], \text{ level } 2$$

$$\downarrow$$

$$\dots$$

$$\downarrow$$

$$[y_n, y_{n-1}, \dots, y_2, y_1], \text{ level } n$$

Assume $n = 4$ such that $N = 16$. Then $n/2 = 2$ and $\sqrt{N} = 2^2 = 4$.

Let $v^\ast$ be the node at level $n/2 = 2$ whose binary representation is all $0$s.

It then follows from the structure shown above that a message from input $X$ to output $Y$ passes through node $0000_2$ at level $2$ if and only if:

$$S_{v^\ast} = \{0000_2, 0001_2, 0010_2, 0011_2\}$$

$$T_{v^\ast} = \{0000_2, 0100_2, 1000_2, 1100_2\}$$

That is to say, at level $2$, lower significance bits of the input have been set to match the LSBs of the output.

So to be at node $0000_2$, the destination must have $00_2$ as its LSBs.

The MSBs of the input have not been corrected.

For the node to be $0000_2$, the input's MSBs must be $00_2$.

Thus $x_4 x_3 = 00$ and $y_2 y_1 = 00$.

**Generalization for an even $n$:**

Because $v^\ast$ is the node at level $n/2$ represented by $[00\dots 00]_2$, an input reaches $v^\ast$ if and only if its first $n/2$ bits (MSBs) are zeros:

$$S_{v^\ast} = \{0^{n/2} \parallel w \mid w \in \{0, 1\}^{n/2}\}$$

where $\parallel$ denotes string concatenation and $w$ represents the lower $n/2$ bits.

The output is reachable from $v^\ast$ if its last $n/2$ bits (LSBs) are zeros:

$$T_{v^\ast} = \{w \parallel 0^{n/2} \mid w \in \{0, 1\}^{n/2}\}$$

where $w$ represents the upper $n/2$ bits.

To maximize congestion, we need a routing permutation $\pi$ that guarantees $\pi(X) \in T_{v^\ast}$ for every $X \in S_{v^\ast}$.

Looking at the bit patterns, this behaves exactly as a circular bit shift by $n/2$ positions.

Let $\pi : \{0, 1\}^n \to \{0, 1\}^n$ be defined as a circular left shift of the input string by $n/2$ bits.

If an input $X = x_n x_{n-1} \dots x_1$, then:

$$\pi(X) = x_{n/2} \dots x_1 x_n \dots x_{(n/2)+1}$$

**Proof that $\pi(X)$ is a bijection:**

Shifting the bits of $\pi(X)$ right by $n/2$ under circular shift exactly recovers the original input $X$.

Because every unique $n$-bit input maps to a unique $n$-bit output, $\pi$ is a bijection for all $N$ inputs.

**Proving the congestion bound:**

Consider input $X \in S_{v^\ast}$.

By definition, $X$ has the form $0^{n/2} \parallel w$.

Applying the bijection:

$$\pi(0^{n/2} \parallel w) = w \parallel 0^{n/2}$$

This maps exactly into the structural requirement for $T_{v^\ast}$.

Therefore under this route assignment, every message from the $2^{n/2}$ inputs in $S_{v^\ast}$ is destined for an output in $T_{v^\ast}$.

Because there is only one unique path between these sets, all $2^{n/2}$ messages are forced through the single vertex $v^\ast$.

From Part (a), we proved the congestion can never exceed $2^{n/2}$.

In Part (b), we constructed a valid permutation $\pi(X)$ that achieves exactly $2^{n/2}$ messages passing through a single node.

Since $2^{n/2} = \sqrt{N}$, we conclude the worst-case congestion of $B_n$ is exactly $\sqrt{N}$ when $n$ is even.

This completes the proof. $\blacksquare$
