> **Problem 33:**
> Suppose that $\mathbf{A} = \hat{\mathbf{x}} \cos \omega t + \hat{\mathbf{y}} \sin \omega t$ where $\omega$ is a constant. Find $d\mathbf{A}/dt$ (note that $\hat{\mathbf{x}}$ and $\hat{\mathbf{y}}$ behave as constants in differentiation). Show that $d\mathbf{A}/dt$ is perpendicular to $\mathbf{A}$.

**Solution:**

Suppose that:
$$\vec{A} = \hat{x} \cos \omega t + \hat{y} \sin \omega t$$
where $\omega$ is a constant. 

Find $d\vec{A}/dt$ ($\hat{x}$ and $\hat{y}$ behave as constants in differentiation).

By Chain rule:
$$
\begin{aligned}
\frac{d}{dt} (\hat{x} \cos \omega t) &= -\hat{x} \sin \omega t \cdot \omega \\
\frac{d}{dt} (\hat{y} \sin \omega t) &= \hat{y} \cos \omega t \cdot \omega
\end{aligned}
$$

$$\therefore \vec{A}' = \hat{x}(-\omega \sin \omega t) + \hat{y}(\omega \cos \omega t)$$

Show that $\vec{A}'$ is perpendicular to $\vec{A}$.

Two vectors $\vec{A}$ and $\vec{B}$ are perpendicular, then $\vec{A} \cdot \vec{B} = 0$, Since $\vec{A} \cdot \vec{B} = AB \cos \theta$, $\cos(\pi/2) = 0$.

$$\therefore \text{we need to show } \vec{A} \cdot \vec{A}' = 0$$

$$\vec{A} \cdot \vec{B} = A_x B_x + A_y B_y + A_z B_z \quad (1)$$

For $\vec{A}'$: 
$$A'_x = -\omega \sin \omega t, \quad A'_y = \omega \cos \omega t$$

For $\vec{A}$: 
$$A_x = \cos \omega t, \quad A_y = \sin \omega t$$

$$\vec{A} \cdot \vec{A}' = -\omega \cos \omega t \sin \omega t + \omega \cos \omega t \sin \omega t$$

$$\therefore \vec{A} \cdot \vec{A}' = 0 \implies \vec{A}' \text{ and } \vec{A} \text{ are perpendicular } \blacksquare$$

***

> **Problem 14:**
> A room measures $4\text{ m}$ in the $x$ direction, $5\text{ m}$ in the $y$ direction, and $3\text{ m}$ in the $z$ direction. A lizard crawls along the walls from one corner of the room to the diametrically opposite corner. If the starting point is the origin of coordinates, what is the displacement vector? What is the length of the displacement vector? If the lizard chooses the shortest path along the walls, what is the length of its path?

**Solution:**

The starting coordinate is $(0,0,0)$.

If the lizard crawls along the walls from $(0,0,0)$ to diametrically the opposite corner, then it would be the furthest away corner.

Let $\vec{r}_i, \vec{r}_f$ be initial and final position vectors.
$$
\begin{aligned}
\therefore \vec{r}_i &= \hat{x}0 + \hat{y}0 + \hat{z}0 \\
\vec{r}_f &= \hat{x}4\text{m} + \hat{y}5\text{m} + \hat{z}3\text{m} \quad ; \text{corner which is the furthest away coordinate from } (0,0,0).
\end{aligned}
$$

$$\therefore \text{Displacement vector } \Delta \vec{r} = \hat{x}4\text{m} + \hat{y}5\text{m} + \hat{z}3\text{m}$$

**a) Length of $\vec{r} = |\vec{r}|$.**
$$
\begin{aligned}
|\vec{r}| &= \sqrt{r_x^2 + r_y^2 + r_z^2} \\
|\vec{r}| &= \sqrt{4^2\text{m}^2 + 5^2\text{m}^2 + 3^2\text{m}^2} \\
|\vec{r}| &= \sqrt{50}\text{m} \quad \text{or} \approx 7.07\text{m}
\end{aligned}
$$

**b) Shortest path**

<p align="center">
  <img src="images/pset3_img1.png" alt="3D Room Path" width="400">
</p>

To find shortest path we must find a way to treat environment as $d^2 = a^2 + b^2$.

Consider "unfolding" the room, like a box. We have a diagram like:

<p align="center">
  <img src="images/pset3_unfold_img2.png" alt="Unfolded Room" width="400">
