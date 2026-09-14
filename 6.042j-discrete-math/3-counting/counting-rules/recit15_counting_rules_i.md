# Recitation 15: Mathematics for Computer Science

## 1. The Tao of BOOKKEEPER

**Question 1.1:** In how many ways can you arrange the letters in the word $POKE$?

**Solution:**

Consider selecting a letter for the first slot. Notice that there are 4 choices.
For the second slot, there are 3 choices since a letter has already been selected for the first.
By the generalized product rule, there are $4 \cdot 3 \cdot 2 \cdot 1 = 4!$ ways to arrange.

Therefore, there are 24 possible ways to arrange the letters in $POKE$. $\blacksquare$

---

**Question 1.2:** In how many ways can you arrange the letters in the word $BO_1O_2K$? Observe that we have subscripted the O's to make them distinct symbols.

**Solution:**

There are 4 possible first entries, 3 possible second entries, etc. Therefore, there are $4! = 24$ ways to arrange the letters in $BO_1O_2K$. $\blacksquare$

---

**Question 1.3:** Suppose we map arrangements of the letters in $BO_1O_2K$ to arrangements of the letters in $BOOK$ by erasing the subscripts. Indicate with arrows how the arrangements on the left are mapped to the arrangements on the right.

**Solution:**

$$
\begin{align*}
O_2BO_1K &\rightarrow OBOK \\
KO_2BO_1 &\rightarrow KOBO \\
O_1BO_2K &\rightarrow OBOK \\
KO_1BO_2 &\rightarrow KOBO \\
BO_1O_2K &\rightarrow BOOK \\
BO_2O_1K &\rightarrow BOOK
\end{align*}
$$

$\blacksquare$

---

**Question 1.4:** What kind of mapping is this, young grasshopper?

**Solution:**

Let $A$ be the set of all arrangements of $BO_1O_2K$. Let $B$ be the set of all arrangements of $BOOK$. Let $f$ be the mapping $f\colon A \rightarrow B$.

Then $f$ is surjective since $\forall L_y \in B, \exists L_x \in A \text{ s.t. } f(L_x) = L_y$. This is a $2\text{-to-}1$ mapping. $\blacksquare$

---

**Question 1.5:** In light of the Division Rule, how many arrangements are there of $BOOK$?

**Solution:**

By the division rule, if $f\colon A \rightarrow B$ is $k\text{-to-}1$, then $|A| = k \cdot |B|$.

Since we know the mapping from arrangements of $BO_1O_2K \rightarrow$ arrangements of $BOOK$ is $2\text{-to-}1$ and we know there are $4!$ ways to arrange $BO_1O_2K$, where $B = \text{Set of all arrangements of } BOOK$:

$$4! = 2 \cdot |B| \implies |B| = \frac{4!}{2}$$

Hence, there are $\frac{4!}{2}$ ways to arrange $BOOK$. $\blacksquare$

---

**Question 1.6:** Very good, young master! How many arrangements are there of the letters in $KE_1E_2PE_3R$?

**Solution:**

By the generalized product rule, there are 6 possible first entries, 5 possible second entries... 1 possible last entry. Hence, there are $6!$ ways to arrange $KE_1E_2PE_3R$. $\blacksquare$

---

**Question 1.7:** Suppose we map each arrangement of $KE_1E_2PE_3R$ to an arrangement of $KEEPER$ by erasing subscripts. List all the different arrangements of $KE_1E_2PE_3R$ that are mapped to $REPEEK$ in this way.

**Solution:**

Consider choosing $E_1, E_2,$ and $E_3$ for all $E_i$ in $REPEEK$. It follows from the generalized product rule that there are $3!$ ways to arrange $E_1, E_2,$ and $E_3$ in $RE\_PE\_E\_K$.

Listing them:

$$RE_1PE_2E_3K, \quad RE_1PE_3E_2K, \quad RE_2PE_1E_3K, \quad RE_3PE_2E_1K, \quad RE_3PE_1E_2K, \quad RE_2PE_3E_1K$$

$\blacksquare$

---

**Question 1.8:** What kind of mapping is this?

**Solution:**

It follows from 1.7 that this is a $3!\text{-to-}1$ mapping. $\blacksquare$

---

