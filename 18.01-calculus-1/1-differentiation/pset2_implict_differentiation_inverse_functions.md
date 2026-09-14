**1F-3** Find $dy/dx$ for $y = x^{1/n}$ by implicit differentiation.

**Solution:**
Given the equation:


$$y^n = x$$


Differentiating both sides with respect to $x$:


$$\frac{d}{dx}(y^n) = \frac{d}{dx}(x)$$


Then, applying the chain rule:


$$n y^{n-1} \cdot \frac{dy}{dx} = 1$$


Thus, isolating $\frac{dy}{dx}$:


$$\frac{dy}{dx} = (n y^{n-1})^{-1}$$

$$\frac{dy}{dx} = \frac{1}{n} y^{1-n}$$


Because $y = x^{1/n}$,
Then, substituting $y$ back:


$$\frac{dy}{dx} = \frac{1}{n} x^{\frac{1}{n}-1}$$


$\blacksquare$

---

**1F-5** Find all points of the curve(s) $\sin x + \sin y = 1/2$ with horizontal tangent lines. (This is a collection of curves with a periodic, repeated pattern because the equation is unchanged under the transformations $y \to y + 2\pi$ and $x \to x + 2\pi$.)

**Solution:**
When the tangent line is horizontal, the slope $m$ is zero:


$$m = f'(x) = 0$$


Calculating the derivative:


$$\frac{d}{dx}\left(\sin x + \sin y = 1/2\right)$$

$$\frac{d}{dx}(\sin x) + \frac{d}{dx}(\sin y) = 1/2$$


Then, using implicit differentiation:


$$\cos x + \cos y \frac{dy}{dx} = 0$$


Thus, solving for $\frac{dy}{dx}$:


$$\frac{dy}{dx} = \frac{-\cos x}{\cos y}$$


When $\frac{dy}{dx} = 0$,


$$\cos x = 0 \quad \text{when } x = \pi/2$$


Since from the original equation:


$$y = \sin^{-1}(1/2 - \sin x) \quad (1)$$


We establish that $\cos y \neq 0$.

Therefore, $\frac{-\cos x}{\cos y}$ is continuous at $x = \pi/2$.

Substituting $x$ in $\sin x + \sin y = 1/2$:


$$\sin(\pi/2) + \sin y = 1/2$$

$$y = -\pi/6 \quad \text{from } (1)$$


Since $x \to x + 2\pi$ (shifting) looks identical and $y \to y + 2\pi$ (shifting) look identical, we only solve for the $2\pi$ window.

Therefore, the coordinate points are $(\pi/2, -\pi/6)$.

Since $\sin(-\pi/6) = \sin(7\pi/6)$,

Then, all coordinates in the $2\pi$ window are:


$$(\pi/2 + 2n\pi, -\pi/6 + 2n\pi) \quad \text{and} \quad (\pi/2 + 2n\pi, 7\pi/6 + 2n\pi)$$


$\blacksquare$

---

**1H-1** The half-life $\lambda$ of a radioactive substance decaying according to the law $y = y_0 e^{-kt}$ is defined to be the time it takes the amount to decrease to $1/2$ of the initial amount $y_0$.
a) Express the half-life $\lambda$ in terms of $k$. (Do this from scratch — don't just plug into formulas given here or elsewhere.)

**Solution:**
Given the decay equation:


$$y = y_0 e^{-kt}$$


Expressing $\lambda$ in terms of $k$, we first isolate the exponential term:


$$e^{-kt} = \frac{y}{y_0}$$


Taking the natural logarithm ($\ln$) of both sides:


$$-kt = \ln\left(\frac{y}{y_0}\right)$$


Then, solving for $t$:


$$t = \frac{-\ln(y/y_0)}{k} \quad (1)$$


When the amount halves, $y = \frac{1}{2}y_0$.

Then, substituting this into our equation for $t$:


$$t = \frac{-\ln(1/2)}{k}$$


Thus, calculating the logarithm:


$$t = \frac{\ln(2)}{k} = \lambda \quad \text{when } y = \frac{1}{2}y_0$$


$\blacksquare$

---

**1H-1** (continued)
b) Show using your expression for $\lambda$ that if at time $t_1$ the amount is $y_1$, then at time $t_1 + \lambda$ it will be $y_1/2$, no matter what $t_1$ is.

**Solution:**
At time $t_1$, the amount is:


$$y_1 = y_0 e^{-k t_1} \quad (1)$$


At time $t_1 + \lambda$, the amount is:


$$y_2 = y_0 e^{-k(t_1 + \lambda)}$$


Expanding the exponent:


$$y_2 = y_0 e^{-k t_1 - k\lambda}$$


From part (a), we know $\lambda = \ln(2)/k$.
Then, substituting $\lambda$:


$$y_2 = y_0 e^{-k t_1 - \ln(2)}$$


Using exponent properties and substituting from (1):


$$y_2 = y_1 \cdot e^{-\ln(2)}$$


Thus, simplifying the exponential:


$$y_2 = \frac{1}{2} y_1$$


Therefore, at $t_1 + \lambda$, $y_2 = y_1/2$ no matter what $t_1$ is.
$\blacksquare$

