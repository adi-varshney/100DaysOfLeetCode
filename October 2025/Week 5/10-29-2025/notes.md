# Problem 16. 3Sum Closest - Notes

## Problem Understanding

- **Summary:** The goal is to find three integers in `nums` whose sum is closest to `target`. There’s exactly one solution for every input.
- **Input:** Given an integer array `nums` of length `n` and a target integer `target`.
- **Output:** Return **the closest sum** of three integers to the `target` value (not the triplet itself).

## Approach

### Initial Thoughts

- This is pretty similar to the **3Sum** problem where we look for triplets summing to zero, except now we look for the **closest** sum to a given target.
- Sorting helps because we can use a **two-pointer** method efficiently to move toward or away from the target.
- The brute-force approach would be `O(n^3)` checking all triplets which too slow for `n <= 500`.
- The optimized idea is:
  - Sort the array.
  - Fix one element (`nums[i]`) and use two pointers (`left`, `right`) to explore possible pairs that form the triplet.
  - Track the closest sum by comparing absolute differences `abs(target - sum)`.

### Approach Taken

- Sort the input array first (`O(n log n)`).
- Initialize an answer with the sum of the **first three elements** to avoid undefined behavior or overflow issues.
- Iterate over `i` from `0` to `n - 2`:
  - Skip duplicate values to avoid redundant checks.
  - Use two pointers:
    - `left = i + 1`
    - `right = n - 1`
  - While `left < right`:
    - Compute the `sum = nums[i] + nums[left] + nums[right]`
    - If this sum is closer to the target than the previous best, update the answer.
    - If `sum == target`, return immediately (can’t get closer than exact match).
    - If `sum < target`, move `left++` to increase the sum.
    - Else, move `right--` to decrease the sum.
- Return the best recorded sum.

### Complexity:

- **Time:** `O(n^2)`
  - Sorting is `O(n log n)` and the two-pointer search runs in `O(n^2)` total.
- **Space:** `O(1)` (in-place sort, constant extra memory).

## Challenges

### Obstacles Faced

- Initializing `ans` as `INT_MAX` led to overflow with `abs(target - ans)`.
- Using the 3Sum (sum = 0) optimization `if (nums[i] > 0) break;` was incorrect because the target can be positive or negative.

### Edge Cases

- Duplicate values causing unnecessary repeated checks.

## Alternative Solutions

- **Brute Force:** Try all possible triplets with triple nested loops (`O(n^3)`), simple but inefficient.
- **Binary Search Variation:** For each pair `(i, j)`, binary search the third element to minimize `|target - (nums[i] + nums[j] + nums[k])|`, yielding `O(n^2 log n)` but more complex to implement.

## Key Takeaways

- The **two-pointer approach** effectively reduces the 3Sum problem from `O(n^3)` to `O(n^2)`.
- Always initialize your “best” value to a valid computed sum, not to an arbitrary constant like `INT_MAX`.
- Sorting enables efficient movement of pointers to get closer to the target sum.
- The logic for “closest sum” relies on continuous comparison of `abs(target - sum)` against the current best difference.
