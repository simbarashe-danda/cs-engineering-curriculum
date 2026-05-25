
***

## Recitation 3 State Machines

### Problem 1: Breaking a Chocolate Bar

We are given a chocolate bar with \(m \times n\) squares of chocolate, and our task is to divide it into \(mn\) individual squares. We are only allowed to split one piece of chocolate at a time using a vertical or a horizontal break. Prove that the number of times you split the bar does not depend on the sequence of splits you make.

**Proof.**

Let \(p\) be the number of discrete pieces.

**Initial state:**

\[
P_0 = 1
\]

Let \(k\) be an arbitrary split operation.

**Lemma:** \(P_n\) increases by 1 relative to \(P_{n-1}\) after exactly one legal split.

*Proof of lemma.* An arbitrary piece \(B\) can only be broken into two pieces in a single split. Therefore if \(P_{k-1} = n\),
\[
P_k = n + 1
\]
\[
\therefore \Delta P_k = 1 \quad \text{relative to} \quad P_{k-1}.
\]

Let the final state occur after exactly \(k_F\) operations. Since the chocolate bar has \(m \times n\) squares,
\[
P_{k_F} = m \cdot n
\]

By the Lemma, \(\Delta P_k = 1\) at each step. The system starts at \(P_0 = 1\) and increases by exactly 1 at each step \(k\); hence the state at step \(k_F\) is given by
\[
P_{k_F} = P_0 + k_F .
\]

Since \(P_{k_F} = mn\) and \(P_0 = 1\),
\[
\begin{align*}
mn &= 1 + k_F \\
k_F &= mn - 1 .
\end{align*}
\]

Because \(m\) and \(n\) are fixed initial conditions, \(k_F\) is a constant independent of the sequence of splits. \(\blacksquare\)

---

### Problem 2: The Temple of Forever
Each monk entering the Temple of Forever is given a bowl with 15 red beads and 12 green beads. Each time the Gong of Time rings, a monk must do one of two things:

1. **Exchange:** If he has at least 3 red beads, he may exchange 3 red beads for 2 green beads.
2. **Swap:** He may replace each green bead with a red bead and each red bead with a green bead.

A monk may leave only when he has exactly 5 red beads and 5 green beads.

#### Theorem 1. No one ever leaves the Temple of Forever.

**State representation.**  
Let \(q\) be an arbitrary state at time step \(k\). Let \(a, b\) be the number of red and green beads respectively.  
At time step \(k\), \(q = (a, b)\).

Let \(dp\) be the difference between the number of red and green beads:
\[
dp = a - b .
\]

**Initial state \(q_0\):**
\[
q_0 = (15, 12), \quad a = 15,\; b = 12, \quad dp = 3 .
\]

**Transition functions.**
\[
T_E(q) = (a - 3,\; b + 2) \quad \text{given } a \geq 3 \qquad \text{(Exchange)}
\]
\[
T_S(q) = (b,\; a) \qquad \text{(Swap)}
\]

**Transition effect on \(dp\).**  
Let \(dp_{k-1} = x\). Then \(dp_k = x - 5\) or \(-x\).

*Proof.* Consider state \(q = (a,b)\) at step \(k-1\) with \(dp_{k-1} = a - b\).

*Case 1:* Exchange \(T_E(q)\) (requires \(a \geq 3\)).
\[
\text{at step } k,\; q = (a-3,\; b+2)
\]
\[
\begin{align*}
dp_k &= (a-3) - (b+2) \\
&= a - b - 5 \\
&= dp_{k-1} - 5 .
\end{align*}
\]

*Case 2:* Swap \(T_S(q)\).
\[
\text{at step } k,\; q = (b,\; a)
\]
\[
\begin{align*}
dp_k &= b - a \\
&= -(a - b) \\
&= -dp_{k-1} .
\end{align*}
\]
\(\blacksquare\)

**Invariant.**  
Proposition: \(P(q) \iff (a-b) \bmod 5 \in \{2, 3\}\).

*Proof by induction.*

**Base case:** \(q_0 = (15, 12)\), \(dp_0 = 3\).
\[
3 \bmod 5 \in \{2, 3\}.
\]
Holds.

**Inductive step:** Assume \(P(q_k)\) is true for an arbitrary reachable state \(q_k = (a, b)\), i.e. \(dp_k \bmod 5 \in \{2, 3\}\).

Consider the transition \(k \to k+1\):

