# [9. Palindrome Number](https://leetcode.com/problems/palindrome-number/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given an integer `x`, return `true` *if `x` is a palindrome, and `false` otherwise*.

### Examples

**Example 1:**
* **Input:** `x = 121`
* **Output:** `true`
* **Explanation:** 121 reads as 121 from left to right and from right to left.

**Example 2:**
* **Input:** `x = -121`
* **Output:** `false`
* **Explanation:** From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

**Example 3:**
* **Input:** `x = 10`
* **Output:** `false`
* **Explanation:** Reads 01 from right to left. Therefore it is not a palindrome.

### Constraints
* `-2^31 <= x <= 2^31 - 1`

---

## Approach & Intuition

A palindrome number reads the same forwards and backwards, so the most direct approach is to **fully reverse the digits** of the number and check whether the reversed version matches the original.

1. **Handle negatives immediately:** Any negative number can never be a palindrome, since the `-` sign only appears on one side — return `false` right away if `x < 0`.
2. Copy `x` into a working variable `num`, and initialize `reverse = 0` (using `long long` as a safety margin, since reversing a large `int` close to `2^31 - 1` could otherwise risk overflow during construction).
3. While `num > 0`, peel off digits from the **right** end and build them into `reverse` from the **left**:
   * `reverse = (reverse * 10) + (num % 10)` shifts the existing reversed digits one place left and appends the current last digit of `num`.
   * `num = num / 10` strips that digit off `num`, moving toward the next one.
4. Once `num` reaches `0`, all digits have been reversed and accumulated into `reverse`.
5. Compare `reverse` to the original `x`: if they're equal, the number is a palindrome — return `true`; otherwise, return `false`.

This approach works because a palindrome is defined precisely as "equal to its own reversal," so directly computing the reversal and comparing is the most literal and efficient translation of the definition.

---

## Complexity Analysis

* **Time Complexity:** $O(\log_{10} x)$ — The loop runs once per digit of `x`, and the number of digits in `x` scales with $\log_{10}$ of its value.
* **Space Complexity:** $O(1)$ — Only a couple of variables (`num`, `reverse`) are used, regardless of the size of `x`.

---

## Code Walkthrough

The solution reverses the digits of `x` and compares the result to the original:
* The initial `if (x < 0) return false` guard eliminates negative numbers immediately, since they can never be palindromes.
* `num` is a mutable copy of `x` used for digit extraction, while `x` itself is preserved untouched for the final comparison.
* `reverse` is declared as `long long` to safely accumulate the reversed digits without risking overflow.
* Inside the `while (num > 0)` loop, `reverse = (reverse * 10) + (num % 10)` builds the reversed number one digit at a time, and `num = num / 10` discards the digit that was just processed.
* After the loop, `if (reverse == x)` performs the final palindrome check, returning `true` on a match and `false` otherwise.