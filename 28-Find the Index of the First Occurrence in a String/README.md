# [28. Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given two strings `needle` and `haystack`, return *the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`*.

### Examples

**Example 1:**
* **Input:** `haystack = "sadbutsad"`, `needle = "sad"`
* **Output:** `0`
* **Explanation:** `"sad"` occurs at index 0 and 6. The first occurrence is at index 0, so we return 0.

**Example 2:**
* **Input:** `haystack = "leetcode"`, `needle = "leeto"`
* **Output:** `-1`
* **Explanation:** `"leeto"` did not occur in `"leetcode"`, so we return -1.

### Constraints
* `1 <= haystack.length, needle.length <= 10^4`
* `haystack` and `needle` consist of only lowercase English characters.

---

## Approach & Intuition

This problem is essentially asking us to implement the functionality of a built-in substring search — find where `needle` first starts inside `haystack`, if it exists at all.

Since C++'s STL already provides an optimized member function for exactly this purpose, the approach leans on that rather than manually rolling a pattern-matching algorithm (like KMP):

1. Call `haystack.find(needle)`, which scans `haystack` and returns the index of the first character of the first match.
2. If no match exists, `find()` returns the special sentinel value `string::npos` (the largest possible `size_t` value).
3. Compare the result against `string::npos`. If they're equal, no occurrence exists, so return `-1`.
4. Otherwise, return the matched index directly, since `find()` already gives the leftmost occurrence.

This keeps the logic minimal and relies on the standard library's internal implementation to do the heavy lifting.

---

## Complexity Analysis

* **Time Complexity:** $O(N \times M)$ — Where $N$ is the length of `haystack` and $M$ is the length of `needle`. In the worst case, the underlying `find()` implementation may need to check every starting position in `haystack` against `needle`.
* **Space Complexity:** $O(1)$ — No auxiliary data structures are used; only a few primitive variables are maintained.

---

## Code Walkthrough

The solution is a thin wrapper around `std::string::find`:
* `size_hay` and `size_needle` store the lengths of `haystack` and `needle` respectively (captured but not directly used in the logic).
* `size_t index = haystack.find(needle)` performs the substring search and stores the result.
* The `if` check compares `index` against `string::npos` to detect a failed search, returning `-1` in that case.
* If a match was found, `index` (implicitly converted to `int`) is returned as the first occurrence position.