</p>

Possible unfolding: 
$$
\begin{aligned}
\therefore d_A^2 &= (A_x + A_z)^2 + A_y^2 \quad \text{or} \\
d_B^2 &= (A_x + A_y)^2 + A_z^2 \quad \text{or} \\
d_C^2 &= (A_y + A_z)^2 + A_x^2 
\end{aligned}
$$

Expanding the terms:
$$
\begin{aligned}
d_A^2 &= A_x^2 + 2A_x A_z + A_z^2 + A_y^2 \\
d_B^2 &= A_x^2 + 2A_x A_y + A_y^2 + A_z^2 \\
d_C^2 &= A_y^2 + 2A_y A_z + A_z^2 + A_x^2
\end{aligned}
$$

Rearranging:
$$
\begin{aligned}
\therefore d_A^2 &= A_x^2 + A_y^2 + A_z^2 + 2A_x A_z \\
d_B^2 &= A_x^2 + A_y^2 + A_z^2 + 2A_x A_y \\
d_C^2 &= A_x^2 + A_y^2 + A_z^2 + 2A_y A_z
\end{aligned}
$$

Assume without loss of generality that, 
$$A_z \le A_x \le A_y$$
$$\therefore d_A \le d_C \le d_B$$

$$\therefore d = \sqrt{(A_x + A_z)^2 + A_y^2} \quad \text{when } A_z \le A_x \text{ \& } A_y \text{ is shortest possible path}$$

We have $A_x = 4\text{m}, A_y = 5\text{m}, A_z = 3\text{m}$.
$$\therefore A_z < A_x < A_y$$

$$\therefore d = \sqrt{(A_x + A_z)^2 + A_y^2}$$
$$d = \sqrt{(3+4)^2 + 5^2} = \sqrt{74}\text{m} \approx 8.60\text{m} \blacksquare$$

***

> **Problem 15:**
> Suppose that two ships proceeding at constant speeds are on converging straight tracks. Prove that the ships will collide if and only if the bearing of each remains constant as seen from the other. This constant-bearing rule is routinely used by mariners to check whether there is danger of collision. (Hint: A convenient method of proof is to draw the displacement vector from one ship to the other at several successive times.)

**Solution:**

Assume ship 1 to be the fixed origin.
Let $\Delta\vec{r}(t) = \Delta\vec{r}_0 + \Delta\vec{v}t$ be the relative position vector between ship 1 and 2.

<p align="center">
  <img src="images/pset3_img3.png" alt="Relative Position Vectors" width="400">
</p>

If the bearing $\alpha$ of ship 2 as seen from ship 1 remains constant,
Then for all relative position vectors $\Delta\vec{r}(t_1), \Delta\vec{r}(t_2), \dots$ they have same direction angle and different magnitudes.

It follows that $\Delta\vec{r}(t)$ is a scalar multiple of $\Delta\vec{r}_0$ for all $t$.

**Proof that (collision $\implies \alpha$ remains constant)**

Assume a collision occurs at some time $t_c > 0$. We must prove that the bearing $\alpha$ is constant for all $0 \le t \le t_c$.

At collision, 
$$\Delta\vec{r}(t_c) = \vec{0}$$

This is the case since $|\Delta\vec{r}(t_c)| = 0$, 
Then $\sqrt{(\Delta x)^2 + (\Delta y)^2} = 0$
$$(\Delta x)^2 + (\Delta y)^2 = 0$$
which is the case if $\Delta\vec{r}(t_c) = \vec{0} \quad (1)$

Using $\Delta\vec{r}(t_c) = \Delta\vec{r}_0 + \Delta\vec{v}t_c$,
$$
\begin{aligned}
\Delta\vec{r}_0 + \Delta\vec{v}t_c &= \vec{0} \\
\Delta\vec{v} &= \frac{-\Delta\vec{r}_0}{t_c} \quad (2)
\end{aligned}
$$

Using the general kinematic equation
$$
\begin{aligned}
\Delta\vec{r}(t) &= \Delta\vec{r}_0 + \Delta\vec{v}t \\
\Delta\vec{r}(t) &= \Delta\vec{r}_0 + \left(\frac{-\Delta\vec{r}_0}{t_c}\right)t \\
\Delta\vec{r}(t) &= \left(1 - \frac{t}{t_c}\right)\Delta\vec{r}_0 \blacksquare
\end{aligned}
$$

