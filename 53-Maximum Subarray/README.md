# [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/description/)

## Difficulty
**Medium**

---

## Problem Statement

Given an integer array `nums`, find the subarray with the largest sum, and return *its sum*.

### Examples

**Example 1:**
* **Input:** `nums = [-2,1,-3,4,-1,2,1,-5,4]`
* **Output:** `6`
* **Explanation:** The subarray `[4,-1,2,1]` has the largest sum `6`.

**Example 2:**
* **Input:** `nums = [1]`
* **Output:** `1`
* **Explanation:** The subarray `[1]` has the largest sum `1`.

**Example 3:**
* **Input:** `nums = [5,4,-1,7,8]`
* **Output:** `23`
* **Explanation:** The subarray `[5,4,-1,7,8]` has the largest sum `23`.

### Constraints
* `1 <= nums.length <= 10^5`
* `-10^4 <= nums[i] <= 10^4`
* `-10^4 <= nums[i] <= 10^4`

---

## Approach & Intuition

This solution uses **Kadane's Algorithm**, a classic dynamic-programming-flavored technique for the maximum subarray sum problem. The core idea: as we scan through the array building up a running sum, if that running sum ever becomes **negative**, it can only be dragging down any future subarray sum it's added to — so it's better to "cut our losses" and restart the sum from the current element instead of carrying the negative baggage forward.

1. Initialize `sum = nums[0]` (running subarray sum) and `ans = nums[0]` (best sum found so far), both seeded with the first element.
2. Iterate through the rest of the array, from index `1` to `n-1`:
   * **If `sum < 0`:** the running sum has become a net negative, meaning it would only hurt any subarray it gets extended into. Discard it and restart the running sum fresh at the current element: `sum = nums[i]`.
   * **Otherwise:** the running sum is still non-negative, so it's worth keeping — extend it by adding the current element: `sum += nums[i]`.
   * After updating `sum` either way, compare it against the best answer so far: `ans = max(sum, ans)`.
3. After the loop completes, `ans` holds the maximum subarray sum found across the entire array.

The key insight is that checking `sum < 0` **before** adding the next element (rather than after) means we only ever discard a running sum when it's strictly harmful to continue — extending a sum that's still `>= 0` can never make things worse, since adding a non-negative baseline can only help or neutrally pass through the next element's value.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — A single linear pass through `nums`, with constant-time work per element.
* **Space Complexity:** $O(1)$ — Only two variables (`sum`, `ans`) are used, regardless of the size of `nums`.

---

## Code Walkthrough

The solution implements Kadane's Algorithm in a single forward pass:
* `n` stores the array length, and both `sum` and `ans` are initialized to `nums[0]`, covering the base case where the best subarray might just be the first element alone.
* The `for` loop starts at index `1`, checking `if (sum < 0)` on each iteration:
  * If the running sum is negative, it's reset to just the current element (`sum = nums[i]`), effectively starting a new candidate subarray from this point.
  * Otherwise, the current element is added onto the existing running sum (`sum += nums[i]`), extending the current candidate subarray.
* Regardless of which branch executed, `ans = max(sum, ans)` updates the best sum seen so far immediately after `sum` is finalized for this iteration.
* Once the loop completes, `ans` — the largest running sum ever recorded — is returned as the maximum subarray sum.