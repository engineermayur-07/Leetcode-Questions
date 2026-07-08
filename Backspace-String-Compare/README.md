# [844. Backspace String Compare](https://leetcode.com/problems/backspace-string-compare/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given two strings `s` and `t`, return `true` *if they are equal when both are typed into empty text editors*. `'#'` means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

### Examples

**Example 1:**
* **Input:** `s = "ab#c"`, `t = "ad#c"`
* **Output:** `true`
* **Explanation:** Both `s` and `t` become `"ac"`.

**Example 2:**
* **Input:** `s = "ab##"`, `t = "c#d#"`
* **Output:** `true`
* **Explanation:** Both `s` and `t` become `""`.

**Example 3:**
* **Input:** `s = "a#c"`, `t = "b"`
* **Output:** `false`
* **Explanation:** `s` becomes `"c"` while `t` becomes `"b"`.

### Constraints
* `1 <= s.length, t.length <= 200`
* `s` and `t` only contain lowercase letters and `'#'`.

---

## Approach & Intuition

The naive approach would be to build the actual final strings (processing backspaces character by character in a stack) and then compare them — but that costs extra space. Instead, this solution compares both strings **from right to left**, simultaneously, using two pointers and a "skip counter" for each string, avoiding the need to build the final strings at all.

The key insight: reading a string from the **end** and moving backward mirrors exactly how backspaces behave — a `'#'` cancels out the *next* character encountered as you move left, so processing right-to-left naturally applies each backspace to the correct character without needing a stack.

1. Set up `s_ptr` and `t_ptr`, both starting at the last index of `s` and `t`. Also maintain `s_skip` and `t_skip` counters, tracking how many pending "deletions" are owed from encountered `'#'` characters.
2. Loop as long as either pointer is still valid (`s_ptr >= 0 || t_ptr >= 0`):
   * **Resolve `s`'s pointer to its next "real" character:** In an inner loop, while `s_ptr >= 0`:
     * If `s[s_ptr]` is `'#'`, increment `s_skip` (one more character owes a deletion) and move `s_ptr` left.
     * Else if `s_skip > 0`, this character is cancelled by a pending backspace — decrement `s_skip` and move `s_ptr` left, without counting this character as "real."
     * Otherwise, this is a genuine, non-deleted character — `break` out of the inner loop, leaving `s_ptr` pointing at it.
   * Do the exact same resolution process for `t_ptr` and `t_skip`.
   * **Compare the resolved characters:**
     * If both pointers are still valid (`s_ptr >= 0 && t_ptr >= 0`), compare `s[s_ptr]` and `t[t_ptr]` — if they differ, the strings aren't equal, return `false`.
     * If only **one** of the pointers is still valid (one string ran out of real characters while the other didn't), the strings have different effective lengths — return `false`.
     * If **both** pointers are exhausted (`< 0`), both strings have been fully consumed, which is consistent so far — continue.
   * Move both pointers one step further left (`s_ptr--`, `t_ptr--`) to prepare for the next round of comparison.
3. If the loop completes without finding any mismatch, the strings are equal after applying backspaces — return `true`.

---

## Complexity Analysis

* **Time Complexity:** $O(N + M)$ — Where $N$ and $M$ are the lengths of `s` and `t`. Each pointer moves strictly leftward and each character is visited a constant number of times (either as a `'#'`, a skipped character, or a compared character).
* **Space Complexity:** $O(1)$ — Only pointer and counter variables are used; no stack or auxiliary string is built, unlike the naive stack-based simulation approach.

---

## Code Walkthrough

The solution processes both strings from the back using nested resolution loops:
* `s_ptr`/`t_ptr` track the current position being examined in each string; `s_skip`/`t_skip` track how many pending backspaces still need to "consume" an upcoming character.
* The outer `while (s_ptr >= 0 || t_ptr >= 0)` loop continues comparing as long as either string still has unprocessed characters.
* The first inner `while (s_ptr >= 0)` loop resolves `s_ptr` to the next real character: `'#'` characters increment `s_skip` and move the pointer left; if `s_skip > 0` when a normal character is hit, it's silently consumed (skip decremented, pointer moved); otherwise the loop `break`s, leaving `s_ptr` at a genuine character (or at `-1` if the string is exhausted).
* The second inner `while (t_ptr >= 0)` loop does the identical resolution for `t_ptr` and `t_skip`.
* After both pointers are resolved, the code checks: both valid → compare characters directly; only one valid → immediate `false` (mismatched effective lengths); both invalid → nothing to compare this round, fall through.
* Finally, `s_ptr--` and `t_ptr--` advance both pointers past the just-compared characters before the outer loop repeats.
* If the outer loop exits cleanly, `true` is returned, confirming the backspaced strings are identical.