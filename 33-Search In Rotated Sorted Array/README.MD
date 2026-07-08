# [33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/)

## Difficulty
**Medium**

---

## Problem Statement

There is an integer array `nums` sorted in ascending order (with **distinct** values).

Prior to being passed to your function, `nums` is **possibly left-rotated** at an unknown index `k` (`1 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (**0-indexed**). For example, `[0,1,2,4,5,6,7]` might be left-rotated by 3 indices and become `[4,5,6,7,0,1,2]`.

Given the array `nums` after the possible rotation and an integer `target`, return *the index of `target` if it is in `nums`, or `-1` if it is not in `nums`*.

You must write an algorithm with $O(\log n)$ runtime complexity.

### Examples

**Example 1:**
* **Input:** `nums = [4,5,6,7,0,1,2]`, `target = 0`
* **Output:** `4`

**Example 2:**
* **Input:** `nums = [4,5,6,7,0,1,2]`, `target = 3`
* **Output:** `-1`

**Example 3:**
* **Input:** `nums = [1]`, `target = 0`
* **Output:** `-1`

---

## Approach & Intuition

The problem demands an $O(\log n)$ time complexity, which strongly indicates a **Binary Search** approach. However, because the sorted array has been rotated, we cannot perform standard binary search directly. 

The key insight for a rotated sorted array is: **If you divide the array in half, at least one of the halves will always remain strictly sorted.**

1. **Find the Middle:** Compute `mid = low + (high - low) / 2`.
2. **Identify the Sorted Half:** * If `nums[low] <= nums[mid]`, the **left half** is sorted.
   * Otherwise, the **right half** must be sorted.
3. **Narrow Down the Search Space:**
   * If the **left half** is sorted: Check if the `target` lies within the range `[nums[low], nums[mid])`. If it does, narrow the search to the left (`high = mid - 1`). Otherwise, search the right half.
   * If the **right half** is sorted: Check if the `target` lies within the range `(nums[mid], nums[high]]`. If it does, narrow the search to the right (`low = mid + 1`). Otherwise, search the left half.

---

## Complexity Analysis

* **Time Complexity:** $O(\log n)$ — Because the search space is cut in half at each step, just like standard binary search.
* **Space Complexity:** $O(1)$ — Only a few pointers (`low`, `high`, `mid`) are modified, requiring constant extra memory.

---

## Code Walkthrough

The solution implements an iterative binary search:
* It initializes two pointers, `low` and `high`, at the boundaries of the array.
* Inside the `while (low <= high)` loop, it first checks if `nums[mid] == target` to return an early match.
* It then uses conditional blocks to separate the logic into the **strictly sorted left-half** and **strictly sorted right-half** cases, safely moving the pointers without ever needing to find the rotation pivot index explicitly.