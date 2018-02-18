# Assignment 2 - CS 4071 - Spring 2018

*Due: 2018-02-19*
*Group #13: Robert DiMartino (dimartrt), Hayden Schiff (schiffha), Jeremiah Leak (leakjz)*

<div style="page-break-after: always;"></div>

## 1. Exercise 2.24

**Problem**: Give pseudocode for interpolation search, and analyze its worst-cast complexity.

## 2. Exercise 3.6

**Problem**: Using the Ratio Limit Theorem, prove the following:
$$
O(108) \subset O(\ln{n}) \subset O(n) \subset O(n \ln{n}) \subset O(n^{2}) \subset O(n^{3}) \subset O(2^{n}) \subset O(3^{n})
$$

### i.
$$
\lim_{n \rightarrow \infty} \frac{108}{\ln{n}} = 0 \\
\therefore O(108) \subset O(\ln{n})
$$

### ii.
$$
\lim_{n \rightarrow \infty} \frac{\ln{n}}{n} \\
= \lim_{n \rightarrow \infty} \frac{\frac{1}{n}}{1} \\
= \frac{0}{1} = 0 \\
\therefore O(\ln{n}) \subset O(n)
$$

### iii.
$$
\lim_{n \rightarrow \infty} \frac{n}{n\ln{n}} \\
= \lim_{n \rightarrow \infty} \frac{1}{1+\ln{n}} \\
= 0 \\
\therefore O(n) \subset O(n \ln{n})
$$

### iv.
$$
\lim_{n \rightarrow \infty} \frac{n \ln{n}}{n^{2}} \\
= \lim_{n \rightarrow \infty} \frac{1+\ln{n}}{2n} \\
= \lim_{n \rightarrow \infty} \frac{\frac{1}{n}}{2} \\
= \frac{0}{2} = 0 \\
\therefore O(n \ln{n}) \subset O(n^{2})
$$

### v.
$$
\lim_{n \rightarrow \infty} \frac{n^{2}}{n^{3}} \\
= \lim_{n \rightarrow \infty} \frac{1}{n} \\
= 0 \\
\therefore O(n^{2}) \subset O(n^{3})
$$

### vi.
$$
\lim_{n \rightarrow \infty} \frac{n^{3}}{2^{n}} \\
= \lim_{n \rightarrow \infty} \frac{3n^{2}}{2^{n} \ln{2}} \\
= \lim_{n \rightarrow \infty} \frac{6n}{2^{n} \ln^{2}{2}} \\
= \lim_{n \rightarrow \infty} \frac{6}{2^{n} \ln^{3}{2}} \\
= 0 \\
\therefore O(n^{3}) \subset O(2^{n})
$$

### vii.
$$
\lim_{n \rightarrow \infty} \frac{2^{n}}{3^{n}} \\
= \lim_{n \rightarrow \infty} \left(\frac{2}{3}\right)^{n} \\
= 0 \\
\therefore O(2^{n}) \subset O(3^{n})
$$

## 3. Exercise 3.26

**Problem**: Obtain a formula for the order of $S(n) = \sum_{i=1}^{n}(\ln{i})^{2}$.

We start by showing that $S(n) \in O(n \ln^{2}{n})$.
$$
S(n) = \sum_{i=1}^{n}(\ln{i})^{2} = \sum_{i=1}^{n}\ln^{2}{i} \\
= \ln^{2}{1} + \ln^{2}{2} + \dots + \ln^{2}{n}
$$
It can be shown that $f(x) = \ln^{2}x$ has a global minimum as $x=1$ and is increasing for $x\geq1$. So it holds that $\ln^{2}a \leq \ln^{2}b$ when $1 \leq a \leq b$. It follows that,
$$
\ln^{2}{1} + \ln^{2}{2} + \dots + \ln^{2}{n}
\leq \ln^{2}{n} + \ln^{2}{n} + \dots + \ln^{2}{n} \\
= n \ln^{2}{n} \\
\therefore S(n) \in O(n \ln^{2}{n})
$$
Now, we intend to show that $S(n) \in \Omega(n\ln^{2}{n})$. Let $m=\lfloor n/2 \rfloor$. Then,
$$
S(n) = \sum_{i=1}^{n}\ln^{2}{i} = \sum_{i=1}^{m}\ln^{2}{i} + \sum_{i=m+1}^{n}\ln^{2}{i} \\
\geq \sum_{i=m+1}^{n}\ln^{2}{i} = \ln^{2}(m+1) + \ln^{2}(m+2) + \dots + \ln^{2}{n} \\
\geq \ln^{2}(m+1)  + \ln^{2}(m+1)  + \dots + \ln^{2}(m+1) \\
= (n-m)\ln^{2}(m+1) \\
\geq \frac{n}{2}\ln^{2}\left(\frac{n}{2}\right) \\
= \frac{n}{2}\left( \ln{n} - \ln{2}\right)^{2}
$$

For sufficiently large $n$,
$$
\frac{n}{2}\left( \ln{n} - \ln{2}\right)^{2} \geq \frac{n}{2}\left( \ln{n} - \frac{\ln{n}}{2}\right)^{2} \\
= \frac{n}{2}\left( \frac{\ln{n}}{2}\right)^{2} \\
= \frac{n}{8}(\ln{n})^2 \\
= \frac{1}{8}(n\ln^{2}{n})\\
\therefore S(n) \in \Omega(n\ln^{2}{n})
$$

Since $S(n) \in O(n \ln^{2}{n})$ and $S(n) \in \Omega(n\ln^{2}{n})$, then $S(n) \in \Theta(n\ln^{2}n)$.