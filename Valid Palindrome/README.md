# [125. Valid Palindrome](https://leetcode.com/problems/valid-palindrome/description/)

## Difficulty
**Easy**

---

## Problem Statement

A phrase is a **palindrome** if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` *if it is a palindrome, or `false` otherwise*.

### Examples

**Example 1:**
* **Input:** `s = "A man, a plan, a canal: Panama"`
* **Output:** `true`
* **Explanation:** `"amanaplanacanalpanama"` is a palindrome.

**Example 2:**
* **Input:** `s = "race a car"`
* **Output:** `false`
* **Explanation:** `"raceacar"` is not a palindrome.

**Example 3:**
* **Input:** `s = " "`
* **Output:** `true`
* **Explanation:** `s` is an empty string `""` after removing non-alphanumeric characters. Since an empty string reads the same forward and backward, it is a palindrome.

### Constraints
* `1 <= s.length <= 2 * 10^5`
* `s` consists only of printable ASCII characters.

---

## Approach & Intuition

This is the classic **two-pointer** palindrome check, but complicated slightly by the need to skip non-alphanumeric characters and treat uppercase/lowercase letters as equal. Rather than pre-processing the string (removing symbols and lowercasing it into a new string), this solution does everything **in place** by working directly with ASCII values.

1. Set two pointers: `first` at index `0` and `last` at the final index of `s`.
2. While `first <= last`:
   * **Skip invalid characters from the left:** Check if `s[first]` is a non-alphanumeric ASCII character (anything outside the ranges for digits `'0'-'9'` (48-57), uppercase `'A'-'Z'` (65-90), and lowercase `'a'-'z'` (97-122)). If so, increment `first` and `continue` to re-check the next character.
   * **Skip invalid characters from the right:** Do the same check for `s[last]`, decrementing it if it's non-alphanumeric.
   * **Case-insensitive comparison:** Once both `s[first]` and `s[last]` are confirmed alphanumeric:
     * If `s[first]` is uppercase (65-90), compare it against `s[last]` both directly and after converting to lowercase (`s[first] + 32`), since ASCII lowercase letters are exactly 32 more than their uppercase counterparts.
     * If `s[first]` is lowercase (97+), compare it against `s[last]` both directly and after converting to uppercase (`s[first] - 32`).
     * If `s[first]` is a digit, compare it directly with `s[last]` (no case conversion needed for digits).
     * If neither comparison matches, the string isn't a palindrome — return `false`.
   * If the characters matched, move both pointers inward: `first++` and `last--`.
3. If the pointers cross without ever finding a mismatch, the string is a valid palindrome — return `true`.

The core idea is the same as any two-pointer palindrome check (compare from both ends, moving inward), but the ASCII range checks replace what would normally be handled by library functions like `isalnum()` and `tolower()`.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — Each pointer moves strictly toward the center and never revisits a character, so the total work across both pointers is linear in the length of `s`.
* **Space Complexity:** $O(1)$ — No extra string or array is created; the check is done entirely in place using two integer pointers.

---

## Code Walkthrough

The solution manually replicates `isalnum()` and case conversion using raw ASCII comparisons:
* `first` and `last` are initialized to the two ends of the string.
* The first `if` block inside the loop filters out non-alphanumeric characters from the **left** side — the condition checks several disjoint ASCII ranges to identify symbols, punctuation, and spaces, incrementing `first` and skipping the rest of the loop body via `continue` if such a character is found.
* The second `if` block performs the same filtering for the **right** side, decrementing `last` instead.
* Once both characters are alphanumeric, the code branches on the ASCII range of `s[first]`:
  * `s[first] <= 90 && s[first] >= 65` handles uppercase letters, comparing against `s[last]` both directly and via `s[first] + 32` (its lowercase equivalent).
  * `s[first] >= 97` handles lowercase letters, comparing via `s[first] - 32` (its uppercase equivalent) as well as directly.
  * The final `else` branch handles digits, where a direct equality check is sufficient.
* If none of the matching conditions hold, `false` is returned immediately; otherwise, `first++` and `last--` shrink the window and the loop continues.
* If the loop completes without a mismatch, `true` is returned.