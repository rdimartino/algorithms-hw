# Assignment 1 - CS 4071 - Spring 2018

*Due: 2018-01-29*
*Group #13: Robert DiMartino (dimartrt), Hayden Schiff (schiffha), Jeremiah Leak (leakjz)*

<div style="page-break-after: always;"></div>

## 1. Exercise 1.1

**Problem**: Trace the action of the left-to-right binary method to compute:

### a. $x^{123}$

$$
123 = 2^{6}+2^{5}+2^{4}+2^{3}+2^{1}+2^{0}\\
123 = 1111011_{2}\\
x \rightarrow x \times (x)^{2} = x^{3} \rightarrow x \times (x^{3})^{2} = x^{7} \rightarrow x \times (x^{7})^{2} \\
= x^{15} \rightarrow (x^{15})^{2} = x^{30} \rightarrow x \times (x^{30})^{2} = x^{61} \rightarrow x \times (x^{61})^{2} = x^{123}
$$

### b. $x^{64}$

$$
64 = 2^{6}\\
64 = 1000000_{2}\\
x \rightarrow (x)^{2} = x^{2} \rightarrow (x^{2})^{2} = x^{4} \rightarrow (x^{4})^{2}\\
= x^{8} \rightarrow (x^{8})^{2} = x^{16} \rightarrow (x^{16})^{2} = x^{32} \rightarrow (x^{32})^{2} = x^{64}
$$

### c. $x^{65}$

$$
65 = 2^{6}+2^{0}\\
65 = 1000001_{2}\\
x \rightarrow (x)^{2} = x^{2} \rightarrow (x^{2})^{2} = x^{4} \rightarrow (x^{4})^{2}\\
= x^{8} \rightarrow (x^{8})^{2} = x^{16} \rightarrow (x^{16})^{2} = x^{32} \rightarrow x \times (x^{32})^{2} = x^{65}
$$

### d. $x^{711}$

$$
711 = 2^{9} + 2^{7}+2^{6}+2^{2}+2^{1}+2^{0}\\
711 = 1011000111_{2}\\
x \rightarrow (x)^{2} = x^{2} \rightarrow x \times (x^{2})^{2} = x^{5} \rightarrow x \times (x^{5})^{2} = x^{11} \rightarrow (x^{11})^{2} = x^{22} \rightarrow (x^{22})^{2}\\
= x^{44} \rightarrow (x^{44})^{2} = x^{88} \rightarrow x \times (x^{88})^{2} = x^{177} \rightarrow x \times (x^{177})^{2} = x^{355} \rightarrow x \times (x^{355})^{2} = x^{711}
$$

## 2-old. Exercise 1.7

**Problem**: Trace the action of the algorithm *GCD* for the following input pairs:

### a. (24, 108)

$$
\mathrm{NaiveGCD}(24, 108) \\
= \gcd(24, 84) = \gcd(24, 60) = \gcd(24, 36) \\
= \gcd(24, 12) = \gcd(12,12) = 12
$$

### b. (23, 108)

$$
\mathrm{NaiveGCD}(23, 108) \\
= \gcd(23, 85) = \gcd(23, 62) = \gcd(23, 39)\\
= \gcd(23, 16) = \gcd(7, 16) = \gcd(7, 9) = \gcd(7, 2)\\
= \gcd(5, 2) = \gcd(3, 2) = \gcd(1, 2) = \gcd(1, 1) = 1
$$

### c. (89, 144)

$$
\mathrm{NaiveGCD}(89, 144)\\
= \gcd(89, 55) = \gcd(34, 55) = \gcd(34, 21)\\
= \gcd(13, 21) = \gcd(13, 8) = \gcd(5, 8) = \gcd(5, 3)\\
= \gcd(2, 3) = \gcd(2, 1) = \gcd(1, 1) = 1
$$

### d. (1953, 1937)

$$
\mathrm{NaiveGCD}(1953, 1937)\\
= \gcd(16, 1937) = \gcd(16, 1921) = \gcd(16, 1905) = \gcd(16, 1889) \\
= \dots = \gcd(16, 49) = \gcd(16, 33) = \gcd(16, 17) = \gcd(16, 1)\\
= \gcd(15, 1) = \gcd(14, 1) = \dots = \gcd(3, 1) = \gcd(2, 1) = \gcd(1, 1) = 1
$$

## 2-new. Exercise 1.8

**Problem**: Trace the action of the algorithm *EuclidGCD* for the following input pairs:

### a. (24, 108)

$$
\mathrm{EuclidGCD}(24,108)\\
= \gcd(108, 24) = \gcd(24,12) = \gcd(12, 0) = 12
$$

### b. (23, 108)

$$
\mathrm{EuclidGCD}(23,108) \\
= \gcd(108,23) = \gcd(23, 16) = \gcd(16,7)\\
= \gcd(7,2) = \gcd(2, 1) = \gcd(1, 0) = 1
$$