**Question 1.9:** So how many arrangements are there of the letters in $KEEPER$?

**Solution:**

We know there are $6!$ ways to arrange $KE_1E_2PE_3R$ and the mapping from the set of arrangements of $KE_1E_2PE_3R$ to the set of arrangements of $KEEPER$ is $3!\text{-to-}1$.

Therefore, by the division rule, there are $\frac{6!}{3!}$ ways to arrange $KEEPER$. $\blacksquare$

---

**Question 1.10:** Now you are ready to face the BOOKKEEPER! How many arrangements of $BO_1O_2K_1K_2E_1E_2PE_3R$ are there?

**Solution:**

By the generalized product rule, there are $10!$ ways to arrange $BO_1O_2K_1K_2E_1E_2PE_3R$. $\blacksquare$

---

**Question 1.11:** How many arrangements of $BOOK_1K_2E_1E_2PE_3R$ are there?

**Solution:**

Notice that the mapping from arrangements of $BO_1O_2K_1K_2E_1E_2PE_3R$ to the set of arrangements of $BOOK_1K_2E_1E_2PE_3R$ is a $2\text{-to-}1$ mapping. Since there are $2!$ ways to arrange $O_1$ and $O_2$, then by the division rule, there are $\frac{10!}{2!}$ ways to arrange $BOOK_1K_2E_1E_2PE_3R$. $\blacksquare$

---

**Question 1.12:** How many arrangements of $BOOKKE_1E_2PE_3R$ are there?

**Solution:**

Notice that the mapping from arrangements of $BOOK_1K_2E_1E_2PE_3R$ to arrangements of $BOOKKE_1E_2PE_3R$ is a $2! \cdot 2!\text{-to-}1 = (2!)^2\text{-to-}1$ mapping. This follows from the property that there are $2!$ ways to arrange $O_1, O_2$ and $2!$ ways to arrange $K_1, K_2$.

Hence, there are $\frac{10!}{(2!)^2}$ ways to arrange $BOOKKE_1E_2PE_3R$. $\blacksquare$

---

**Question 1.13:** How many arrangements of $BOOKKEEPER$ are there?

**Solution:**

Notice that there are $3!$ ways to arrange $E_1, E_2, E_3$. So the mapping from arrangements of $BOOKKE_1E_2PE_3R$ to arrangements of $BOOKKEEPER$ is a $3!\text{-to-}1$ mapping.

Hence, there are $\frac{10!}{(2!)^2 \cdot 3!}$ ways to arrange $BOOKKEEPER$. $\blacksquare$

---

**Question 1.14:** How many arrangements of $VOODOODOLL$ are there?

**Solution:**

By generalizing 1.13, there are $\frac{10!}{5! \cdot (2!)^2}$ ways to arrange $VOODOODOLL$. $\blacksquare$

---

**Question 1.15:** (IMPORTANT) How many $n$-bit sequences contain $k$ zeros and $(n-k)$ ones?

**Solution:**

From $\frac{n!}{k!(n-k)!}$, it follows that there are $\binom{n}{k}$ $n$-bit sequences that contain $k$ zeros and $(n-k)$ ones. $\blacksquare$

---

## 2. Pigeonhole Principle

**Question 2.1:** In a room of 500 people, there exist two who share a birthday.

**Solution:**

**Generalized Pigeonhole Principle (GPP):** If $|X| > k|Y|$, then for every function $f\colon X \rightarrow Y$ there exist $k+1$ different elements of $X$ that are mapped to the same element of $Y$.

Let $X$ be the set of 500 people. Let $Y$ be the set of 365 birthdays. It follows that $|X| > 1 \cdot |Y|$. From the theorem, there are $1+1 = 2$ people $\in X$ that share the same birthday. $\blacksquare$

---

**Question 2.2:** Suppose that each of the 115 students in 6.042 sums the nine digits of his or her ID number. Must two people arrive at the same sum?

**Solution:**

Consider a case where all 9 digits on the student's ID card are 9. The sum is $9 \times 9 = 81$, which is the biggest possible sum.

Let $Y$ be the set of all possible sums of digits such that $Y = \{0, 1, 2, \dots, 79, 80, 81\}$.

Let $X$ be the set of all 115 students in 6.042.

