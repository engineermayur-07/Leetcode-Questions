# [485. Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given a binary array `nums`, return *the maximum number of consecutive `1`'s in the array*.

### Examples

**Example 1:**
* **Input:** `nums = [1,1,0,1,1,1]`
* **Output:** `3`
* **Explanation:** The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

**Example 2:**
* **Input:** `nums = [1,0,1,1,0,1]`
* **Output:** `2`

### Constraints
* `1 <= nums.length <= 10^5`
* `nums[i]` is either `0` or `1`.

---

## Approach & Intuition

This is a straightforward **running counter** problem: we scan through the array once, keeping track of how many `1`s we've seen in a row, and whenever the streak breaks (a `0` is hit), we compare it against the best streak found so far before resetting.

This solution implements that idea using two markers, `left` and `right`, where their **difference** (`left - right`) represents the length of the current unbroken run of `1`s:

1. Initialize `ans = 0` (best streak found so far), and `left = 0`, `right = 0` (both starting at the same position, meaning a streak length of `0`).
2. Iterate through `nums`:
   * **If `nums[i] == 0`** (the streak is broken):
     * First, update `ans` with `left - right` — this captures the length of the run that just ended.
     * Then reset both `left` and `right` to the current index `i`, effectively zeroing out the counter (`left - right` becomes `0` again) so the next run starts fresh from this point.
   * **If `nums[i] == 1`** (the streak continues): simply increment `left`. Since `right` stays fixed at the last reset point, `left - right` naturally grows by one for every consecutive `1`, tracking the current streak's length.
3. After the loop ends, do **one final comparison** — `ans = max(ans, left - right)` — since the array might end in the middle of a streak that was never "closed off" by a trailing `0` (and therefore never got compared inside the loop).
4. Return `ans`.

The core trick is using `left - right` as an implicit counter for "how long is the current run of 1s," rather than literally tracking two ends of a sliding window — `right` acts as an anchor at the most recent reset point, while `left` climbs upward for every `1` encountered since then.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — A single pass through `nums`, with constant-time work per element.
* **Space Complexity:** $O(1)$ — Only a few integer variables (`ans`, `left`, `right`) are used, regardless of input size.

---

## Code Walkthrough

The solution tracks the current run length using the difference between two counters:
* `ans`, `left`, and `right` are all initialized to `0` at the start.
* The `for` loop checks each `nums[i]`:
  * On a `0`, `ans = max(ans, left - right)` locks in the length of the streak that just ended, and both `left` and `right` are reset to the current index `i`, restarting the count from zero for the next potential streak.
  * On a `1`, only `left++` executes — since `right` doesn't move, this steadily increases the gap `left - right`, which represents the current streak's length.
* After the loop, a final `ans = max(ans, left - right)` catches any streak that was still ongoing when the array ended (and thus never got evaluated inside the loop).
* The final `ans` — the longest streak of `1`s found across the whole array — is returned.