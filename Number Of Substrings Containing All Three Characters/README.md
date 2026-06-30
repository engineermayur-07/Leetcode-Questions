# [1358. Number of Substrings Containing All Three Characters](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/)

## Difficulty
**Medium**

---

## Problem Statement

Given a string `s` consisting only of characters *a*, *b* and *c*.

Return the number of substrings containing **at least** one occurrence of all these characters *a*, *b* and *c*.

### Examples

**Example 1:**
* **Input:** `s = "abcabc"`
* **Output:** `10`
* **Explanation:** The substrings containing at least one occurrence of the characters *a*, *b* and *c* are `"abc"`, `"abca"`, `"abcab"`, `"abcabc"`, `"bca"`, `"bcab"`, `"bcabc"`, `"cab"`, `"cabc"` and `"abc"` (again, starting from the second index).

**Example 2:**
* **Input:** `s = "aaacb"`
* **Output:** `3`
* **Explanation:** The substrings containing at least one occurrence of the characters *a*, *b* and *c* are `"aaacb"`, `"aacb"` and `"acb"`.

**Example 3:**
* **Input:** `s = "abc"`
* **Output:** `1`

### Constraints
* `3 <= s.length <= 5 * 10^4`
* `s` strictly contains characters *a*, *b* and *c* only.

---

## Approach & Intuition

A naive approach would look at every possible substring, which takes $O(n^2)$ time and results in a *Time Limit Exceeded (TLE)* error due to the $5 \times 10^4$ constraint. Instead, this solution uses a brilliant, optimized **Sliding Window / Tracking Pointers** approach that resolves it in a single pass.

### The Core Idea:
As we iterate through the string with a pointer `i`, we treat `i` as the **end** position of our valid substrings. 

1. We keep track of the **most recent (last seen) index** of each character (`'a'`, `'b'`, and `'c'`) using `lastA`, `lastb`, and `lastC`.
2. Once we have seen all three characters at least once (i.e., none of the tracking variables are `-1`), we can find the start of the smallest valid substring ending at `i`.
3. The boundary of this valid window is determined by the character that appeared furthest to the left. We find this using `min(lastA, min(lastb, lastC))`.
4. **The Counting Trick:** If the furthest-left character of our valid set sits at index `min_idx`, then *any* substring starting from index `0` up to `min_idx` and ending at `i` is guaranteed to contain all three characters. Therefore, the number of valid substrings ending exactly at index `i` is exactly `min_idx + 1`.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — We iterate through the string `s` exactly once, performing constant time $O(1)$ operations at each character.
* **Space Complexity:** $O(1)$ — Only three primitive integer variables (`lastA`, `lastb`, `lastC`) are stored to track character positions.

---

## Code Walkthrough

The C++ solution efficiently implements this tracking system:
* The pointers `lastA`, `lastb`, and `lastC` are initialized to `-1` to represent that no characters have been processed yet.
* For each index `i`, the corresponding character tracking variable is updated to `i`.
* An `if` statement safely blocks tracking until all three elements have entered the stream.
* `min(minAB, lastC) + 1` mathematically adds all valid sub-segments ending at `i` directly to the `count` accumulator in a single step.