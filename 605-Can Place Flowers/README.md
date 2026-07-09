# [605. Can Place Flowers](https://leetcode.com/problems/can-place-flowers/description/)

## Difficulty
**Easy**

---

## Problem Statement

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers **cannot be planted in adjacent plots**. Given an integer array `flowerbed` containing `0`'s and `1`'s, where `0` means empty and `1` means not empty, and an integer `n`, return *if `n` new flowers can be planted in the `flowerbed` without violating the no-adjacent-flowers rule*.

### Examples

**Example 1:**
* **Input:** `flowerbed = [1,0,0,0,1]`, `n = 1`
* **Output:** `true`

**Example 2:**
* **Input:** `flowerbed = [1,0,0,0,1]`, `n = 2`
* **Output:** `false`

### Constraints
* `1 <= flowerbed.length <= 2 * 10^4`
* `flowerbed[i]` is `0` or `1`.
* There are no two adjacent flowers in `flowerbed`.
* `0 <= n <= flowerbed.length`

---

## Approach & Intuition

This is a classic **greedy** problem: to maximize the number of flowers planted, we should plant one as soon as we find a valid empty spot, rather than trying to be strategic about which empty spot to pick. Planting greedily at the earliest opportunity never hurts, because a plot with `0`s on both sides remains just as plantable later — there's no benefit to skipping it.

1. Iterate through each plot `i` in `flowerbed`.
2. **Early exit:** If `n` has already reached `0` (or below) at the start of an iteration, we've already planted enough — return `true` immediately without checking further.
3. For each plot, check if it's a candidate for planting:
   * The plot itself must be empty: `flowerbed[i] == 0`.
   * The **left neighbor** must not have a flower — this is true if either `i == 0` (no left neighbor exists, so treat it as satisfied) or `flowerbed[i-1] == 0`.
   * The **right neighbor** must not have a flower — true if either `i == size - 1` (no right neighbor exists) or `flowerbed[i+1] == 0`.
4. If all three conditions hold, plant a flower here: set `flowerbed[i] = 1` and decrement `n`. This also automatically ensures no future adjacent plot can be planted next to this one, since the check on the next iteration will now see a `1` immediately to its left.
5. After scanning every plot, if `n` has been brought down to exactly `0`, all required flowers were successfully placed — return `true`. Otherwise, return `false`.

The boundary checks (`i == 0` and `i == size - 1`) are what let the same single condition handle the first and last plots without needing special-cased logic outside the loop.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — Where $n$ is the length of `flowerbed`. A single linear pass is made through the array.
* **Space Complexity:** $O(1)$ — The flowerbed is modified in place (no copy is made), and only a couple of integer variables are used.

---

## Code Walkthrough

The solution greedily plants flowers in a single forward pass:
* `size` stores the flowerbed length, used for the loop bound and the right-boundary check.
* The `for` loop's first line, `if (n <= 0) return true`, short-circuits as soon as enough flowers have been planted, avoiding unnecessary further iterations.
* The nested `if (flowerbed[i] == 0)` check filters to only empty plots.
* The compound condition `(i == 0 || flowerbed[i-1] == 0) && (i == size - 1 || flowerbed[i+1] == 0)` verifies both neighbors (or the array boundary) are safe for planting.
* When a plot passes all checks, `flowerbed[i] = 1` plants the flower directly in the input array (marking it as occupied for subsequent boundary checks), and `n--` reduces the remaining count needed.
* After the loop, `if (n == 0) return true` confirms all requested flowers were placed; otherwise `false` is returned.