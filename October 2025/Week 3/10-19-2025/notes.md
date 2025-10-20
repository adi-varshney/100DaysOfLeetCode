# Problem 7. Reverse Integer - Notes

## Problem Understanding

- **Summary:** Reverse the digits of a signed 32-bit integer `x` and return the reversed number.
- **Input:** An _int_(that may include negative values).
- **Output:** The reversed _int_. Leading zeros in the reversed result are ignored. If the reversed integer exceeds the signed 32-bit range [`-2^31`, `2^31 - 1`], return `0`.

## Approach

### Initial Thoughts

- I can extract digits using `% 10` and shrink the number with `/= 10`.
- I need to handle negative values without converting to string.
- Multiplying by `10` may overflow, so a check before updating the result is necessary.
- I’ll use a loop that processes digits until `x` becomes `0`.

### Approach Taken

- Initialize `ans = 0`.
- While `x != 0`:
  - Extract last digit with `x % 10`.
  - Before multiplying `ans` by `10`, check:
    - If `(ans > INT_MAX / 10)` or `(ans < INT_MIN / 10)`, return `0`.
  - Update `ans = ans * 10 + (x % 10)`.
  - Divide `x /= 10` to remove the processed digit.
- Return `ans` as the reversed integer after the loop.

### Complexity:

- **Time:** `O(N)` where `N` is the number of digits in `x`.
- **Space:** `O(1)` since only a few variables are used.

<!--
## Challenges
### Obstacles Faced
-

### Edge Cases
-
-->

## Alternative Solutions

- Convert integer to string, reverse it, and check range afterward. Easier but uses extra space and slower.

## Key Takeaways

- Checking for overflow before multiplying by 10 avoids undefined behavior.
- Integer math (digit popping and pushing) is more efficient and memory-safe.
- Always verify against `INT_MAX / 10` and `INT_MIN / 10` before scaling to prevent overflow.
