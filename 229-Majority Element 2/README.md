# [229. Majority Element II](https://leetcode.com/problems/majority-element-ii/description/)

## Difficulty
**Medium**

---

## Problem Statement

Given an integer array of size `n`, find all elements that appear more than `⌊n / 3⌋` times.

### Examples

**Example 1:**
* **Input:** `nums = [3,2,3]`
* **Output:** `[3]`

**Example 2:**
* **Input:** `nums = [1]`
* **Output:** `[1]`

**Example 3:**
* **Input:** `nums = [1,2]`
* **Output:** `[1,2]`

### Constraints
* `1 <= nums.length <= 5 * 10^4`
* `-10^9 <= nums[i] <= 10^9`

---

## Approach & Intuition

This is the natural extension of the **Boyer-Moore Voting Algorithm** (used for the "more than `n/2`" majority element problem) to the "more than `n/3`" case. The key mathematical insight: **at most 2 elements** can ever appear more than `n/3` times in an array (since 3 elements each appearing more than `n/3` times would require more than `n` total elements). So instead of tracking one candidate with one vote counter, we track **two** candidates with two independent vote counters.

### Phase 1: Find Up to Two Candidates

1. Initialize two candidate slots (`candidate1`, `candidate2`, both starting at `INT_MIN` as sentinel placeholders) and two vote counters (`count1`, `count2`, both starting at `0`).
2. For each number `i` in `nums`, check conditions in this priority order:
   * **If `i` matches `candidate1`:** it supports the first candidate — increment `count1`.
   * **Else if `i` matches `candidate2`:** it supports the second candidate — increment `count2`.
   * **Else if `count1 == 0`:** the first slot is currently empty (fully voted out) — claim it for `i`, setting `candidate1 = i` and `count1 = 1`.
   * **Else if `count2 == 0`:** the second slot is empty — claim it for `i` similarly.
   * **Else (both slots occupied by different values, and `i` matches neither):** this number opposes both current candidates — decrement **both** `count1` and `count2`.
3. After this pass, `candidate1` and `candidate2` hold the only two values that *could possibly* appear more than `n/3` times (though this isn't guaranteed yet — they're just the surviving candidates from the voting process).

### Phase 2: Verify the Candidates

Since Boyer-Moore only identifies *potential* majority candidates (not confirmed ones) when there isn't a guaranteed majority element, a second pass is required to verify their actual counts:

1. Reset `count1 = 0` and `count2 = 0`.
2. Loop through `nums` again, incrementing `count1` for every match with `candidate1`, and `count2` for every match with `candidate2`.
3. Only include `candidate1` in the result if its true count exceeds `n/3`, and similarly for `candidate2`.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — Two separate linear passes through `nums`: one for the voting phase, one for the verification phase.
* **Space Complexity:** $O(1)$ — Only a fixed number of integer variables (`count1`, `count2`, `candidate1`, `candidate2`) are used, plus the output vector which holds at most 2 elements.

---

## Code Walkthrough

The solution implements the extended Boyer-Moore algorithm in two clearly separated passes:
* `candidate1`/`candidate2` start at `INT_MIN`, and `count1`/`count2` start at `0`.
* The first `for (int i : nums)` loop applies the priority-ordered checks: matching an existing candidate increments its counter; an empty slot (`count == 0`) is claimed by the current number; and if neither applies, both counters are decremented together (representing a "vote against both").
* `count1` and `count2` are then explicitly reset to `0` before the second `for` loop begins.
* The second loop simply tallies the **actual** occurrences of `candidate1` and `candidate2` across the whole array.
* Finally, `candidate1` is added to `result` only `if (count1 > n/3)`, and likewise for `candidate2` — ensuring only genuinely qualifying elements make it into the final answer.