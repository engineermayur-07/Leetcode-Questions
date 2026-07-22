# [704. Binary Search](https://leetcode.com/problems/binary-search/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with `O(log n)` runtime complexity.

### Examples

**Example 1:**
* **Input:** `nums = [-1,0,3,5,9,12]`, `target = 9`
* **Output:** `4`
* **Explanation:** 9 exists in `nums` and its index is 4.

**Example 2:**
* **Input:** `nums = [-1,0,3,5,9,12]`, `target = 2`
* **Output:** `-1`
* **Explanation:** 2 does not exist in `nums` so return `-1`.

### Constraints
* `1 <= nums.length <= 10^4`
* `-10^4 < nums[i], target < 10^4`
* All the integers in `nums` are **unique**.
* `nums` is sorted in ascending order.

---

## Approach & Intuition

This is the textbook implementation of **binary search** on a sorted array — repeatedly halving the search space by comparing the target against the middle element:

1. Initialize `low = 0` and `high = nums.size() - 1`, representing the full range of valid indices to search.
2. While `low <= high`:
   * Compute `mid = low + (high - low) / 2` (this overflow-safe formula avoids potential issues with `(low + high) / 2` for very large index values, though less critical here given the constraint `n <= 10^4`).
   * Compare `nums[mid]` to `target`:
     * If they're **equal**, the target has been found — return `mid` immediately.
     * If `nums[mid] > target`, the target (if present) must lie in the **left half**, since the array is sorted ascending — discard the right half by setting `high = mid - 1`.
     * If `nums[mid] < target`, the target must lie in the **right half** — discard the left half by setting `low = mid + 1`.
3. If the loop exits (`low > high`) without ever finding a match, the target isn't present in the array — return `-1`.

Each comparison eliminates half of the remaining search space, which is what gives binary search its logarithmic runtime — a stark improvement over a linear scan, especially for large arrays.

---

## Complexity Analysis

* **Time Complexity:** $O(\log n)$ — Each iteration of the `while` loop halves the search range `[low, high]`, so the number of comparisons needed scales logarithmically with the size of `nums`.
* **Space Complexity:** $O(1)$ — Only a constant number of integer variables (`low`, `high`, `mid`) are used, regardless of the input size.

---

## Code Walkthrough

The solution implements the standard binary search template directly:
* `high` and `low` are initialized to `nums.size() - 1` and `0`, bounding the entire array.
* Inside the `while (low <= high)` loop, `mid` is computed using the overflow-safe midpoint formula `low + (high - low) / 2`.
* `if (nums[mid] == target) return mid` handles the success case immediately.
* `else if (nums[mid] > target) high = mid - 1` narrows the search to the left half when the middle value overshoots the target.
* The final implicit `else` (`low = mid + 1`) narrows the search to the right half when the middle value undershoots the target.
* If the loop terminates without a match, `-1` is returned to indicate the target wasn't found.