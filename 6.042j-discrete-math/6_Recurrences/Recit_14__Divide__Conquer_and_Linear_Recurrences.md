# Recitation 14

## Part 1: TriMergeSort

We noted in lecture that reducing the size of subproblems is much more important to the speed of an algorithm than reducing the number of additional steps per call[cite: 1]. Let's consider a new version of MergeSort called TriMerge Sort, where the size $n$ list is now broken into three sublists of size $n/3$ which are sorted recursively and then merged[cite: 1]. Since we know that floors and ceilings do not affect the asymptotic solution to a recurrence, let's assume that $n$ is a power of 3[cite: 1].

### Question 1
**How many comparisons are needed to merge three lists of 1 item each?**[cite: 1]

**Solution:**
Consider three lists of 1 item each[cite: 1]. Assume the items are $a$, $b$, and $c$ respectively, and assume that $a < b < c$[cite: 1]. 

To merge we would need:
1. $\min(a, b) \implies a$[cite: 1]
2. $\min(a, c) \implies a$[cite: 1]
3. $\min(b, c) \implies b$[cite: 1]

The merged list is now $a, b, c$, where $a$ is the smallest and $b$ is the second smallest[cite: 1]. 

Notice that at any step to determine the smallest item, we need $2$ comparisons (by checking the heads of all $3$ lists simultaneously)[cite: 1]. Also notice that when the total remaining items is $2$, we need a single comparison[cite: 1]. And if there is a single item left, no comparison is needed[cite: 1]. 

Hence, we need $3$ comparisons total[cite: 1].

---

### Question 2
**In the worst case, how many comparisons are needed to merge three lists of $n/3$ items, where $n$ is a power of 3?**[cite: 1]

**Solution:**
Notice that for any step where the total remaining items is greater than $2$, we need $2$ comparisons to determine the smallest element[cite: 1]. Also, when the total remaining items is $2$, we need a single comparison, and if there is a single item left, no comparison is needed[cite: 1]. 

Hence we need:
$$2(n-2) + 1 \text{ comparisons}$$ 
$$= 2n - 3 \text{ comparisons}$$[cite: 1]

---

### Question 3
**Define a divide-and-conquer recurrence for this algorithm. Let $T(n)$ be the number of comparisons to sort a list of $n$ items.**[cite: 1]

**Solution:**
Let $T(n)$ be the number of comparisons to sort a list of $n$ items[cite: 1]. 
Then, 
$$T(n) = 3T\left(\frac{n}{3}\right) + 2n - 3$$[cite: 1]
where $3T\left(\frac{n}{3}\right)$ is the comparisons by the $3$ sublists and $2n - 3$ is the comparisons used for merging the three lists[cite: 1].

---

### Question 4
**We could analyze the running time of this using plug-and-chug, but let's try Akra-Bazzi. First, what is $p$?**[cite: 1]

**Solution:**
Using the Akra-Bazzi theorem (strong form), we need $p$ such that:
$$\sum_{i=1}^{k} a_i b_i^p = 1$$[cite: 1]
where $a_i = 3$, $b_i = \frac{1}{3}$, and $k = 1$[cite: 1]. 

We need:
$$3\left(\frac{1}{3}\right)^p = 1$$[cite: 1]
Then $p = 1$[cite: 1].

---

### Question 5
**Does the condition $|g'(x)| = O(x^c)$ hold for some $c \in \mathbb{N}$?**[cite: 1]

**Solution:**
Given $g(x) = 2x - 3$, we find $g'(x) = 2$[cite: 1]. 
We check if $2 = O(x^c)$[cite: 1]. 

The condition holds because $|g'(x)| = O(x^c)$ where $c = 0$ and $g'(x) = 2$[cite: 1].

---

### Question 6
**Determine the theta bound on $T(n)$ by integration.**[cite: 1]

**Solution:**
By Akra-Bazzi, we know:
$$T(x) = \Theta\left(x^p \left(1 + \int_{1}^{x} \frac{g(u)}{u^{p+1}} du\right)\right)$$[cite: 1]

Substituting $p = 1$ and $g(u) = 2u - 3$:
$$T(x) = \Theta\left(x \left(1 + \int_{1}^{x} \frac{2u - 3}{u^2} du\right)\right)$$[cite: 1]

