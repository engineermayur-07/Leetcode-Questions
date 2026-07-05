# [58. Length of Last Word](https://leetcode.com/problems/length-of-last-word/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given a string `s` consisting of words and spaces, return *the length of the **last** word in the string*.

A **word** is a maximal substring consisting of non-space characters only.

### Examples

**Example 1:**
* **Input:** `s = "Hello World"`
* **Output:** `5`
* **Explanation:** The last word is `"World"` with length 5.

**Example 2:**
* **Input:** `s = "   fly me   to   the moon  "`
* **Output:** `4`
* **Explanation:** The last word is `"moon"` with length 4.

**Example 3:**
* **Input:** `s = "luffy is still joyboy"`
* **Output:** `6`
* **Explanation:** The last word is `"joyboy"` with length 6.

### Constraints
* `1 <= s.length <= 10^4`
* `s` consists of only English letters and spaces `' '`.
* There will be at least one word in `s`.

---

## Approach & Intuition

Since we only care about the **last** word, there's no need to scan the string from the beginning — it's more efficient to scan **backwards** from the end and stop as soon as the last word has been fully measured.

1. Initialize `ans = 0` to track the length of the word currently being counted.
2. Iterate `i` from the last index (`n-1`) down to `0`:
   * If `s[i]` is **not a space**, it's part of a word — increment `ans`.
   * If `s[i]` **is a space** and `ans > 0`, that means a word has just been fully traversed (we've hit the space right before it), so return `ans` immediately.
   * If `s[i]` is a space but `ans == 0`, it's trailing whitespace after the last word — simply continue scanning without returning yet.
3. If the loop finishes without hitting a mid-string space after counting (i.e., the last word starts at index `0`), fall through and return `ans` directly.

This backward scan naturally skips over any trailing spaces first, then counts the last word's characters, and stops the moment it detects the boundary (a space) before that word — without needing to process the rest of the string.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — In the worst case (e.g., the last word starts at index 0, or the entire string is one word), the loop scans through the full string once.
* **Space Complexity:** $O(1)$ — Only a couple of integer variables (`n`, `ans`) are used; no extra strings or arrays are created.

---

## Code Walkthrough

The solution performs a single reverse pass over the string:
* `n` stores the string length, and the `for` loop initializes `i = n - 1`, moving down to `0`.
* `ans` accumulates the length of the word currently being scanned, starting at `0`.
* The `if (s[i] != ' ')` branch increments `ans` for every non-space character encountered — this builds up the last word's length as the loop moves leftward through it.
* The `else if (ans > 0)` branch triggers only once a space is hit **after** some characters have already been counted, signaling the start boundary of the last word — at that point, `ans` is returned immediately, short-circuiting the rest of the loop.
* If the loop runs to completion without triggering that return (e.g., the last word extends all the way to index `0`), the final `ans` is returned after the loop as a fallback.