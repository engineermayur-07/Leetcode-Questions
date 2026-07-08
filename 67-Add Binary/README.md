# [67. Add Binary](https://leetcode.com/problems/add-binary/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given two binary strings `a` and `b`, return *their sum as a binary string*.

### Examples

**Example 1:**
* **Input:** `a = "11"`, `b = "1"`
* **Output:** `"100"`

**Example 2:**
* **Input:** `a = "1010"`, `b = "1011"`
* **Output:** `"10101"`

### Constraints
* `1 <= a.length, b.length <= 10^4`
* `a` and `b` consist only of `'0'` or `'1'` characters.
* Each string does not contain leading zeros except for the zero itself.

---

## Approach & Intuition

This is essentially simulating **elementary school column addition**, but in base 2 instead of base 10 — and since binary strings can be arbitrarily long (up to `10^4` characters), we can't just convert them to integers (they'd overflow). Instead, we add digit-by-digit from the **rightmost (least significant) bit** toward the left, exactly how addition is done by hand.

1. Set up two pointers, `right_a` and `right_b`, starting at the last index of `a` and `b` respectively — this is where addition begins.
2. Initialize an empty result string `ans` and a `carry` variable set to `0`.
3. Loop as long as there are digits left in either string, **or** there's a leftover carry to process:
   * Start `sum` with the current `carry`.
   * If `right_a` is still valid, add the digit at that position (converted from char to int via `a[right_a] - '0'`) into `sum`, then move `right_a` one step left.
   * Do the same for `right_b` and `right_a`'s counterpart.
   * The **current bit** of the result is `sum % 2` (i.e., whether the total is odd or even), appended to `ans`.
   * The **new carry** for the next position is `sum / 2` (integer division), since in binary, any sum of `2` or more overflows into the next bit.
4. Since digits were appended from least-significant to most-significant, `ans` is built in **reverse order** — so it's reversed once at the end before being returned.

---

## Complexity Analysis

* **Time Complexity:** $O(\max(N, M))$ — Where $N$ and $M$ are the lengths of `a` and `b`. The loop runs once per digit position across the longer of the two strings (plus possibly one extra step for a final carry), and the final reversal is also linear in the length of the result.
* **Space Complexity:** $O(\max(N, M))$ — The result string `ans` grows to be roughly as long as the longer input string (plus at most one extra digit for a final carry-out).

---

## Code Walkthrough

The solution simulates binary addition using two trailing pointers and a running carry:
* `right_a` and `right_b` are initialized to the last valid indices of `a` and `b`, and are decremented independently as each string is consumed.
* `carry` starts at `0` and is updated at the end of each iteration to hold any overflow into the next digit.
* The `while` loop condition `right_a >= 0 || right_b >= 0 || carry > 0` ensures the loop continues until **both** strings are fully consumed **and** there's no leftover carry — this correctly handles cases like `"1" + "1"`, which produces an extra leading `1` from a final carry.
* Inside the loop, `sum` accumulates the current carry plus whichever digits are still available from `a` and `b`.
* `to_string(sum % 2)` appends the current bit to `ans`, while `carry = sum / 2` computes the carry-out for the next iteration.
* After the loop, `reverse(ans.begin(), ans.end())` flips the digit-by-digit result (built least-significant-first) into the correct left-to-right binary string, which is then returned.