Because $\Delta\vec{r}(t)$ is a scalar multiple of the initial vector $\Delta\vec{r}_0$, and direction of $\Delta\vec{r}(t)$ and $\Delta\vec{r}_0$ is the same, for all $t < t_c$,
This proves that (collision $\implies \alpha$ remains constant).

**Proof that ($\alpha$ remains constant $\implies$ collision)**

Assume $\alpha$ is constant for all $t$. We must show a collision must occur.

$\alpha$ is constant means $\Delta\vec{r}(t)$ is always parallel to $\Delta\vec{r}_0$.
This allows us to define general position vector as a scalar multiple of initial position,
$$\Delta\vec{r}(t) = c(t)\Delta\vec{r}_0 \quad (1)$$

From $\Delta\vec{r}(t) = \Delta\vec{r}_0 + \Delta\vec{v}t$,
$$
\begin{aligned}
\text{Then} \quad c(t)\Delta\vec{r}_0 &= \Delta\vec{r}_0 + \Delta\vec{v}t \\
\text{Thus} \quad \Delta\vec{v} &= \Delta\vec{r}_0 \frac{(c(t)-1)}{t} \quad (2)
\end{aligned}
$$

Let $\frac{c(t)-1}{t} = k$
$$\text{Then} \quad \Delta\vec{v} = k \Delta\vec{r}_0 \quad (3)$$

Let $c(t_c) = 0 \quad (1)$
$$\text{Thus} \quad k t_c = -1 \implies t_c = \frac{-1}{k}$$
$$\text{Then} \quad t_c = \frac{-1}{k} \quad (3)$$

*(NOT OMITTED)*
For a valid future collision, it must be the case that $t_c > 0$
Then $k < 0$ from (3)
*(END NOT OMITTED)*

We know that:
$$|\Delta\vec{r}(t)| = \sqrt{\Delta\vec{r}(t) \cdot \Delta\vec{r}(t)}$$

Distance is strictly positive Hence $|\Delta\vec{r}(t)| > 0$.
The condition $\Delta\vec{r}(t)$ is decreasing is equivalent to
$$\left(\frac{d}{dt} |\Delta\vec{r}(t)| < 0\right)$$

Squaring for easy calculation:
$$\frac{d}{dt} |\Delta\vec{r}(t)|^2 < 0$$
$$\text{Thus} \quad \frac{d}{dt} [\Delta\vec{r}(t) \cdot \Delta\vec{r}(t)] < 0$$

By product rule we get:
$$
\begin{aligned}
\Delta\vec{r}'(t) \cdot \Delta\vec{r}(t) + \Delta\vec{r}(t) \cdot \Delta\vec{r}'(t) &< 0 \\
\text{Then} \quad 2 \Delta\vec{r}'(t) \cdot \Delta\vec{r}(t) &< 0 \\
\text{Then} \quad 2 \Delta\vec{v} \cdot \Delta\vec{r}(t) &< 0
\end{aligned}
$$

We can see that $\Delta\vec{v} = \Delta\vec{r}'(t)$.
$$\text{Then} \quad \Delta\vec{v} \cdot \Delta\vec{r}(t) < 0$$

To finalize $k < 0$, let's evaluate at $t=0$.
We can see that $\Delta\vec{r}(0) = \Delta\vec{r}_0$
$$\text{Then} \quad \Delta\vec{v} \cdot \Delta\vec{r}_0 < 0$$

Using (3) $\Delta\vec{v} = k\Delta\vec{r}_0$:
$$
\begin{aligned}
\text{Then} \quad k \Delta\vec{r}_0 \cdot \Delta\vec{r}_0 &< 0 \\
\text{Then} \quad k |\Delta\vec{r}_0|^2 &< 0
\end{aligned}
$$

Because for any vector $\vec{v}$, $|\vec{v}|^2 > 0$. Because the ships don't start at same location then $|\Delta\vec{r}_0| > 0$.
$$\text{Then we can conclude that } k < 0$$

Because $k < 0$, the time of collision $t_c$ is strictly positive, $t_c > 0$.
Therefore a valid future collision is guaranteed. $\blacksquare$

This completes the proof that The Two ships proceeding at constant speeds on converging straight tracks will collide if and only if the bearing of each remains constant as seen from the other. $\blacksquare$

***

