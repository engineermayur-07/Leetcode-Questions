# [Leaders in an Array](https://takeuforward.org/plus/dsa/problems/leaders-in-an-array?source=strivers-a2z-dsa-track)

## Difficulty
**Easy**

---

## Problem Statement

Given an array `nums`, print all the elements which are **leaders**. A **leader** is an element that is greater than all elements to its right side. The rightmost element is always a leader.

### Examples

**Example 1:**
* **Input:** `nums = [10, 22, 12, 3, 0, 6]`
* **Output:** `[22, 12, 6]`
* **Explanation:** `22` is greater than everything to its right (`12, 3, 0, 6`). `12` is greater than everything to its right (`3, 0, 6`). `6` is the rightmost element, so it's a leader by default.

**Example 2:**
* **Input:** `nums = [4, 5, 2, 25]`
* **Output:** `[25]`
* **Explanation:** Only `25` (the rightmost element) qualifies, since `4`, `5`, and `2` all have something larger somewhere to their right.

### Constraints
* `1 <= nums.length <= 10^5`
* Elements can be positive, negative, or zero.

---

## Approach & Intuition

A brute-force approach would check, for every element, whether it's greater than **all** elements to its right — an $O(n^2)$ comparison. Instead, since "leader" only depends on the elements to the **right**, it's far more efficient to scan the array **from right to left**, keeping track of the largest value seen so far (`last_leader`). Any element that beats this running maximum is, by definition, a leader — since everything to its right has already been scanned and none of it was larger.

1. Start from the **last element** of `nums` — it's always a leader (nothing exists to its right to beat it). Push it into the `leader` result vector, and initialize `last_leader` to this value.
2. Iterate `i` from the second-to-last index down to `0`:
   * If `nums[i] > last_leader`, this element beats everything scanned so far (which represents everything to its right in the original array) — it's a new leader. Push it into `leader` and update `last_leader = nums[i]`.
   * Otherwise, skip it — some element further right is greater or equal, so it's disqualified.
3. Since elements were discovered in **right-to-left** order but leaders are conventionally expected in their **original left-to-right** order, `reverse()` is applied to `leader` before returning it.

The key insight is that scanning right-to-left turns "is this the max of everything to my right?" into a simple running-maximum comparison, avoiding any nested loops.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — A single right-to-left pass through `nums`, plus a final `reverse()` call which is also linear in the size of the result.
* **Space Complexity:** $O(k)$ — Where $k$ is the number of leaders found (this is required for the output itself; excluding the output, only a couple of extra variables are used).

---

## Code Walkthrough

The solution scans backward while tracking a running maximum:
* `n` is set to the last valid index of `nums`. `last_leader` is initialized to `nums[n]` (the last element, always a leader), and it's immediately pushed into the `leader` result vector.
* The `for` loop starts at `i = n` and walks backward to `0`, checking `if (nums[i] > last_leader)` at each step.
* Whenever a new leader is found, it's pushed into `leader`, and `last_leader` is updated to reflect this new, larger running maximum.
* Since the loop discovers leaders from right to left, `reverse(leader.begin(), leader.end())` restores them to their original left-to-right order before the vector is returned.