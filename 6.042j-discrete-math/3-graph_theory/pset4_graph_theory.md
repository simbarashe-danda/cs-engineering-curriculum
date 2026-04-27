## Problem 1

> **Problem 1. [15 points]** Let $G = (V,E)$ be a graph. A matching in $G$ is a set $M \subset E$ such that no two edges in $M$ are incident on a common vertex.
> 
> Let $M_1, M_2$ be two matchings of $G$. Consider the new graph $G' = (V, M_1 \cup M_2)$ (i.e. on the same vertex set, whose edges consist of all the edges that appear in either $M_1$ or $M_2$). Show that $G'$ is bipartite.
> 
> *Helpful definition: A connected component is a subgraph of a graph consisting of some vertex and every node and edge that is connected to that vertex.*

**Solution:**

Let $M_1$ and $M_2$ be two matchings of $G$.

Consider $G' = (V, M_1 \cup M_2)$.

Proof that $G'$ is Bipartite

First note that the maximum degree of a node in the matching $M_1$ or $M_2$ is 1.
The $M_1 \cup M_2$ can have a maximum node degree of 2.

Now notice that the only possible structures $G'$ can take are paths and cycles (since degree is limited to 2).

If $M_1 \cup M_2$ forms a cycle, then it must be an even cycle (alternating between $M_1$ and $M_2$).
Assume starting at node $v_0$ that belongs to $M_1$, then the closing edge $E_{end}$ must belong to $M_2$ or we will break matching rules.
And this also shows if its a cycle then the number of edges can't be odd.

If $M_1 \cup M_2$ forms a path then it contains no cycles at all.

$\therefore$ It follows $G'$ is bipartite $\blacksquare$

---

## Problem 2 (a)

> **Problem 2. [20 points]** Let $G = (V, E)$ be a graph. Recall that the degree of a vertex $v \in V$, denoted $d_v$, is the number of vertices $w$ such that there is an edge between $v$ and $w$.
> 
> **(a) [10 pts]** Prove that 
> $$2|E| = \sum_{v \in V} d_v$$

**Solution:**

Proof that $2|E| = \sum_{v \in V} d_v$ where $d_v$ is the degree of a vertex $v$.

Lemma 1: Every edge contributes exactly 2 degrees to the total sum of degrees in the graph.

P.f: Consider adding an edge $e$ to a graph such that the edge gets connected to node $u$ and $v$ (which is the only way, an edge can be connected to exactly two nodes).
It follows that the degree of each node increases by $1 \Rightarrow$ total increase is $2 \blacksquare$

Let $|E|$ be $M$.
Let $P(M)$ be the proposition:
$\sum_{v \in V} d_v = 2M$ where $d_v$ is the degree of a node $v$.

By Mathematical induction:

Base case, $M=0$.
Since there are no edges then every node has degree 0. holds.

Inductive step:
Assume $P(M)$
Consider an $M+1$ number of edges graph.

By Lemma 1, sum of all degrees must increase by 2
$\therefore \sum_{v \in V} d_v + 2 = 2(M+1)$

By the inductive hypothesis
$2M + 2 = 2(M+1) \Rightarrow P(M+1)$

This completes the inductive step and proof by induction $\blacksquare$

---

## Problem 2 (b)

> **(b) [5 pts]** At a 6.042 ice cream study session (where the ice cream is plentiful and it helps you study too) 111 students showed up. During the session, some students shook hands with each other (everybody being happy and content with the ice-cream and all). Turns out that the University of Chicago did another spectacular study here, and counted that each student shook hands with exactly 17 other students. Can you debunk this too?

**Solution:**

b) Let the graph which characterize students shaking hands be 
$G = (V,E)$ where $|V| = 111$.

We can also note that the degree $d_v$ of each student is 17
$\therefore \sum_{v \in V} 17 = 17 \cdot 111 = 1887$

But from the proof from (a) we know
$\sum_{v \in V} d_v = 2|E|$, which is a contradiction since $1887 \equiv 1 \pmod 2$.

$\therefore$ The claim is false $\blacksquare$

---

## Problem 2 (c)

> **(c) [5 pts]** And on a more dull note, how many edges does $K_n$, the complete graph on $n$ vertices, have?

**Solution:**

c) By def, a complete graph contain every possible edge.

If there are $n$-nodes then each node $v \in V$ must have exactly a degree of 
$d_v = n-1$

Applying theorem:
$2|E| = \sum_{v \in V} d_v$
$2|E| = n \cdot (n-1)$
$|E| = \frac{n(n-1)}{2}$

$\therefore \frac{n(n-1)}{2} \blacksquare$


## Problem 3

### (a) Properties Preserved Under Isomorphism
Which of these properties are preserved under isomorphism?

1.  **$G$ has an even number of vertices.**
    * **Preserved.** If two graphs are isomorphic, there is a bijection between their vertex sets; therefore, $|V_1| = |V_2|$.
