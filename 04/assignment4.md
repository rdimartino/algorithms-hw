# Assignment 4 - CS 4071 - Spring 2018

*Due: 2018-02-19*  
*Group #13: Robert DiMartino (dimartrt), Hayden Schiff (schiffha), Jeremiah Leak (leakjz)*

<div style="page-break-after: always;"></div>

## 1. Exercise 6.5

**Problem**: Solve the following instance of the knapsack problem for capacity C=30.

|   $i$   |  0   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |
| :-----: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
| $v_{i}$ |  60  |  50  |  40  |  30  |  20  |  10  |  5   |  1   |
| $w_{i}$ |  30  | 100  |  10  |  10  |  8   |  8   |  1   |  1   |

To solve this knapsack problem, we want to greedily select objects of decreasing densities, i.e. the ratio of value to weight, $v_{i}/w_{i}$, until the knapsack is full. So first we compute the densities for each object.

|      $i$      |  0   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |
| :-----------: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
| $d_{i} = v_{i}/w_{i}$ |  2   | 0.5  |  4   |  3   | 2.5  | 1.25 |  5   |  1   |

Then we repeatedly select available objects with the next highest density until the knapsack is full (or we run out of items).

0. Starting capacity: 30
1. Select: 6 ($d=5, w=1$), fraction: 1, remaining capacity: 29
2. Select: 2 ($d=4, w=10$), fraction: 1, remaining capacity: 19
3. Select: 3 ($d=3, w=10$), fraction: 1, remaining capacity: 9
4. Select: 4 ($d=2.5, w=8$), fraction: 1, remaining capacity: 1
5. Select: 0 ($d=2, w=30$), fraction: 1/30, remaining capacity: 0

The fractions, $f_{i}$, of each item that yield the optimal value for the knapsack are provided in the table below.

|      $i$      |  0   |  1   |  2   |  3   |  4   |  5   |  6   |  7   | Total |
| :-----------: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
| $f_{i}$ |  1/30  | 0  |  1   |  1   | 1  | 0 |  1   |  0   | |
| $f_{i}v_{i}$ | 2 | 0 | 40 | 30 | 20 | 0 | 5 | 0 | 97 |
| $f_{i}w_{i}$ | 1 | 0 | 10 | 10 | 8 | 0 | 1 | 0 | 30 |

## 2. Exercise 6.9

**Problem**: Trace the action of _HuffmanCode_ for the letters _a, b, c, d, e, f, g, h_ occuring with frequencies 10, 7, 3, 5, 9, 2, 3, 2.



0. Initial forest

    ```mermaid
    graph TD
        %% unallocated
        a:10
        b:7
        c:3
        d:5
        e:9
        f:2
        g:3
        h:2
    ```

1. Stage 1

	```mermaid
    graph TD
        %% stage 1
        n1((4))---|0|f:2
        n1---|1|h:2

        %% unallocated
        a:10
        b:7
        c:3
        d:5
        e:9
        f:2
        g:3
  ```

2. Stage 2

    ```mermaid
    graph TD
        %% stage 1
        n1((4))---|0|f:2
        n1---|1|h:2
        %% stage 2
        n2((6))---|0|c:3
        n2---|1|g:3

        %% unallocated
        a:10
        b:7
        d:5
        e:9
    ```

3. Stage 3

    ```mermaid
    graph TD
        %% stage 1
        n1((4))---|0|f:2
        n1---|1|h:2
        %% stage 3
        n3((9))---|0|n1
        n3---|1|d:5

        %% stage 2
        n2((6))---|0|c:3
        n2---|1|g:3

        %% unallocated
        a:10
        b:7
        e:9
    ```

4. Stage 4

    ```mermaid
    graph TD
        %% stage 1
        n1((4))---|0|f:2
        n1---|1|h:2
        %% stage 3
        n3((9))---|0|n1
        n3---|1|d:5

        %% stage 2
        n2((6))---|0|c:3
        n2---|1|g:3
        %% stage 4
        n4((13))---|0|n2
        n4---|1|b:7

        %% unallocated
        a:10
        e:9
    ```

5. Stage 5

    ```mermaid
    graph TD

        %% stage 1
        n1((4))---|0|f:2
        n1---|1|h:2
        %% stage 3
        n3((9))---|0|n1
        n3---|1|d:5
        %% stage 5
        n5((18))---|0|n3
        n5---|1|e:10

        %% stage 2
        n2((6))---|0|c:3
        n2---|1|g:3
        %% stage 4
        n4((13))---|0|n2
        n4---|1|b:7

        %% unallocated
        a:10
    ```

6. Stage 6

    ```mermaid
    graph TD
        %% stage 1
        n1((4))---|0|f:2
        n1---|1|h:2
        %% stage 3
        n3((9))---|0|n1
        n3---|1|d:5
        %% stage 5
        n5((18))---|0|n3
        n5---|1|e:10
        %% stage 6
        n6((23))---|0|n4
        n6---|1|a:10

        %% stage 2
        n2((6))---|0|c:3
        n2---|1|g:3
        %% stage 4
        n4((13))---|0|n2
        n4---|1|b:7
    ```

7. Stage 7: Huffman Tree

    ```mermaid
    graph TD
        %% stage 1
        n1((4))---|0|f:2
        n1---|1|h:2
        %% stage 3
        n3((9))---|0|n1
        n3---|1|d:5
        %% stage 5
        n5((18))---|0|n3
        n5---|1|e:10
        %% stage 6
        n6((23))---|0|n4
        n6---|1|a:10
        %% stage 2
        n2((6))---|0|c:3
        n2---|1|g:3
        %% stage 4
        n4((13))---|0|n2
        n4---|1|b:7
        %% stage 7
        n7((41))---|0|n5
        n7---|1|n6
    ```

| letter | frequency | encoding |
| :--: | :--: | :--: |
| _a_ | 10 |`11`|
| _b_ | 7  |`101`|
| _c_ | 3  |`1000`|
| _d_ | 5  |`001`|
| _e_ | 9  |`01`|
| _f_ | 2  |`0000`|
| _g_ | 3  |`1001`|
| _h_ | 2  |`0001`|

## 3. Exercise 6.10

**Problem**: Given the Huffman Code Tree in Figure 6.6, decode the string `100111100001101111001`

> **Figure 6.6**
> | letter | frequency | encoding |
> | :--: | :--: | :--: |
> | _a_ | 9 |`01`|
> | _b_ | 8  |`00`|
> | _c_ | 5  |`101`|
> | _d_ | 3  |`1001`|
> | _e_ | 15  |`11`|
> | _f_ | 2  |`1000`|

We read binary characters from the encoded string one at a time. Because the Huffman Code is a prefix code, when the binary substring we've read matches one of the letter encodings from Figure 6.6 we can unambiguously determine which letter is decoded.

Reading the string from the front:

1. `1001` = _d_ 
2. `11` = _e_
3. `1000` = _f_
4. `01` = _a_
5. `101` = _c_
6. `11` = _e_
7. `1001` = _d_

Then `100111100001101111001` decoded is "defaced".