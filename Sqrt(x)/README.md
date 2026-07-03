# [69. Sqrt(x)](https://leetcode.com/problems/sqrtx/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given a non-negative integer `x`, return *the square root of `x` rounded down to the nearest integer*. The returned integer should be **non-negative** as well.

You **must not use** any built-in exponent function or operator (e.g., `pow(x, 0.5)` or `x ** 0.5`).

### Examples

**Example 1:**
* **Input:** `x = 4`
* **Output:** `2`
* **Explanation:** The square root of 4 is 2, so we return 2.

**Example 2:**
* **Input:** `x = 8`
* **Output:** `2`
* **Explanation:** The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

### Constraints
* `0 <= x <= 2^31 - 1`

---

## Approach & Intuition

Two solutions are included here — a brute-force scan and a much faster numerical method.

### Approach 1: Linear Scan (Brute Force)

The core idea is that `mySqrt(x)` is just the largest integer `i` such that `i * i <= x`. Instead of squaring directly (which risks overflow for large `i`), the code compares using division:

1. Iterate `i` from `0` up to `x/2 + 1` (the square root of any `x >= 4` can never exceed `x/2`, so this bounds the loop safely).
2. At each step, check `(i+1) > x/(i+1)`. If true, it means `(i+1)*(i+1) > x`, so `i` itself is the floor of the square root — return `i`.
3. Also check the exact-match edge case: if `(i+1) == x/(i+1)`, then `i+1` divides evenly and is itself a perfect square root — return `i+1`.
4. If the loop completes without returning (shouldn't happen for valid input), return `-1` as a fallback.

This works but scans linearly through roughly `x/2` values in the worst case.

### Approach 2: Newton's Method (Optimized)

Rather than searching value-by-value, this approach uses **Newton's method for root-finding**, which converges much faster (quadratically) by repeatedly refining a guess:

1. Start with an initial guess `ans = x`.
2. While the current guess overshoots (`ans * ans > x`), refine it using the Newton's method update rule: `ans = (ans + x/ans) / 2`. This formula averages the current guess with `x` divided by the guess, pulling `ans` closer to the true square root on each iteration.
3. Once `ans * ans <= x`, the loop stops — `ans` now holds the floor of the square root.
4. `long long` is used for `ans` to safely handle intermediate multiplication (`ans * ans`) without overflowing, since `x` can be as large as `2^31 - 1`.

---

## Complexity Analysis

### Approach 1: Linear Scan
* **Time Complexity:** $O(\sqrt{x})$ — The loop runs up to roughly `x/2` times in the worst case, but since it stops once `i` reaches the actual square root, the effective number of useful iterations is on the order of $\sqrt{x}$.
* **Space Complexity:** $O(1)$ — Only a couple of integer variables are used.

### Approach 2: Newton's Method
* **Time Complexity:** $O(\log x)$ — Newton's method converges quadratically, meaning the number of correct digits roughly doubles each iteration, so it reaches the answer in a small number of steps relative to brute force.
* **Space Complexity:** $O(1)$ — Only a single `long long` accumulator is used.

---

## Code Walkthrough

**Approach 1 (`mySqrt` — linear scan):**
* The `for` loop bounds `i` between `0` and `x/2 + 1`.
* `(i+1) > x/(i+1)` is a division-based rearrangement of `(i+1)*(i+1) > x`, avoiding overflow for large `x`.
* The first condition catches the case where `i` is the correct floor value; the second condition catches the case where `i+1` is an exact square root.
* A fallback `-1` is returned if no condition is hit (defensive, not expected to trigger).

**Approach 2 (`mySqrt` — Newton's method):**
* `ans` is declared as `long long` and initialized to `x` itself, an intentionally loose starting guess.
* The `while (ans * ans > x)` loop keeps refining `ans` using the Newton's method formula `(ans + x/ans) / 2` until the guess no longer overshoots.
* The final `ans` is cast back to `int` before returning, since it's guaranteed to fit within valid `int` range once converged.