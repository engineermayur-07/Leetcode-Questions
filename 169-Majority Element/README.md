# [169. Majority Element](https://leetcode.com/problems/majority-element/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given an array `nums` of size `n`, return *the majority element*.

The majority element is the element that appears more than `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.

### Examples

**Example 1:**
* **Input:** `nums = [3,2,3]`
* **Output:** `3`

**Example 2:**
* **Input:** `nums = [2,2,1,1,1,2,2]`
* **Output:** `2`

### Constraints
* `n == nums.length`
* `1 <= n <= 5 * 10^4`
* `-10^9 <= nums[i] <= 10^9`
* `-10^9 <= nums[i] <= 10^9`
* The majority element always exists in the array.

---

## Approach & Intuition

This solution uses the **Boyer-Moore Voting Algorithm**, a clever $O(1)$-space technique for finding a majority element (one that appears more than `n/2` times).

The core intuition: think of each occurrence of the current candidate as a `+1` "vote," and every other value as a `-1` "vote" against it. Since the majority element appears more than half the time, its votes will always outweigh the combined votes of everything else — so if we keep a running tally and reset our candidate whenever the tally hits zero, we're guaranteed to end up with the true majority element as our final candidate.

1. Initialize `count = 0` and `ans = nums[0]` (an initial guess for the candidate).
2. Iterate through every element in `nums`:
   * **If `count == 0`:** there's currently no "surviving" candidate, so adopt the current element as the new candidate: `ans = nums[i]`.
   * **Then, regardless of whether `ans` was just reset:** compare `nums[i]` to `ans`.
     * If they match, increment `count` (another vote for the current candidate).
     * If they don't match, decrement `count` (a vote against the current candidate, cancelling out one of its prior votes).
3. After scanning the entire array, `ans` holds the majority element.

Since the problem guarantees a majority element always exists, this algorithm is guaranteed to converge on it — any non-majority "impostor" candidate will eventually get its `count` driven down to `0` and be replaced, while the true majority element's votes can never be fully cancelled out by the (strictly fewer) votes against it.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — A single linear pass through `nums`, with constant-time work per element.
* **Space Complexity:** $O(1)$ — Only two variables (`count`, `ans`) are used, regardless of the size of `nums`.

---

## Code Walkthrough

The solution implements the Boyer-Moore Voting Algorithm directly:
* `size` stores the array length, `count` starts at `0` (no current candidate), and `ans` is pre-initialized to `nums[0]` as a starting guess.
* Inside the `for` loop, `if (count == 0)` checks whether the current candidate has been fully "voted out" — if so, `ans` is reassigned to `nums[i]`, adopting a fresh candidate.
* Immediately after (not as an `else`), `if (nums[i] == ans)` checks whether the current element supports the (possibly just-updated) candidate, incrementing `count` on a match.
* The `else` branch decrements `count` when the current element opposes the candidate.
* Since the array is guaranteed to contain a true majority element, its votes can never be entirely cancelled out, so by the end of the loop, `ans` correctly holds the majority element and is returned.