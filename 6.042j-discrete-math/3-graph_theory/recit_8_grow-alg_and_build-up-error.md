# Problems for Recitation 8

## 1 Build-up error

Recall a graph is connected iff there is a path between every pair of its vertices.

**False Claim.** If every vertex in a graph has positive degree, then the graph is connected.

Prove that this Claim is indeed false by providing a counterexample.

Since the Claim is false, there must be a logical mistake in the following bogus proof. Pinpoint the first logical mistake (unjustified step) in the proof.

**Proof.** We prove the Claim above by induction. Let $P(n)$ be the proposition that if every vertex in an $n$-vertex graph has positive degree, then the graph is connected.

**Base cases:** ($n \le 2$). In a graph with 1 vertex, that vertex cannot have positive degree, so $P(1)$ holds vacuously. 
$P(2)$ holds because there is only one graph with two vertices of positive degree, namely, the graph with an edge between the vertices, and this graph is connected.

**Inductive step:** We must show that $P(n)$ implies $P(n+1)$ for all $n \ge 2$.

Consider an $n$-vertex graph in which every vertex has positive degree.

By the assumption $P(n)$, this graph is connected; that is, there is a path between every pair of vertices.

Now we add one more vertex $x$ to obtain an $(n+1)$-vertex graph: obtain a path from $x$ to $z$ by going from $x$ to $y$ and then following the path from $y$ to $z$. This proves $P(n+1)$.

By the principle of induction, $P(n)$ is true for all $n \ge 0$, which proves the Claim. $\square$

### Solution to Problem 1

$G$ is connected iff

$\forall u, v \in V, \exists$ path from $u$ to $v$ (1)

**False claim:**

 For a graph $G = (V,E)$,

$\forall n \in V, \text{deg}(n) > 0 \implies \text{connected}$

**Counterexample:**

 Consider a graph $G = (V,E)$ 

such that $V = \{a, b, c, d\}$ and  

$E = \{(a, b), (c, d)\}$  

$\forall n \in V, \text{deg}(n) > 0$ is true  

But (1) fails since $\neg \exists$ path $b$ to $c$  

This is a contradiction to the claim,  

$\therefore$ claim is false $\blacksquare$  

The problem is the inductive step starts with a good $n$-node graph then add a node.  

This works only for a subset of $(n+1)$-node graph when $\forall n \in V, \text{deg}(n) > 0$  

Consider trying to build the counter example from 1 

We start with a connected 3-node graph. Adding a node and edge definitely makes a connected graph.  

Graph induction must shrink down not build up.  

---

## 2 The Grow Algorithm


**ALG-GROW:**  

Label the edges of the graph $e_1, e_2, \dots, e_t$ so that $wt(e_1) \le wt(e_2) \dots \le wt(e_t)$. 

Let $S$ be the empty set.  

For $i = 1 \dots t$, if $S \cup \{e_i\}$ does not contain a cycle, then extend $S$ with the edge $e_i$.  

Output $S$.

### 2.1 Analysis of ALG-GROW

In this problem i will assume the following lemma from the problem set:  

**Lemma 1.**

 Suppose that $T = (V,E)$ is a simple, connected graph. Then $T$ is a tree iff $|E| = |V| - 1$.

i will prove the following theorem.  

**Theorem.** 

For any connected, weighted graph $G$, ALG-GROW produces an MST of $G$.

---

### Part (a)

**(a) Prove the following lemma.** 

**Lemma 2.** Let $T = (V,E)$ be a tree and let $e$ be an edge not in $E$. Then, $G = (V, E \cup \{e\})$ contains a cycle.  

#### Proof

First we know by def of a tree, 

$T$ is a connected graph. (1)

By lemma 1, we know  

$|E| + 1 = |V|$  

adding an edge we get  

$|E| = |V|$  

$G = (V, E \cup \{e\})$ is not a tree (2)  

Notice that adding an edge does not invalidate the property that a connected graph is connected, that is the property  

$\forall u, v \in V, \exists$ path from $u$ to $v$  

still holds for $G$ since $|V_G| = |V_T|$,  

$\therefore G$ is connected (3)  

It follows from (2) and (3) that  

$G$ is connected and is not a tree.  

$G$ is not a tree $\implies G$ has a cycle.  

This completes the proof $\blacksquare$  

---

### Part (b)

**(b) Prove the following lemma.**  

**Lemma 3.**

Let $T = (V,E)$ be a spanning tree of $G$ and let $e$ be an edge not in $E$. 

Then there exists an edge $e' \neq e$ in $E$ such that $T^* = (V, E - \{e'\} \cup \{e\})$ is a spanning tree of $G$.  

#### Proof

Let $T = (V,E)$ be a spanning tree of $G$.  

