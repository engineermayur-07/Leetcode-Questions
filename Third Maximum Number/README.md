# [414. Third Maximum Number](https://leetcode.com/problems/third-maximum-number/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given an integer array `nums`, return *the **third distinct maximum** number in this array. If the third maximum does not exist, return the **maximum** number*.

### Examples

**Example 1:**
* **Input:** `nums = [3,2,1]`
* **Output:** `1`
* **Explanation:** The first distinct maximum is 3, the second distinct maximum is 2, and the third distinct maximum is 1.

**Example 2:**
* **Input:** `nums = [1,2]`
* **Output:** `2`
* **Explanation:** The first distinct maximum is 2, and the second distinct maximum is 1. The third distinct maximum does not exist, so the maximum (2) is returned instead.

**Example 3:**
* **Input:** `nums = [2,2,3,1]`
* **Output:** `1`
* **Explanation:** The first distinct maximum is 3, the second distinct maximum is 2 (both 2's are counted together since they have the same value), and the third distinct maximum is 1.

### Constraints
* `1 <= nums.length <= 10^4`
* `-2^31 <= nums[i] <= 2^31 - 1`

---

## Approach & Intuition

Rather than sorting the array (which would work but costs $O(n \log n)$), this solution tracks the top three **distinct** values using a single linear pass, similar to how you'd manually keep track of "1st place, 2nd place, 3rd place" while scanning through a list of scores.

1. Maintain three trackers — `max`, `sec_max`, and `third_max` — all initialized to `LONG_MIN` (using `long long` to safely sentinel-value below any possible `int`, since `nums[i]` can be as low as `-2^31`).
2. For each number in `nums`, check three cascading conditions in order:
   * **If `nums[i] > max`:** A new overall maximum has been found. Before overwriting, "demote" the existing values down the chain: `third_max = sec_max`, `sec_max = max`, then `max = nums[i]`.
   * **Else if `nums[i] > sec_max` and `nums[i] != max`:** The number qualifies as a new second-highest **distinct** value (the `!= max` check prevents duplicates of the current max from being wrongly counted as the second max). Demote: `third_max = sec_max`, then `sec_max = nums[i]`.
   * **Else if `nums[i] > third_max` and it's distinct from both `max` and `sec_max`:** It becomes the new third-highest distinct value.
3. After the scan, handle the edge cases:
   * If the array has fewer than 3 elements (`size < 3`), a third distinct maximum can't exist by definition — return `max`.
   * If `third_max` still equals `sec_max`, `max`, or the initial sentinel `LONG_MIN`, it means fewer than 3 distinct values were ever found — return `max` instead.
   * Otherwise, `third_max` is valid and is returned directly.

The explicit `!=` checks at each stage are what enforce **distinctness** — without them, duplicate values (like two copies of the maximum) could incorrectly slide into the second or third slot.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — A single linear pass through `nums` is sufficient, with constant-time work per element.
* **Space Complexity:** $O(1)$ — Only three `long long` tracker variables (`max`, `sec_max`, `third_max`) are used, regardless of input size.

---

## Code Walkthrough

The solution implements a three-slot "podium" tracker using `long long` to avoid sentinel/overflow issues:
* `max`, `sec_max`, and `third_max` all start at `LONG_MIN`, guaranteeing any real `int` value will initially exceed them.
* The `for` loop checks `nums[i]` against the three trackers in strict priority order, cascading demotions whenever a higher value is found — this ensures the three trackers always reflect the current top three **distinct** values seen so far.
* The `!= max` and `!= max && != sec_max` guards in the second and third conditions are what prevent duplicate values from being miscounted as distinct ranks.
* After the loop, `if (size < 3) return max` handles arrays too small to have a third distinct value.
* The final check `if (third_max == sec_max || third_max == max || third_max == LONG_MIN)` catches the case where fewer than 3 distinct values existed in the array (so `third_max` never got properly updated), falling back to `max`.
* Otherwise, `third_max` holds a legitimately found third-distinct-maximum and is returned.