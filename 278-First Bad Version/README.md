# [278. First Bad Version](https://leetcode.com/problems/first-bad-version/description/)

## Difficulty
**Easy**

---

## Problem Statement

You are a product manager and currently leading a team to develop a new product. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have `n` versions `[1, 2, ..., n]` and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API `bool isBadVersion(version)` which returns whether `version` is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

### Examples

**Example 1:**
* **Input:** `n = 5`, `bad = 4`
* **Output:** `4`
* **Explanation:** Calling `isBadVersion(3)` → `false`. Calling `isBadVersion(5)` → `true`. Calling `isBadVersion(4)` → `true`. Then `4` is the first bad version.

**Example 2:**
* **Input:** `n = 1`, `bad = 1`
* **Output:** `1`

### Constraints
* `1 <= bad <= n <= 2^31 - 1`

---

## Approach & Intuition

This is a classic **binary search on the answer** problem. The key observation is that the versions form a monotonic sequence: once a version is bad, every version after it is also bad. This "sorted" true/false pattern (`good, good, ..., good, bad, bad, ..., bad`) is exactly the structure binary search thrives on — we're not searching for a value in an array, but searching for the **boundary point** where the condition flips from `false` to `true`.

1. Initialize `low = 1` and `high = n`, representing the full range of possible versions.
2. Initialize `ans = 0` to keep track of the best candidate found so far for "first bad version."
3. While `low <= high`:
   * Compute `mid = low + (high - low) / 2` (this avoids potential integer overflow compared to `(low + high) / 2`, which matters given the constraint `n` can be as large as `2^31 - 1`).
   * Call `isBadVersion(mid)`:
     * If `mid` **is bad**, it's a *possible* answer, but there could be an earlier bad version. Record `ans = mid` and shrink the search space to the left half by setting `high = mid - 1`.
     * If `mid` **is not bad**, the first bad version must lie strictly to the right, so set `low = mid + 1`.
4. Once `low > high`, the search space is exhausted and `ans` holds the leftmost (first) bad version.

This narrows the search space by half on every iteration, converging on the exact boundary in logarithmic time.

---

## Complexity Analysis

* **Time Complexity:** $O(\log n)$ — Each iteration of the `while` loop halves the search range `[low, high]`, so the number of `isBadVersion` calls scales logarithmically with `n`.
* **Space Complexity:** $O(1)$ — Only a constant number of integer variables (`low`, `high`, `mid`, `ans`) are used, regardless of the input size.

---

## Code Walkthrough

The solution implements the boundary-search binary search pattern directly:
* `low` and `high` are initialized to `1` and `n`, covering the entire valid version range.
* `ans` acts as a running record of the best-known bad version, defaulting to `0`.
* Inside the loop, `mid` is computed using the overflow-safe formula `low + (high - low) / 2`.
* If `isBadVersion(mid)` is `true`, the code updates `ans = mid` and moves `high` to `mid - 1`, continuing to search the left half for an even earlier bad version.
* If `isBadVersion(mid)` is `false`, `low` is pushed to `mid + 1`, discarding the entire left (good) half.
* Once the loop terminates (`low > high`), `ans` correctly holds the first bad version and is returned.