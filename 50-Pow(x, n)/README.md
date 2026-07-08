# [50. Pow(x, n)](https://leetcode.com/problems/powx-n/description/)

## Difficulty
**Medium**

---

## Problem Statement

Implement `pow(x, n)`, which calculates `x` raised to the power `n` (i.e., $x^n$).

### Examples

**Example 1:**
* **Input:** `x = 2.00000`, `n = 10`
* **Output:** `1024.00000`

**Example 2:**
* **Input:** `x = 2.10000`, `n = 3`
* **Output:** `9.26100`

**Example 3:**
* **Input:** `x = 2.00000`, `n = -2`
* **Output:** `0.25000`
* **Explanation:** $2^{-2} = \frac{1}{2^2} = \frac{1}{4} = 0.25$

### Constraints
* `-100.0 < x < 100.0`
* `-2^31 <= n <= 2^31 - 1`
* Either `x` is not zero or `n > 0`.
* `-10^4 <= x^n <= 10^4`

---

## Approach & Intuition

The naive way to compute $x^n$ is to multiply `x` by itself `n` times. However, this takes $O(n)$ time, which will result in a Time Limit Exceeded (TLE) error given that `n` can be as large as $2^{31} - 1$. 

Instead, this solution utilizes the **Binary Exponentiation** algorithm (also known as Exponentiation by Squaring), which optimizes the process to $O(\log n)$ by exploiting the parity of the exponent:

### Handling Negative Exponents
If $n$ is negative, $x^n$ is mathematically equivalent to $(\frac{1}{x})^{-n}$. To handle this:
1. We cast `n` to a `long long` variable `N`. This is critical because if `n` is `INT_MIN` ($-2^{31}$), changing its sign to positive would overflow the standard 32-bit signed integer range ($2^{31}$ exceeds `INT_MAX`).
2. We convert `N` to its absolute positive equivalent (`N = -N`) and invert the base (`x = 1.0 / x`).

### Iterative Binary Exponentiation
We can break down the power calculation by reducing the exponent by half at each step:
1. If the current exponent `N` is odd (`N % 2 == 1`), we multiply our accumulated `ans` by the current base `x`. This accounts for the extra single factor of `x`.
2. We then square the base (`x = x * x`) and divide the exponent by 2 (`N = N / 2`), matching the mathematical property: $x^N = (x^2)^{N/2}$ for even numbers.
3. This process repeats inside a `while (N > 0)` loop until the exponent is exhausted.

---

## Complexity Analysis

### Binary Exponentiation
* **Time Complexity:** $O(\log n)$ — In each iteration of the loop, the exponent `N` is divided by 2. Thus, the loop runs at most $\approx \log_2(n)$ times.
* **Space Complexity:** $O(1)$ — The algorithm uses a few primitive variables (`N`, `ans`) and processes the result iteratively without recursion stacks.

---

## Code Walkthrough

* **`long long N = n;`**: Prevents integer overflow when handling `n = -2147483648`.
* **`if (N < 0) { ... }`**: Transforms negative exponent problems into positive exponent problems by replacing `x` with `1/x`.
* **`while (N > 0)`**: Iterates through the binary representation bits of the exponent.
* **`if (N % 2 == 1)`**: Checks if the least significant bit of `N` is `1` (odd exponent). If so, it factors the current base value into `ans`.
* **`x = x * x;` and `N = N / 2;`**: Advances to the next power of the base and shifts the exponent down by half.