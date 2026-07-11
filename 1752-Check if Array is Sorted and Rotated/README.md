# [1752. Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given an array `nums`, return `true` *if the array was originally sorted in non-decreasing order, then rotated **some** number of positions (including zero)*. Otherwise, return `false`.

There may be **duplicates** in the original array.

**Note:** An array `A` rotated by `x` positions results in an array `B` of the same length such that `A[i] == B[(i+x) % A.length]` for every valid index `i`.

### Examples

**Example 1:**
* **Input:** `nums = [3,4,5,1,2]`
* **Output:** `true`
* **Explanation:** `[1,2,3,4,5]` is the original sorted array. You can rotate the array by `x = 3` positions to begin with the element of index `3` in the array, which is `[3,4,5,1,2]`.

**Example 2:**
* **Input:** `nums = [2,1,3,4]`
* **Output:** `false`
* **Explanation:** There is no sorted array once rotated that can make `nums`.

**Example 3:**
* **Input:** `nums = [1,2,3]`
* **Output:** `true`
* **Explanation:** `[1,2,3]` is the original sorted array. You can rotate the array by `x = 0` positions to begin with the element of index `0` in the array, which is `[1,2,3]`.

### Constraints
* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`

---

## Approach & Intuition

A rotated sorted array has a very specific shape: it's non-decreasing everywhere **except** for a single "drop" point where the rotation wraps around (e.g., `[3,4,5,1,2]` — sorted, sorted, then one drop from `5` down to `1`, then sorted again). If there's more than one such drop, the array couldn't have come from rotating a sorted array. This solution checks for exactly that structure.

1. Loop through `nums`, comparing each adjacent pair `nums[i]` and `nums[i+1]`.
2. **When a drop is found** (`nums[i] > nums[i+1]`), this is the potential rotation point. For the array to still be validly "sorted and rotated," two wraparound conditions must both hold:
   * `nums[i]` (the largest element before the drop) must be **greater than or equal to** `nums[size-1]` (the last element) — otherwise the last element wouldn't fit into the sorted order before wrapping.
   * `nums[0]` (the first element) must be **greater than or equal to** `nums[size-1]` — since after wrapping around, the last element must connect smoothly back to the start of the array.
   * If **either** condition fails (checked via `nums[i] < nums[size-1] || nums[0] < nums[size-1]`), the wraparound is invalid, so return `false` immediately.
3. **After confirming the wraparound is valid**, verify there are **no further drops** for the remainder of the array — a valid rotated-sorted array can only have exactly one drop point. An inner loop scans from `i+1` to the end, and if it finds `nums[j] > nums[j+1]` anywhere, a second drop exists, meaning the array isn't a valid rotation — return `false`.
4. If the outer loop completes without ever triggering a `false` return (either no drop was found at all — meaning the array is already fully sorted — or exactly one valid drop was found and everything after it stayed sorted), the array qualifies — return `true`.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — Although there's a nested loop, the inner loop only executes **once**, at the first drop point found, and scans the remainder of the array exactly once before the function returns. So across the whole execution, each element is visited a constant number of times.
* **Space Complexity:** $O(1)$ — Only a couple of integer variables (`size`, loop indices) are used; no extra data structures are created.

---

## Code Walkthrough

The solution scans for a single drop point and validates the wraparound around it:
* `size` stores the array length, and the outer `for` loop walks through adjacent pairs looking for `nums[i] > nums[i+1]`.
* When a drop is detected, the wraparound check `nums[i] < nums[size-1] || nums[0] < nums[size-1]` verifies that both the pre-drop maximum and the array's first element are large enough to consistently follow the last element in sorted (rotated) order — if not, `false` is returned immediately.
* If the wraparound is valid, the inner `for` loop (from `j = i+1` to `size - 2`) checks that no further drops exist in the remainder of the array; any additional drop means more than one rotation point, so `false` is returned.
* Since the inner loop and its surrounding `return` statements guarantee the function exits as soon as the first drop is fully processed, the outer loop effectively only "does real work" up until (and including) that first drop.
* If the outer loop finishes without ever returning `false` (either zero drops or one valid drop followed by a fully sorted remainder), the function falls through to `return true`.