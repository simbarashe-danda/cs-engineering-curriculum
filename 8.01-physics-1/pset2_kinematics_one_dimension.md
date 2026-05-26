# Kinematics in One Dimension – Problem Set Solutions

---

## Problem 20 – Simple Harmonic Motion

### Given
Worldline:  
$$x(t) = A \cos(bt)$$  
with \(A = 2.0\ \text{m}\) and \(b = 1.0\ \text{rad/s}\).

### (a) Rough plot for \(0 \le t \le 7.0\ \text{s}\)
- Amplitude: \(A = 2.0\ \text{m}\)
- Angular frequency: \(b = 1.0\ \text{rad/s}\)
- Period: \(T = \frac{2\pi}{b} = 2\pi\ \text{s} \approx 6.28\ \text{s}\)

The graph is a cosine wave starting at \(x = +2.0\ \text{m}\) at \(t = 0\), crossing the time axis at \(t = \pi/2,\ 3\pi/2,\ \dots\), reaching \(x = -2.0\ \text{m}\) at \(t = \pi,\ 3\pi,\ \dots\), and returning to \(+2.0\ \text{m}\) at \(t = 2\pi\).

**DIAGRAM** – Plot of \(x\) vs. \(t\) with the features described above.

### (b) Time when the particle passes the origin (\(x = 0\))
Set \(x = 0\):
$$A \cos(bt) = 0 \ \Longrightarrow \ \cos(bt) = 0.$$
Then
$$bt = \frac{\pi}{2} + n\pi \qquad (n = 0, 1, 2, \dots)$$
$$t = \frac{\frac{\pi}{2} + n\pi}{b} = \frac{\pi}{2} + n\pi \ \text{s}.$$
First passage: \(t = \pi/2 \approx 1.57\ \text{s}\). Later passages every \(\pi\ \text{s}\).

Velocity and acceleration:
$$v = \frac{dx}{dt} = -Ab \sin(bt) = -2.0 \sin(bt)$$
$$a = \frac{dv}{dt} = -Ab^2 \cos(bt) = -2.0 \cos(bt)$$

At \(bt = \frac{\pi}{2} + n\pi\):
- \(\sin(bt) = \pm 1 \ \Rightarrow \ v = -2.0(\pm 1) = \mp 2.0\ \text{m/s}\).
- \(\cos(bt) = 0 \ \Rightarrow \ a = 0\ \text{m/s}^2\).

So at each origin passage the speed is \(2.0\ \text{m/s}\) and the acceleration is zero.

### (c) Maximum distance from the origin
Maximum \(|x|\) occurs when \(\cos(bt) = \pm 1\), i.e.  
$$bt = n\pi \ \Longrightarrow \ t = n\pi\ \text{s} \quad (n = 0, 1, 2, \dots).$$

At these times:
$$v = -2.0 \sin(n\pi) = 0\ \text{m/s}$$
$$a = -2.0 \cos(n\pi) = -2.0(\pm 1) = \mp 2.0\ \text{m/s}^2.$$
Magnitude of acceleration: \(2.0\ \text{m/s}^2\), velocity zero.

### Problem Statement (20)
The equation of the worldline of a particle is given by \(X = A \cos(bt)\) where \(A\) and \(b\) are constants. Assume that \(A = 2.0\ \text{m}\) and \(b = 1.0\ \text{rad/s}\).  
(a) Roughly plot the worldline of this particle for the time interval \(0\ \text{s} \le t \le 7.0\ \text{s}\).  
(b) At what time does the particle pass the origin (\(x = 0\))? What are its velocity and acceleration at this instant?  
(c) At what time does the particle reach maximum distance from the origin? What are its velocity and acceleration at this instant.

---

## Problem 30 – Drag Race

### Given
- Distance: \(d = 440\ \text{yd} = 440 \times 0.9144\ \text{m} = 402.336\ \text{m}\)
- Record time: \(t_f = 5.637\ \text{s}\)
- Final speed: \(v_f = 250.69\ \text{mi/h} = 250.69 \times 0.44704\ \text{m/s} = 112.07\ \text{m/s}\)
- Starts from rest: \(v_0 = 0\)

### (a) Average acceleration
$$a_{\text{avg}} = \frac{\Delta v}{\Delta t} = \frac{v_f - v_0}{t_f} = \frac{112.07}{5.637} \approx 19.88\ \text{m/s}^2.$$

### (b) Proof that the car did not move with constant acceleration
Assume constant acceleration \(a = a_{\text{avg}}\). The distance would be:
$$d_{\text{const}} = \frac{v_0 + v_f}{2}\, t_f = \frac{0 + 112.07}{2} \times 5.637 = 56.035 \times 5.637 \approx 315.8\ \text{m}.$$
Actual distance: \(402.336\ \text{m}\).  
Since \(315.8\ \text{m} \neq 402.336\ \text{m}\), acceleration cannot have been constant.

