# Introduction

During a linear algebra lecture, professor teach us using linear transformation to solve polynomial transformation. 

This example immediately raised a question for me.

The differential operator works naturally on polynomial spaces and satisfies the definition of a linear transformation. However, many differentiation techniques learned in calculus involve additional structures beyond simple addition and scalar multiplication. Examples include the Product Rule, the Chain Rule, and derivatives of transcendental functions such as $e^x$, $\sin x$, and $\cos x$.

This led me to wonder:

> If differentiation on polynomial spaces can be understood through linear transformations, can the same perspective also explain these other differentiation rules?

To investigate this question, I first verified that the differential operator on polynomial spaces is indeed a linear transformation. I then explored whether the same framework could be extended to multiplication, function composition, and transcendental functions.

Rather than attempting to prove the familiar differentiation formulas directly, the goal of this project is to examine the scope and limitations of the linear transformation viewpoint and identify where additional mathematical structures become necessary.



---
# Polynomial Differential Operator

## polynomial differential operator is linear transformation
### Proof

Let $P_n$ be the vector space of all polynomials of degree at most n, and define the differential operator $D:P_n \rightarrow P_{n-1}$ by $D(f)=f',\ f\in P_n.$

To show that $D$ is a linear transformation, it suffices to verify that $\forall \ f,g\in P_n, \ D(af+bg)=aD(f)+bD(g)$ and scalars $a,b\in\mathbb{R}$.

Using the definition of the derivative,

$$\begin{aligned}  
D(af+bg)  
&=(af+bg)'\\  
&=\lim_{h\to0} \frac{(af+bg)(x+h)-(af+bg)(x)}{h}\\  
&=\lim_{h\to0} \frac{a f(x+h)+b g(x+h)-a f(x)-b g(x)}{h}\\  
&=\lim_{h\to0} \left( a \ \frac{f(x+h)-f(x)}{h} + b \ \frac{g(x+h)-g(x)}{h} \right) \\  
&= a\lim_{h\to0} \frac{f(x+h)-f(x)}{h} + b\lim_{h\to0} \frac{g(x+h)-g(x)}{h} \\  
&= af'(x)+bg'(x) \\  
&= aD(f)+bD(g).  
\end{aligned}$$

Therefore, $D(af+bg)=aD(f)+bD(g)$, so $D$ is a linear transformation.

---
# Product Rule

After proving that differentiation is a linear transformation on $P_n$, I wondered whether differentiation also preserves multiplication.

That is, I tested the conjecture

$$D(fg)=D(f)D(g).$$

### Counterexample

Let $f(x)=x,\ g(x)=x$.<br>Then $D(fg)=D(x^2)=2x.$<br>On the other hand, $D(f)D(g)=D(x)D(x)=1.$<br>Since $2x \neq 1$, the conjecture $D(fg)=D(f)D(g)$ is false.<br>Therefore, differentiation does not preserve multiplication.

## Reflection

The counterexample shows that differentiation does not preserve multiplication in the same way that it preserves addition.

This observation is significant because multiplication introduces a new operation that is not included in the definition of a linear transformation. While linearity completely describes the behavior of differentiation under addition and scalar multiplication, it provides no information about products of functions.

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

At this point, both $D$ and $C_g$ are linear transformations. Therefore, $D \circ C_g$ is also a linear transformation. However, linear algebra only tells us that the composition remains linear. it does not provide its explicit form.

## Reflection

The composition operator successfully transforms function composition into a linear transformation.

However, although both $D$ and $C_g$ are linear transformations, the current framework only tells us that $D\circ C_g$ remains linear. It does not explain why the Chain Rule takes the form $(f\circ g)^{\prime}=(f'\circ g)g^{\prime}$.

This suggests that function composition introduces additional structure that is not fully captured by the linear transformation framework developed so far.

---
# Transcendental Functions

Using Taylor series expansions, many transcendental functions can be represented as infinite polynomials.

$$\begin{aligned}
&e^x = \sum_{n=0}^{\infty} \frac{x^n}{n!} \\
&\sin x = \sum_{n=0}^{\infty} (-1)^n \ \frac{x^{2n+1}}{(2n+1)!} \\
&\cos x = \sum_{n=0}^{\infty} (-1)^n \frac{x^{2n}}{(2n)!} \\
&\arctan x = \sum_{n=0}^{\infty} (-1)^n \ \frac{x^{2n+1}}{2n+1} \\
&\ln(1+x) = \sum_{n=1}^{\infty} (-1)^{n-1} \ \frac{x^n}{n}
\end{aligned}$$

These Taylor series expansions suggest that transcendental functions behave similarly to infinite polynomials.

Since polynomial functions can be studied through the differential operator on polynomial spaces, I wondered whether the same idea could be extended to transcendental functions by viewing them as infinite polynomials.

---

## Verification by Taylor Series

If transcendental functions can indeed be treated as infinite polynomials, then the differential operator should act on them in the same way it acts on ordinary polynomials.

To test this idea, I differentiate several Taylor series term-by-term and compare the results with familiar derivative formulas from calculus.

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

Hence, $(\sin x)'=\cos x$.

### Cosine Function

$$\cos x = 1-\frac{x^2}{2!} +\frac{x^4}{4!} -\cdots$$

Differentiating term-by-term,

$$\begin{aligned}
D(\cos x)
&= 0-x+\frac{x^3}{3!} -\frac{x^5}{5!} + \cdots \\
&= -\sin x.
\end{aligned}$$

Hence, $(\cos x)'=-\sin x$.

---

## Limitation

The above derivations suggest that the differential operator may continue to behave like a linear transformation in an infinite-dimensional function space.

However, Taylor series contain infinitely many terms. To justify term-by-term differentiation and determine whether all finite-dimensional results remain valid, additional knowledge of infinite-dimensional vector spaces and convergence theory is required.

These topics are beyond the scope of my current study.

---
# Conclusion

This project was motivated by a question that arose during a linear algebra lecture. After seeing polynomial differentiation represented as a linear transformation, I became curious whether the same perspective could also be applied to other familiar topics in calculus, such as the Product Rule, the Chain Rule, and transcendental functions.

To explore this question, I first verified that the differential operator on polynomial spaces is indeed a linear transformation. I then investigated whether similar ideas could be extended to multiplication, function composition, and Taylor series representations of transcendental functions.