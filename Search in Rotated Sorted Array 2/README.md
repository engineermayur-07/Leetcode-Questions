# [81. Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/)

## Difficulty
**Medium**

---

## Problem Statement

There is an integer array `nums` sorted in non-decreasing order (not necessarily with distinct values), which is then **rotated** at an unknown pivot index.

Given the rotated array `nums` and an integer `target`, return `true` *if `target` is in `nums`, or `false` if it is not*.

You must decrease the overall operation steps as much as possible.

### Examples

**Example 1:**
* **Input:** `nums = [2,5,6,0,0,1,2]`, `target = 0`
* **Output:** `true`

**Example 2:**
* **Input:** `nums = [2,5,6,0,0,1,2]`, `target = 3`
* **Output:** `false`

### Constraints
* `1 <= nums.length <= 5000`
* `-10^4 <= nums[i] <= 10^4`
* `nums` is guaranteed to be rotated at some pivot.
* `-10^4 <= target <= 10^4`

---

## Approach & Intuition

This problem combines two ideas seen in earlier problems: searching a **rotated sorted array** (like problem 33) and handling **duplicate values** (like problem 154). The array is still made up of two sorted halves joined at a rotation point, but duplicates can make it impossible to tell which half is properly sorted just by comparing endpoints.

1. Initialize `low = 0`, `high = n - 1`.
2. While `low <= high`:
   * Compute `mid = low + (high - low) / 2`.
   * If `nums[mid] == target`, the target has been found — return `true` immediately.
   * **Ambiguity check:** If `nums[low] == nums[high]`, the values at both ends are equal, so it's impossible to determine which half is sorted purely by comparison. In this case, shrink the search space conservatively by incrementing `low` and `continue` to the next iteration.
   * Once the ambiguity is resolved, determine which half is properly sorted:
     * If `nums[low] <= nums[mid]`, the **left half** `[low, mid]` is sorted. Check if `target` falls within `nums[low]` and `nums[mid]` (inclusive) — if so, the target must be in the left half, so set `high = mid - 1`; otherwise, discard the left half and set `low = mid + 1`.
     * Otherwise, the **right half** `[mid, high]` must be sorted. Check if `target` falls within `nums[mid]` and `nums[high]` — if so, search there by setting `low = mid + 1`; otherwise, set `high = mid - 1`.
3. If the loop exits without finding the target, return `false`.

The core idea is the same "identify the sorted half, then check if the target lies within it" trick used for rotated array search without duplicates — with an added escape hatch for when duplicates make that identification ambiguous.

---

## Complexity Analysis

* **Time Complexity:** $O(\log n)$ on average, degrading to $O(n)$ in the **worst case** — When there are many duplicate values causing `nums[low] == nums[high]` repeatedly (e.g., `[2,2,2,2,2,2,2,2,1,2]`), the algorithm falls back to shrinking the range one element at a time.
* **Space Complexity:** $O(1)$ — Only a constant number of integer variables (`low`, `high`, `mid`) are used.

---

## Code Walkthrough

The solution follows the standard rotated-array binary search template, extended with a duplicate-handling guard:
* `n`, `low`, and `high` are initialized to span the entire array.
* Each iteration first checks `nums[mid] == target` as an early exit.
* The `if (nums[low] == nums[high])` block handles the ambiguous duplicate case by incrementing `low` and skipping to the next iteration via `continue`.
* If `nums[low] <= nums[mid]`, the code treats the left half as sorted and checks whether `target` lies in the range `[nums[low], nums[mid]]` to decide whether to search left (`high = mid - 1`) or right (`low = mid + 1`).
* Otherwise, the right half `[mid, high]` is treated as sorted, and an analogous range check (`nums[mid]` to `nums[high]`) decides whether to move `low` up or `high` down.
* If the loop terminates without a match, `false` is returned.