Define the mapping $f: X \rightarrow Y$ that maps each student to the sum of the digits on their ID.

Notice that $|X| > k|Y|$. Here, $|X| = 115$ and $|Y| = 82$, where $k = 1$.

It then follows from the Generalized Pigeonhole Principle that $\exists s_a, s_b \in X$ such that $f(s_a) = f(s_b)$. $\blacksquare$

---

**Question 2.3:** In every set of 100 integers, there exist two whose difference is a multiple of 37.

**Solution:**

Consider two integers $a$ and $b$ such that $37 | (a-b)$. Notice that this is the formal definition of $a \equiv b \pmod{37}$.

Consider the integers $a$ and $b$ such that $m | (a-b)$ when $m \in \mathbb{Z}^+$. Notice that this is the formal definition of $a \equiv b \pmod m$.

Notice that $\forall a_i \in \mathbb{Z}$, $a_i \pmod m \in [0, m-1]$.

Let $X$ be the set of 100 integers. Let $Y$ be the set of all possible remainders when we divide by $m$ such that $Y = \{0, 1, \dots, m-2, m-1\}$. Let $m=37$.

Define $f: X \rightarrow Y$ to be a mapping that maps integers in $X$ to their remainder when divided by $m$.

Since $|X| = 100$ and $|Y| = 37 \implies |X| > 1 \cdot |Y|$.

It follows from GPP that $\exists x_1, x_2 \in X$ such that $f(x_1) = f(x_2) \implies x_1 \pmod{37} = x_2 \pmod{37} \implies x_1 \equiv x_2 \pmod{37}$. $\blacksquare$

---

## 3. More Counting Problems

**Question 3.1:** (IMPORTANT) In how many ways can $k$ elements be chosen from an $n$-element set $\{x_1, x_2, \dots, x_n\}$?

**Solution:**

Let $S = \{x_1, x_2, \dots, x_n\}$. Define $A$ to be the set of $k$-element subsets of $S$. Define $B$ to be the set of all $n$-bit sequences that contain $k$ ones and $(n-k)$ zeros. Let $s = (x_1, x_2, \dots, x_n)$ be the ordered tuple representing $S$.

For any subset $U \in A$, the mapping (indicator function) $\chi_U: S \rightarrow \{0, 1\}$ we define by:

$$
\chi_U(x) = \begin{cases} 
1 & \text{if } x \in U \\ 
0 & \text{if } x \notin U 
\end{cases}
$$

Define the mapping $f: A \rightarrow B$ by $f(U) = \chi_U \circ s$, where $U \in A$ and the output is the component-wise evaluation, $f(U) = (\chi_U(x_1), \chi_U(x_2), \dots, \chi_U(x_n))$.

**Proof that $f$ is a bijection:**

**a) Showing that $f$ is injective:**

Let $U, V \in A$ and assume $f(U) = f(V)$.

$$(\chi_U(x_1), \chi_U(x_2), \dots, \chi_U(x_n)) = (\chi_V(x_1), \chi_V(x_2), \dots, \chi_V(x_n))$$

Then $\forall x_i \in S, \chi_U(x_i) = \chi_V(x_i)$.

If $x_i \in U$, then $\chi_U(x_i) = 1 \implies \chi_V(x_i) = 1$, so $x_i \in V$. Thus $U \subseteq V$.

If $x_i \in V$, then $\chi_V(x_i) = 1 \implies \chi_U(x_i) = 1$, so $x_i \in U$. Thus $V \subseteq U$.

Since $U \subseteq V$ and $V \subseteq U$, then $U = V$. So $f$ is injective.

**b) Showing that $f$ is surjective:**

Let $b = (b_1, b_2, \dots, b_n) \in B$ be an arbitrary binary sequence containing exactly $k$ ones. Consider constructing a subset $U \subseteq S$ by collecting the elements of $S$ where the sequence has a 1: $U = \{x_i \in S : b_i = 1\}$.

Because $b$ contains exactly $k$ ones, the set $U$ has exactly $k$ elements. Therefore $U \in A$.

Now $f(U) = (\chi_U(x_1), \dots, \chi_U(x_n))$. By our construction, $\chi_U(x_i) = 1$ if $b_i = 1$ and $0$ otherwise. Thus $\chi_U(x_i) = b_i$ for all $i$. Therefore $f(U) = b$. $f$ is surjective.

