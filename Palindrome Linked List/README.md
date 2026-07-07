# [234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/description/)

## Difficulty
**Easy**

---

## Problem Statement

Given the `head` of a singly linked list, return `true` *if it is a palindrome, or `false` otherwise*.

### Examples

**Example 1:**
* **Input:** `head = [1,2,2,1]`
* **Output:** `true`

**Example 2:**
* **Input:** `head = [1,2]`
* **Output:** `false`

### Constraints
* The number of nodes in the list is in the range `[1, 10^5]`.
* `0 <= Node.val <= 9`

---

## Approach & Intuition

A linked list is not easy to read backwards. There is no "previous" pointer, so we cannot just walk from both ends like we do with an array. To fix this, we first copy all the values into something we *can* read from both ends easily — a normal array (here called `queue`).

1. Walk through the linked list from `head` to the end, and push every node's value into an array.
2. Now we have all the values in a simple array, just like the list, but easy to index from both sides.
3. Use two pointers, `front` starting at the beginning of the array and `rear` starting at the end.
4. Compare `queue[front]` and `queue[rear]`:
   * If they are not equal, the list is not a palindrome, so return `false` right away.
   * If they are equal, move `front` one step forward and `rear` one step backward, and check again.
5. Keep doing this until `front` crosses `rear`. If we never found a mismatch, the list is a palindrome, so return `true`.

This is the same idea as checking if a string is a palindrome by comparing the first and last letter, then the second and second-last, and so on — just applied after converting the list into an array first.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — We visit every node once to copy it into the array, and then do one more pass comparing from both ends, which is also linear.
* **Space Complexity:** $O(n)$ — We store a copy of every node's value in the `queue` array, so extra space grows with the number of nodes.

---

## Code Walkthrough

The code has two clear parts:
* First, `temp` starts at `head` and walks through the whole list. For every node, its value is pushed into the `queue` array, and `rear` is increased by one each time, so at the end `rear` points to the last valid index.
* `front` starts at `0`, the beginning of the array.
* In the second `while` loop, we check `queue[front] != queue[rear]`. If the values don't match, we return `false` immediately.
* If they do match, `front` moves forward and `rear` moves backward, and the loop repeats.
* If `front` becomes greater than `rear` without finding any mismatch, the loop ends naturally and `true` is returned, meaning the list reads the same forwards and backwards.