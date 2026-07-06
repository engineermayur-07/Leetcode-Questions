# [54. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/description/)

## Difficulty
**Medium**

---

## Problem Statement

Given an `m x n` matrix, return *all elements of the matrix in spiral order*.

### Examples

**Example 1:**
* **Input:** `matrix = [[1,2,3],[4,5,6],[7,8,9]]`
* **Output:** `[1,2,3,6,9,8,7,4,5]`

**Example 2:**
* **Input:** `matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]`
* **Output:** `[1,2,3,4,8,12,11,10,9,5,6,7]`

### Constraints
* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 10`
* `-100 <= matrix[i][j] <= 100`

---

## Approach & Intuition

The spiral traversal can be thought of as repeatedly peeling off the **outer boundary layer** of the matrix — first the top row, then the right column, then the bottom row (reversed), then the left column (reversed) — and shrinking the boundary inward after each layer, until nothing is left to traverse.

This is done using four boundary pointers: `top`, `bottom`, `left`, and `right`, which define the current "unvisited" rectangular region:

1. Initialize `top = 0`, `bottom = rows - 1`, `left = 0`, `right = cols - 1`, and a `count` index for filling the result array.
2. While the current boundary region is still valid (`bottom >= top && right >= left`), traverse one full "ring" in four steps:
   * **Top row (left → right):** Walk across `matrix[top][left..right]`, then increment `top` (this row is now consumed).
   * **Right column (top → bottom):** Walk down `matrix[top..bottom][right]`, then decrement `right`.
   * **Bottom row (right → left):** *Only if `top <= bottom` still holds* (guards against re-traversing a row already consumed by the top-row step in a single-row matrix) — walk across `matrix[bottom][right..left]` in reverse, then decrement `bottom`.
   * **Left column (bottom → top):** *Only if `left <= right` still holds* (guards against re-traversing a column in a single-column matrix) — walk up `matrix[top..bottom][left]` in reverse, then increment `left`.
3. Repeat this shrinking process until the boundaries cross, at which point every element has been visited exactly once.

The two guard conditions (`top <= bottom` and `left <= right`) before the bottom-row and left-column steps are essential — without them, a matrix with a single remaining row or column would have its elements double-counted, since the top-row or right-column step would have already visited them.

---

## Complexity Analysis

* **Time Complexity:** $O(rows \times cols)$ — Every element in the matrix is visited exactly once across all the spiral layers.
* **Space Complexity:** $O(1)$ **extra space** — Aside from the output array (which is required for the result and not counted as auxiliary space), only a fixed number of pointer variables (`top`, `bottom`, `left`, `right`, `count`) are used.

---

## Code Walkthrough

The solution directly implements the four-directional boundary-shrinking traversal:
* `rows` and `cols` capture the matrix dimensions, and `array` is pre-sized to `rows * cols` to hold the final spiral-ordered result.
* `top`, `bottom`, `left`, `right` are initialized to the outermost boundary of the matrix, and `count` tracks the next insertion index into `array`.
* The outer `while (bottom >= top && right >= left)` loop continues as long as there's an unvisited rectangular region remaining.
* The first inner `for` loop walks the current top row left-to-right, then `top++` shrinks the boundary downward.
* The second inner `for` loop walks the current right column top-to-bottom, then `right--` shrinks the boundary leftward.
* The `if (top <= bottom)` guarded loop walks the current bottom row right-to-left (only if a distinct bottom row still exists), then `bottom--`.
* The `if (left <= right)` guarded loop walks the current left column bottom-to-top (only if a distinct left column still exists), then `left++`.
* Once the boundaries fully cross, the loop exits and the fully populated `array` is returned.