Since $f$ is surjective and injective, then $f$ is bijective.

We already knew that $|B| = \binom{n}{k}$. It then follows from the bijection that, since $f: A \rightarrow B$ is a bijection, $|A| = |B| = \binom{n}{k}$.

This completes the proof. $\blacksquare$

---

**Question 3.2:** How many different ways are there to select a dozen donuts if five varieties are available?

**Solution:**

Assume a single row, grouped sequentially by their variety A, B, C, D, E. Let $0$ represent a donut selection and $1$ represent a variety divider.

Sequence: `001 000 1000 100100` represents 2A, 3B, 3C, 2D, 2E.

Let $A$ be the set of all possible donut selections. Let $B$ be the set of all 16-bit sequences representing donut selections and variety dividers.

Since the mapping $f: A \rightarrow B$ is constructed directly, then $f$ is a bijection.

By the bijection rule we know $|A| = |B|$. We also know $|B| = \binom{n}{k} = \binom{16}{12}$ where $n = 16$ and $k = 12$.

Therefore, there are $\binom{16}{12}$ different ways. Alternatively, $\binom{16}{4} = \binom{16}{12}$ different ways. $\blacksquare$

---

**Question 3.3:** An independent living group is hosting eight pre-frosh, affectionately known as $P_1, \dots, P_8$ by the permanent residents. Each pre-frosh is assigned a task: 2 must wash pots, 2 must clean the kitchen, 1 must clean the bathrooms, 1 must clean the common area, and 2 must serve dinner. In how many ways can $P_1, \dots, P_8$ be put to productive use?

**Solution:**

Consider mapping identical tasks to identical characters such that $(A, A, B, B, C, D, E, E)$ represent (pots, pots, kitchen, kitchen, bathroom, common area, dinner, dinner) and are assigned to $P_1, P_2, P_3, P_4, P_5, P_6, P_7, P_8$ respectively.

Let $S = (A, A, B, B, C, D, E, E)$.

Let $S' = (A_1, A_2, B_1, B_2, C, D, E_1, E_2)$.

Let $X$ be the set of all possible arrangements of $S'$. Let $Y$ be the set of all possible arrangements of $S$.

Define $f: X \rightarrow Y$ by removing subscripts. Notice that $f$ is a $2! \cdot 2! \cdot 2!\text{-to-}1$ mapping.

We already know that $|X| = 8!$ by the product rule.

Thus $|Y| = \frac{8!}{2! \cdot 2! \cdot 2!}$ by the division rule. $\blacksquare$

---

**Question 3.4:** Suppose that two identical 52-card decks are mixed together. In how many ways can the cards in this double-size deck be arranged?

**Solution:**

Let $S$ be an arbitrary sequence of 104 cards treating them all as indistinguishable such that $S = (\text{Ace Spades}, \text{Ace Spades}, \dots, \text{King Hearts}, \text{King Hearts})$.

Let $S'$ be an arbitrary sequence of 104 cards treating them all as distinguishable such that $S' = (\text{Ace Spades}_1, \text{Ace Spades}_2, \dots, \text{King Hearts}_1, \text{King Hearts}_2)$.

Let $X$ be the set of all possible arrangements of $S'$. Let $Y$ be the set of all possible arrangements of $S$.

Define $f: X \rightarrow Y$ by treating indistinguishable cards in $X$ as identical to map to $y \in Y$. Notice that $f$ is a $2^{52}\text{-to-}1$ function.

We already know that $|X| = 104!$ by the product rule.

Thus $|Y| = \frac{104!}{2^{52}}$. There are $\frac{104!}{2^{52}}$ ways to arrange a double-sized deck. $\blacksquare$

---

## 4. Fun with Phonology: Hawaiian

**Question 4.1:** Before tackling the general problem, work out how many different words there are with exactly 4 phonemes.

**Solution:**

Let V denote a vowel. Let C denote a consonant. Listing all sequences of length 4:

$$\text{VVVV, CVVV, CVCV, VCVV, VVCV}$$

Notice that:

