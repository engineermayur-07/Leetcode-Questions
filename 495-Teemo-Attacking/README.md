# [495. Teemo Attacking](https://leetcode.com/problems/teemo-attacking/description/)

## Difficulty
**Easy**

---

## Problem Statement

Our hero Teemo is attacking an enemy Ashe with poison attacks! When Teemo attacks Ashe, Ashe gets poisoned for a exactly `duration` seconds. More formally, an attack at second `t` will mean Ashe is poisoned during the **inclusive** time interval `[t, t + duration - 1]`. If Teemo attacks again **before** the poison effect ends, the timer for it is **reset**, and the poison effect will end `duration` seconds after the new attack.

You are given a **non-decreasing** integer array `timeSeries`, where `timeSeries[i]` denotes that Teemo attacks Ashe at second `timeSeries[i]`, and an integer `duration`.

Return *the total number of seconds that Ashe is poisoned*.

### Examples

**Example 1:**
* **Input:** `timeSeries = [1,4]`, `duration = 2`
* **Output:** `4`
* **Explanation:** Teemo's attacks on Ashe happen at seconds `1` and `4` with a duration of `2` seconds. The poisoning time is `[1,2]` and `[4,5]`, which totals 4 seconds.

**Example 2:**
* **Input:** `timeSeries = [1,2]`, `duration = 2`
* **Output:** `3`
* **Explanation:** Teemo's attacks on Ashe happen at seconds `1` and `2` with a duration of `2` seconds. The poisoning time is `[1,2]` and `[2,3]`, but the poison effect is extended at second `2`, so the poisoning time is `[1,3]`, which totals 3 seconds.

### Constraints
* `1 <= timeSeries.length <= 10^4`
* `0 <= timeSeries[i]`
* `timeSeries` is sorted in **non-decreasing** order.
* `1 <= duration <= 10^7`

---

## Approach & Intuition

Since `timeSeries` is already sorted, we can process attacks in order and reason about each pair of **consecutive** attacks independently, rather than tracking every second Ashe is poisoned.

For each attack, it contributes `duration` seconds of poison — **unless** the next attack lands before the current poison window would have ended, in which case the current attack's contribution gets cut short (overlap), and only the gap until the next attack actually counts as "new" poison time.

1. **Edge case:** If `duration == 0`, there's no poison effect at all — return `0` immediately.
2. Initialize `ans = duration`, accounting for the **first** attack's full poison duration up front (there's no previous attack to compare it against).
3. Loop through the remaining attacks, from index `1` to `n-1`, comparing each attack to the one right before it:
   * Compute the gap: `timeSeries[i] - timeSeries[i-1]`.
   * **If the gap is `<= duration`:** the new attack lands *before* the previous poison effect would have expired, so the timer resets early. Only the **gap itself** (not the full `duration`) is added to `ans`, since the overlapping portion was already counted by the previous attack.
   * **Else (gap `> duration`):** the previous poison effect fully expired before the next attack. The new attack contributes its **entire** `duration` to `ans`, with no overlap to worry about.
4. Return `ans`, the total accumulated poisoned seconds.

This avoids simulating second-by-second poison status (which could be up to `10^7` per attack) and instead reasons purely about the relationships between consecutive attack timestamps — keeping the whole computation linear in the number of attacks.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — A single pass through `timeSeries`, comparing each element only to its immediate predecessor.
* **Space Complexity:** $O(1)$ — Only a running total (`ans`) and loop variables are used; no auxiliary arrays are needed.

---

## Code Walkthrough

The solution accumulates poisoned time by comparing consecutive attack gaps:
* `n` stores the number of attacks, and the early `if (duration == 0) return 0` guard handles the trivial no-poison case.
* `ans` is initialized to `duration`, pre-accounting for the first attack's full poison window.
* The `for` loop starts at index `1`, comparing `timeSeries[i]` against `timeSeries[i-1]` on each iteration.
* `if (timeSeries[i] - timeSeries[i-1] <= duration)` detects an overlapping/reset case — only the gap (`timeSeries[i] - timeSeries[i-1]`) is added to `ans`, since the rest was already counted by the previous attack's contribution.
* The `else` branch handles a fully expired previous poison window, adding the full `duration` for the new attack.
* After the loop, `ans` holds the total number of seconds Ashe was poisoned across all attacks, and is returned.