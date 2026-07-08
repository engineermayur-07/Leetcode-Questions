# [136. Single Number](https://leetcode.com/problems/single-number/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given a **non-empty** array of integers `nums`, every element appears **twice** except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

### Examples

**Example 1:**
* **Input:** `nums = [2,2,1]`
* **Output:** `1`

**Example 2:**
* **Input:** `nums = [4,1,2,1,2]`
* **Output:** `4`

**Example 3:**
* **Input:** `nums = [1]`
* **Output:** `1`

### Constraints
* `1 <= nums.length <= 3 * 10^4`
* `-3 * 10^4 <= nums[i] <= 3 * 10^4`
* Each element in the array appears twice except for one element which appears only once.

---

## Approach & Intuition

> **Note:** Although grouped alongside binary search practice, this problem is solved using a **bitwise XOR** trick rather than a binary search, since the array is unsorted and the property being exploited is bitwise cancellation, not a sorted/monotonic search space.

The approach relies on two core properties of the XOR (`^`) operator:
* `x ^ x = 0` — any number XORed with itself cancels out to zero.
* `x ^ 0 = x` — any number XORed with zero remains unchanged.
* XOR is both **commutative** and **associative**, so the order of operations doesn't matter.

Given these properties, if we XOR every element in the array together, every number that appears **twice** will cancel itself out (`x ^ x = 0`), leaving only the number that appears **once** as the final result:

1. Initialize `ans = 0`.
2. Iterate through every element in `nums`, XORing it into `ans`: `ans = ans ^ nums[i]`.
3. By the end of the loop, all paired duplicates have cancelled to zero, and `ans` holds exactly the single unpaired number.
4. Return `ans`.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — The algorithm makes a single pass through `nums`, performing one XOR operation per element.
* **Space Complexity:** $O(1)$ — Only a single accumulator variable (`ans`) is used, satisfying the constant-space requirement.

---

## Code Walkthrough

The solution is a minimal, single-pass XOR accumulation:
* `ans` is initialized to `0`, acting as the running XOR accumulator.
* `n` stores the size of `nums` for the loop bound.
* The `for` loop iterates through each index `i`, updating `ans = ans ^ nums[i]` at every step.
* Since duplicate values cancel each other out via XOR (`x ^ x = 0`) regardless of order, only the unpaired value survives in `ans` by the time the loop finishes.
* The final `ans` is returned directly as the single number.