Integrating:
$$\int_{1}^{x} \left(\frac{2}{u} - 3u^{-2}\right) du = \left[ 2 \ln|u| + \frac{3}{u} \right]_{1}^{x}$$[cite: 1]
$$= \left(2 \ln|x| + \frac{3}{x}\right) - \left(2 \ln(1) + \frac{3}{1}\right)$$[cite: 1]
$$= 2 \ln|x| + \frac{3}{x} - 3$$[cite: 1]

Then:
$$T(x) = \Theta\left(x \left(1 + 2\ln|x| + \frac{3}{x} - 3\right)\right)$$[cite: 1]
$$T(x) = \Theta(2x \ln|x| + 3 - 2x)$$[cite: 1]

Dropping constants and slow growth terms, we get:
$$T(n) = \Theta(n \log n)$$[cite: 1]

---

### Question 7
**Turns out that any equal partition of the list into a constant number of sublists $c > 1$ will yield the same theta bound. Can you see why?**[cite: 1]

**Solution:**
Assuming $n$ is a power of $c$, then the number of sublists is $c$[cite: 1]. 

Notice that for any step where the total remaining items is greater than $2$, we need $c - 1$ comparisons[cite: 1]. When the total remaining items is $2$, we need $1$ comparison[cite: 1]. 

To merge the lists, we need $(c-1)(n-2) + 1$ comparisons[cite: 1]. 
Then:
$$T(n) = cT\left(\frac{n}{c}\right) + (c-1)(n-2) + 1$$[cite: 1]

Using Akra-Bazzi, let $g(x) = (c-1)(x-2) + 1$ where $c$ is a constant[cite: 1]. 
Then $g'(x) = c - 1$[cite: 1]. 
The condition $c - 1 = O(x^0)$ holds[cite: 1]. 

We need $\sum_{i=1}^{k} a_i b_i^p = 1$, where $k = 1, a_i = c, b_i = \frac{1}{c}$[cite: 1]. 
$$c\left(\frac{1}{c}\right)^p = 1 \implies p = 1$$[cite: 1]

Since $c$ is an arbitrary constant and does not affect the result of integration, we know from the integration of $\int_{1}^{x} \frac{(c-1)(u-2)+1}{u^2} du$ that the result has the form:
$$a \ln(x) + \frac{b}{x} + d$$[cite: 1]
where $a, b, d$ are constants[cite: 1]. 

Then $T(x) = \Theta\left(x(a \ln(x) + \frac{b}{x} + d + 1)\right) = \Theta(a x \ln(x) + b + (d+1)x)$[cite: 1]. 
Dropping lower terms gives $T(n) = \Theta(n \log n)$[cite: 1]. 
This completes the proof[cite: 1].

---

## Part 2: Linear Recurrences

Find closed-form solutions to the following linear recurrences[cite: 1].

### Problem 1
$$T_0 = 0$$[cite: 1]
$$T_1 = 1$$[cite: 1]
$$T_n = T_{n-1} + T_{n-2} + 1$$[cite: 1]

**Solution:**

**1. Finding the homogeneous solution:**
$$T_n = T_{n-1} + T_{n-2}$$[cite: 1]
Try $T_n = \alpha^n$ for a constant $\alpha$[cite: 1].
$$\alpha^n = \alpha^{n-1} + \alpha^{n-2}$$[cite: 1]
Dividing by $\alpha^{n-2}$:
$$\alpha^2 = \alpha + 1 \implies \alpha^2 - \alpha - 1 = 0$$[cite: 1]

Using the quadratic formula:
$$\alpha = \frac{-(-1) \pm \sqrt{(-1)^2 - 4(1)(-1)}}{2(1)} = \frac{1 \pm \sqrt{5}}{2}$$[cite: 1]
Then $T_n^{(h)}$ uses roots $\alpha_1 = \frac{1+\sqrt{5}}{2}$ and $\alpha_2 = \frac{1-\sqrt{5}}{2}$[cite: 1].

