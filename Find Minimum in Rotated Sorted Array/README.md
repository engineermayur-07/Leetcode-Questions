# [153. Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/)

## Difficulty
**Medium**

---

## Problem Statement

Suppose an array of length `n` sorted in ascending order is **rotated** between `1` and `n` times. For example, the array `nums = [0,1,2,4,5,6,7]` might become:
* `[4,5,6,7,0,1,2]` if it was rotated `4` times.
* `[0,1,2,4,5,6,7]` if it was rotated `7` times.

Given the sorted rotated array `nums` of **unique** elements, return *the minimum element of this array*.

You must write an algorithm that runs in `O(log n)` time.

### Examples

**Example 1:**
* **Input:** `nums = [3,4,5,1,2]`
* **Output:** `1`
* **Explanation:** The original array was `[1,2,3,4,5]` rotated 3 times.

**Example 2:**
* **Input:** `nums = [4,5,6,7,0,1,2]`
* **Output:** `0`
* **Explanation:** The original array was `[0,1,2,4,5,6,7]` rotated 4 times.

**Example 3:**
* **Input:** `nums = [11,13,15,17]`
* **Output:** `11`
* **Explanation:** The original array was `[11,13,15,17]` and it was rotated 4 times.

### Constraints
* `n == nums.length`
* `1 <= n <= 5000`
* `-5000 <= nums[i] <= 5000`
* All the integers of `nums` are **unique**.
* `nums` is sorted and rotated between `1` and `n` times.

---

## Approach & Intuition

Even though the array has been rotated, it still consists of **two sorted subarrays** joined together (e.g., `[4,5,6,7 | 0,1,2]`). This partial ordering is exactly what makes binary search applicable here, even though the array isn't fully sorted:

1. Initialize `low = 0`, `high = n - 1`, and `ans = INT_MAX` to track the minimum found so far.
2. While `low <= high`:
   * Compute `mid = low + (high - low) / 2`.
   * Update `ans` with `nums[mid]`, since the midpoint is always a valid candidate for the minimum.
   * Check whether the **left half** (`nums[low]` to `nums[mid]`) is sorted, using the condition `nums[low] <= nums[mid]`:
     * If it **is sorted**, then `nums[low]` is the smallest value in that sorted left half. Update `ans` with `nums[low]`, and since the left half is already known to be sorted (and thus can't contain the rotation point / global minimum any lower than `nums[low]`), move the search to the right half by setting `low = mid + 1`.
     * If it's **not sorted**, that means the rotation point (and hence the true minimum) lies somewhere within the left half (including `mid`), so narrow the search by setting `high = mid - 1`.
3. Once the loop ends, `ans` holds the smallest element encountered across all the valid candidates checked during the search.

The key insight is that at every step, at least one half of the current range is guaranteed to be properly sorted — and checking `nums[low] <= nums[mid]` is what tells us which half to trust and which half to keep searching.

---

## Complexity Analysis

* **Time Complexity:** $O(\log n)$ — Each iteration discards half of the remaining search space, regardless of which half is sorted.
* **Space Complexity:** $O(1)$ — Only a few integer variables (`low`, `high`, `mid`, `ans`) are used; no extra data structures are allocated.

---

## Code Walkthrough

The solution adapts the standard binary search template to track a running minimum rather than searching for a single fixed target:
* `n` stores the array size, and `low`/`high` are initialized to span the full array.
* `ans` starts at `INT_MAX` and is progressively tightened as better (smaller) candidates are found.
* Inside the loop, `ans = min(nums[mid], ans)` ensures the midpoint is always considered, even if the search moves away from it afterward.
* The check `nums[low] <= nums[mid]` determines whether the left portion `[low, mid]` is internally sorted:
  * If sorted, `nums[low]` (the smallest value in that portion) is folded into `ans`, and the search shifts right via `low = mid + 1`.
  * If not sorted, the rotation point lies within `[low, mid]`, so the search shifts left via `high = mid - 1`, keeping `mid` itself in the range.
* The final `ans` — accumulated from all visited candidates — is returned as the overall minimum.