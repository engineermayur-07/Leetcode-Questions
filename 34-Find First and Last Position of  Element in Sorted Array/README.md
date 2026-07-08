# [34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/)

## Difficulty
**Medium**

---

## Problem Statement

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with $O(\log n)$ runtime complexity.

### Examples

**Example 1:**
* **Input:** `nums = [5,7,7,8,8,10]`, `target = 8`
* **Output:** `[3,4]`

**Example 2:**
* **Input:** `nums = [5,7,7,8,8,10]`, `target = 6`
* **Output:** `[-1,-1]`

**Example 3:**
* **Input:** `nums = [0]`, `target = 0`
* **Output:** `[0,0]`

### Constraints
* `0 <= nums.length <= 10^5`
* `-10^9 <= nums[i] <= 10^9`
* `nums` is a non-decreasing array.
* `-10^9 <= target <= 10^9`

---

## Approach & Intuition

The problem demands an $O(\log n)$ time complexity on a sorted array, which points directly to **Binary Search**. However, because duplicates can exist, a standard binary search might land on *any* instance of the target rather than its boundary positions.

To overcome this, we split the problem into two distinct modified binary searches:

### 1. Finding the First Position (Left Boundary)
* We perform binary search as usual.
* When we find `nums[mid] == target`, instead of stopping, we record `mid` as a potential starting position (`ans[0] = mid`).
* Because we want the *first* occurrence, we continue looking in the left half by shifting our boundary: `high = mid - 1`.

### 2. Finding the Last Position (Right Boundary)
* We reset our search bounds (`low = 0`, `high = n - 1`) and run a second search.
* When we find `nums[mid] == target`, we record `mid` as a potential ending position (`ans[1] = mid`).
* Because we want the *last* occurrence, we continue looking in the right half by shifting our boundary: `low = mid + 1`.

---

## Complexity Analysis

* **Time Complexity:** $O(\log n)$ — We run two independent binary searches back-to-back. Since each search takes $O(\log n)$, the total time complexity remains $2 \times O(\log n) = O(\log n)$.
* **Space Complexity:** $O(1)$ — The algorithm performs modifications completely in-place and only uses primitive integer variables for tracking markers.

---

## Code Walkthrough

The C++ solution implements the independent passes sequentially:
* `ans` is initialized to `{-1, -1}` right away to automatically handle missing targets.
* **First loop:** Focuses entirely on finding the lower bound. By updating `high = mid - 1` upon matching the target, it aggressively shifts toward index `0`.
* **Second loop:** Resets boundaries and focuses on the upper bound. By updating `low = mid + 1` upon matching the target, it pushes toward the end of the array.