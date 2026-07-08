# [35. Search Insert Position](https://leetcode.com/problems/search-insert-position/)

## Difficulty
**Easy**

---

## Problem Statement

Given a sorted array of distinct integers `nums` and a `target` value, return the index if the `target` is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with $O(\log n)$ runtime complexity.

### Examples

**Example 1:**
* **Input:** `nums = [1,3,5,6]`, `target = 5`
* **Output:** `2`

**Example 2:**
* **Input:** `nums = [1,3,5,6]`, `target = 2`
* **Output:** `1`

**Example 3:**
* **Input:** `nums = [1,3,5,6]`, `target = 7`
* **Output:** `4`

---

## Approach & Intuition

The problem requires a runtime complexity of $O(\log n)$ within a sorted array, which points directly to standard **Binary Search**. 

The unique twist here is finding the *insertion position* if the target is missing. 

### Why returning `low` works:
* As the binary search loop narrows down, `low` and `high` converge on the closest elements.
* If `nums[mid]` is greater than the `target`, the target belongs to the left of `mid`. We shift `high = mid - 1`.
* If `nums[mid]` is less than the `target`, the target belongs to the right of `mid`. We shift `low = mid + 1`.
* When the loop terminates (`low > high`), `low` will naturally point to the exact index where the target *should* be inserted to maintain sorted order.

---

## Complexity Analysis

* **Time Complexity:** $O(\log n)$ — The search space is halved in every iteration of the loop.
* **Space Complexity:** $O(1)$ — Only three integer variables (`low`, `high`, `mid`) are utilized, requiring constant space.

---

## Code Walkthrough

The C++ solution utilizes a classic iterative binary search setup:
* `low` and `high` boundaries are set to wrap the full vector range.
* `mid` is safely calculated using `low + (high - low) / 2` to avoid potential integer overflow.
* If a direct match is found (`nums[mid] == target`), the index is returned instantly.
* If the loop finishes without a match, `return low;` correctly provides the sorted insertion position.