### (c) Final speed with constant acceleration to cover 440 yd in 5.637 s
For constant acceleration from rest:
$$d = \frac{1}{2} a t_f^2 \ \Longrightarrow \ a = \frac{2d}{t_f^2}.$$
Then final speed:
$$v = a t_f = \frac{2d}{t_f} = \frac{2 \times 402.336}{5.637} \approx 142.8\ \text{m/s}.$$
(This is about \(319\ \text{mi/h}\), much higher than the record.)

### Problem Statement (30)
In a “drag” race a car starts at rest and attempts to cover 440 yd in the shortest possible time. The world record for a piston-engined car is 5.637 s; while setting this record, the car reached a final speed of 250.69 mi/h at the 440-yd mark.  
(a) What was the average acceleration for the run?  
(b) Prove that the car did not move with constant acceleration.  
(c) What would have been the final speed if the car had moved with constant acceleration so as to reach 440 yd in 5.637 s?

---

## Problem 32 – World Trade Center Elevator

### Given
- Descent from 107th floor to ground: distance \(D = 400\ \text{m}\)
- Total time: \(T = 55\ \text{s}\)
- Starts and ends at rest.

### (a) Average speed
$$v_{\text{avg}} = \frac{D}{T} = \frac{400}{55} \approx 7.27\ \text{m/s}.$$

### (b) Minimum acceleration/deceleration program
To minimise peak acceleration for a given distance and time, use a symmetric triangular velocity profile.

**DIAGRAM** – Velocity vs. time graph. Triangle of base \(T\) and height \(v_{\text{max}}\). Area = \(D\).

Area under \(v\)–\(t\) curve equals distance:
$$D = \frac{1}{2} T v_{\text{max}}.$$
$$v_{\text{max}} = \frac{2D}{T} = \frac{800}{55} \approx 14.55\ \text{m/s}.$$

Acceleration (magnitude) during first half:
$$a_{\text{min}} = \frac{v_{\text{max}}}{T/2} = \frac{2 v_{\text{max}}}{T} = \frac{4D}{T^2}.$$
$$a_{\text{min}} = \frac{4 \times 400}{55^2} = \frac{1600}{3025} \approx 0.529\ \text{m/s}^2.$$

Motion program:
- Accelerate at \(+0.529\ \text{m/s}^2\) for the first \(27.5\ \text{s}\).
- Reach maximum speed \(14.55\ \text{m/s}\) at \(t = 27.5\ \text{s}\).
- Decelerate at \(-0.529\ \text{m/s}^2\) for the remaining \(27.5\ \text{s}\).

### Problem Statement (32)
(a) At the World Trade Center in New York City, the elevator takes 55 s to descend from the 107th floor to ground level, a distance of 400 m. What is the average speed of the elevator for this trip?  
(b) The elevator is at rest at the beginning and at the end of the trip. If you wanted to program the elevator so that it completes the trip in the specified time with a minimum acceleration and a minimum deceleration, how would you have to accelerate and decelerate the elevator? What would be these minimum values of the acceleration and deceleration? What would be the maximum speed during the trip?

---

## Problem 34 – Cow on the Road

### Given
- Initial speed: \(90\ \text{km/h} = 25\ \text{m/s}\)
- Reaction time: \(t_r = 0.75\ \text{s}\)
- Distance to cow: \(30\ \text{m}\)
- Deceleration: \(a = -0.80\,g\) with \(g \approx 9.8\ \text{m/s}^2\)

### Solution
#### State 1 – Reaction phase (constant speed)
Distance travelled before braking:
$$\Delta x_1 = v_0 t_r = 25 \times 0.75 = 18.75\ \text{m}.$$

#### State 2 – Braking phase
Remaining distance: \(\Delta x_2 = 30 - 18.75 = 11.25\ \text{m}\).  
Initial speed for braking: \(v_0 = 25\ \text{m/s}\).  
Acceleration: \(a = -0.80 \times 9.8 = -7.84\ \text{m/s}^2\).

Using the time‑independent kinematic equation:
$$v^2 = v_0^2 + 2a \Delta x_2.$$
$$v^2 = 25^2 + 2(-7.84)(11.25) = 625 - 176.4 = 448.6\ \text{m}^2/\text{s}^2.$$
$$v = \sqrt{448.6} = \pm 21.18\ \text{m/s}.$$
The positive root gives the speed at impact: \(v = 21.18\ \text{m/s}\).

