# [75. Sort Colors](https://leetcode.com/problems/sort-colors/description/)

## Difficulty
**Medium**

---

## Problem Statement

Given an array `nums` with `n` objects colored red, white, or blue, sort them **in-place** so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

### Examples

**Example 1:**
* **Input:** `nums = [2,0,2,1,1,0]`
* **Output:** `[0,0,1,1,2,2]`

**Example 2:**
* **Input:** `nums = [2,0,1]`
* **Output:** `[0,1,2]`

### Constraints
* `n == nums.length`
* `1 <= n <= 300`
* `nums[i]` is `0`, `1`, or `2`.

---

## Approach & Intuition

Two solutions are included here — a two-pass counting approach, and the optimal single-pass **Dutch National Flag** algorithm.

### Approach 1: Counting Sort (Two-Pass)

Since there are only three possible values (`0`, `1`, `2`), we don't need a comparison-based sort at all — we can simply **count** how many of each value exist, then overwrite the array in the correct order:

1. Make a first pass through `nums`, tallying up `count0`, `count1`, and `count2` — the number of `0`s, `1`s, and `2`s respectively.
2. Make a second pass, this time **writing** values back into `nums` based on the counts:
   * Fill indices `0` to `count0 - 1` with `0`.
   * Fill indices `count0` to `count0 + count1 - 1` with `1`.
   * Fill the remaining indices with `2`.

This works because once we know exactly how many of each color exist, their final sorted positions are fully determined — no comparisons are needed.

### Approach 2: Dutch National Flag Algorithm (One-Pass, Optimal)

Rather than counting first and writing second, this approach sorts the array in a **single pass** using three pointers that partition the array into four regions as it goes: `[0s | 1s | unprocessed | 2s]`.

1. Initialize `zero = 0` and `one = 0` (both marking the start of the unprocessed region) and `two = nums.size() - 1` (marking the end of the unprocessed region).
2. While `one <= two`, examine `nums[one]`:
   * **If `nums[one] == 0`:** it belongs in the "zeros" region. Swap it with `nums[zero]` (moving the zero into place), then advance **both** `zero` and `one` forward — `one` can safely advance too, since the element swapped into `nums[one]` from `nums[zero]` is guaranteed to be a `1` or already-processed `0`, never an unexamined `2`.
   * **If `nums[one] == 2`:** it belongs in the "twos" region at the end. Swap it with `nums[two]`, then decrement `two` — but **do not** advance `one`, since the newly swapped-in value at `nums[one]` (from the back) hasn't been examined yet.
   * **If `nums[one] == 1`:** it's already in the correct middle region — just advance `one`.
3. The loop terminates once `one` and `two` cross, at which point every element has been correctly partitioned into `0`s, `1`s, and `2`s in order.

---

## Complexity Analysis

### Approach 1: Counting Sort
* **Time Complexity:** $O(n)$ — Two linear passes over `nums`: one to count, one to overwrite.
* **Space Complexity:** $O(1)$ — Only three counter variables are used; the array is overwritten in place.

### Approach 2: Dutch National Flag
* **Time Complexity:** $O(n)$ — A single linear pass, since `one` always moves forward and `two` always moves backward, giving each element a bounded number of comparisons.
* **Space Complexity:** $O(1)$ — Only three pointer variables (`zero`, `one`, `two`) are used, with sorting done entirely via in-place swaps.

---

## Code Walkthrough

**Approach 1 (`sortColors` — counting sort):**
* The first `for` loop tallies `count0`, `count1`, and `count2` by checking each `nums[i]` against `0`, `1`, and `2`.
* The second block uses three separate `for` loops to overwrite `nums` in three contiguous chunks: first all `0`s (up to `count0`), then all `1`s (from `count0` to `count0 + count1`), then all `2`s (filling the rest).

**Approach 2 (`sortColors` — Dutch National Flag):**
* `zero` and `one` start at `0`; `two` starts at the last index of `nums`.
* The `while (one <= two)` loop examines `nums[one]` on each iteration:
  * `nums[one] == 0` triggers `swap(nums[zero], nums[one])` followed by incrementing **both** `zero` and `one`.
  * `nums[one] == 2` triggers `swap(nums[one], nums[two])` followed by decrementing only `two` (leaving `one` in place to re-examine the swapped-in value).
  * The implicit `else` case (`nums[one] == 1`) just increments `one`, since the value is already correctly positioned.
* Once `one` exceeds `two`, the array has been fully partitioned into sorted `0`s, `1`s, and `2`s, with no explicit return needed since sorting is done in place.