We know $T$ is connected and has no cycles.  

Let the new edge $e$ connect nodes $u$ to $v$.  

Then before $e$ was added, there existed path between $u$ to $v$.  

By Lemma 2 we know  

$G = (V, E \cup \{e\})$ has a cycle.  

This is actually clear from the fact that,  

Since there existed path $P$ from $u$ to $v$  

adding edge $e = (u,v)$ closed the path and made cycle  

$C = P \cup \{e\}$  

Then choosing $e'$ from the edges of $P$  

guarantees $e' \neq e$ and $e' \in E$.  

Removing $e'$ breaks the cycle  

$\therefore$ we have shown $e'$ exists $\blacksquare$  

**Claim:** $T^* = (V, E - \{e'\} \cup \{e\})$ is a spanning tree of $G$ 

We must show that  

$T^*$ spans $G$, has no cycles, is connected  

**Proof that $T^*$ is connected**  

We know that adding edge $e$ creates a cycle  

$C = P \cup \{e\}$  

We know that $T^*$ has no cycle $C$.  

Lets analyze two cases  

**Case 1:** 

Original path between $X$ and $Y$ in $T$ did not utilize the edge $e'$.  

Then removing the $e'$ does not make $X$ and $Y$ disconnected from each other.

**Case 2:** 

Original path between $X$ and $Y$ did utilize $e'$.  

Let the path be $K$, that utilized edge $e'$  

if we consider adding edge $e$ such that $e$ connects $u$ to $v$ and $u$ and $v$ are part of $K$, 

then $K$ is closed and we form a cycle $C$ such that  

$C = K \cup \{e\}$.  

Consider removing an arbitrary edge $e^* \in K$ from the cycle $C$.  

Since $C$ is a cycle then this creates a new path $K'$ from any node $u' \in C$ to any node $v' \in C$. 

$\therefore$ there is guaranteed to be a path between all nodes of a cycle after an arbitrary edge is removed. 

It then follows that  

$\exists$ path $K'$ between any nodes in the $C$ such that $K' = C - \{e^*\}$  

$\therefore$ nodes $X$ and $Y$ can utilize the path $K'$, making $X$ and $Y$ connected.  

$\therefore T^*$ is connected $\blacksquare$  

It also follows that $T^*$ spans all $G$ $\blacksquare$  

**Proof that $T^*$ has no cycles.**  

First note that adding an edge $e$ to path $P$ where $T$ contained no cycles increase the cycle count exactly by 1,  

$G = (V, E \cup \{e\})$ has a single cycle  

This follows from the fact that edge $e$ closed exactly one path, that is path $P$ from $u$ to $v$.  

$\therefore$ removing edge $e'$ from the cycle $C = P \cup \{e\}$ is supposed to break the cycle and decrease cycle count by 1 such that  

$T^* = (V, E \cup \{e\} - \{e'\})$ has cycle count $= 0$.  

$\therefore T^*$ has no cycles $\blacksquare$  

It follows from all the above proofs that $T^*$ is a spanning tree of $G$. 

This completes the proof  $\blacksquare$  

---

### Part (c)

**(c) Prove the following lemma.**  

**Lemma 4.**

 Let $T = (V,E)$ be a spanning tree of $G$, let $e$ be an edge not in $E$ and let $S \subseteq E$ such that $S \cup \{e\}$ does not contain a cycle.
 
  Then there exists an edge $e' \neq e$ in $E - S$ such that $T^* = (V, E - \{e'\} \cup \{e\})$ is a spanning tree of $G$.  

#### Proof

Suppose for the sake of contradiction that $\neg \exists$ an edge $e' \neq e$ in $E - S$ such that $T^* = (V, E - \{e'\} \cup \{e\})$ is a spanning tree of $G$.  

Using the path $P$ from the cycle $C = P \cup \{e\}$ from Lemma 3,

This would mean every edge in $P$ is an element of $S$, that is to say $P \subseteq S$.  

We defined $P$ to be a path connecting node $u \in E$ to node $v \in E$.  

But since we assume $P \subseteq S$,  

it follows that $u \in S$ and $v \in S$  

Let $e$ be an edge connecting node $u$ to node $v$,  

It follows that $S \cup \{e\}$ closes the path and creates a cycle,  

Which is a contradiction to the premise that $S \cup \{e\}$ does not contain a cycle #  

We know that e must cause some path cycle $C'$ such that $e'$ will break it.  

$\implies e', e \in C'$,  

but since $S \cup \{e\}$ does not contain a cycle  

$\implies$ it follows that $e' \notin S$,  

But since $e' \in E$,  

it follows that $e' \in E - S$.  

This completes the proof $\blacksquare$

---

### Part (d)

