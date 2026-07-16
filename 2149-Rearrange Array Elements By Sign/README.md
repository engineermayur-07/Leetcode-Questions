# [2149. Rearrange Array Elements by Sign](https://leetcode.com/problems/rearrange-array-elements-by-sign/description/)

## Difficulty
**Medium**

---

## Problem Statement

You are given a **0-indexed** integer array `nums` of **even** length consisting of an **equal** number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:
1. Every consecutive pair of integers have **opposite** signs.
2. For all integers with the same sign, the **order** in which they were present in `nums` is preserved.
3. The rearranged array begins with a positive integer.

Return *the modified array after rearranging the elements to satisfy the mentioned conditions*.

### Examples

**Example 1:**
* **Input:** `nums = [3,1,-2,-5,2,-4]`
* **Output:** `[3,-2,1,-5,2,-4]`
* **Explanation:** The positive integers in nums are `[3,1,2]`. The negative integers are `[-2,-5,-4]`. The only possible way to rearrange them such that they satisfy all conditions is `[3,-2,1,-5,2,-4]`.

**Example 2:**
* **Input:** `nums = [-1,1]`
* **Output:** `[1,-1]`
* **Explanation:** `1` and `-1` are the only positive and negative integers in `nums`. So `nums` is rearranged to `[1,-1]`.

### Constraints
* `2 <= nums.length <= 2 * 10^5`
* `nums.length` is even.
* There of equal number of positive and negative integers.
* `-1` <= there are no zeros in `nums`. (i.e., `1 <= |nums[i]| <= 10^5`)

---

## Approach & Intuition

Since the array is guaranteed to have an **equal count** of positives and negatives, and their **relative order** must be preserved within each sign group, the problem reduces to: separate the positives and negatives (preserving order within each), then **interleave** them starting with a positive.

Two solutions are included here — one using two intermediate arrays, and a more optimized single-output-array version.

### Approach 1: Two Separate Arrays

1. Make a first pass through `nums`, pushing every non-negative number into a `positive` vector and every negative number into a `negative` vector — since we're appending in original scan order, relative order within each group is automatically preserved.
2. Make a second pass, this time writing back into `nums` two elements at a time (`i` and `i+1`): `nums[i]` gets the next positive number, and `nums[i+1]` gets the next negative number, both pulled using a shared `index` counter that advances once per pair.
3. Return the rearranged `nums`.

### Approach 2: Single Output Array with Two Write-Pointers (Optimized)

Instead of building two separate arrays and then merging them, this approach writes directly into the final output array using two independent pointers that both advance by `2` each time:

1. Initialize `positive = 0` (the next even index, for positive numbers) and `negative = 1` (the next odd index, for negative numbers), along with a result vector `ans` sized to match `nums`.
2. Iterate through `nums` once:
   * If the current number is non-negative, place it at `ans[positive]` and advance `positive` by `2`.
   * If it's negative, place it at `ans[negative]` and advance `negative` by `2`.
3. Return `ans`, which now has positives at all even indices and negatives at all odd indices, both in their original relative order.

This skips the intermediate separation step entirely — each number is written directly to its final destination in a single pass.

---

## Complexity Analysis

### Approach 1: Two Separate Arrays
* **Time Complexity:** $O(n)$ — One pass to separate positives/negatives, and one pass to interleave them back into `nums`.
* **Space Complexity:** $O(n)$ — The `positive` and `negative` vectors together hold all `n` elements.

### Approach 2: Single Output Array
* **Time Complexity:** $O(n)$ — A single pass through `nums`, with constant-time work per element.
* **Space Complexity:** $O(n)$ — The `ans` vector holds all `n` elements (required for the output regardless of approach).

---

## Code Walkthrough

**Approach 1 (`rearrangeArray` — two arrays):**
* The first `for` loop partitions `nums` into `positive` and `negative` vectors based on sign, preserving each element's original relative order within its group.
* The second `for` loop steps through `nums` two indices at a time (`i` and `i+1`), assigning `positive[index]` to the even position and `negative[index]` to the odd position, incrementing the shared `index` once per pair.
* The modified `nums` is returned directly.

**Approach 2 (`rearrangeArray` — single pass, dual pointers):**
* `positive` and `negative` are initialized to `0` and `1` respectively — the first even and odd indices — and `ans` is pre-sized to hold `nums.size()` elements.
* The range-based `for (int i : nums)` loop checks the sign of each element: non-negative values are written to `ans[positive]` (with `positive` then incremented by `2`), and negative values are written to `ans[negative]` (with `negative` incremented by `2`).
* Since both pointers only ever move to their respective parity's next slot, the final `ans` naturally alternates between positive and negative values, starting with a positive at index `0`.
* The fully populated `ans` is returned.