2.  **None of the vertices of $G$ is an even integer.**
    * **Not Preserved.** This is a property of the labeling/naming of vertices, not the structure of the graph itself.
3.  **$G$ has a vertex of degree 3.**
    * **Preserved.** Isomorphism preserves the adjacency and degree of corresponding vertices.
4.  **$G$ has exactly one vertex of degree 3.**
    * **Preserved.** Since degrees are preserved, the number of vertices with a specific degree must remain constant.

---

### (b) Isomorphism Identification
**Goal:** Determine which of the four graphs ($G_1, G_2, G_3, G_4$) are isomorphic.

![Figure 1: Graphs for Problem 3b](problem_3b.png)


#### 1. Filtering by Invariants
* **Number of Nodes:** $|V| = 10$ for all graphs.
* **Number of Edges:**
    * $G_1: 15$
    * $G_2: 16$
    * $G_3: 15$
    * $G_4: 15$
    * *Result:* Eliminate $G_2$ because $|E|$ differs.
* **Degree Sequence:**
    * $G_1, G_3, G_4$ are all 3-regular (every vertex has degree 3).
* **Girth (Shortest Cycle):**
    * $G_1: 5$
    * $G_3: 5$
    * $G_4: 4$ (e.g., the cycle $1-6-7-2-1$)
    * *Result:* Eliminate $G_4$.

**Candidates for Isomorphism:** $\{G_1, G_3\}$.

#### 2. Establishing the Mapping $f: G_1 \to G_3$
By identifying corresponding cycles and forced adjacencies, we define the following isomorphism:

| $G_1$ Vertex | $G_3$ Vertex |
| :--- | :--- |
| $v_1$ | $w_1$ |
| $v_2$ | $w_2$ |
| $v_3$ | $w_3$ |
| $v_4$ | $w_4$ |
| $v_5$ | $w_{10}$ |
| $v_6$ | $w_9$ |
| $v_7$ | $w_8$ |
| $v_8$ | $w_7$ |
| $v_9$ | $w_6$ |
| $v_{10}$ | $w_5$ |

---

## Problem 4

### (a) Counterexample for $k = 2$
**Claim:** If $G$ has max degree $\le k$ and has at least one node with degree $< k$, then $G$ is $k$-colorable.

**Counterexample:**
Let $G$ be a disjoint union of two components, $C_1$ and $C_2$:
* **Component $C_1$:** A triangle ($K_3$) with vertices $\{1, 2, 3\}$.
    * Max degree is 2.
    * It is **not** 2-colorable (requires 3 colors).
* **Component $C_2$:** A single edge ($K_2$) with vertices $\{a, b\}$.
    * Degree of $a = 1$, which is $< k$ (where $k=2$).

**Conclusion:** Even though $G$ has a vertex with degree $< 2$, the entire graph is not 2-colorable because of the odd cycle in $C_1$. Thus, the claim is invalid.

### (b) Error in the Proof
**The Sentence:** "Removing $v$ reduces the degree of all vertices adjacent to $v$ by 1. So in $G_n$, each of these vertices has degree less than $k$."

**The Flaw:** If the removed vertex $v$ has a degree of 0 (it is isolated), it has no neighbors. Therefore, removing it does not reduce the degree of any other vertices, and the inductive step fails to guarantee a vertex of degree $< k$ in $G_n$.

---

## Problem 5: Stable Matching Claim

**Claim:** For $n \ge 3$, there exists a preference set such that *every* dating arrangement is stable.

**Disproof (by Contradiction for $n=3$):**
Let $V_b = \{b_1, b_2, b_3\}$ and $V_g = \{g_1, g_2, g_3\}$. For every matching to be stable, specific constraints must be met:
1.  **Constraint 1:** No two boys can share the same first-choice girl.
2.  **Constraint 2:** No two girls can share the same first-choice boy.

Consider the following **Preference Matrices**:

| Boy | 1st | 2nd | 3rd | | Girl | 1st | 2nd | 3rd |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **$b_1$** | $g_1$ | $g_2$ | $g_3$ | | **$g_1$** | $b_2$ | $b_3$ | $b_1$ |
| **$b_2$** | $g_2$ | $g_3$ | $g_1$ | | **$g_2$** | $b_3$ | $b_1$ | $b_2$ |
| **$b_3$** | $g_3$ | $g_1$ | $g_2$ | | **$g_3$** | $b_1$ | $b_2$ | $b_3$ |

**Analysis of Matching $M = \{(b_1, g_1), (b_2, g_3), (b_3, g_2)\}$:**
* $b_3$ is matched with $g_2$ (his 3rd choice), but he prefers **$g_1$** (his 2nd choice).
* $g_1$ is matched with $b_1$ (her 3rd choice), but she prefers **$b_3$** (her 2nd choice).

**Result:** The pair $(b_3, g_1)$ forms a **rogue couple**, making the matching unstable. Since we established a set of preferences following the "perfect" constraints and still found an unstable matching, the claim is false.