# [415. Add Strings](https://leetcode.com/problems/add-strings/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given two non-negative integers, `num1` and `num2` represented as strings, return *the sum of `num1` and `num2` as a string*.

You must solve the problem without using any built-in library for handling large integers (such as `BigInteger`). You must also not convert the inputs to integers directly.

### Examples

**Example 1:**
* **Input:** `num1 = "11"`, `num2 = "123"`
* **Output:** `"134"`

**Example 2:**
* **Input:** `num1 = "456"`, `num2 = "77"`
* **Output:** `"533"`

**Example 3:**
* **Input:** `num1 = "0"`, `num2 = "0"`
* **Output:** `"0"`

### Constraints
* `1 <= num1.length, num2.length <= 10^4`
* `num1` and `num2` consist of only digits.
* `num1` and `num2` don't have any leading zeros except for the zero itself.

---

## Approach & Intuition

This is the same core idea as **Add Binary** (problem 67), just done in **base 10** instead of base 2 — simulating manual column addition digit-by-digit, starting from the rightmost (least significant) digit of each number and working leftward.

1. Set up two pointers, `n1` and `n2`, initialized to the last valid index of `num1` and `num2` respectively.
2. Initialize an empty result string `ans` and a `carry` variable set to `0`.
3. Loop as long as there are digits left in either number, **or** there's a leftover carry:
   * Start `sum` with the current `carry`.
   * If `n1` is still valid, convert the character at that position to its numeric value (`num1[n1] - '0'`) and add it to `sum`, then move `n1` one step left.
   * Do the same for `n2`.
   * Append the current digit of the result: `(sum % 10) + '0'` converts the ones-digit of `sum` back into a character and appends it directly to `ans` (equivalent to, but slightly faster than, `to_string(sum % 10)`).
   * Compute the new carry: `carry = sum / 10`, since any total of `10` or more overflows into the next column, just like in manual addition.
4. Since digits are appended from least-significant to most-significant, `ans` ends up **reversed** — so it's flipped once at the end with `reverse(ans.begin(), ans.end())` before being returned.

---

## Complexity Analysis

* **Time Complexity:** $O(\max(N, M))$ — Where $N$ and $M$ are the lengths of `num1` and `num2`. The loop runs once per digit position across the longer number (plus possibly one extra step for a final carry), and the final reversal is linear in the length of the result.
* **Space Complexity:** $O(\max(N, M))$ — The result string `ans` grows to roughly the length of the longer input string (plus at most one extra digit for a final carry-out).

---

## Code Walkthrough

The solution mirrors the Add Binary approach, adapted for base 10:
* `n1` and `n2` are initialized to the last valid indices of `num1` and `num2`, decremented independently as each string is consumed.
* `carry` starts at `0` and is updated at the end of each iteration to carry over any overflow into the next digit.
* The `while (n1 >= 0 || n2 >= 0 || carry)` condition ensures the loop continues until both numbers are fully consumed **and** there's no leftover carry — this correctly handles a final carry-out (e.g., `"5" + "5"` producing `"10"`).
* Inside the loop, `sum` accumulates the current carry plus whichever digits are still available from `num1` and `num2`.
* `ans += (sum % 10) + '0'` appends the current digit directly as a character (using ASCII arithmetic instead of `to_string`), while `carry = sum / 10` computes the carry-out for the next iteration.
* After the loop, `reverse(ans.begin(), ans.end())` flips the digit-by-digit result (built least-significant-first) into the correct left-to-right numeric string, which is then returned.