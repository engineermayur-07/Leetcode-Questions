# [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)

## Difficulty
**Easy**

---

## Problem Statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day.

You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.

Return *the maximum profit you can achieve from this transaction*. If you cannot achieve any profit, return `0`.

### Examples

**Example 1:**
* **Input:** `prices = [7,1,5,3,6,4]`
* **Output:** `5`
* **Explanation:** Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5. Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

**Example 2:**
* **Input:** `prices = [7,6,4,3,1]`
* **Output:** `0`
* **Explanation:** In this case, no transactions are done and the max profit = 0.

### Constraints
* `1 <= prices.length <= 10^5`
* `0 <= prices[i] <= 10^4`

---

## Approach & Intuition

The maximum profit from a single buy-sell transaction is determined by finding the **lowest price seen so far** and comparing it against every price that comes **after** it. Rather than checking every possible buy-sell pair (which would be $O(n^2)$), we can track the minimum price seen up to the current day in a single pass, since the best day to sell can only ever be paired with the cheapest price that occurred *before* it.

1. Initialize `buy = prices[0]`, representing the lowest purchase price encountered so far (starting with day 0's price), and `ans = 0`, the best profit found so far.
2. Start a pointer `left` at index `1` (the earliest possible "sell" day, since you must buy before you sell).
3. Iterate through the rest of the array:
   * First, compute the profit if we were to **sell today** at `prices[left]`, having bought at the cheapest price seen so far (`buy`): `prices[left] - buy`. Compare this against `ans` and keep the larger value.
   * Then, update `buy` to be the minimum of its current value and today's price — this ensures `buy` always reflects the lowest price seen up to (and including) the current day, ready to be used for evaluating future days.
   * Advance `left` to the next day.
4. After the loop finishes, `ans` holds the maximum achievable profit across the entire price history.

The order of operations here matters: we calculate the potential profit for **today's price as a sell day** *before* updating `buy` with today's price — this correctly enforces that we can't buy and sell on the same day, since `buy` still reflects a price from a **strictly earlier** day at the moment the profit comparison happens.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$ — A single linear pass through `prices`, with constant-time work per element.
* **Space Complexity:** $O(1)$ — Only a few integer variables (`left`, `buy`, `ans`) are used, regardless of the size of `prices`.

---

## Code Walkthrough

The solution tracks a running minimum price alongside a running best profit:
* `buy` is initialized to `prices[0]`, and `ans` starts at `0` (no profit found yet). `left` starts at `1`, since a sale can't happen on day 0 without a prior buy day.
* Inside the `while (left < prices.size())` loop, `ans = max(ans, prices[left] - buy)` first checks whether selling at today's price (against the cheapest price bought so far) beats the current best profit.
* Immediately after, `buy = min(buy, prices[left])` updates the running minimum to include today's price, so it's available for evaluating profit on subsequent days.
* `left++` advances to the next day, and the loop repeats.
* Once every day has been considered as a potential sell day, `ans` holds the maximum profit achievable and is returned.