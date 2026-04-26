# Problem Set 4

## Problem 1

**Proof that $G' = (V, M_1 \cup M_2)$ is bipartite given matchings $M_1$ and $M_2$.**

Let $M_1$ and $M_2$ be two matchings of $G$.

Consider $G' = (V, M_1 \cup M_2)$.

First note that the maximum degree on a node in the matching $M_1$ or $M_2$ is 1.  
The $M_1 \cup M_2$ can have a maximum node degree of 2.

Now notice that the only possible structures $G'$ can take are paths and cycles (since degree is limited to 2).

If $M_1 \cup M_2$ forms a cycle, then it must be an even cycle (alternating between $M_1$ and $M_2$).  
Assume starting at edge $E_0$ that belongs to $M_1$, then the closing edge $E_{end}$ must belong to $M_2$ or we will break matching rules.  
And this also shows if its a cycle then the number of edge can't be odd.

If $M_1 \cup M_2$ forms a path then it contains no cycles at all.

$\therefore$ It follows $G'$ is bipartite $\blacksquare$

---

## Problem 2

### (a)
**Proof that $2|E| = \sum_{v \in V} d_v$ where $d_v$ is the degree of a vertex $v$.**

**Lemma 1:** Every edge contribute exactly 2 degree to the total sum of degrees in the graph.

*P.f:* consider adding an edge $e$ to a graph such that the edge gets connected to node $u$ and $v$ (which is the only way, an edge can be connected to exactly two nodes).  
It follows that the degree of each node increase by 1  
$\therefore$ total increase is 2 $\blacksquare$

Let $|E|$ be $M$.  
Let $P(M)$ be the proposition:

$\sum_{v \in V} d_v = 2M$ where $d_v$ is the degree of a node $v$.

By Mathematical induction:

**Base case**, $M = 0$.  
Since there are no edges then every node has degree 0. $\underline{\text{holds}}$

**Inductive step** Assume $P(M)$.  
Consider an $M+1$ number of edges graph.

By Lemma 1, sum of all degrees must increase by 2.

$\therefore \sum_{v \in V} d_v + 2 = 2(M+1)$

By the inductive hypothesis:

$2M + 2 = 2(M+1) \implies P(M+1)$

This completes the inductive step and proof by induction $\blacksquare$

### (b)
**Determine if 111 students can each shake exactly 17 hands.**

Let the graph which characterize students shaking hands be $G = (V,E)$ where $|V| = 111$.

We can also notice that the degree $d_v$ of each student is 17.

$\therefore \sum_{v \in V} 17 = 17 \cdot 111 = 1887$

But from the proof from (a) we know:

$\sum_{v \in V} d_v = 2|E|$, which is a contradiction since $1887 \equiv 1 \pmod 2$. $\blacksquare$

The claim is false.

---

## Problem 3

### (a)
**Prove that a finite graph is bipartite if and only if it contains no cycles of odd length.**

$\Rightarrow$ Assume $G$ is Bipartite.
Then its vertices can be partitioned into two disjoint sets $V_1$ and $V_2$ such that every edge connects a vertex in $V_1$ to one in $V_2$.
A cycle must start and end at the same vertex.
Every step in the cycle alternates between $V_1$ and $V_2$.
To return to the starting set, the number of steps must be even.
$\therefore G$ contains no cycles of odd length.

$\Leftarrow$ Assume $G$ contains no cycles of odd length.
We want to show $G$ is Bipartite.
Assume $G$ is connected (if not, apply to each connected component).
Pick an arbitrary node $v \in V$.
Define $V_1 = \{u \in V \mid \text{shortest path from } v \text{ to } u \text{ is even length}\}$.
Define $V_2 = \{u \in V \mid \text{shortest path from } v \text{ to } u \text{ is odd length}\}$.
Suppose $x, y \in V_1$ are adjacent.
Then there is a cycle: $v \rightarrow \dots \rightarrow x \rightarrow y \rightarrow \dots \rightarrow v$.
The length of this cycle is (even) + 1 + (even) = odd.
This contradicts our assumption that $G$ has no cycles of odd length.
$\therefore$ No two nodes in $V_1$ are adjacent. (Similarly for $V_2$).
$\therefore G$ is Bipartite. $\blacksquare$

### (b)
**If $G$ contains a closed walk of odd length, then $G$ contains a cycle of odd length.**

Let $W = v_0, e_1, v_1, e_2, \dots, e_k, v_k$ where $v_0 = v_k$ and $k$ is odd.
Let $W$ be the shortest closed walk of odd length in $G$.
Suppose $W$ is not a cycle.
Then some vertex is repeated, say $v_i = v_j$ for $0 \leq i < j < k$.
We can split $W$ into two closed walks:
$W_1 = v_i \rightarrow \dots \rightarrow v_j$
$W_2 = v_0 \rightarrow \dots \rightarrow v_i \rightarrow v_{j+1} \rightarrow \dots \rightarrow v_k$
The sum of the lengths of $W_1$ and $W_2$ is $k$ (which is odd).
Therefore, one must be odd and the other even.
Suppose $W_1$ is odd.
Length of $W_1 < k$.
This contradicts that $W$ is the shortest closed walk of odd length.
$\therefore W$ must be a cycle. $\blacksquare$

---

## Problem 4

**State whether each of the following statements is true or false. If the statement is true, give a short proof. If the statement is false, give a counter-example.**

