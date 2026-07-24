# [13. Roman to Integer](https://leetcode.com/problems/roman-to-integer/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given a roman numeral, convert it to an integer.

Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D`, and `M`.

Symbol Value
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Roman numerals are usually written largest to smallest from left to right. However, there are six instances where **subtraction** is used:
* `I` placed before `V` (5) or `X` (10) makes 4 and 9.
* `X` placed before `L` (50) or `C` (100) makes 40 and 90.
* `C` placed before `D` (500) or `M` (1000) makes 400 and 900.

### Examples

**Example 1:**
* **Input:** `s = "III"`
* **Output:** `3`

**Example 2:**
* **Input:** `s = "LVIII"`
* **Output:** `58`
* **Explanation:** L = 50, V = 5, III = 3.

**Example 3:**
* **Input:** `s = "MCMXCIV"`
* **Output:** `1994`
* **Explanation:** M = 1000, CM = 900, XC = 90 and IV = 4.

### Constraints
* `1 <= s.length <= 15`
* `s` contains only the characters `('I', 'V', 'X', 'L', 'C', 'D', 'M')`.
* It's guaranteed that `s` is a valid roman numeral in the range `[1, 3000]`.

---

## Approach & Intuition

The key rule governing Roman numerals is: **a symbol is subtracted only when it's immediately followed by a strictly larger symbol** (e.g., `I` before `V` means "one less than five"). Otherwise, every symbol simply **adds** its value to the running total. This gives a clean single-pass rule without needing to special-case all six subtractive pairs individually.

Two solutions are included here — one using a helper function with a `switch` statement, and one using an `unordered_map` for lookups.

### Approach 1: Helper Function with Switch Statement

1. Define a helper `getvalue(char roman)` that maps each Roman character to its integer value using a `switch` statement.
2. Iterate through the string `s` from left to right:
   * Get the value of the current character via `getvalue(s[i])`.
   * **Look ahead** to the next character (if it exists, i.e., `i < n-1`): if the current character's value is **less than** the next character's value, this is a subtractive pair (like `IV` or `IX`) — so **subtract** the current value from `sum` instead of adding it.
   * Otherwise, simply **add** the current value to `sum`.
3. Return `sum` after processing every character.

### Approach 2: Unordered Map Lookup

This follows the exact same logic, but replaces the `switch`-based helper function with a direct `unordered_map<char, int>` lookup table (`map.at(s[i])`) for retrieving each symbol's value — functionally identical, just a different data structure for the value lookup.

---

## Complexity Analysis

### Both Approaches
* **Time Complexity:** $O(n)$ — A single pass through the string `s`, with constant-time value lookup per character (whether via `switch` or hash map).
* **Space Complexity:** $O(1)$ — The value lookup table (whether the `switch` cases or the `unordered_map`) has a fixed, constant size (7 possible symbols), independent of the input length.

---

## Code Walkthrough

**Approach 1 (`romanToInt` — switch-based helper):**
* `getvalue(char roman)` uses a `switch` statement to return the correct integer value for each of the 7 valid Roman characters, defaulting to `0` for anything unmatched (not expected given valid input).
* In `romanToInt`, `n` stores the string length, and the `for` loop retrieves `temp = getvalue(s[i])` for the current character.
* The condition `i < n-1 && temp < getvalue(s[i+1])` checks whether a look-ahead comparison is possible and whether the current symbol is smaller than the next — if so, `temp` is subtracted from `sum`.
* Otherwise, `temp` is added to `sum`.
* After the loop, `sum` holds the final converted integer value and is returned.

**Approach 2 (`romanToInt` — unordered map):**
* `map` is initialized as an `unordered_map<char, int>` with all 7 Roman symbol-value pairs pre-populated.
* The `for` loop mirrors Approach 1's logic exactly, but uses `map.at(s[i])` in place of the `getvalue()` helper call for retrieving each character's value.
* The same look-ahead comparison (`map.at(s[i]) < map.at(s[i+1])`) determines whether to subtract or add the current value into `sum`, which is returned at the end.