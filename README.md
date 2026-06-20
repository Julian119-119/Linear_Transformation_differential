# Intro

# Polynomial Differential Operator

## polynomial differential operator is linear transformation
### Proof

Let $P_n$ be the vector space of all polynomials of degree at most n, and define the differential operator $D:P_n \rightarrow P_{n-1}$ by $D(f)=f',\; f\in P_n.$

To show that $D$ is a linear transformation, it suffices to verify that $\forall \ f,g\in P_n, \ D(af+bg)=aD(f)+bD(g)$ and scalars $a,b\in\mathbb{R}$.

Using the definition of the derivative,

$$  
\begin{aligned}  
D(af+bg)  
&=(af+bg)'\\  
&=\lim_{h\to0} \frac{(af+bg)(x+h)-(af+bg)(x)}{h}\\  
&=\lim_{h\to0} \frac{a f(x+h)+b g(x+h)-a f(x)-b g(x)}{h}\\  
&=\lim_{h\to0} \left( a\frac{f(x+h)-f(x)}{h} + b\frac{g(x+h)-g(x)}{h} \right) \\  
&= a\lim_{h\to0} \frac{f(x+h)-f(x)}{h} + b\lim_{h\to0} \frac{g(x+h)-g(x)}{h} \\  
&= af'(x)+bg'(x) \\  
&= aD(f)+bD(g).  
\end{aligned}  
$$

Therefore, $D(af+bg)=aD(f)+bD(g)$, so $D$ is a linear transformation.

---
# Product Rule

After proving that differentiation is a linear transformation on $P_n$, I wondered whether differentiation also preserves multiplication.

That is, I tested the conjecture

$$
D(fg)=D(f)D(g).
$$

### Counterexample

Let $f(x)=x,\qquad g(x)=x$.<br>Then $D(fg)=D(x^2)=2x.$<br>On the other hand, $D(f)D(g)=D(x)D(x)=1.$<br>Since $2x \neq 1$, the conjecture $D(fg)=D(f)D(g)$ is false.<br>Therefore, differentiation does not preserve multiplication.

---

# Chain Rule

We have shown that differentiation is a linear transformation: $D(af+bg)=aD(f)+bD(g)$. However, this property only describes how differentiation behaves under addition and scalar multiplication. It does not tell us how to deal with $D(f\circ g).$ To investigate this problem, I first study the composition operator $C_g(f)=f\circ g.$  

I then check whether $C_g$ is a linear transformation.

$$\begin{aligned}  
C_g(af+bh)  
&=(af+bh)\circ g\\  
&=(af+bh)(g(x))\\
&=af(g(x))+bh(g(x))\\  
&=a(f\circ g)(x)+b(h\circ g)(x)\\  
&=aC_g(f)+bC_g(h).  
\end{aligned}$$

Therefore, $C_g$ is a linear transformation.

Since $C_g(f)=f\circ g$, we may rewrite $D(f\circ g) = D(C_g(f)) = (D\circ C_g)(f).$  

At this point, both $D$ and $C_g$ are linear transformations. Therefore, $D \circ C_g$ is also a linear transformation. However, linear algebra only tells us that the composition remains linear; it does not provide its explicit form.

---
# Transcendental Functions

Using Taylor series expansions, many transcendental functions can be represented as infinite polynomials.

$$\begin{aligned}
&e^x = \sum_{n=0}^{\infty} \frac{x^n}{n!} \\
&\sin x = \sum_{n=0}^{\infty} (-1)^n \frac{x^{2n+1}}{(2n+1)!} \\
&\cos x = \sum_{n=0}^{\infty} (-1)^n \frac{x^{2n}}{(2n)!} \\
&arctan x = \sum_{n=0}^{\infty} (-1)^n \frac{x^{2n+1}}{2n+1} \\
&\ln(1+x) = \sum_{n=1}^{\infty} (-1)^{n-1} \frac{x^n}{n}
\end{aligned}$$

Therefore, transcendental functions can be viewed as elements of an infinite-dimensional function space with basis $\{1,x,x^2,x^3,\ldots\}.$<br>this thing leads me to think:

> If differentiation is a linear transformation on polynomial spaces, can the same idea be extended to an infinite-dimensional function space?

---

## Verification by Taylor Series

Assume that differentiation can be applied term-by-term to Taylor series.

### Exponential Function

$$e^x = 1+x+\frac{x^2}{2!} +\frac{x^3}{3!} + \cdots$$

Differentiating term-by-term,

$$\begin{aligned}
D(e^x)
&= D\left( 1+x+\frac{x^2}{2!} +\frac{x^3}{3!} +\cdots \right) \\
&= 0+1+x+\frac{x^2}{2!} +\frac{x^3}{3!} +\cdots \\
&= e^x
\end{aligned}$$

Hence, $(e^x)'=e^x.$

### Sine Function

$$\sin x = x-\frac{x^3}{3!} +\frac{x^5}{5!} -\cdots$$

Differentiating term-by-term,

$$\begin{aligned}
D(\sin x) 
&= 1-\frac{x^2}{2!} +\frac{x^4}{4!} -\cdots \\
&= \cos x
\end{aligned}$$

Hence, $(\sin x)'=\cos x$

### Cosine Function

$$\cos x = 1-\frac{x^2}{2!} +\frac{x^4}{4!} -\cdots$$

Differentiating term-by-term,

$$\begin{aligned}
D(\cos x)
&= 0-x+\frac{x^3}{3!} -\frac{x^5}{5!} + \cdots \\
&= -\sin x.
\end{aligned}$$

Hence, $(\cos x)'=-\sin x$

---

## Limitation

The above derivations suggest that the differential operator may continue to behave like a linear transformation in an infinite-dimensional function space.

However, Taylor series contain infinitely many terms. To justify term-by-term differentiation and determine whether all finite-dimensional results remain valid, additional knowledge of infinite-dimensional vector spaces and convergence theory is required.

These topics are beyond the scope of my current study.
# Conclusion