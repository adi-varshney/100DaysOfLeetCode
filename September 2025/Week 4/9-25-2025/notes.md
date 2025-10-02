# Problem 121. Best Time to Buy and Sell Stock - Notes

## Problem Understanding
- **Summary:** Find the maximum profit from exactly one buy and one later sell. If profit is never positive, return 0.
- **Input:** A _vector\<int\>_ `prices`, each element is the stock price on day i.
- **Output:** An _int_ maximum profit achievable with one transaction.

## Approach

### Initial Thoughts
- This problem seems kinda of like a __greedy solution__ because we always need to take the *__most locally-optimal solution__*.
- I only need the cheapest price seen so far while scanning from left to right.
- Profit at any day equals `prices[i] - minSoFar` so I can update the answer on the fly.
- If the current price becomes the new minimum, buying today and selling today yields profit 0 which is fine.
- If prices keep dropping, the best profit stays 0 so no special handling is needed.
- Storing any full history is unnecessary since the future sell only cares about the smallest earlier buy.

### Approach Taken
- Track two integers while iterating.
  - `minPrice` the smallest value seen up to the current index.
  - `profit` the best profit found so far.
- For each price
  - Update `minPrice = min(minPrice, price)` to reflect the cheapest possible buy so far.
  - Update `profit = max(profit, price - minPrice)` to reflect the best sell given that buy.
- Return `profit` which will be 0 when no profitable pair exists.

### Complexity:
- **Time:** `O(n)`, looping 
- **Space:** `O(1)`, only used constant memory variables to hold `minPrice` and `maxProfit`

<!--
## Challenges
### Obstacles Faced
- placeholder
### Edge Cases
- placeholder
-->

## Alternative Solutions
- Brute force check all pairs `i < j` and track max `prices[j] - prices[i]`
  - **Time:** `O(n^2)`
  - **Space:** `O(1)`
- Kadane view on day-to-day differences transform to max subarray on `diff[i] = prices[i] - prices[i-1]`
  - **Time:** `O(n)`
  - **Space:** `O(1)`
- DP two-state formulation keep `bestHold` and `bestNotHold` for one transaction
  - **Time:** `O(n)`
  - **Space:** `O(1)`

## Key Takeaways
- One pass is enough by maintaining the minimum price so far and the best profit so far.
- The order buy before sell is enforced naturally since `minPrice` only comes from earlier days.
- When prices are strictly decreasing, the correct answer is 0 without extra checks.