### c. (89, 144)

$$
\mathrm{EuclidGCD}(89,144) \\
= \gcd(144,89) = \gcd(89, 55) = \gcd(55, 34) = \gcd(34, 21) \\
= \gcd(21, 13) = \gcd(13, 8) = \gcd(8, 5) = \gcd(5, 3) \\
= \gcd(3, 2) = \gcd(2, 1) = \gcd(1, 0) = 1
$$

### d. (1953, 1937)

$$
\mathrm{EuclidGCD}(1953,1937) \\
= \gcd(1937, 16) = \gcd(16, 1) = \gcd(1, 0) = 1
$$

## 3. Exercise 1.9

**Problem**: Give a formula for $\mathrm{lcm}(a,b)$ in terms of $\gcd(a,b)$.

$n$ is a multiple of $x$ if there exists some integer $p$ such that $x \times p = n$. Let $m=\mathrm{lcm}(a,b)$. $m$ must contain all of the prime factors of both $a$ and $b$. Clearly, $a  b$ is a multiple of both $a$ and $b$ because $a \times b = ab = b \times a$ and $ab$ contains all of the prime factors of both $a$ and $b$. Is there a smaller common multiple? Yes! $ab$ is double-counting all of the prime factors that $a$ and $b$ share. The product of these shared factors is $\gcd(a,b)$.  We can divide those shared factors out of the product and see that this is still a common multiple of both $a$ and $b$ because:
$$
a \times \frac{b}{\gcd(a,b)} = \frac{ab}{\gcd(a,b)} = b \times \frac{a}{\gcd(a,b)}
$$

And $\gcd(a,b) \ge 1$ therefore $\frac{ab}{\gcd(a,b)} \le ab$. So we arrive at our formula for the $\mathrm{lcm}(a,b)$:

 $\mathrm{lcm}(a, b) = a \times b \div \gcd(a, b)$

## 4. Exercise 1.17

**Problem**: Trace the action of Horner's rule for the polynomial $7x^5-3x^3+2x^2+x-5$.

Horner's rule for 5th degree polynomial:

$((((a_{5} \times x + a_{4}) \times x + a_{3}) \times x + a_{2}) \times x + a_{1}) \times x + a_{0}$

For the polynomial $7x^{5} - 3x^{3} + 2x^{2} + x - 5$ the coefficients are:

$a_{5} = 7,\quad a_{4} = 0,\quad a_{3} = -3,\quad a_{2} = 2,\quad a_{1} = 1,\quad a_0 = -5$

So Horner's rule is:

$((((7 \times x + 0) \times x + -3) \times x + 2) \times x + 1) \times x + -5$

For $x = 7$:
$$
((((7 \times 7 + 0) \times 7 + -3) \times 7 + 2) \times 7 + 1) \times 7 + -5\\
((((49) \times 7 + -3) \times 7 + 2) \times 7 + 1) \times 7 + -5\\
(((340) \times 7 + 2) \times 7 + 1) \times 7 + -5\\
((2,382) \times 7 + 1) \times 7 + -5\\
(16,675) \times 7 + -5\\
116,720
$$



## 5. Exercise 2.13

**Problem**: Design an algorithm that tests whether or not two input lists of size $n$ have at least one element in common. Give formulas for $B(n)$ and $W(n)$ for your algorithm.

**function** $$ \mathrm{CheckShareElements}(a[0:n-1], b[0:n-1])$$  
**Input**: $a[0:n-1], b[0:n-1]$ (two arrays of real numbers)  
**Output**: `true` if $a$ and $b$ have at least 1 element in common, else `false`

```
for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		if (i == j) return true
return false
```

If $a[0] = b[0]$, then it'll return true after the very first comparison. Thus, $B(n) = 1$.

If $a \cap b = \emptyset$ (or if the only common element is the last element of $a$ and the last element of $b$), then it'll have to compare every element of $a$ to every element of $b$. Thus, $W(n) = n^2$.

## 6. Exercise 2.16

### Part a.

**Problem**: Write a procedure that finds both the largest and second-largest elements in a list $L[0:n-1]$ of size $n$.

**function** $\textrm{FindTwoLargest}(L[0:n-1])$  
**Input:** $L[0:n-1]$ (an array of real numbers)  
**Output**: $a$ and $b$ (the largest two numbers from $L$)

```
# start by assuming the first two elements are the largest
a = L[0]
b = L[1]
if (b > a) # make sure a is bigger than b
	temp = a
	a = b
	b = temp

# search the list for bigger numbers, and update a and b as needed
for (i = 2; i < n; i++)
	if (L[i] > a)
		b = a
		a = L[i]
	elif (L[i] > b)
		b = L[i]

return a, b
```

### Part b.

**Problem**: Determine $B(n)$ and $W(n)$ for the algorithm in a.

