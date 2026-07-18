# [1979. Find Greatest Common Divisor of Array](https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given an integer array `nums`, return *the **greatest common divisor** of the smallest number and largest number in `nums`*.

The **greatest common divisor** of two numbers is the largest positive integer that evenly divides both numbers.

### Examples

**Example 1:**
* **Input:** `nums = [2,5,6,9,10]`
* **Output:** `2`
* **Explanation:** The smallest number in `nums` is 2. The largest number in `nums` is 10. The greatest common divisor of 2 and 10 is 2.

**Example 2:**
* **Input:** `nums = [7,5,6,8,3]`
* **Output:** `1`
* **Explanation:** The smallest number in `nums` is 3. The largest number in `nums` is 8. The greatest common divisor of 3 and 8 is 1.

**Example 3:**
* **Input:** `nums = [3,3]`
* **Output:** `3`
* **Explanation:** The smallest number in `nums` is 3. The largest number in `nums` is 3. The greatest common divisor of 3 and 3 is 3.

### Constraints
* `2 <= nums.length <= 1000`
* `1 <= nums[i] <= 1000`

---

## Approach & Intuition

The problem boils down to two independent steps: **find the min and max** of the array, then **compute their GCD**. Two solutions are included here — one that implements the GCD calculation manually using the Euclidean algorithm, and one that relies on C++'s built-in `__gcd()` function.

### Approach 1: Manual Euclidean Algorithm

1. Scan through `nums` once, tracking `large` (initialized to `0`) and `small` (initialized to `10001`, safely above the maximum possible value per constraints) — updating each whenever a bigger or smaller number is found.
2. Apply the **Euclidean algorithm** to compute `gcd(large, small)` manually:
   * Set `remainder = small` to kick off the loop.
   * While `remainder > 0`:
     * Save the current `remainder` into `small` (this becomes the new "smaller" value for the next iteration).
     * Compute the new `remainder` as `large % remainder` (the classic Euclidean step: the GCD of two numbers equals the GCD of the smaller number and the remainder of dividing the larger by the smaller).
     * Update `large = small`, shifting the previous `small` into the "larger" role for the next iteration.
   * The loop terminates once `remainder` reaches `0`, at which point `small` holds the final GCD.
3. Return `small`.

This is a direct, iterative implementation of the Euclidean algorithm: repeatedly replacing `(large, small)` with `(small, large % small)` until the remainder hits zero — at which point the non-zero value left over is the GCD.

### Approach 2: Built-in `__gcd()`

1. Perform the same min/max scan as above.
2. Simply call C++'s built-in `__gcd(large, small)` function, which internally implements the same Euclidean algorithm, and return the result directly.

---

## Complexity Analysis

### Both Approaches
* **Time Complexity:** $O(n + \log(\min(large, small)))$ — Finding the min and max takes $O(n)$ for a single pass through `nums`. The Euclidean algorithm (whether manual or via `__gcd()`) runs in $O(\log(\min(large, small)))$, since each step roughly reduces the numbers by a factor related to the golden ratio.
* **Space Complexity:** $O(1)$ — Only a fixed number of integer variables are used in either approach.

---

## Code Walkthrough

**Approach 1 (`findGCD` — manual Euclidean algorithm):**
* The `for (int num : nums)` loop updates `large` and `small` to track the maximum and minimum values in the array.
* `remainder` is initialized to `small` before the `while (remainder > 0)` loop begins.
* Inside the loop, `small = remainder` captures the current remainder as the new candidate GCD; `remainder = large % remainder` computes the next remainder using the Euclidean step; and `large = small` shifts values forward for the next iteration.
* Once `remainder` reaches `0`, the loop exits, and `small` — now holding the final non-zero remainder from the last valid step — is returned as the GCD.

**Approach 2 (`findGCD` — built-in `__gcd`):**
* The same `for` loop determines `large` and `small`.
* `__gcd(large, small)` is called directly to compute and return the greatest common divisor, letting the standard library handle the Euclidean algorithm internally.