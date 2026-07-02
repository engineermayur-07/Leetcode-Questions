# [374. Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/description/)

## Difficulty
**Easy**

---

## Problem Statement

We are playing the Guess Game. The game is as follows:

I pick a number from `1` to `n`. You have to guess which number I picked.

Every time you guess wrong, I tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API `int guess(int num)`, which returns three possible results:
* `-1`: Your guess is higher than the number I picked (i.e. `num > pick`).
* `1`: Your guess is lower than the number I picked (i.e. `num < pick`).
* `0`: Your guess is equal to the number I picked (i.e. `num == pick`).

Return *the number that I picked*.

### Examples

**Example 1:**
* **Input:** `n = 10`, `pick = 6`
* **Output:** `6`

**Example 2:**
* **Input:** `n = 1`, `pick = 1`
* **Output:** `1`

**Example 3:**
* **Input:** `n = 2`, `pick = 1`
* **Output:** `1`

### Constraints
* `1 <= n <= 2^31 - 1`
* `1 <= pick <= n`

---

## Approach & Intuition

The numbers `1` to `n` form an implicit sorted sequence, and the `guess()` API acts as a comparator that tells us which direction the target lies in relative to our current guess. That's the standard setup for **binary search**: instead of scanning linearly, we repeatedly guess the midpoint and use the feedback to eliminate half of the remaining range each time.

1. Initialize `low = 1` and `high = n` to represent the full candidate range.
2. While `low <= high`:
   * Compute `mid = low + (high - low) / 2` (overflow-safe, important since `n` can be as large as `2^31 - 1`).
   * Call `guess(mid)` and inspect the return value:
     * If it returns `0`, `mid` is exactly the picked number — return it immediately.
     * If it returns `1`, the picked number is greater than `mid`, so discard the left half by setting `low = mid + 1`.
     * If it returns `-1`, the picked number is smaller than `mid`, so discard the right half by setting `high = mid - 1`.
3. The loop is guaranteed to find the exact match before `low` and `high` cross, since `pick` always lies within the current `[low, high]` bounds.

---

## Complexity Analysis

* **Time Complexity:** $O(\log n)$ — Each call to `guess()` halves the remaining search space, so the number of API calls grows logarithmically with `n`.
* **Space Complexity:** $O(1)$ — Only a fixed number of integer variables (`low`, `high`, `mid`) are used.

---

## Code Walkthrough

The solution follows the standard binary search template, adapted to the three-way feedback from `guess()`:
* `low` and `high` are initialized to `1` and `n`, bounding the search space.
* `mid` is recomputed each iteration using the overflow-safe midpoint formula.
* `guess_return_value` stores the result of `guess(mid)` so it's only queried once per iteration.
* The three branches map directly to the API's semantics: `0` → exact match, return `mid`; `1` → picked number is lower than expected(higher), move `low` up; `-1` → move `high` down.
* If the loop somehow exits without finding a match (which shouldn't happen given valid input), `0` is returned as a fallback.