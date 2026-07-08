# [154. Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/)

## Difficulty
**Hard**

---

## Problem Statement

Suppose an array of length `n` sorted in ascending order is **rotated** between `1` and `n` times. For example, the array `nums = [0,1,4,4,5,6,7]` might become:
* `[4,5,6,7,0,1,4]` if it was rotated `4` times.
* `[0,1,4,4,5,6,7]` if it was rotated `7` times.

Given the sorted rotated array `nums` that **may contain duplicates**, return *the minimum element of this array*.

You must decrease the overall operation steps as much as possible.

### Examples

**Example 1:**
* **Input:** `nums = [1,3,5]`
* **Output:** `1`

**Example 2:**
* **Input:** `nums = [2,2,2,0,1]`
* **Output:** `0`

### Constraints
* `n == nums.length`
* `1 <= n <= 5000`
* `-5000 <= nums[i] <= 5000`
* `nums` is sorted and rotated between `1` and `n` times.

---

## Approach & Intuition

This is the follow-up to problem 153, with one key twist: **duplicates are allowed**. That single change breaks the clean "is the left half sorted?" check from the previous problem, because `nums[low] <= nums[mid]` can now be `true` even when `low` and `mid` straddle the rotation point (e.g., `[3,3,1,3]` — here `nums[low] == nums[mid]` but the minimum is still hidden to the right).

The fix is to explicitly handle the ambiguous case where `nums[low] == nums[high]`:

1. Initialize `low = 0`, `high = n - 1`, and `ans = INT_MAX`.
2. While `low <= high`:
   * Compute `mid = low + (high - low) / 2` and fold `nums[mid]` into `ans`.
   * **Ambiguity check:** If `nums[low] == nums[high]`, we cannot reliably determine which side is sorted (both ends look identical, but the minimum could be hidden anywhere in between, including inside a run of duplicates). In this case, we can't safely eliminate half the array — so we conservatively shrink the range by one from the right (`high--`) and `continue` to the next iteration without deciding a direction.
   * Once `nums[low] != nums[high]`, the same logic from problem 153 applies safely:
     * If `nums[low] <= nums[mid]`, the left half `[low, mid]` is properly sorted. Fold `nums[low]` into `ans` and move right: `low = mid + 1`.
     * Otherwise, the rotation point lies in `[low, mid]`, so move left: `high = mid - 1`.
3. Return `ans` once the loop ends.

The `high--` fallback is what keeps the algorithm correct in the presence of duplicates, at the cost of occasionally degrading to linear behavior in the worst case (e.g., an array of all identical elements).

---

## Complexity Analysis

* **Time Complexity:** $O(\log n)$ on average, degrading to $O(n)$ in the **worst case** — When large runs of duplicate values cause `nums[low] == nums[high]` repeatedly, the algorithm falls back to shrinking the range one element at a time instead of halving it, as in the case of an array like `[2,2,2,2,2,2,1,2]`.
* **Space Complexity:** $O(1)$ — Only a fixed number of integer variables (`low`, `high`, `mid`, `ans`) are used.

---

## Code Walkthrough

The solution extends the problem 153 template with an extra guard clause for duplicates:
* `n`, `low`, `high`, and `ans` are initialized exactly as in the no-duplicates version.
* Inside the loop, `ans = min(nums[mid], ans)` is evaluated first, unconditionally, on every iteration.
* The new check `if (nums[low] == nums[high])` catches the ambiguous case introduced by duplicates. When triggered, `high--` shrinks the search space conservatively, and `continue` skips the rest of the loop body for that iteration.
* Once the ambiguity is resolved (`nums[low] != nums[high]`), the familiar comparison `nums[low] <= nums[mid]` decides which half is sorted, folding `nums[low]` into `ans` and adjusting `low` or `high` exactly as in the 153 solution.
* The final `ans`, accumulated across all visited midpoints and left-bound candidates, is returned as the minimum.