# [26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

## Difficulty
**Easy**

---

## Problem Statement

Given an integer array `nums` sorted in **non-decreasing order**, remove the duplicates **[in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** such that each unique element appears only **once**. The relative order of the elements should be kept the **same**. Then return *the number of unique elements in `nums`*.

To get accepted, you need to do the following things:
1. Change the array `nums` such that the first `k` elements of `nums` contain the unique elements in the order they were present in `nums` initially.
2. Return `k`.

### Examples

**Example 1:**
* **Input:** `nums = [1,1,2]`
* **Output:** `2`, `nums = [1,2,_]`
* **Explanation:** Your function should return `k = 2`, with the first two elements of `nums` being `1` and `2` respectively. It does not matter what you leave beyond the returned `k` (hence they are underscores).

**Example 2:**
* **Input:** `nums = [0,0,1,1,1,2,2,3,3,4]`
* **Output:** `5`, `nums = [0,1,2,3,4,_,_,_,_,_]`
* **Explanation:** Your function should return `k = 5`, with the first five elements of `nums` being `0`, `1`, `2`, `3`, and `4` respectively.

---

## Approach & Intuition

Since the input array is already **sorted**, all duplicate elements will always sit adjacent to each other. This allows us to use a **Two-Pointer Approach** to solve the problem efficiently in-place:

1. **Fast Pointer (`i`):** Scans through the array starting from index `1` to find unique elements.
2. **Slow Pointer (`index`):** Keeps track of the position where the next unique element should be written.

### Step-by-Step Logic:
* We start tracking unique elements from index `1` because the first element (`nums[0]`) is always unique relative to itself.
* We loop through the array with `i`. Whenever `nums[i] != nums[i - 1]`, it means we have found a brand-new unique element.
* We overwrite the value at `nums[index]` with this new unique element (`nums[i]`) and increment our `index` pointer.
* By the end of the loop, `index` will represent the count of unique elements, and the first `index` positions of the array will contain them in sorted order.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — We iterate through the array of length $n$ exactly once.
* **Space Complexity:** $O(1)$ — The modifications are performed completely in-place without using any extra memory structures.

---

## Code Walkthrough

The C++ solution implements the two-pointer tracking seamlessly:
* An edge-case handling statement `if (nums.size() == 0) return 0;` ensures we safely return empty constraints immediately.
* The variable `index` is initialized to `1` and strictly serves as our placement boundary marker for unique values.
* The `for` loop dynamically filters updates based on an element comparison with its immediate left neighbor (`nums[i - 1]`), moving items down the line continuously.