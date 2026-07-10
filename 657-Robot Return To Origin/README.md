# [657. Robot Return to Origin](https://leetcode.com/problems/robot-return-to-origin/description/)

## Difficulty
**Easy**

---

## Problem Statement

There is a robot starting at the position `(0, 0)`, the origin, on a 2D plane. Given a sequence of its moves, judge if this robot **ends up at `(0, 0)`** after it completes its moves.

You are given a string `moves` that represents the move sequence of the robot where `moves[i]` represents its `i`th move. Valid moves are `R` (right), `L` (left), `U` (up), and `D` (down). If the robot returns to the origin after it finishes all of its moves, return `true`. Otherwise, return `false`.

**Note:** The way that the robot is "facing" is irrelevant. `R` will always make the robot move to the right once, `L` will always make it move to the left once, etc. Also, assume that the magnitude of the robot's movement is the same for each move.

### Examples

**Example 1:**
* **Input:** `moves = "UD"`
* **Output:** `true`
* **Explanation:** The robot moves up once, and then down once. All moves have the same magnitude, so it ended up at the origin where it started. Therefore, we return `true`.

**Example 2:**
* **Input:** `moves = "LL"`
* **Output:** `false`
* **Explanation:** The robot moves left twice. It ends up two "moves" to the left of the origin. Therefore, we return `false`.

### Constraints
* `1 <= moves.length <= 2 * 10^4`
* `moves[i]` is either `'R'`, `'L'`, `'U'`, or `'D'`.

---

## Approach & Intuition

Since every move shifts the robot exactly one unit along either the horizontal or vertical axis, we just need to track the **net displacement** on each axis independently. If both the horizontal and vertical net displacement end up at zero, the robot must have returned to the origin — regardless of the specific order the moves happened in.

1. Initialize two counters, `row` and `col`, both at `0`, representing net vertical and horizontal displacement respectively.
2. Traverse the `moves` string (here done from the **last** character to the **first**, though the direction of traversal doesn't affect the outcome since we're just summing displacements):
   * `'R'` (right): increment `col`.
   * `'L'` (left): decrement `col`.
   * `'U'` (up): decrement `row`.
   * `'D'` (down, the final `else` case): increment `row`.
3. After processing every character, check if both `row == 0` and `col == 0`. If so, the robot's net movement cancels out entirely on both axes, meaning it's back at the origin — return `true`. Otherwise, return `false`.

Since addition is commutative, iterating forward or backward through `moves` produces the same final `row` and `col` totals — only the *net sum* of all moves matters, not the path taken to get there.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — A single pass through the `moves` string, with constant-time work per character.
* **Space Complexity:** $O(1)$ — Only two integer counters (`row`, `col`) are used, regardless of the length of `moves`.

---

## Code Walkthrough

The solution accumulates net displacement using a reverse scan of the string:
* `row` and `col` are initialized to `0`, and `size` is set to the last valid index of `moves`.
* The `while (size >= 0)` loop walks backward through the string, checking each character against the four possible move types:
  * `'R'` increments `col`; `'L'` decrements `col`.
  * `'U'` decrements `row`; the final `else` branch (implicitly `'D'`) increments `row`.
* `size--` moves the scan one character to the left after each iteration.
* Once the loop completes, `if (row == 0 && col == 0)` checks whether both axes cancelled out to zero, returning `true` if the robot is back at the origin and `false` otherwise.