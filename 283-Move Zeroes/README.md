# [283. Move Zeroes](https://leetcode.com/problems/move-zeroes/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Note** that you must do this in-place without making a copy of the array.

### Examples

**Example 1:**
* **Input:** `nums = [0,1,0,3,12]`
* **Output:** `[1,3,12,0,0]`

**Example 2:**
* **Input:** `nums = [0]`
* **Output:** `[0]`

### Constraints
* `1 <= nums.length <= 10^4`
* `-2^31 <= nums[i] <= 2^31 - 1`

---

## Approach & Intuition

This is a classic **two-pointer, in-place partitioning** problem — very similar in spirit to the "move all elements matching a condition to one side" pattern. Instead of physically shifting elements one by one (which could be costly), we use a slow pointer (`index`) to track where the **next non-zero element should go**, and swap it into place as we scan through the array.

1. Initialize `index = 0` — this pointer marks the position where the next non-zero value should be placed.
2. Iterate through the array with a second pointer `i` from `0` to `n-1`:
   * If `nums[i]` is **non-zero**, it belongs in the "non-zero" region at the front of the array. Swap it with whatever is currently at `nums[index]`, then advance `index` by one.
   * If `nums[i]` **is zero**, do nothing and simply move on — it'll naturally get pushed toward the back as non-zero elements are swapped past it.
3. By the time `i` finishes scanning the whole array, all non-zero elements have been swapped into the front `index` positions in their original relative order, and all the zeros have been pushed (via the swaps) to occupy the remaining back positions.

The key insight is that swapping (rather than overwriting) preserves every element already in the array — a `0` that gets swapped out of the front simply moves to wherever the non-zero element used to be, which is always at or behind the current scanning position, so it naturally lands further back as the process continues.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — A single pass through `nums`, with a constant-time swap operation per element.
* **Space Complexity:** $O(1)$ — The rearrangement happens entirely in place using swaps; no auxiliary array is created.

---

## Code Walkthrough

The solution uses a single forward pass with a slow/fast pointer pair:
* `index` starts at `0` and tracks the boundary of the "non-zero elements placed so far" region.
* `n` stores the array size for the loop bound.
* The `for` loop advances `i` through every index of `nums`.
* Whenever `nums[i] != 0`, `swap(nums[index], nums[i])` moves that non-zero value into its correct position at `index` (while whatever was previously at `index` — often a zero — gets swapped out to where `i` currently is), and `index++` moves the boundary forward by one.
* If `nums[i] == 0`, nothing happens for that iteration, and the loop simply continues to the next `i`.
* Since all operations happen via in-place swaps on the original vector, no return value is needed — `nums` is modified directly to reflect all non-zero elements moved to the front (in original order) and all zeros pushed to the end.