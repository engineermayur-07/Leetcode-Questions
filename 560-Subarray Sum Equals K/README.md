# [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/description/)

## Difficulty
**Medium**

---

## Problem Statement

Given an array of integers `nums` and an integer `k`, return *the total number of subarrays whose sum equals to `k`*.

A subarray is a **contiguous** non-empty sequence of elements within an array.

### Examples

**Example 1:**
* **Input:** `nums = [1,1,1]`, `k = 2`
* **Output:** `2`

**Example 2:**
* **Input:** `nums = [1,2,3]`, `k = 3`
* **Output:** `2`

### Constraints
* `1 <= nums.length <= 2 * 10^4`
* `-1000 <= nums[i] <= 1000`
* `-10^7 <= k <= 10^7`

---

## Approach & Intuition

This solution uses the **brute-force** approach of checking every possible contiguous subarray directly, by fixing a starting index and extending the ending index outward while accumulating a running sum.

1. Loop over every possible **starting index** `i` from `0` to `n-1`, resetting `sum = 0` at the start of each new starting point.
2. For each starting index `i`, loop over every possible **ending index** `j` from `i` to `n-1`:
   * Extend the current subarray by adding `nums[j]` into the running `sum` — this incrementally builds the sum of the subarray `nums[i..j]` without needing to re-sum from scratch each time.
   * If `sum == k` at any point, the subarray `nums[i..j]` is a valid match — increment `count`.
3. After all `(i, j)` pairs have been checked, `count` holds the total number of subarrays summing to `k`.

This directly enumerates every possible subarray (there are $O(n^2)$ of them) and checks its sum, using the inner loop's running total to avoid the extra $O(n)$ cost of re-summing each subarray from scratch — but it is still fundamentally an exhaustive check of all subarrays, rather than the optimal prefix-sum + hash map approach (which reduces this problem to $O(n)$).

---

## Complexity Analysis

* **Time Complexity:** $O(n^2)$ — The nested loops examine every possible pair of `(start, end)` indices, giving roughly $\frac{n(n+1)}{2}$ subarrays checked, which simplifies to $O(n^2)$.
* **Space Complexity:** $O(1)$ — Only a couple of integer variables (`sum`, `count`) are used; no auxiliary arrays or hash maps are created.

---

## Code Walkthrough

The solution directly enumerates all subarrays using nested loops:
* `n` stores the array length, and `count` accumulates the total number of valid subarrays found.
* The outer `for` loop fixes `i`, the starting index of the current subarray, and resets `sum = 0` for each new start.
* The inner `for` loop fixes `j`, the ending index, starting from `i` and extending rightward — `sum += nums[j]` incrementally builds up the sum of `nums[i..j]` as `j` grows.
* The `if (sum == k)` check inside the inner loop increments `count` every time the running subarray sum matches the target `k`.
* Once both loops complete, `count` — the total number of matching subarrays — is returned.