### (a) Let $G=(V,E)$ be a simple graph. Then $G$ must contain a cycle of length $\geq 3$ or an independent set of size $\geq 3$.
False. 
Counter-example: $K_2$.
$K_2$ has no cycles and its maximum independent set size is 1.

### (b) If $G$ has an Eulerian walk, then $G$ must be connected.
False. 
Counter-example: A graph with an Eulerian walk but also isolated vertices (degree 0). The walk traverses all edges, but the graph is disconnected because of the isolated vertices.

### (c) If $G$ is a bipartite graph, then it cannot have an Eulerian cycle.
False. 
Counter-example: $C_4$.
$C_4$ is an even cycle so it is bipartite, and it has an Eulerian cycle because every vertex has an even degree.

### (d) Let $G$ be a connected simple graph. If $G$ has an Eulerian cycle, then every vertex of $G$ has even degree.
True.
Proof: Let $C$ be an Eulerian cycle in $G$.
$C$ traverses every edge exactly once.
For every time $C$ enters a vertex $v$, it must also leave $v$.
Each visit (enter and leave) contributes 2 to the degree of $v$.
Since $C$ starts and ends at the same vertex, the first leaving edge and last entering edge also contribute 2.
$\therefore$ Every vertex must have an even degree. $\blacksquare$

---

## Problem 5

**Let $G = (V,E)$ be a simple bipartite graph. Let $|V| = n$. Show that $|E| \leq \frac{n^2}{4}$.**

Let $G = (V_1 \cup V_2, E)$ be a bipartite graph where $|V_1| + |V_2| = n$.
The max number of edges is when every node in $V_1$ is connected to every node in $V_2$.
So $|E| \leq |V_1||V_2|$.
Let $|V_1| = x$, then $|V_2| = n - x$.
$|E| \leq x(n-x) = nx - x^2$.
To find the maximum, take the derivative and set to 0.
$\frac{d}{dx} (nx - x^2) = n - 2x = 0$
$2x = n \implies x = \frac{n}{2}$
$\therefore$ max edges $= (\frac{n}{2})(n - \frac{n}{2}) = \frac{n^2}{4}$.
$\therefore |E| \leq \frac{n^2}{4}$ $\blacksquare$

---

## Problem 6

**Prove that every $k$-regular bipartite graph has a perfect matching.**

Let $G = (V_1 \cup V_2, E)$ be a $k$-regular bipartite graph ($k \geq 1$).

First we prove $|V_1| = |V_2|$. Total edges $|E| = \sum_{v \in V_1} \text{deg}(v) = k|V_1|$.
Also $|E| = \sum_{v \in V_2} \text{deg}(v) = k|V_2|$.
$\therefore k|V_1| = k|V_2| \implies |V_1| = |V_2|$.

We will use Hall's Marriage Theorem: $G$ has a matching covering $V_1$ iff $|N(A)| \geq |A|$ for all $A \subseteq V_1$.

Let $A \subseteq V_1$. Let $E_A$ be the set of edges incident to vertices in $A$.
Since each vertex has degree $k$, $|E_A| = k|A|$.

All these edges must connect to vertices in $N(A)$.
The maximum number of edges the vertices in $N(A)$ can 'accept' is $k|N(A)|$.

$\therefore k|A| \leq k|N(A)| \implies |A| \leq |N(A)|$.

Therefore, by Hall's Marriage Theorem, $G$ contains a matching that covers $V_1$.
Since $|V_1| = |V_2|$, this matching is a perfect matching. $\blacksquare$

---

## Problem 7

**Show that a tree with $n \geq 2$ vertices has at least 2 leaves (vertices of degree 1).**

Let $T$ be a tree with $n \geq 2$ vertices.

Consider the longest simple path in $T$, let it be $P = v_1, e_1, v_2, \dots, e_k, v_{k+1}$.
Since $n \geq 2$, $P$ has at least one edge.

The vertex $v_1$ has degree 1 in $T$. If it had another neighbor $u$, then either $u$ is in $P$ (creating a cycle, which is a contradiction since $T$ is a tree) or $u$ is not in $P$ (which would make a longer path, contradicting that $P$ is the longest simple path).

Similarly, $v_{k+1}$ must have degree 1.

Therefore $v_1$ and $v_{k+1}$ are leaves. $T$ has at least 2 leaves. $\blacksquare$

---

## Problem 8

**Prove that a tree with $n$ vertices has exactly $n-1$ edges.**

Proof by induction on $n$.

**Base case:** $n=1$. 
$T$ has 1 vertex and 0 edges. $1 - 1 = 0$. Holds.

**Inductive step:** Assume any tree with $k$ vertices has $k-1$ edges.

Consider a tree $T$ with $k+1$ vertices. By the previous problem, $T$ has at least one leaf $v$.
Remove $v$ and its incident edge $e$ to get $T'$.
$T'$ is connected and acyclic, so $T'$ is a tree with $k$ vertices.

By the inductive hypothesis, $T'$ has $k-1$ edges.
Since $T$ has one more edge than $T'$, $T$ has $(k-1) + 1 = k$ edges.

This completes the proof by induction. $\blacksquare$

---

## Problem 9

**What is the max number of leaves in a tree with $n$ vertices? min number?**

**Max number of leaves:** $n-1$.
This happens in a star graph where 1 central node is connected to $n-1$ leaves.

**Min number of leaves:** $2$.
This happens in a path graph where all nodes are arranged in a single line, so only the two endpoints are leaves.