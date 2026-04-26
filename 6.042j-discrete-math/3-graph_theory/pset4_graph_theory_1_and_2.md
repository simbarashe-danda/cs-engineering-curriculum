# 6.042 / 18.062J — Problem Set 4

Course: 6.042/18.062J Mathematics for Computer Science (Fall 2010)
Authors: Tom Leighton and Marten van Dijk
Source: MIT OpenCourseWare — September 28, 2010

---

## Problem 1 — Union of Two Matchings is Bipartite (15 points)

Let M1 and M2 be two matchings of a graph G = (V, E). Consider the graph
G' = (V, M1 ∪ M2) whose edge set is all edges that appear in either M1 or M2.
Show that G' is bipartite.

Solution.

First note that every vertex in a matching has degree at most 1. Therefore in
G' every vertex has degree at most 2. Hence each connected component of G' is
either a path or a cycle.

If a connected component of G' is a cycle, the edges alternate between M1 and
M2, so the cycle length must be even. If a component is a path it contains no
cycle. Thus every connected component is bipartite, and therefore G' is
bipartite. ∎

---

## Problem 2 — Degree sum formula and applications (20 points)

(a) Prove that

  2|E| = Σ_{v∈V} d_v

where d_v denotes the degree of vertex v.

Solution.

Each edge contributes exactly 1 to the degree of each of its two endpoints,
so each edge contributes 2 to the sum of degrees. Summing over all edges gives
2|E| = Σ_v d_v. (An induction proof is also valid.) ∎

(b) At a session 111 students showed up, and each student shook hands with
exactly 17 others. Is this possible?

Solution.

If each of the 111 vertices has degree 17 then the sum of degrees is 111·17 =
1887, which is odd. But by part (a) the sum of degrees must equal 2|E|, an
even number. Contradiction — such a configuration is impossible. ∎

(c) How many edges does K_n (the complete graph on n vertices) have?

Solution.

Each of the n vertices has degree n−1, so Σ_v d_v = n(n−1) = 2|E|, hence
|E| = n(n−1)/2. ∎

---

## Problem 3 — Bipartiteness and odd cycles (15 points)

(a) Prove that a finite graph is bipartite if and only if it contains no odd
cycles.

Solution.

(⇒) If G is bipartite with parts V1 and V2, any cycle must alternate between
V1 and V2, so cycles have even length.

(⇐) Conversely, if G has no odd cycles, pick a vertex v and let V1 be the set
of vertices at even distance from v and V2 those at odd distance. If there
were an edge between two vertices in V1 it would create an odd cycle; hence
V1 and V2 are independent and G is bipartite. ∎

(b) Show that if G contains a closed walk of odd length then G contains an odd
cycle.

Solution.

Take a shortest closed odd walk; if some vertex repeats within the walk it
splits the walk into shorter closed walks, one of which must be odd, contradicting
minimality. Hence the shortest such walk is a cycle. ∎

---

## Problem 4 — True/False statements about graphs (15 points)

For each statement state True or False and give a brief justification or a
counterexample.

(a) Let G be a simple graph. Then G must contain a cycle of length ≥ 3 or an
independent set of size ≥ 3.

Answer: False. Counterexample: K_2 has no cycle and its largest independent set
has size 1.

(b) If G has an Eulerian walk, then G must be connected.

Answer: False. A graph can have an Eulerian walk that traverses all edges in a
connected component while isolated vertices (degree 0) make the graph
disconnected.

(c) If G is bipartite, then it cannot have an Eulerian cycle.

Answer: False. Example: a 4-cycle C4 is bipartite and has an Eulerian cycle
because all vertex degrees are even.

(d) Let G be a connected simple graph. If G has an Eulerian cycle, then every
vertex of G has even degree.

Answer: True. In an Eulerian cycle each time the tour enters a vertex it must
also leave it, contributing an even number to its degree. ∎

---

## Problem 5 — Maximum edges in a bipartite graph (15 points)

Let G = (V, E) be a simple bipartite graph with |V| = n. Show that
|E| ≤ n^2 / 4.

Solution.

Write V = V1 ∪ V2 with |V1| = x and |V2| = n−x. Then |E| ≤ x(n−x) = nx − x^2,
which is maximized at x = n/2, giving |E| ≤ n^2/4. ∎

---

## Problem 6 — k-regular bipartite graphs have perfect matchings (20 points)

Prove that every k-regular bipartite graph (k ≥ 1) has a perfect matching.

Solution.

First note k|V1| = |E| = k|V2|, so |V1| = |V2|. For any subset A ⊆ V1 consider the
set of edges incident to A; there are k|A| such edges, and they all go to N(A).
Since each vertex of N(A) has degree at most k, k|A| ≤ k|N(A)|, so |A| ≤ |N(A)|.
By Hall's theorem there is a matching that covers V1; since |V1| = |V2| this is a
perfect matching. ∎

---

## Problem 7 — Trees have at least two leaves (10 points)

Show that a tree with n ≥ 2 vertices has at least two leaves.

Solution.

Take a longest path in the tree. Its two endpoints have degree 1, otherwise the
path could be extended. Thus there are at least two leaves. ∎

---

## Problem 8 — Trees have n−1 edges (10 points)

Prove that any tree with n vertices has exactly n−1 edges.

Solution.

By induction on n: removing a leaf from an n-vertex tree yields an
(n−1)-vertex tree with (n−2) edges by the inductive hypothesis, so the original
tree had (n−1) edges. ∎

---

## Problem 9 — Extremal number of leaves in a tree (5 points)

What are the maximum and minimum possible numbers of leaves in an n-vertex
tree?

Answer: Maximum = n−1 (a star); Minimum = 2 (a path). ∎

---

Notes on including images in Markdown

Yes — you can include images in Markdown. Common options:

1. Use a relative path to an image committed in the repository, e.g.

   ![Figure 1](./images/pset4_fig1.png)

   Place the file at 6.042j-discrete-math/3-graph_theory/images/pset4_fig1.png
   and the image will render on GitHub and in the repository README pages.

2. Use an absolute URL (hosted elsewhere):

   ![Alt text](https://example.com/path/to/image.png)

3. Use the GitHub raw URL if you want to reference a specific branch/commit:

   ![Raw image](https://raw.githubusercontent.com/simbarashe-danda/cs-engineering-curriculum/main/6.042j-discrete-math/3-graph_theory/images/pset4_fig1.png)

Recommendations:
- Prefer PNG or SVG for diagrams. SVG scales well; PNG is broadly supported.
- Keep images in a dedicated images/ directory next to the Markdown file.
- Use relative paths so the images move with the repo.

Example snippet to add to this file (you can copy-paste):

```markdown name=example_image_snippet.md
![Example graph](./images/pset4_example_graph.png)
```

---

If you'd like, I can:
- commit this improved file for you (I have just updated it),
- or instead create a new file such as `pset4_graph_theory_1_and_2.md` in a
  `polished/` folder so the original is preserved,
- or add an `images/` directory and upload example images (please provide the
  image files or tell me where to fetch them).

Tell me which of these you prefer and I'll continue.