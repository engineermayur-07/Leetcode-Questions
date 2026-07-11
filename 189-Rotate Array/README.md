# [189. Rotate Array](https://leetcode.com/problems/rotate-array/description/)

## Difficulty
**Medium**

---

## Problem Statement

Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

### Examples

**Example 1:**
* **Input:** `nums = [1,2,3,4,5,6,7]`, `k = 3`
* **Output:** `[5,6,7,1,2,3,4]`
* **Explanation:**
  * rotate 1 steps to the right: `[7,1,2,3,4,5,6]`
  * rotate 2 steps to the right: `[6,7,1,2,3,4,5]`
  * rotate 3 steps to the right: `[5,6,7,1,2,3,4]`

**Example 2:**
* **Input:** `nums = [-1,-100,3,99]`, `k = 2`
* **Output:** `[3,99,-1,-100]`
* **Explanation:**
  * rotate 1 steps to the right: `[99,-1,-100,3]`
  * rotate 2 steps to the right: `[3,99,-1,-100]`

### Constraints
* `1 <= nums.length <= 10^5`
* `-2^31 <= nums[i] <= 2^31 - 1`
* `0 <= k <= 100000`

---

## Approach & Intuition

Rotating an array right by `k` steps is really just **splitting the array into two chunks and swapping their order**. If you rotate `[1,2,3,4,5,6,7]` right by `3`, the last `3` elements (`5,6,7`) end up at the front, and the remaining first `4` elements (`1,2,3,4`) get pushed to the back — the array is effectively cut at position `size - k` and the two halves swap places.

1. **Edge case:** If `k == 0`, no rotation is needed at all — return immediately.
2. **Normalize `k`:** Since rotating by `size` steps brings the array back to its original order, only `k % size` rotations actually matter — this also protects against `k` being larger than the array length.
3. Split `nums` into two temporary vectors in a single pass:
   * `temp1` collects the **first** `size - k` elements (indices `0` to `size - k - 1`) — this is the portion that will end up at the **back** after rotation.
   * `temp2` collects the **remaining** `k` elements (indices `size - k` to `size - 1`) — this is the portion that will end up at the **front** after rotation.
4. Write the result back into `nums` in the new order:
   * First, copy all of `temp2` into `nums` starting at index `0` — placing the "wrapped around" tail elements at the front.
   * Then, continue copying all of `temp1` right after `temp2`, filling in the rest of `nums` — placing the original front elements at the back.

This effectively performs the rotation using a straightforward "cut and swap the two halves" strategy, using two auxiliary arrays instead of manipulating the array in place.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — The array is split into two temporary vectors in one pass, and then copied back into `nums` in another pass — both linear in the size of `nums`.
* **Space Complexity:** $O(n)$ — Two auxiliary vectors, `temp1` and `temp2`, are created, which together hold as many elements as the original array. (Note: an in-place approach — e.g., using the three-reversal trick — can achieve this rotation in $O(1)$ extra space.)

---

## Code Walkthrough

The solution performs the rotation via a two-vector split-and-recombine:
* The early `if (k == 0) return` guard skips unnecessary work when no rotation is needed.
* `k = k % size` normalizes `k` so it always represents a meaningful rotation amount within the array's bounds.
* The first `for` loop partitions `nums` into `temp1` (the first `size - k` elements, destined for the back) and `temp2` (the last `k` elements, destined for the front), based on whether `i < size - k`.
* The second `for` loop copies all of `temp2` into the front of `nums`, using `i` as a shared running index into `nums`.
* The third `for` loop continues from where `i` left off, copying all of `temp1` into the remaining back portion of `nums`.
* After both copy loops complete, `nums` has been rearranged in place to reflect the array rotated right by `k` steps.