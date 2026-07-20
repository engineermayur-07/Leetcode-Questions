# [15. 3Sum](https://leetcode.com/problems/3sum/description/)

## Difficulty
**Medium**

---

## Problem Statement

Given an integer array `nums`, return *all the triplets* `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

### Examples

**Example 1:**
* **Input:** `nums = [-1,0,1,2,-1,-4]`
* **Output:** `[[-1,-1,2],[-1,0,1]]`
* **Explanation:** `nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0`. `nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0`. `nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0`. The distinct triplets are `[-1,0,1]` and `[-1,-1,2]`. Notice that the order of the output and the order of the triplets does not matter.

**Example 2:**
* **Input:** `nums = [0,1,1]`
* **Output:** `[]`
* **Explanation:** The only possible triplet does not sum up to 0.

**Example 3:**
* **Input:** `nums = [0,0,0]`
* **Output:** `[[0,0,0]]`
* **Explanation:** The only possible triplet sums up to 0.

### Constraints
* `3 <= nums.length <= 3000`
* `-10^5 <= nums[i] <= 10^5`

---

## Approach & Intuition

Brute-forcing all triplets would take $O(n^3)$. Instead, this solution **sorts the array first**, which unlocks two-pointer scanning: once sorted, for a fixed first element, finding a pair that sums to a target becomes the well-known **two-pointer** technique (used similarly in problems like "Two Sum II").

1. **Sort `nums`** in ascending order — this is what makes two-pointer narrowing possible, and also makes duplicate-skipping straightforward since duplicates end up adjacent.
2. Iterate `i` from `0` to `n-1`, treating `nums[i]` as the **fixed first element** of the triplet:
   * **Skip duplicate first elements:** if `i > 0 && nums[i] == nums[i-1]`, this same value was already fully explored as the first element in a previous iteration — `continue` to avoid generating duplicate triplets.
   * Set up two pointers: `left = i + 1` (just after `i`) and `right = n - 1` (the end of the array).
   * While `left < right`:
     * Compute `sum = nums[i] + nums[left] + nums[right]`.
     * **If `sum == 0`:** a valid triplet is found — push `{nums[i], nums[left], nums[right]}` into `ans`. Then, skip over any duplicate values at `left` and `right` (using inner `while` loops) so the same triplet isn't re-added, and finally move both pointers inward (`left++`, `right--`) to look for the next distinct pair.
     * **If `sum < 0`:** the total is too small, so increase it by moving `left` rightward (toward larger values).
     * **If `sum > 0`:** the total is too large, so decrease it by moving `right` leftward (toward smaller values).
3. After all `i` values have been processed, `ans` contains every unique triplet summing to zero.

Sorting is what makes both the two-pointer narrowing *and* the duplicate-skipping logic work cleanly — since equal values are guaranteed to be adjacent after sorting, checking `nums[i] == nums[i-1]` (or the equivalent for `left`/`right`) is enough to detect and skip duplicates without needing a hash set.

---

## Complexity Analysis

* **Time Complexity:** $O(n^2)$ — Sorting costs $O(n \log n)$, but the dominant cost is the outer loop over `i` combined with the inner two-pointer scan, which together examine each pair of `(left, right)` positions in $O(n)$ per fixed `i`, giving $O(n^2)$ overall.
* **Space Complexity:** $O(1)$ **extra space** (excluding the output and the space used by the sort) — Only pointer variables are used for the scanning logic; the result vector `ans` is required for the output itself.

---

## Code Walkthrough

The solution combines sorting, an outer fixed-pointer loop, and an inner two-pointer scan:
* `nums` is sorted in place at the start via `sort(nums.begin(), nums.end())`.
* The outer `for (i = 0; i < n; i++)` loop fixes the first element of each candidate triplet, with `if (i > 0 && nums[i] == nums[i-1]) continue` skipping repeated first elements.
* `left` and `right` are initialized to bracket the remaining unsorted portion of the array for each `i`.
* Inside the `while (left < right)` loop, `sum` is computed fresh each iteration:
  * On a match (`sum == 0`), the triplet is pushed into `ans`, and the two inner `while` loops (`nums[left] == nums[left+1]` and `nums[right] == nums[right-1]`) advance past any duplicate values before the outer `left++`/`right--` step, ensuring no duplicate triplet is added.
  * On `sum < 0`, `left++` moves toward larger values to increase the sum.
  * On `sum > 0`, `right--` moves toward smaller values to decrease the sum.
* Once the outer loop completes, `ans` — containing all unique zero-sum triplets — is returned.