Our basic operation is comparisons. We do one comparison at the beginning, before the loop. Then on each iteration of the loop, we do one comparison if $L[i] > a$; if not, we end up doing two comparisons. Thus, our best case would be if the list sorted from smallest to largest (meaning $L[i] > a$ will be true on every iteration). Our worst case would any list where none of the other elements are larger than $L[0]$ or $L[1]$ (meaning $L[i] > a$ will be false on every iteration). Thus:

$B(n) = 1 + (n - 2) = n - 1$

$W(n) = 1 + 2(n - 2) = 2n - 3$

## 7. Exercise 2.30

### Part a.

**Problem**: Design a recursive version of *InsertionSort*.

**function** $\mathrm{recursiveInsertionSort}(a[0:n-1], k)$  
**Input:** $L[0:n-1]$ (an array of $n$ elements), $k$ (an index of list $L$)  
**Output:** $L[0:n-1]$ with elements $L[0:k]$ sorted in ascending order

```
# initial condition
# a list of one element is already sorted
if k==0:
	return
endif

# recursively call function to sort up to index k-1
recursiveInsertionSort(L[0:n-1], k-1);

insertElement ← L[k] # element to sort
i ← k-1
# shift all elements greater than the
# insertElement up one position in L
while i >= 0 and L[i] > insertElement:
	L[i+1] ← L[i]
	i ← i-1
endwhile
L[i] ← L[k]
```

### Part b.

**Problem**: Design a recursive linked list version of *InsertionSort*.

**function** $\mathrm{recDLLInsertionSort}(a[0:n-1], k)$  
**Input:** $head$ (a pointer to the head node of a doubly linked list), $tail$ (a pointer to a node in the doubly linked list pointed to by $head$)  
**Output:** A doubly linked list where the nodes from $head$ to $tail$ are sorted in ascending order

```
# initial condition
# a list of one node is already sorted
if head == tail:
	return
endif

# recursively call function to sort up to the
# node before tail
recursiveInsertionSort(head, tail.previous);

insertNode ← tail # node to sort

# set cursor and remove insertNode
cursor ← insertNode.previous
cursor.next ← insertNode.next
if tail.next is not null:
	tail.next.prev ← cursor
endif

while cursor is not null and cursor.data > insertNode.data:
	cursor ← cursor.previous
endwhile

# move insertNode into sorted position
if cursor is null: # insertNode is the smallest
	head.prev ← insertNode
	insertNode.next ← head
	insertNode.prev ← null
	head = insertNode
else:
	cursor.next.prev ← insertNode
	insertNode.next ← cursor.next
	insertNode.prev ← cursor
	cursor.next ← insertNode
endif
```



## 8. Exercise 1.19

**Problem**: Describe a modification of *HornerEval* that solves this particular evaulation problem using only $n+1$ multiplications and $n+1$ additions.

_TA Note: This solution was found before the hint was given in class._

If we modified the polynomial to just look at the even powers of $x$, i.e. $P_{even}(x) = a_{0} + a_{2}x^{2} + a_{4}x^{4} + \cdots$, we noticed that $P_{even}(x) = P_{even}(-x)$. This is because all even powers $x^{2k}$ an be re-written $(x^{2})^{k}$ and $(-x)^{2} =x^{2}$.

Similiary, for a polynomial of just the odd powers of $x$, i.e. $P_{odd}(x) = a_{1}x + a_{3}x^{3} + a_{5}x^{5} + \cdots$, we noticed that $P_{odd}(-x) = -P_{odd}(x)$. This is because for all odd powers
$$
(-x)^{2k+1} = (-x) \times (-x)^{2k}=(-x) \times (-x)^{2k}=-(x \times x^{2k})=-x^{2k+1}
$$

Using these two observations, we modified Horner's algorithm to keep track of two sums, one for the even powers of $x$ and one for the odd powers of $x$. The extra multiplication comes from keep track of $v^{2}$ and the extra addition comes from the return when we have to sum and difference the even and odd sums.

**function** $\mathrm{ModifiedHornerEval}(a[0:n], v)$  
**Input:** $a[0:n]$ (an array of real numbers), $v$ (a real number)  
**Output:** the values of polynomial $P(x)=a_{n}x^{n}+a_{n-1}x^{n-1}+\cdots+a_{1}x+a_{0}$ at $x = v$ and $x = -v$

```
vSquared ← v*v
if n is even:
	EvenSum ← a[n]
	OddSum ← 0
else:
	EvenSum ← 0
	OddSum ← a[n]
endif
for i ← n-1 downto 0 do:
	if i is even:
		EvenSum ← EvenSum * vSquared + a[i]
	else:
		OddSum ← OddSum * vSquared + a[i]
	endif
endfor
OddSum ← OddSum*v
return(P(v) is EvenSum+OddSum and P(-v) is EvenSum-OddSum)
```

