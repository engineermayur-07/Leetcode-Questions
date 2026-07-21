# [217. Contains Duplicate](https://leetcode.com/problems/contains-duplicate/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given an integer array `nums`, return `true` *if any value appears **at least twice** in the array, and return `false` if every element is distinct*.

### Examples

**Example 1:**
* **Input:** `nums = [1,2,3,1]`
* **Output:** `true`

**Example 2:**
* **Input:** `nums = [1,2,3,4]`
* **Output:** `false`

**Example 3:**
* **Input:** `nums = [1,1,1,3,3,4,3,2,4,2]`
* **Output:** `true`

### Constraints
* `1 <= nums.length <= 10^5`
* `-10^9 <= nums[i] <= 10^9`

---

## Approach & Intuition

Three solutions are included here, going from an early-exit hash-set scan, to a sort-based comparison, to a compact one-liner — all reflecting different tradeoffs between speed, extra memory, and code brevity.

### Approach 1: Hash Set with Early Exit (Optimal)

The most direct way to detect a duplicate is to remember every value seen so far, and check each new value against that memory before adding it:

1. Initialize an empty `unordered_set<int> s`.
2. Iterate through `nums`:
   * If the current number already exists in `s` (`s.count(num) > 0`), a duplicate has been found — return `true` immediately, without scanning the rest of the array.
   * Otherwise, insert the number into `s` and continue.
3. If the loop finishes without ever returning `true`, no duplicates exist — return `false`.

This approach can **short-circuit** as soon as the first duplicate is found, making it the fastest in practice when duplicates appear early.

### Approach 2: Sort and Compare Adjacent Elements

Once sorted, any duplicate values are guaranteed to sit **next to each other**, so a duplicate check reduces to comparing each element with its immediate neighbor:

1. Sort `nums` in ascending order.
2. Loop through the array, comparing `nums[i]` to `nums[i+1]` for every adjacent pair.
3. If any pair matches, return `true` immediately. If no match is found by the end, return `false`.

This trades the extra memory of a hash set for the (typically larger) time cost of sorting, and modifies the input array in the process.

### Approach 3: One-Liner Using Set Size Comparison

Since a set can never contain duplicate values, converting `nums` into a set and comparing its size to the original array's size tells us instantly whether any duplicates existed:

1. Build an `unordered_set<int>` directly from `nums` using its range constructor — this automatically discards duplicate values.
2. Compare the resulting set's `.size()` to `nums.size()`. If the set is **smaller**, at least one duplicate must have been collapsed away — return `true` (via the comparison result); otherwise return `false`.

This is the most concise of the three, expressed as a single return statement, but unlike Approach 1, it can't short-circuit early — it must always build the entire set before comparing.

---

## Complexity Analysis

### Approach 1: Hash Set with Early Exit
* **Time Complexity:** $O(n)$ average case — Each insertion and lookup in an `unordered_set` is $O(1)$ on average; the loop can also exit early on the first duplicate found.
* **Space Complexity:** $O(n)$ — The set may grow to hold up to `n` distinct elements in the worst case (no duplicates).

### Approach 2: Sort and Compare
* **Time Complexity:** $O(n \log n)$ — Dominated by the sorting step; the subsequent adjacent-comparison scan is $O(n)$.
* **Space Complexity:** $O(1)$ **extra space** (excluding space used internally by the sort) — The array is sorted in place, and only a loop index is used.

### Approach 3: Set Size Comparison
* **Time Complexity:** $O(n)$ average case — Building the set from `nums` costs $O(n)$ on average, same as Approach 1, but without the ability to exit early.
* **Space Complexity:** $O(n)$ — A full set of up to `n` elements is constructed before the size comparison.

---

## Code Walkthrough

**Approach 1 (`containsDuplicate` — hash set):**
* `s` is an empty `unordered_set<int>` used to track seen values.
* The `for (int num : nums)` loop checks `s.count(num) > 0` first; a positive count means `num` was already inserted earlier, triggering an immediate `return true`.
* If the count is `0`, `s.insert(num)` records this value before moving to the next.
* If the loop completes without a match, `false` is returned.

**Approach 2 (`containsDuplicate` — sort and compare):**
* `sort(nums.begin(), nums.end())` sorts the array in place first.
* The `for` loop runs from `0` to `nums.size() - 2`, comparing `nums[i]` to `nums[i+1]` — since duplicates are now adjacent after sorting, a match here confirms a duplicate exists, returning `true`.
* If no adjacent match is found across the whole array, `false` is returned.

**Approach 3 (`containsDuplicate` — one-liner):**
* `unordered_set<int>(nums.begin(), nums.end())` constructs a temporary set directly from the array's contents, deduplicating as it builds.
* `.size() < nums.size()` compares the deduplicated count to the original count — if smaller, duplicates were collapsed away, so the comparison (and thus the function) returns `true`; otherwise it returns `false`.