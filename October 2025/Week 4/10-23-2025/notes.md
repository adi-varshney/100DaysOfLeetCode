<!-- Problem 11. Container With Most Water notes -->

# Problem 11. Container With Most Water - Notes

## Problem Understanding

- **Summary:** Pick two lines whose container with the x axis holds the most water
- **Input:** Integer array `height` of length `n`
- **Output:** Maximum area as an integer

## Approach

### Initial Thoughts

- I think the area equals distance between indices times the shorter height
- I realize the shorter height is the bottleneck
- I am considering two pointers starting at both ends
- I think moving the shorter side is the only move that can improve the minimum height
- I am considering skipping non increasing runs to cut extra iterations

### Approach Taken

- Initialize `left = 0` and `right = n - 1`
- At each step compute `width = right - l` and `low = min(height[l], height[r])`
  - My code just uses `min(height[left], height[right]) * (right - left)` to calculate current area
- Update `ans = max(ans, width * low)`
- Move the pointer at the shorter height to try to raise the minimum
- Optional improvement skips consecutive heights that are less than or equal to the height just passed
- Use constant extra memory

### Complexity:

- **Time:** `O(n)`
- **Space:** `O(1)`

<!-- ## Challenges
### Obstacles Faced
-

### Edge Cases
-
-->

## Alternative Solutions

- Brute force checks every pair which is `O(n^2)` and `O(1)` space and is too slow

## Key Takeaways

- The shorter line limits the area so only moving that pointer can help
- Two pointers from the ends achieve optimal `O(n)` time and `O(1)` space
- Skipping non improving runs preserves correctness and often reduces iterations