*Case 1:* \(T_E(q_k)\).
\[
q_{k+1} = (a-3,\; b+2) \quad \text{(given } a \geq 3\text{)}
\]
\[
dp_{k+1} = dp_k - 5 \quad \text{(by the transition equation)}
\]
Subtracting 5 does not change the residue modulo 5.
\[
\therefore dp_{k+1} \bmod 5 \in \{2, 3\}.
\]
Thus \(P(q_{k+1})\) holds.

*Case 2:* \(T_S(q_k)\).
\[
q_{k+1} = (b,\; a)
\]
\[
dp_{k+1} = -dp_k
\]
Since \(dp_k \bmod 5 \in \{2, 3\}\), we have \(-dp_k \bmod 5 \in \{3, 2\} = \{2, 3\}\).
\[
\therefore dp_{k+1} \bmod 5 \in \{2, 3\}.
\]
Thus \(P(q_{k+1})\) holds.

By induction, \(P(q_k)\) holds for all reachable states.

**Conclusion:**
The target state is \(q_F = (5, 5)\), giving \(dp_F = 5 - 5 = 0\).
Since \(0 \bmod 5 \notin \{2, 3\}\), \(q_F\) is unreachable.
This completes the proof of Theorem 1. \(\blacksquare\)

---

#### Theorem 2. There is a finite number of reachable states.

**Total sum.** Let \(S\) be the total number of beads at discrete time step \(k\):
\[
S = a + b .
\]

**Transition relations for the sum.** Consider state \(q = (a, b)\) at step \(k-1\) with \(S_{k-1} = a + b\).

*Case 1:* \(T_E(q_{k-1})\) (given \(a \geq 3\)).
\[
q_k = (a-3,\; b+2)
\]
\[
\begin{align*}
S_k &= (a-3) + (b+2) \\
&= a + b - 1 \\
&= S_{k-1} - 1 .
\end{align*}
\]

*Case 2:* \(T_S(q_{k-1})\).
\[
q_k = (b,\; a)
\]
\[
\begin{align*}
S_k &= b + a \\
&= S_{k-1} .
\end{align*}
\]

**Invariant on \(S\).** For any reachable sum \(S_k\),
\[
2 \leq S_k \leq S_0 .
\]

*Proof.* From the transition relations, \(\Delta S_k \in \{-1, 0\}\); hence \(S_k \leq S_0\) (non‑increasing).  
The Exchange operation requires \(a \geq 3\) and reduces the sum by 1. The state with the smallest possible sum that still allows an exchange is \((3, 0)\). Applying \(T_E\):
\[
T_E(3,0) = (0, 2) \implies S = 2 .
\]
Thus \(S_k \geq 2\), giving \(2 \leq S_k \leq S_0\). \(\blacksquare\)

**Proof of finiteness.**  
Let \(M\) be the set of all reachable states.  
We know \(q_0 = (15, 12)\) with \(S_0 = 27\). By the invariant, for any \(q_k = (a, b) \in M\),
\[
a + b \leq 27 .
\]
Since \(a, b\) are non‑negative integers, this implies \(0 \leq a, b \leq 27\).

Let \(A = \{0, 1, \dots, 27\}\). Every reachable state \((a, b)\) belongs to \(A \times A\), so \(M \subseteq A \times A\).
\[
|M| \leq |A \times A| = 28^2 < \infty .
\]
Therefore \(M\) is finite. \(\blacksquare\)

---

#### Theorem 3. It is not possible to visit 108 unique states.

**Proof.** Assume, for contradiction, that a monk can visit 108 distinct states.

By Theorem 2, the total sum \(S_k\) satisfies \(2 \leq S_k \leq 27\) and is non‑increasing.  
To maximize the number of distinct visited states, note:

* The Swap operation \(T_S\) does not change \(S_k\).
* We cannot apply \(T_S\) twice in a row, because \(T_S(T_S(a,b)) = (a,b)\) would return to the immediately preceding state, contributing no new state.

Thus, operations must alternate between \(T_S\) and \(T_E\).  
Starting from \(q_0 = (15, 12)\) with \(S_0 = 27\), the sum can only decrease via \(T_E\).  
The number of Exchange operations needed to go from \(S = 27\) down to \(S = 2\) is \(27 - 2 = 25\).

Since \(S\) can take \(26\) distinct values (\(27, 26, \dots, 2\)), and we can visit at most two distinct states per sum value (one before a swap and one after), the maximum number of distinct states reachable is
\[
26 \times 2 = 52 .
\]

But \(52 < 108\), contradicting the assumption that 108 distinct states can be visited. Hence it is impossible. \(\blacksquare\)