# Problems for Recitation 9: Traveling Salesperson Problem

Let $OPT$ be the optimum TSP tour cost.

### 1. Show that the cost of any tour is at least the cost of an MST of $G$. Hence conclude that the cost of an MST is at most $OPT$.

**Proof:**

A valid TSP tour is a Hamiltonian cycle. Let the TSP tour be $T_{opt}$. Consider removing an edge $e \in T_{opt}$.

By def, this remaining structure connects all nodes with no cycle, it is a spanning tree. Let the spanning tree be $T_{path}$.

An MST $T$ of $G$ is a spanning tree whose sum of edge weight is as small as possible.

$\therefore$ let minimum possible sum cost be $C_{min}$ then $Cost(T) = C_{min}$

It logically follows that

$Cost(T) \le Cost(T_{path})$ since $T_{path}$ cost can be atleast minimum possible cost.

This implies $Cost(T) \le Cost(T_{path}) \le Cost(T_{opt})$

$\Rightarrow Cost(T) \le Cost(T_{opt})$

This completes the proof $\blacksquare$

---

### 2. Prove that the size of $S$ is even.

**Proof:**

Let S be the set of all nodes in G that have odd degree

$S = \{ A \in G : d_A \text{ is odd} \}$ where $d_A$ is degree of node A.

let $S'$ be the set $V - S$. Notice $S' \cap S = \emptyset$.

By the handshaking lemma we know

$\sum_{v \in V} d_v = 2|E|$ for any n-node graph where V is set of all node, E is set of all edges and $d_v$ is degree of a node $v \in V$.

It follows from this lemma that if

$V_{sum} = \sum_{v \in V} d_v$ then

$V_{sum} \equiv 0 \pmod 2$.

$\therefore$ It follows that

$$V_{sum} = \left( \sum_{a \in S} d_a + \sum_{b \in S'} d_b \right) \equiv 0 \pmod 2 \quad (1)$$

we know $\sum_{b \in S'} d_b \equiv 0 \pmod 2$ since

$\forall b \in S', d_b = 0 \pmod 2$.

We know that $\forall a \in S, d_a = 1 \pmod 2$.

From (2),

$$V_{sum} \equiv 0 \pmod 2$$

it then follow that

$|S| \equiv 0 \pmod 2$ by parity of sum of odd integers.

That is to say that $V_{sum} \equiv 0 \pmod 2$

iif $|S| \equiv 0 \pmod 2$ otherwise

$V_{sum}$ would be odd.

This completes the proof $\blacksquare$


### 3. Prove that the weight of the min weight perfect matching is at most $OPT/2$.

**Proof:**

Let $S = \{ A \in V : d_A \text{ is odd} \}$

Let $T_{opt}$ be the optimal TSP tour on the entire graph $G$,
where $Cost(T_{opt}) = OPT$

Consider a $C_S$ that visits only the nodes in $S$, bypassing all other nodesbut maintaining the same relative visiting order as $T_{opt}$.

If $A, C \in S$ and $T_{opt}$ visits path

$A \to B \to C$ and $B \notin S$

then by triangle rule we know

$d(A, C) \le d(A, B) + d(B, C)$.

It then follows that
$Cost(C_S) \le OPT$.

We know $|S|$ is even.

Then $C_S$ consist of an even number of edges.

Consider alternate 2-colouring of the edges of $C_S$ into two distinct set of edges.

The resulting edges are entirely disconnected from one another,

However every single node in the set
$S$ is touched by exactly one of these
edges

$\therefore$ this a perfect matching.

Let the two alternating set of edges

be $M_1$ and $M_2$.

Let $M'$ be the minimum weight
perfect matching on $S$.

It the follows that

$Cost(M) \le Cost(M_1) \le Cost(C_S) \le OPT$,

same for $Cost(M_2)$

Since $|S|$ is even then

$|M_1| = |M_2|$

$\implies Cost(M_1) \le \frac{OPT}{2} \land Cost(M_2) \le \frac{OPT}{2}$

The follows conclusion that

$Cost(M) \le OPT/2 \quad \blacksquare$


### 4. Prove that $G'$ has an Euler circuit, and its cost is at most $3OPT/2$.

**Proof:**

4. Prove $G'$ has an Euler circuit and cost is atmost $3OPT/2$

Recall that $G' = (V, E')$ where $E' = M \cup T$ and $M$ is perfect matching on $S$ and $T$ edges of MST of $G$.

a) Proof that $\exists$ Euler circuit in $G'$.

A connected graph has an Euler circuit if every node has even degree.

That is

$\exists \text{Euler circuit } N \text{ of } G' \implies \forall n \in V, d_n \equiv 0 \pmod 2$

We defined Set of nodes S to contain all nodes $v \in$ of MST T that have odd degree.

Perfect matching M added exactly 1 to the degree of each of the node in S, and these edges did not exist in T.

$M \cup T$ is guaranteed to have even degree for all nodes.

That is to say every $v \notin S$ had even degree and is unchanged and $v \in S$ has odd degree and had its degree increased by 1.

We know

$Cost(G') = Cost(T) + Cost(M) - Cost(T \cap M)$.

But since $T \cap M = \emptyset$ since M has edges that did not exist in T,

Then $Cost(T \cap M) = 0$

Since we know $Cost(T) \le OPT$ and $Cost(M) \le OPT/2$,

It follows that

$Cost(G') \le OPT + OPT/2$

$\Rightarrow Cost(G') \le 3OPT/2$

This completes the proof $\blacksquare$

---

### 5. Show that the length of the TSP tour is at most $3OPT/2$.

**Proof:**

5. Let $E_{cir}$ be the Euler circuit on $G'$ and let $T_{final}$ be the resulting TSP tour.
6. 
Notice that $T_{final}$ is a hamiltonian cycle of $E_{cir}$.

Consider nodes A, B, C where we want to travel from A to C and B was already touched, then we take the shortest path to C bypassing B, and by triangle inequality we know

$d(A,C) \le d(A,B) + d(B,C)$

$\therefore Cost(T_{final}) \le Cost(E_{cir})$

From (4) we know that

$Cost(E_{cir}) \le 3OPT/2$

$\Rightarrow \text{Cost}(T_{\text{final}}) \le 3\text{OPT}/2$


This completes the proof $\blacksquare$

---

### 6. Conclude that our algorithm outputs a 3/2-approximation.

**Proof:**

Since $T_{final}$ is a valid round-trip route visiting each city once and has cost atmost $3/2 \cdot OPT$, it then follows that our algorithm outputs a $3/2$-approximation 

This completes the proof of the algorithm $\blacksquare$