---

**1H-2** If a solution containing a heavy concentration of hydrogen ions (i.e., a strong acid) is diluted with an equal volume of water, by approximately how much is its pH changed? 

**Solution:**
Let the initial pH in terms of hydrogen ions $[H^+]_{\text{initial}}$ be:


$$\text{pH}_{\text{original}} = -\log_{10}[H^+]_{\text{initial}} \quad (1)$$


When diluted with an equal volume of water, the concentration halves:


$$[H^+]_{\text{new}} = \frac{1}{2}[H^+]_{\text{initial}} \quad (2)$$


Then, the new pH is:


$$\text{pH}_{\text{diluted}} = -\log_{10}\left(\frac{1}{2}[H^+]_{\text{initial}}\right)$$


Using the logarithm law $\log(AB) = \log A + \log B$:
Then, expanding the expression:


$$\text{pH}_{\text{diluted}} = -\log_{10}(0.5) - \log_{10}[H^+]_{\text{initial}}$$


Because $-\log_{10}(0.5) \approx 0.301$,
Then, substituting this value:


$$\text{pH}_{\text{diluted}} = 0.301 - \log_{10}[H^+]_{\text{initial}}$$


Thus, substituting from (1):


$$\text{pH}_{\text{diluted}} = 0.301 + \text{pH}_{\text{original}}$$


$\blacksquare$

---

**1H-5** Solve for $x$ :
b) $y = e^x + e^{-x}$

**Solution:**
Given the equation:


$$y = e^x + e^{-x}$$


Let $u = e^x \quad (1)$
Then, substituting $u$ into the equation:


$$y = u + 1/u$$


Then, combining over a common denominator:


$$y = \frac{u^2 + 1}{u}$$


Thus, multiplying by $u$ and rearranging into a standard quadratic form:


$$u^2 - uy + 1 = 0$$


Then, solving for $u$ by the quadratic formula:


$$u = \frac{y \pm \sqrt{y^2 - 4}}{2}$$


From (1), taking the natural logarithm to solve for $x$:


$$x = \ln\left(\frac{y \pm \sqrt{y^2 - 4}}{2}\right)$$


$\blacksquare$

---

**1I-1** Calculate the derivatives
c) $e^{-x^2}$

**Solution:**
Taking the derivative with respect to $x$:


$$\frac{d}{dx}(e^{-x^2})$$


By applying the chain rule:


$$= -2x \cdot e^{-x^2}$$


$\blacksquare$

---

**1I-1** Calculate the derivatives
d) $x \ln x - x$

**Solution:**
Taking the derivative with respect to $x$:


$$\frac{d}{dx}(x \ln x - x)$$


By applying the product rule to the first term:


$$= x' \cdot \ln x + x(\ln x)' - x'$$


Then, simplifying the derivatives:


$$= \ln x$$


$\blacksquare$

---

**1I-1** Calculate the derivatives
e) $\ln(x^2)$

**Solution:**
Taking the derivative with respect to $x$:


$$\frac{d}{dx}(\ln(x^2))$$


By applying the chain rule:


$$\Rightarrow \frac{1}{x^2} \cdot 2x$$


Then, evaluating the result:


$$= \frac{2x}{x^2}$$

$$= 2/x$$


$\blacksquare$

---

**1I-1** Calculate the derivatives
f) $(\ln x)^2$

**Solution:**
Taking the derivative with respect to $x$:


$$\frac{d}{dx}((\ln x)^2)$$


By applying the chain rule:


$$= 2 \ln x \cdot \frac{1}{x}$$


Thus, combining terms:


$$= \frac{2 \ln x}{x}$$


$\blacksquare$

---

**1I-1** Calculate the derivatives
m) $(1 - e^x)/(1 + e^x)$

**Solution:**
Taking the derivative with respect to $x$:


$$\frac{d}{dx}\left(\frac{1 - e^x}{1 + e^x}\right)$$


By applying the quotient rule:


$$= \frac{(1 - e^x)' \cdot (1 + e^x) - (1 - e^x)(1 + e^x)'}{(1 + e^x)^2}$$


Then, differentiating and expanding the numerator:


$$= \frac{-e^{2x} - e^x - e^x + e^{2x}}{(1 + e^x)^2}$$


Thus, combining like terms:


$$= \frac{-2e^x}{(1 + e^x)^2}$$


$\blacksquare$

---

**1I-4** Using $\lim_{n \to \infty} (1 + \frac{1}{n})^n = e$, calculate
a) $\lim_{n \to \infty} (1 + \frac{1}{n})^{3n}$

**Solution:**
Using the given limit property:


$$\lim_{n \to \infty} \left(1 + 1/n\right)^n = e \quad (1)$$


Evaluating the given limit:


$$\lim_{n \to \infty} \left(1 + 1/n\right)^{3n}$$


Which is equivalent by exponent rules to:


$$\lim_{n \to \infty} \left(\left(1 + 1/n\right)^n\right)^3$$


From (1), we substitute $e$ into the limit.
Then, raising it to the third power:


$$\lim_{n \to \infty} \left(1 + 1/n\right)^{3n} = e^3$$


$\blacksquare$
