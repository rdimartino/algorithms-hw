# Assignment 1 - CS 4071 - Spring 2018

_Due: 2018-01-26_

## 1. Exercise 1.1

1. $x^{123}$

  $123 = 1111011_{2}$

  $x \rightarrow x \times (x)^{2} = x^{3} \rightarrow x \times (x^{3})^{2} = x^{7} \rightarrow x \times (x^{7})^{2}$

  $= x^{15} \rightarrow (x^{15})^{2} = x^{30} \rightarrow x \times (x^{30})^{2} = x^{61} \rightarrow x \times (x^{61})^{2} = x^{123}$

2. $x^{64}$

  $64 = 1000000_{2}$ 

  $x \rightarrow (x)^{2} = x^{2} \rightarrow (x^{2})^{2} = x^{4} \rightarrow (x^{4})^{2}$

  $= x^{8} \rightarrow (x^{8})^{2} = x^{16} \rightarrow (x^{16})^{2} = x^{32} \rightarrow (x^{32})^{2} = x^{64}$

3. $x^{65}$

  $65 = 1000001_{2}$

  $x \rightarrow (x)^{2} = x^{2} \rightarrow (x^{2})^{2} = x^{4} \rightarrow (x^{4})^{2}$

  $= x^{8} \rightarrow (x^{8})^{2} = x^{16} \rightarrow (x^{16})^{2} = x^{32} \rightarrow x \times (x^{32})^{2} = x^{65}$

4. $x^{711}$

  $711 = 1011000111_{2}$

  $x \rightarrow (x)^{2} = x^{2} \rightarrow x \times (x^{2})^{2} = x^{5} \rightarrow x \times (x^{5})^{2} = x^{11} \rightarrow (x^{11})^{2} = x^{22} \rightarrow (x^{22})^{2}$

  $= x^{44} \rightarrow (x^{44})^{2} = x^{88} \rightarrow x \times (x^{88})^{2} = x^{177} \rightarrow x \times (x^{177})^{2} = x^{355} \rightarrow x \times (x^{355})^{2} = x^{711}$


## 2. Exercise 1.7

1. NaiveGCD(24, 108) 
  = gcd(24, 84) = gcd(24, 60) = gcd(24, 36)
  = gcd(24, 12) = gcd(12,12) = 12

2. NaiveGCD(23, 108) 
  = gcd(23, 85) = gcd(23, 62) = gcd(23, 39)
  = gcd(23, 16) = gcd(7, 16) = gcd(7, 9) = gcd(7, 2)
  = gcd(5, 2) = gcd(3, 2) = gcd(1, 2) = gcd(1, 1) = 1

3. NaiveGCD(89, 144)
  = gcd(89, 55) = gcd(34, 55) = gcd(34, 21)
  = gcd(13, 21) = gcd(13, 8) = gcd(5, 8) = gcd(5, 3)
  = gcd(2, 3) = gcd(2, 1) = gcd(1, 1) = 1

4. NaiveGCD(1953, 1937)
  = gcd(16, 1937) = gcd(16, 1921) = gcd(16, 1905)
  = gcd(16, 1889) = … = gcd(16, 49) = gcd(16, 33) = gcd(16, 17) = gcd(16, 1)
  = gcd(15, 1) = gcd(14, 1) = … = gcd(3, 1) = gcd(2, 1) = gcd(1, 1) = 1

## 3. Exercise 1.9

lcm(_a_, _b_) = _a_ * _b_ / gcd(_a_, _b_)

## 4. Exercise 1.17

Horner's rule for 5th degree polynomial:

$((((a_{5} \times x + a_{4}) \times x + a_{3}) \times x + a_{2}) \times x + a_{1}) \times x + a_{0}$

For the polynomial $7x^{5} - 3x^{3} + 2x^{2} + x - 5$ the coefficients are:

$a_{5} = 7, a_{4} = 0, a_{3} = -3, a_{2} = 2, a_{1} = 1, a_0 = -5$

So Horner's rule is:

$((((7 \times x + 0) \times x + -3) \times x + 2) \times x + 1) \times x + -5$

For $x = 7$:

$((((7 \times 7 + 0) \times 7 + -3) \times 7 + 2) \times 7 + 1) \times 7 + -5$

$=((((49) \times 7 + -3) \times 7 + 2) \times 7 + 1) \times 7 + -5$

$=(((340) \times 7 + 2) \times 7 + 1) \times 7 + -5$

$=((2,382) \times 7 + 1) \times 7 + -5$

$=(16,675) \times 7 + -5$

$=116,720$

## 8. Exercise 1.19

**function** `ModifiedHornerEval(a[0:n], v)`

**Input:** `a[0:n]` (an array of real numbers), `v` (a real number)

**Output:** the values of polynomial $P(x)=a_{n}x^{n}+a_{n-1}x^{n-1}+\cdots+a_{1}x+a_{0}$ at $x = v$ and $x = -v$

```
v2 = v*v
if n is even:
	EvenSum <= a[n]
	OddSum <= 0
else:
	EvenSum <= 0
	OddSum <= a[n]
endif
for i <= n-1 downto 0 do:
	if i is even:
		EvenSum <= EvenSum * v2 + a[i]
	else:
		OddSum <= OddSum * v2 + a[i]
	endif
endfor
OddSum = OddSum*v
return(P(v) is EvenSum+OddSum and P(-v) is EvenSum-OddSum)
```

