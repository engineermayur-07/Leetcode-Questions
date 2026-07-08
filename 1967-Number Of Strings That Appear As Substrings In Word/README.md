# [1967. Number of Strings That Appear as Substrings in Word](https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given an array of strings `patterns` and a string `word`, return *the number of strings in `patterns` that exist as a substring in `word`*.

A **substring** is a contiguous sequence of characters within a string.

### Examples

**Example 1:**
* **Input:** `patterns = ["a","abc","bc","d"]`, `word = "abc"`
* **Output:** `3`
* **Explanation:**
  * `"a"` appears as a substring in `"abc"`.
  * `"abc"` appears as a substring in `"abc"`.
  * `"bc"` appears as a substring in `"abc"`.
  * `"d"` does not appear as a substring in `"abc"`.
  * 3 of the strings in patterns appear as a substring in word.

**Example 2:**
* **Input:** `patterns = ["a","b","c"]`, `word = "aaaaabbbbb"`
* **Output:** `2`

**Example 3:**
* **Input:** `patterns = ["a","a","a"]`, `word = "ab"`
* **Output:** `3`

### Constraints
* `1 <= patterns.length <= 100`
* `1 <= patterns[i].length <= 100`
* `1 <= word.length <= 100`
* `patterns[i]` and `word` consist of lowercase English letters.

---

## Approach & Intuition

The problem requires us to check each individual string in the `patterns` array and determine whether it exists inside the main string `word`. 

Since the constraints are relatively small ($1 \le \text{length} \le 100$), we can iterate through the array directly and utilize built-in string manipulation methods:

1. Maintain a `count` variable initialized to `0`.
2. Loop through every pattern string in `patterns`.
3. Use C++'s built-in string searching function `word.find(pattern)` to check for the presence of the substring.
4. If `find()` returns a valid position (meaning it does not equal `std::string::npos`, which evaluates numerically to `-1` when cast to a standard integer), we increment our `count`.
5. Return the total `count` at the end.

---

## Complexity Analysis

* **Time Complexity:** $O(N \times M)$ — Where $N$ is the number of strings in `patterns` and $M$ is the length of the string `word`. For each pattern, the built-in `find()` method scans through `word`. Given the constraints ($100 \times 100$), this approach runs almost instantly.
* **Space Complexity:** $O(1)$ — No extra memory allocations or structures are created; we only maintain a few primitive integer counters.

---

## Code Walkthrough

The C++ solution cleanly structures the iteration:
* `lenpattern` stores the total number of patterns to check.
* A standard `for` loop evaluates each index `i`.
* `word.find(patterns[i])` is used to hunt for the pattern match. If the pattern isn't found, it yields `string::npos` (which matches your check against `-1`).
* If a match occurs, `count` increments seamlessly before returning the final sum.