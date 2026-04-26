# Recitation 6: Simple graphs

## Problem 1

*An undirected graph $G$ has width $w$ if the vertices can be arranged in a sequence $v_1, v_2, v_3, \dots, v_n$ such that each vertex $v_i$ is joined by an edge to at most $w$ preceding vertices. (Vertex $v_j$ precedes $v_i$ if $j < i$.) Use induction to prove that every graph with width at most $w$ is $(w+1)$-colorable.*

**Proof:**
Let $P(n)$ the proposition that Every graph with width $w$ is $(w+1)$-colourable.

**Base case $P(1)$**
$w = 0$, $1$-colourable - holds

**Inductive step.**
Assume $P(n)$.
Let $G$ be the graph with $(n+1)$-nodes and width $w_g$ such that $G = (V, E)$ and $V = \{v_1, v_2, ..., v_n, v_{n+1}\}$

Consider removing the node $v_{n+1}$.
By $P(n)$ we know the remaining set $V'$ is $(w+1)$-colourable.

Now consider adding back $v_{n+1}$. We can see there are atmost $w$ edges connecting to $v_{n+1}$.
Let the total pool of available colors be $C$, where $|C| = w+1$.

It then follows that we can color $v_{n+1}$ using a color from the $w+1$ colors, since all the neighbors of $v_{n+1}$ are guaranteed to use atmost $w$ colors $\implies P(n+1)$

This completes the inductive step and the proof.

---

## Problem 2

*A planar graph is a graph that can be drawn without any edges crossing.*

### 1. First, show that any subgraph of a planar graph is planar.

**Proof:**
Let $G'$ be a subgraph of the planar graph $G$
Assume for purpose of contradiction $G'$ is not planar.
This is the case if $G'$ has crossing edges.
But since $G'$ is a subgraph of $G$ then this implies $G$ has crossing edges.
But This contradicts the assumption that $G$ is planar. #
This completes the proof by contradiction

### 2. Also, any planar graph has a node of degree at most 5. Now, prove by induction that any graph can be colored in at most 6 colors.

**Proof:**
Let $P(n)$ be the proposition any $n$-node planar graph has a node of atmost degree at most 5 and Any planar graph can be coloured in atmost 6 colours.

**Base Case**
$n=1$, degree $= 0$, colour $= 1$. $1 \le 6$. holds

**Inductive Step**
Assume $P(n)$. Consider a $(n+1)$-node planar graph, $G = (V, E)$
and the set of nodes $V = \{v_1, v_2, ..., v_n, v_{n+1}\}.$
Since $G$ is planar then
$\exists v \in V(G)$ such that $\text{deg}(v) \le 5$

Consider removing $v$ from $V$ to create $G' = (V', E')$ which is planar and true for $P(n)$.
We know there are atmost 5 nodes connecting $v$ to $G'$.

It follows that there is atleast a colour remaining from the set of 6 colours that can be dedicated to $v$

---

# 6 Colouring Algorithm (Planar Graph)

### Procedure (Removal)

repeatedly identify a node $u$ where $\text{deg}(u) \le 5$, remove $u$ with its incident edges from the active graph, & push $u$ onto a stack (LIFO sequence).
Base case $|V| = 1$

### Recolouring

Pop node of the stack one by one.
Because of (LIFO), we know by the proof the moment a node is popped, it is guaranteed to have a degree $\le 5$ to the already reinstated nodes.

And the proof shows we can keep on colouring using only 6 colors.

### Loop Invariant

**Invariant 1:** All Graphs at each recursive step are planar. This is true since $G$ is planar $\implies$ Subgraph $G'$ is planar. $\blacksquare$

**Invariant 2:** Just before a node is popped back into the Sub Graph and assigned a colour, the active Graph has a valid Graph colouring (no two adjacent nodes share a colour)
and the colouring uses atmost 6 colours.
By Invariant 1, the active Graph is Planar and by the Proof 2 it can be coloured validly by atmost 6-colours. $\blacksquare$

