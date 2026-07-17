# [128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/description/)

## Difficulty
**Medium**

---

## Problem Statement

Given an unsorted array of integers `nums`, return *the length of the longest consecutive elements sequence*.

You must write an algorithm that runs in `O(n)` time.

### Examples

**Example 1:**
* **Input:** `nums = [100,4,200,1,3,2]`
* **Output:** `4`
* **Explanation:** The longest consecutive elements sequence is `[1, 2, 3, 4]`. Therefore its length is 4.

**Example 2:**
* **Input:** `nums = [0,3,7,8,2,5,4,6,1]`
* **Output:** `9`

### Constraints
* `0 <= nums.length <= 10^5`
* `-10^9 <= nums[i] <= 10^9`

---

## Approach & Intuition

Two solutions are included here — the optimal $O(n)$ **hash set** approach, and a simpler-to-reason-about **sorting** approach that trades time complexity for conceptual simplicity.

### Approach 1: Hash Set (Optimal, O(n))

To hit the required $O(n)$, this approach uses a **hash set** for $O(1)$ average-case lookups, combined with a key trick: only ever start counting a sequence from its **true starting point**.

1. **Edge case:** If `nums` is empty, return `0` immediately.
2. Load all elements of `nums` into an `unordered_set`, which automatically removes duplicates and gives fast $O(1)$ average lookups.
3. Iterate over every number `i` in the set:
   * **Check if `i` is the start of a sequence:** look up whether `i - 1` exists in the set. If it **does**, `i` is *not* the start of its sequence — skip it, since it will be correctly counted when we reach its actual starting number.
   * **If `i - 1` does NOT exist**, `i` is confirmed to be the **beginning** of a run. Start counting forward: initialize `current_length = 1` and a step counter `j = 1`, then repeatedly check whether `i + j` exists in the set, incrementing both `current_length` and `j` on each match.
   * Once the chain breaks, update `longest = max(longest, current_length)`.
4. Return `longest` after checking every number.

The critical optimization is the `set.find(i - 1) == set.end()` check — without it, the same sequence would be redundantly re-counted from every one of its members. By only expanding forward from confirmed **sequence starts**, each number is visited by the inner loop at most once overall, keeping the total work linear.

### Approach 2: Sort First (Simpler, O(n log n))

If a sequence's numbers are sorted, consecutive elements of the sequence become **adjacent** in the sorted array, so a single linear scan can then measure run lengths directly:

1. Sort `nums` in ascending order.
2. Initialize `longest = 1` and `current_length = 1` (accounting for the first element being a trivial run of length 1 on its own).
3. Iterate from index `1` to the end:
   * **If `nums[i] == nums[i-1]`:** it's a duplicate — `continue` without affecting the current run, since duplicates don't extend or break a consecutive sequence.
   * **Else if `nums[i-1] + 1 == nums[i]`:** the current element continues the consecutive run — increment `current_length` and update `longest` if this is a new best.
   * **Otherwise:** the run has broken — reset `current_length` back to `1` to start counting a fresh run from this element.
4. Return `longest`.

This is simpler to reason about since sorting turns "find consecutive runs" into "find equal-or-adjacent neighbors," but it costs the $O(n \log n)$ of sorting instead of the optimal $O(n)$.

---

## Complexity Analysis

### Approach 1: Hash Set
* **Time Complexity:** $O(n)$ — Every element is visited by the inner `while` loop at most once overall (only sequence-starts trigger expansion), so the total work across all iterations remains linear.
* **Space Complexity:** $O(n)$ — The `unordered_set` stores up to `n` elements.

### Approach 2: Sorting
* **Time Complexity:** $O(n \log n)$ — Dominated by the initial sort; the subsequent linear scan is $O(n)$.
* **Space Complexity:** $O(1)$ **extra space** (excluding the space used internally by the sort), since the array is sorted in place and only a couple of counters are maintained.

---

## Code Walkthrough

**Approach 1 (`longestConsecutive` — hash set):**
* The initial `if (nums.size() == 0) return 0` guard handles the empty-array case.
* `set` is built directly from `nums` via the range constructor, deduplicating values.
* The `for (int i : set)` loop checks `set.find(i-1) == set.end()` to identify sequence starts.
* For each confirmed start, the inner `while (set.find(i + j) != set.end())` loop extends the run forward, incrementing `current_length` and `j` together.
* `longest = max(longest, current_length)` updates the best answer after each sequence is fully measured, and the final `longest` is returned.

**Approach 2 (`longestConsecutive` — sorting):**
* `nums` is sorted first via `sort(nums.begin(), nums.end())`.
* `longest` and `current_length` both start at `1`.
* The `for` loop compares each element to its predecessor: `nums[i] == nums[i-1]` skips duplicates via `continue`; `nums[i-1] + 1 == nums[i]` extends the current run and updates `longest`; any other case resets `current_length` back to `1`.
* After the loop finishes scanning the sorted array, `longest` holds the length of the longest consecutive sequence and is returned.