$$S_0 = \{\text{set of all 4-phoneme words from VVVV}\}$$
$$S_1 = \{\text{set of all 4-phoneme words from CVVV}\}$$
$$S_2 = \{\text{set of all 4-phoneme words from CVCV}\}$$
$$S_3 = \{\text{set of all 4-phoneme words from VCVV}\}$$
$$S_4 = \{\text{set of all 4-phoneme words from VVCV}\}$$

By the product rule:

$$|S_0| = 25^4$$
$$|S_1| = 8 \cdot 25^3$$
$$|S_2| = 8^2 \cdot 25^2$$
$$|S_3| = 8 \cdot 25^3$$
$$|S_4| = 8 \cdot 25^3$$

Since $S_0, \dots, S_4$ are disjoint, then by the sum rule, $|S_0 \cup \dots \cup S_4| = \sum_{k=0}^{4} |S_k|$.

Then $|S_0 \cup \dots \cup S_4| = 25^4 + 8 \cdot 25^3 + 8^2 \cdot 25^2 + 8 \cdot 25^3 + 8 \cdot 25^3$.

Thus $25^2(25^2 + 8 \cdot 25 + 8^2 + 2 \cdot 8 \cdot 25) = 614,025$ different 4-phoneme words. $\blacksquare$

---

**Question 4.2:** Now for the general case. Let $A$ be the set of all $n$-phoneme words, and let $A_k$ be the set of all $n$-phoneme words with exactly $k$ consonants. Express $|A|$ in terms of $|A_k|$ for all possible $k$.

**Solution:**

Given $n$ is even, the maximum $k$ occurs when we have the sequence CVCVCV...

Thus $k_{\max} = \frac{n}{2}$.

Thus using the sum rule, $|A| = \sum_{k=0}^{n/2} |A_k|$ where $A_k$ is the set of all $n$-phoneme words with exactly $k$ consonants. $\blacksquare$

---

**Question 4.3:** Now let's find $|A_k|$ for an arbitrary $k$. For simplicity's sake, assume Hawaiian has only one consonant and only one vowel. Find a bijection between $A_k$ and a set of arbitrary sequences of 0 and 1 of length $p$. What is $p$?

**Solution:**

Since no two consonants can be adjacent and the word must end in a vowel, consider binding a consonant to a vowel to form a "CV" block. Notice that there are $k$ "CV" blocks and $(n-2k)$ free vowels required to reach the total length $n$.

Define $f: A \rightarrow \{0, 1\}^p$ where $A$ is an arbitrary $k$-consonant, $n$-phoneme word:

$$
f(x) = \begin{cases} 
1 & \text{if } x = \text{CV} \\
0 & \text{if } x = \text{V}
\end{cases}
$$

Let $p$ be the length of the $0$ and $1$ forming sequence.

Thus $p = k + (n-2k)$.

Thus $p = n - k$. $\blacksquare$

---

**Question 4.4:** Using this bijection, compute $|A_k|$.

**Solution:**

Let $Y$ be the set of 0 and 1 sequences of length $n-k$ that contain exactly $k$ ones. We know that $|Y| = \binom{n-k}{k}$.

Since $f$ is a bijection, then $|A_k| = |Y|$.

Thus $|A_k| = \binom{n-k}{k}$. $\blacksquare$

---

**Question 4.5:** How would you change your expression for $|A_k|$ to allow for 8 consonants and 25 vowels, not just one of each?

**Solution:**

Since there are 8 consonants and 25 vowels, then each "CV" block has $8 \cdot 25$ possibilities and each "V" has 25 possibilities. Since we have $k$ "CV" blocks and $(n-2k)$ "V" vowels, it then follows that $|A_k| = \binom{n-k}{k} (8 \cdot 25)^k \cdot (25)^{n-2k}$ by the product rule.

Thus $|A_k| = 8^k \cdot 25^{n-k} \binom{n-k}{k}$. $\blacksquare$

---

**Question 4.6:** How many $n$-phoneme words are there in Hawaiian?

**Solution:**

Using $|A| = \sum_{k=0}^{n/2} |A_k|$, then:

$$|A| = \sum_{k=0}^{n/2} \binom{n-k}{k} 8^k 25^{n-k}$$

$|A|$ is the set of all $n$-phoneme words in Hawaiian. $\blacksquare$