**(d) Prove the following lemma.**  

**Lemma 5.** 

Define $S_m$ to be the set consisting of the first $m$ edges selected by ALG-GROW from a connected graph $G$. Let $P(m)$ be the predicate that if $m \le |V|$ then $S_m \subseteq E$ for some MST $T = (V,E)$ of $G$. Then $\forall m \ . \ P(m)$.  

#### Proof

Let $P(m)$ be the predicate.  

**Base case:** $P(0)$. $S_m = \emptyset$. Then $S_m \subseteq E$  

**Base case:** $P(1)$. Since a single edge has no cycle then $S_m \subseteq E$.  

**Inductive step:** Assume $P(m)$ for an arbitrary $m > 0$. We need to prove $P(m+1)$.  

**Case 1:** $m + 1 > |V|$.  

$P(m+1) \implies S_{m+1} \subseteq E$ by logical implication of a false hypothesis.  

Therefore case 1 is vacuously true $\blacksquare$  

**Case 2:** $m + 1 \le |V|$  

The hypothesis is true,  

$\therefore$ to prove $P(m+1)$ we must prove the conclusion $S_{m+1} \subseteq E^{\ast}$ for some MST $T^{\ast} = (V, E^{\ast})$ of $G$.  

By $P(m)$ we know $S_m \subseteq E$ for a specific MST $T = (V, E)$.  

During step $m+1$, ALG-GROW selects a new valid edge $e$  

$\therefore$ our new set of edge is $S_{m+1} = S_m \cup \{e\}$  

**Subcase 2.1:**    $e \in E$.  

Let $\{e\}$ be a single element set with $e$ as its only element.  

$\therefore S_m \subseteq E \land \{e\} \subseteq E$. We know $S_{m+1} = S_m \cup \{e\}$  

$\implies S_{m+1} \subseteq E$ $\blacksquare$  

**Subcase 2.2:**     $e \notin E$.  

Since $e \notin E$, it is impossible for $S_{m+1}$ to be subset of $E$. 

Therefore to prove $P(m+1)$, we must construct new MST,  

$T^{\ast} = (V, E^{\ast})$ and prove that $S_{m+1} \subseteq E^{\ast}$

Mapping our current state to lemma 4,  

let our MST $T$ be the spanning tree of $G$.  

Let $e$ be the new edge, which we also know $e \notin E$.  

Let $S_m$ be the subset $S$.  

Condition $S_m \cup \{e\}$ has no cycle holds since by the operational def of ALG-GROW, $e$ is chosen such that it does not form a cycle with the selected edges $S_m$.  

$\therefore S_m \cup \{e\}$ is acyclic.  

Precondition satisfied  

By Lemma 4 we know $\exists$ edge $e'$ and new spanning tree  

$T^* = (V, E^*)$.  

we know $E^* = E - \{e'\} \cup \{e\}$  

Since $e, e' \notin S_m$  

$\therefore E^*$ did not alter $S_m$, then  

$S_m \subseteq E^*$  

Since $\{e\} \subseteq E^*$  

it follows that  

$S_{m+1} \subseteq E^*$ $\blacksquare$  


#### Claim: $T^*$ is still MST

#### Proof

By the greedy nature of ALG-GROW, it always selects the minimum weight edge that does not form a cycle.  

Since $e'$ was not selected  
  
Since $e'$ was not in $S_m$ and ALG-GROW chose $e$ instead, it must be true that the weight $w(e) \le w(e')$.  

Since $T^{\ast}$ removes $e'$ and adds $e$, the total weight of $T^{\ast}$ is less than or equal to total weight of original MST $T$.  

Since a tree can't have weight lower than absolute minimum, $T^*$ must also be exactly minimum weight.  

$T^{\ast}$ is an MST and $S_{m+1} \subseteq E^{\ast}$

This completes the inductive and $P(m) \implies P(m+1)$,

and the follows from it $\blacksquare$

---

### Part (e)

**(e) Prove the theorem.**  

#### Proof

**Theorem:** For any connected weighted graph $G$, ALG-GROW produces MST of $G$  

By def ALG-GROW terminates exactly when it has selected $|V|-1$ edges.  

Let this final set of edges be $S_{|V|-1}$  

Claim: According to Lemma 5,  

$|S_{|V|-1}| = |E|$ where $E$ is set of edges of some MST $T$.  

This follows from lemma 1, that  

$S_{|V|-1} = S_{|E|}$  

And since an MST must have the absolute minimum possible number of edges  

$\therefore$ It follows that $S_{|V|-1} \subseteq E \land |S_{|V|-1}| = |E|$  

$\therefore S_{|V|-1} = E$ $\blacksquare$  

This completes the proof of the Theorem $\blacksquare$v