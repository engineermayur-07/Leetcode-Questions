# [412. Fizz Buzz](https://leetcode.com/problems/fizz-buzz/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given an integer `n`, return *a string array `answer` (**1-indexed**) where*:
* `answer[i] == "FizzBuzz"` if `i` is divisible by `3` and `5`.
* `answer[i] == "Fizz"` if `i` is divisible by `3`.
* `answer[i] == "Buzz"` if `i` is divisible by `5`.
* `answer[i] == i` (as a string) if none of the above conditions are true.

### Examples

**Example 1:**
* **Input:** `n = 3`
* **Output:** `["1","2","Fizz"]`

**Example 2:**
* **Input:** `n = 5`
* **Output:** `["1","2","Fizz","4","Buzz"]`

**Example 3:**
* **Input:** `n = 15`
* **Output:** `["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]`

### Constraints
* `1 <= n <= 10^4`

---

## Approach & Intuition

This is a direct simulation problem — there's no clever trick needed, just a careful ordering of divisibility checks so the correct string is picked for each number from `1` to `n`.

1. Pre-allocate a result vector `answer` of size `n`, since we already know exactly how many entries it will hold.
2. Loop `i` from `1` to `n` (inclusive), and for each `i`, decide which string belongs at `answer[i-1]` (adjusting for 0-based indexing since the problem is 1-indexed):
   * **Check divisibility by 5 first:** If `i % 5 == 0`, then nest a check for divisibility by 3 as well:
     * If `i % 3 == 0` too, it's divisible by both — assign `"FizzBuzz"`.
     * Otherwise, it's divisible by 5 only — assign `"Buzz"`.
   * **Else check divisibility by 3:** If `i % 3 == 0` (and we already know it's *not* divisible by 5, since that case was handled above), assign `"Fizz"`.
   * **Otherwise:** None of the divisibility rules apply, so convert `i` to a string directly using `to_string(i)`.
3. Return the fully populated `answer` array.

The key structural insight is nesting the `%3` check *inside* the `%5` check (rather than checking them as three separate independent `if` conditions) — this naturally and cleanly handles the "divisible by both" case without needing a redundant `i % 15 == 0` check.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — A single pass from `1` to `n`, with constant-time work (a couple of modulo checks and a string assignment) per iteration.
* **Space Complexity:** $O(n)$ — Excluding the output array itself (which is required to hold the result), only a loop counter is used; if the output is counted, space is $O(n)$ to store `n` strings.

---

## Code Walkthrough

The solution directly maps the problem's rules onto a single `for` loop:
* `answer` is pre-sized to `n` entries upfront using `vector<string> answer(n)`.
* The loop runs `i` from `1` through `n`, matching the problem's 1-indexed numbering, while writing results to `answer[i-1]` to fit C++'s 0-indexed vectors.
* The outer `if (i % 5 == 0)` branch is checked first; within it, a nested `if (i % 3 == 0)` distinguishes between `"FizzBuzz"` (both conditions true) and `"Buzz"` (only divisible by 5).
* The `else if (i % 3 == 0)` branch catches numbers divisible by 3 alone (since divisibility by 5 was already ruled out by reaching this branch), assigning `"Fizz"`.
* The final `else` branch handles all remaining numbers, converting `i` to its string form via `to_string(i)`.
* After the loop completes, the fully populated `answer` vector is returned.