# [268. Missing Number](https://leetcode.com/problems/missing-number/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return *the only number in the range that is missing from the array*.

### Examples

**Example 1:**
* **Input:** `nums = [3,0,1]`
* **Output:** `2`
* **Explanation:** `n = 3` since there are 3 numbers, so all numbers are in the range `[0,3]`. `2` is the missing number in the range since it does not appear in `nums`.

**Example 2:**
* **Input:** `nums = [0,1]`
* **Output:** `2`
* **Explanation:** `n = 2` since there are 2 numbers, so all numbers are in the range `[0,2]`. `2` is the missing number in the range since it does not appear in `nums`.

**Example 3:**
* **Input:** `nums = [9,6,4,2,3,5,7,0,1]`
* **Output:** `8`
* **Explanation:** `n = 9` since there are 9 numbers, so all numbers are in the range `[0,9]`. `8` is the missing number in the range since it does not appear in `nums`.

### Constraints
* `n == nums.length`
* `1 <= n <= 10^4`
* `0 <= nums[i] <= n`
* All the numbers of `nums` are **unique**.

---

## Approach & Intuition

> **Note:** Although this problem is commonly grouped with binary search practice sets, this solution uses a **math-based (sum difference) approach** rather than binary search, since the array is unsorted and searching for a boundary condition doesn't directly apply here.

The key insight is that if no number were missing, `nums` would contain every integer from `0` to `n` exactly once — and the sum of that complete sequence is a well-known closed-form value: $\frac{n(n+1)}{2}$ (the sum of the first `n` natural numbers, extended to include `0`).

1. Compute the **expected total**: `total_sum = n * (n+1) / 2`, representing what the sum *would* be if every number from `0` to `n` were present.
2. Iterate through the actual array `nums` and **subtract** each element from `total_sum`.
3. Whatever value remains in `total_sum` after all elements have been subtracted is exactly the one number from `[0, n]` that never appeared in the array — since every other number cancelled itself out.
4. Return `total_sum` as the missing number.

This works because subtracting every present number from the expected total leaves only the difference — i.e., the single number that was never subtracted out.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — The algorithm makes a single pass through `nums` to subtract each element from the running total.
* **Space Complexity:** $O(1)$ — Only a fixed number of integer variables (`n`, `total_sum`) are used; no extra arrays or structures are allocated.

---

## Code Walkthrough

The solution computes the missing number using a running difference rather than a search:
* `n` stores the size of `nums`, i.e., how many numbers are present out of the `n+1` possible values in `[0, n]`.
* `total_sum` is initialized to $\frac{n(n+1)}{2}$, the sum of all integers from `0` to `n` if none were missing.
* The `for` loop walks through every element in `nums`, subtracting each `nums[i]` from `total_sum`.
* After the loop, all present numbers have cancelled out of the expected total, leaving only the missing number behind in `total_sum`, which is returned directly.