> **Problem 45:**
> Show that the magnitude of $\mathbf{A} \cdot (\mathbf{B} \times \mathbf{C})$ is the volume of the parallelepiped determined by $\mathbf{A}$, $\mathbf{B}$, and $\mathbf{C}$.

**Solution:**

Show that $\vec{A} \cdot (\vec{B} \times \vec{C})$ is the volume of the parallelepiped determined by $A, B, C$.

From geometry, Volume $V$ of a parallelepiped is:
$$V = \text{Area}_{\text{base}} \times h \quad (1)$$

From vectors, if two vectors form two adjacent sides of a parallelogram, their area is the magnitude of their cross product.
$$\text{The Area}_{\text{base}} = |\vec{B} \times \vec{C}|$$

Let $\vec{N} = \vec{B} \times \vec{C}$ be the vector perpendicular to the base.

It follows that $h$ is the scalar projection of $\vec{A}$ onto $\vec{N}$.
$$\text{Then} \quad h = \frac{|\vec{A} \cdot \vec{N}|}{|\vec{N}|} \quad \text{Since geometric height must be non negative.}$$

From (1):
$$V = |\vec{B} \times \vec{C}| \cdot \frac{|\vec{A} \cdot \vec{N}|}{|\vec{N}|}$$
*\* for scalars $|x|$ is absolute value. for vector $|\vec{x}|$ is magnitude.*

We know that $\vec{N} = \vec{B} \times \vec{C}$
$$\text{Then} \quad |\vec{N}| = |\vec{B} \times \vec{C}|$$

$$\text{Then} \quad V = |\vec{B} \times \vec{C}| \cdot \frac{|\vec{A} \cdot (\vec{B} \times \vec{C})|}{|\vec{B} \times \vec{C}|}$$

$$\text{Then} \quad V = |\vec{A} \cdot (\vec{B} \times \vec{C})| \blacksquare$$

This completes the derivation and the proof $\blacksquare$

***

> **Problem 54:**
> Suppose that the coordinates $x', y', z'$ are related to the coordinates $x, y, z$ by a rotation through an angle $\theta$ about the $z$ axis [as in Eqs. (40) and (41)]. Suppose that the coordinates $x'', y'', z''$ are related to $x', y', z'$ by a rotation through an angle $\phi$ about the $x'$ axis.
> (a) What is the equation that relates the $x'', y'', z''$ coordinates to the $x', y', z'$ coordinates?
> (b) What is the equation that relates the $x'', y'', z''$ coordinates to the $x, y, z$ coordinates?

**Solution:**

**a)**
We know from (40) and (41) that under rotation by $\theta$:
$$
\begin{aligned}
x' &= x \cos \theta + y \sin \theta \quad [40] \\
y' &= -x \sin \theta + y \cos \theta \quad [41]
\end{aligned}
$$

It follows that under rotation by $\phi$,
$$
\begin{aligned}
x'' &= x' \cos \phi + y' \sin \phi \\
y'' &= -x' \sin \phi + y' \cos \phi
\end{aligned}
$$

**b)** Using (40) and (41)

$$\text{Then} \quad x'' = (x \cos \theta + y \sin \theta) \cos \phi + (-x \sin \theta + y \cos \theta) \sin \phi$$
$$\text{Then} \quad x'' = x \cos \theta \cos \phi + y \sin \theta \cos \phi - x \sin \theta \sin \phi + y \cos \theta \sin \phi$$

Rearranging and factoring,
$$x'' = x(\cos \theta \cos \phi - \sin \theta \sin \phi) + y(\sin \theta \cos \phi + \cos \theta \sin \phi)$$

By trig identities then
$$x'' = x \cos(\theta + \phi) + y \sin(\theta + \phi) \blacksquare$$

For $y''$:
$$y'' = -(x \cos \theta + y \sin \theta) \sin \phi + (-x \sin \theta + y \cos \theta) \cos \phi$$
$$y'' = -x \cos \theta \sin \phi - y \sin \theta \sin \phi - x \sin \theta \cos \phi + y \cos \theta \cos \phi$$

By rearranging and factoring,
$$y'' = -x(\cos \theta \sin \phi + \sin \theta \cos \phi) + y(\cos \theta \cos \phi - \sin \theta \sin \phi)$$

Then by trig identities,
$$y'' = -x \sin(\theta + \phi) + y \cos(\theta + \phi) \blacksquare$$