### Additional – Minimum safe distance to stop completely
Set final velocity \(v = 0\):
$$0 = v_0^2 + 2a \Delta x_{\text{brake}} \ \Longrightarrow \ \Delta x_{\text{brake}} = \frac{-v_0^2}{2a} = \frac{-(25)^2}{2(-7.84)} = \frac{625}{15.68} = 39.86\ \text{m}.$$
Total distance needed:
$$\Delta x_{\text{total}} = \Delta x_1 + \Delta x_{\text{brake}} = 18.75 + 39.86 = 58.61\ \text{m}.$$
The cow would need to be at least \(58.6\ \text{m}\) away to avoid being hit.

### Problem Statement (34)
An automobile is traveling at 90 km/h on a country road when the driver suddenly notices a cow in the road 30 m ahead. The driver attempts to brake the automobile, but the distance is too short. With what velocity does the automobile hit the cow? Assume that, as in Problem 33, the reaction time of the driver is 0.75 s and that the deceleration of the automobile is 0.80 G when the brakes are applied.

---

## Problem 36 – Passing Acceleration

### Given (from manual figure)
- Truck speed: \(v_{\text{truck}} = 32\ \text{km/h} = 8.89\ \text{m/s}\) (constant)
- Car speed during pass: \(v_{\text{car,pass}} = 56\ \text{km/h} = 15.56\ \text{m/s}\)
- Car starts the pass at the same speed as the truck: \(v_{\text{car,initial}} = v_{\text{truck}}\)
- Relative passing distance (from geometry of clearances and vehicle lengths): \(\Delta x_{\text{rel}} = 46\ \text{m}\)

**DIAGRAM** – Top‑view schematic with initial and final positions of car and truck, showing lengths and gaps.

### Solution – Relative motion
Define relative quantities (car relative to truck):

$$x_{\text{rel}}(t) = x_{\text{car}}(t) - x_{\text{truck}}(t) \tag{1}$$
$$v_{\text{rel}}(t) = v_{\text{car}}(t) - v_{\text{truck}}(t) \tag{2}$$

Initial relative velocity: \(v_{\text{rel,0}} = v_{\text{car,initial}} - v_{\text{truck}} = 0\).  
Final relative velocity: \(v_{\text{rel}} = 15.56 - 8.89 = 6.67\ \text{m/s}\).  
Relative displacement: \(\Delta x_{\text{rel}} = 46\ \text{m}\).

Assume constant acceleration \(a_{\text{rel}}\) (and thus \(a_{\text{car}} = a_{\text{rel}}\) because \(a_{\text{truck}} = 0\)).

From the definitions of constant acceleration:
$$\Delta x = v_0 t + \frac{1}{2} a t^2, \qquad a = \frac{v - v_0}{t}.$$

Eliminate \(t\) to get a relation between \(\Delta x\) and \(v\):
\begin{align}
\Delta x &= v_0 t + \frac{1}{2}\left(\frac{v - v_0}{t}\right) t^2
          = \left(v_0 + \frac{1}{2}(v - v_0)\right) t
          = \frac{v_0 + v}{2}\,t \tag{3}\\[4pt]
t &= \frac{v - v_0}{a} \ \Longrightarrow\ 
\Delta x = \frac{v_0 + v}{2}\,\frac{v - v_0}{a}
        = \frac{v^2 - v_0^2}{2a} \tag{4}
\end{align}

Apply equation (4) to the relative quantities:
$$\Delta x_{\text{rel}} = \frac{v_{\text{rel}}^2 - v_{\text{rel,0}}^2}{2a_{\text{rel}}}.$$
$$46 = \frac{(6.67)^2 - 0^2}{2a_{\text{rel}}} = \frac{44.49}{2a_{\text{rel}}}.$$
$$a_{\text{rel}} = \frac{44.49}{2 \times 46} = \frac{44.49}{92} \approx 0.4836\ \text{m/s}^2. \tag{5}$$

Time required for the pass:
$$t = \frac{v_{\text{rel}} - v_{\text{rel,0}}}{a_{\text{rel}}} = \frac{6.67}{0.4836} \approx 13.8\ \text{s}. \tag{6}$$

Since the truck’s acceleration is zero,
$$a_{\text{car}} = a_{\text{rel}} \approx 0.48\ \text{m/s}^2.$$

### Result
The car accelerates at \(0.48\ \text{m/s}^2\) for \(13.8\ \text{s}\) to complete the pass.

### Problem Statement (36)
Figure 2.13 (copied from the operation manual of an automobile) describes the passing ability of the automobile at low speed. From the data supplied in this figure, calculate the acceleration of the automobile during the pass and the time required for the pass. Assume constant acceleration.