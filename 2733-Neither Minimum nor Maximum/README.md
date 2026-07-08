# [2733. Neither Minimum nor Maximum](https://leetcode.com/problems/neither-minimum-nor-maximum/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given an array of **distinct** integers `nums`, return *any number from the array that is neither the minimum nor the maximum value in the array*, or `-1` if there is no such number.

### Examples

**Example 1:**
* **Input:** `nums = [3,2,1,4]`
* **Output:** `2`
* **Explanation:** In this example, the minimum value is 1 and the maximum value is 4. Either 2 or 3 can be valid answers.

**Example 2:**
* **Input:** `nums = [1,2]`
* **Output:** `-1`
* **Explanation:** Since there are only two elements, both the minimum and maximum values are `1` and `2`, so there's no number that is neither of those.

**Example 3:**
* **Input:** `nums = [2,1,3]`
* **Output:** `2`
* **Explanation:** Since 2 is neither the maximum nor the minimum, it's the answer.

### Constraints
* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`
* All values of `nums` are **distinct**.

---

## Approach & Intuition

Since the array has **distinct** values and only the min and max need to be excluded, this reduces to a simple two-pass scan:

1. **Edge case first:** If `size < 3`, there can be at most 2 distinct values (min and max), leaving no room for a third "neither" value — immediately return `-1`.
2. **First pass — find the min and max:** Track the *indices* of the minimum and maximum elements (`min` and `max`), initialized to index `0`. Scan through `nums`, updating `max` whenever a larger element is found, and `min` whenever a smaller one is found. Using indices (rather than storing values directly) also matches the pattern of tracking positions for later comparison.
3. **Second pass — find any qualifying element:** Scan through `nums` again, and return the **first** element whose value differs from both `nums[min]` and `nums[max]` — this is guaranteed to be neither the minimum nor the maximum.
4. If no such element is found (which, given the `size < 3` check, shouldn't happen for valid inputs), return `-1` as a fallback.

Since the problem only asks for *any* valid answer (not the smallest, or in any particular position), a straightforward "find min/max, then find anything else" approach is sufficient — no sorting or extra data structures are needed.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — Two separate linear passes over `nums` (one to find min/max, one to find a qualifying element), which is still linear overall.
* **Space Complexity:** $O(1)$ — Only a few integer variables (`max`, `min`, `size`) are used; no extra arrays or structures are created.

---

## Code Walkthrough

The solution uses index-tracking variables and two sequential loops:
* `max` and `min` are initialized to index `0` (not the values themselves), and `size` stores the array length.
* The early `if (size < 3) return -1` guard handles the case where fewer than 3 elements make finding a "neither" value impossible.
* The first `for` loop updates `max` to `i` whenever `nums[i] > nums[max]`, and similarly updates `min` to `i` whenever `nums[i] < nums[min]` — by the end, `nums[max]` and `nums[min]` hold the true maximum and minimum values.
* The second `for` loop checks each element against `nums[min]` and `nums[max]`; the first element that matches neither is returned immediately as the answer.
* If the second loop completes without finding a match (not expected given the earlier size check), `-1` is returned as a safety fallback.