# [2124. Check if All A's Appears Before All B's](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given a string `s` consisting of only the characters `'a'` and `'b'`, return `true` *if **every** `'a'` appears before **every** `'b'` in the string*. Otherwise, return `false`.

### Examples

**Example 1:**
* **Input:** `s = "aaabbb"`
* **Output:** `true`
* **Explanation:** The `'a'`s are at indices `0, 1, 2`, while the `'b'`s are at indices `3, 4, 5`. Hence, every `'a'` appears before every `'b'` and we return `true`.

**Example 2:**
* **Input:** `s = "abab"`
* **Output:** `false`
* **Explanation:** There is an `'a'` at index `2` and a `'b'` at index `1`. Hence, not every `'a'` appears before every `'b'` and we return `false`.

**Example 3:**
* **Input:** `s = "bba"`
* **Output:** `false`
* **Explanation:** There is an `'a'` at index `2` and a `'b'` at index `0`. Hence, not every `'a'` appears before every `'b'` and we return `false`.

### Constraints
* `1 <= s.length <= 100`
* `s[i]` is either `'a'` or `'b'`.

---

## Approach & Intuition

Since `s` only contains `'a'` and `'b'`, the condition "every `'a'` appears before every `'b'`" is equivalent to saying the string looks like a block of `'a'`s followed by a block of `'b'`s (e.g., `"aaabbb"`), with **no `'b'` ever immediately followed by an `'a'`** anywhere in between.

That means the entire check boils down to a single question: **does the substring `"ba"` ever appear in `s`?** If it does, that's direct proof of a `'b'` occurring before some `'a'`, which violates the required order. If `"ba"` never appears, the string must already be correctly ordered as all `'a'`s followed by all `'b'`s.

1. Search for the substring `"ba"` within `s` using `s.find("ba")`.
2. If `"ba"` is found (i.e., `find()` does **not** return `string::npos`), the ordering is violated — the underlying condition `s.find("ba") != string::npos` becomes `true`, which is then **negated** with `!` to produce `false` for the final answer.
3. If `"ba"` is never found, the condition is `false`, and negating it gives `true` — meaning the string satisfies the required order.

This is a compact way of expressing "no b-before-a violation exists anywhere in the string" using a single substring search instead of manually tracking the last seen character.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — Where $n$ is the length of `s`. The `find()` method scans through `s` once to look for the two-character substring `"ba"`.
* **Space Complexity:** $O(1)$ — No extra data structures are created; the check is a single expression evaluation.

---

## Code Walkthrough

The entire solution is a single-line substring check:
* `s.find("ba")` searches `s` for the first occurrence of the substring `"ba"`, returning its starting index if found, or `string::npos` if not found.
* The comparison `s.find("ba") != string::npos` evaluates to `true` if `"ba"` exists anywhere in `s` (i.e., there's a `'b'` immediately followed by an `'a'`, which violates the ordering).
* The `!` operator flips this result — so the function returns `true` only when `"ba"` is **absent** from `s`, meaning all `'a'`s properly precede all `'b'`s.