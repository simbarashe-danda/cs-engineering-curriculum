# Graph Theory — Generalized Stable Matching Algorithm

## 1. A Protocol for College Admission

We are exploring a generalization of the stable marriage problem.

There are $N$ students $s_1, s_2, \dots, s_N$ and $M$ universities $u_1, u_2, \dots, u_M$. University $u_i$ has $n_i$ slots for students, and we are guaranteed that $\sum_{i=1}^M n_i = N$. Each student ranks all universities (no ties) and each university ranks all students (no ties).

The objective is to design an algorithm to assign students to universities satisfying the following properties:

1. Every student is assigned to one university.
2. $\forall\, i,\ u_i$ gets assigned $n_i$ students.
3. There does not exist a **rogue pair** $s_i, s_j, u_k, u_\ell$ where $s_i$ is assigned to $u_k$, $s_j$ is assigned to $u_\ell$, $s_j$ prefers $u_k$ to $u_\ell$, and $u_k$ prefers $s_j$ to $s_i$.
4. It is **student-optimal**: of all possible assignments satisfying the first three properties, students get their top choice of university amongst these assignments.

---

## 2. Generalized Matching Algorithm

**Each Day:**

- **Morning:** Each student applies to their favourite university that they have not yet crossed off their list.
- **Afternoon:** Each university $u_j$ looks at its pool of applicants for that day (say there are $k$ applications).
  - If $k \le n_j$, the university says "maybe, come back tomorrow" to all $k$ applicants.
  - If $k > n_j$, the university says "maybe, come back tomorrow" to its $n_j$ favourite applicants. It says "no" to the remaining $k - n_j$ least preferred applicants.
- **Evening:** Any student who hears "No" crosses that university off their list.

**Termination Condition:** If there is a day when no student hears a "No" (equivalently, every university $u_j$ has $k \le n_j$ applicants), the algorithm stops. Each university accepts its applicants.

---

## 3. Mathematical Proofs of Algorithm Properties

**Termination — Upper Bound of $NM + 1$ Days**
Each student has $M$ universities on their list, giving $NM$ total entries across all lists. Because at least one entry is crossed off on every day the algorithm does not terminate, there can be at most $NM$ days of rejections. The algorithm must terminate on the day following the final possible rejection. Therefore the absolute upper bound for termination is $NM + 1$ days. $\blacksquare$

---

**Claim 1**
**If during some day a university $u_j$ has at least $n_j$ applicants, then when the algorithm terminates, it accepts exactly $n_j$ students.**

**Proof.** Let day $d$ be the first day that $u_j$ receives $k \ge n_j$ applicants. The university rejects the $k - n_j$ least preferred applicants and tells its top $n_j$ to "come back tomorrow." Since these applicants applied because $u_j$ is their current top choice, on day $d+1$ university $u_j$ again receives $\ge n_j$ applications.

The claim follows from the invariant: if a university receives $\ge n_j$ applicants on day $d$, its number of applications stays $\ge n_j$ on all subsequent days. $\blacksquare$

---

**Claim 2**
**Every student is assigned to one university.**

**Proof.** We know $\sum_{i=1}^M n_i = N$, so there are exactly enough slots for all students. Assume for contradiction that upon termination there exists a student $s_i$ assigned to no university. This is only possible if $s_i$ was rejected by every university, which is only possible if for every university $u_j$, $s_i$ was among the least preferred applicants and the number of applicants exceeded $n_j$.

This would imply the total number of slots is less than $N$, contradicting $\sum_{i=1}^M n_i = N$. $\blacksquare$

---

**Claim 3**
**For all $j$, $u_j$ gets assigned exactly $n_j$ students.**

**Proof.** Assume for contradiction that some $u_j$ is assigned fewer than $n_j$ students. Since $\sum_{i=1}^M n_i = N$ and by Claim 2 every student is assigned, some other university must be assigned more than its maximum slots — contradicting Claim 1. $\blacksquare$

---

**Claim 4**
**The rank of $u_j$'s least favourite "maybe" applicant cannot decrease (i.e. get worse) on any future day.**

**Proof.** Suppose on day $d$, university $u_j$ has $k \ge n_j$ applicants and says "maybe" to its top $n_j$. Let $S_{\text{worst}}$ be the least favourite among these, with rank $R$ on $u_j$'s preference list.

On day $d+1$, if $u_j$ again has $k > n_j$ applicants, the new $S_{\text{worst}}$ must have rank $\le R$ (i.e. be preferred at least as much). It is impossible for a student with a worse rank than $R$ to enter the top-$n_j$ accepted group. Hence the quality of the worst accepted applicant never decreases. $\blacksquare$

---

**Claim 5 — No rogue pairs exist**
**There do not exist $s_i, s_j, u_k, u_\ell$ such that $s_i$ is assigned to $u_k$, $s_j$ is assigned to $u_\ell$, $s_j$ prefers $u_k$ to $u_\ell$, and $u_k$ prefers $s_j$ to $s_i$.**

**Proof.** Assume for contradiction such a rogue combination exists at termination. Since $s_j$ prefers $u_k$ to $u_\ell$ but is assigned to $u_\ell$, by the algorithm $s_j$ must have applied to $u_k$ before $u_\ell$ and been rejected.

Since $s_j$ was rejected by $u_k$ and $s_i$ was accepted, by Claim 4 $u_k$ must prefer $s_i$ to $s_j$. This directly contradicts the assumption that $u_k$ prefers $s_j$ to $s_i$. $\blacksquare$

---

**Claim 6 — Student optimality**
**Each student is assigned to their optimal university.**

**Proof.** Assume for contradiction the algorithm does not assign every student to their optimal university. Then at least one student is rejected by their optimal university during execution.

Let day $d$ be the first day any student is rejected by their optimal university. Let $s$ be the student rejected by $u_{\text{opt}}$ on day $d$. Since $u_{\text{opt}}$ rejected $s$, it kept $n_{\text{opt}}$ students it prefers over $s$ — call this set $S'$.

Since day $d$ is the **first** day any student is rejected by their optimal university, every student in $S'$ has not yet been rejected by their optimal university. Since $S'$ is applying to $u_{\text{opt}}$, $u_{\text{opt}}$ must be optimal for each member of $S'$.

Now consider any stable assignment where $s$ is assigned to $u_{\text{opt}}$. Such an assignment exists by assumption (since $u_{\text{opt}}$ is $s$'s optimal). But $u_{\text{opt}}$ prefers every member of $S'$ over $s$, and $u_{\text{opt}}$ is also optimal for $S'$ — so $s$ and any member of $S'$ assigned elsewhere would form a rogue pair, contradicting stability.

Hence no valid stable assignment exists where $s$ is assigned to $u_{\text{opt}}$, contradicting the assumption that $u_{\text{opt}}$ is $s$'s optimal. $\blacksquare$
