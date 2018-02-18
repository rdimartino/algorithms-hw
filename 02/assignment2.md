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