**2. Finding the particular solution:**
$$T_n = T_{n-1} + T_{n-2} + 1$$[cite: 1]
where $1 = 1^n$[cite: 1]. Guess $T_n = C(1^n)$[cite: 1].
$$C(1^n) - C(1^{n-1}) - C(1^{n-2}) = 1^n$$[cite: 1]
Dividing by $1^{n-2}$:
$$C(1^2) - C(1) - C = 1^2 \implies -C = 1 \implies C = -1$$[cite: 1]
Then $T_n^{(p)} = -1$[cite: 1].

**3. Finding the general solution:**
Adding the homogeneous and particular solutions:
$$T_n = C_1\left(\frac{1+\sqrt{5}}{2}\right)^n + C_2\left(\frac{1-\sqrt{5}}{2}\right)^n - 1$$[cite: 1]

Using boundary conditions:
$$T_0 = C_1\left(\frac{1+\sqrt{5}}{2}\right)^0 + C_2\left(\frac{1-\sqrt{5}}{2}\right)^0 - 1 = 0$$[cite: 1]
$$C_1 + C_2 = 1 \quad \text{--- (1)}$$[cite: 1]

$$T_1 = C_1\left(\frac{1+\sqrt{5}}{2}\right)^1 + C_2\left(\frac{1-\sqrt{5}}{2}\right)^1 - 1 = 1$$[cite: 1]
$$C_1\left(\frac{1+\sqrt{5}}{2}\right) + C_2\left(\frac{1-\sqrt{5}}{2}\right) = 2 \quad \text{--- (2)}$$[cite: 1]

Substitute $C_2 = 1 - C_1$ into (2):
$$C_1\left(\frac{1+\sqrt{5}}{2}\right) + (1-C_1)\left(\frac{1-\sqrt{5}}{2}\right) = 2$$[cite: 1]
$$C_1\left(\frac{1+\sqrt{5}}{2} - \frac{1-\sqrt{5}}{2}\right) + \frac{1-\sqrt{5}}{2} = 2$$[cite: 1]
$$C_1(\sqrt{5}) = 2 - \frac{1-\sqrt{5}}{2} = \frac{3+\sqrt{5}}{2}$$[cite: 1]
$$C_1 = \frac{3+\sqrt{5}}{2\sqrt{5}} = \frac{5+3\sqrt{5}}{10}$$[cite: 1]

From (1), $C_2 = 1 - C_1$:
$$C_2 = 1 - \frac{5+3\sqrt{5}}{10} = \frac{5-3\sqrt{5}}{10}$$[cite: 1]

**Final Closed-Form Solution:**
$$T_n = \left(\frac{5+3\sqrt{5}}{10}\right)\left(\frac{1+\sqrt{5}}{2}\right)^n + \left(\frac{5-3\sqrt{5}}{10}\right)\left(\frac{1-\sqrt{5}}{2}\right)^n - 1$$[cite: 1]

---

### Problem 2
$$S_0 = 0$$[cite: 1]
$$S_1 = 1$$[cite: 1]
$$S_n = 6S_{n-1} - 9S_{n-2}$$[cite: 1]

**Solution:**
Try $S_n = \alpha^n$ for a constant $\alpha$[cite: 1]. 
$$\alpha^n = 6\alpha^{n-1} - 9\alpha^{n-2}$$[cite: 1]
Dividing by $\alpha^{n-2}$:
$$\alpha^2 = 6\alpha - 9 \implies \alpha^2 - 6\alpha + 9 = 0$$[cite: 1]
$$(\alpha - 3)^2 = 0 \implies \alpha = 3 \text{ (double root)}$$[cite: 1]

Using the theorem from lectures: if $\alpha$ is a root of the characteristic polynomial repeated $r$ times, then $\alpha^n, n\alpha^n, \dots, n^{r-1}\alpha^n$ are all solutions to the recurrence[cite: 1].

Then:
$$S_n = C_1(3)^n + C_2 n(3)^n$$[cite: 1]

Using boundary conditions:
$$S_0 = C_1(3)^0 + C_2(0)(3)^0 = 0 \implies C_1 = 0$$[cite: 1]
$$S_1 = C_1(3) + C_2(1)(3) = 1$$[cite: 1]
Since $C_1 = 0$:
$$3C_2 = 1 \implies C_2 = \frac{1}{3}$$[cite: 1]

**Final Closed-Form Solution:**
$$S_n = \frac{1}{3} n(3)^n = n 3^{n-1}$$[cite: 1]