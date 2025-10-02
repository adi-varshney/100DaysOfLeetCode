# Problem 69. Sqrt(x) - Notes
## Problem Understanding
 - **Summary**: Given a non-negative integer `x`, return the *integer* square root of `x` (i.e., ⌊√`x`⌋). No using exponent functions/operators.
 - **Input**: One *integer* `x` where `0 ≤ x ≤ 2^31 − 1`.
 - **Output**: A *String* representing `a + b` in base-2.

## Approach
- **Initial Thoughts**:
  - Okay, so the problem is basically asking for the integer square root, the largest number k such that `k*k ≤ x`. I’m thinking the brute force way would be to just loop upward and check until `k*k > x`, but that’s gonna be way too slow if `x` is big (like near `2^31−1`), because that could mean billions of iterations. Clearly not practical.

  - I think what this really boils down to is that the square root grows much slower than x itself, so we can shrink the search space pretty aggressively. That’s why binary search makes sense here, cus I can just keep halving the possible interval until I land near the right number.

  - Another thing I’m considering is that the search range doesn’t need to go all the way up to `x`. For any `x ≥ 4`, the sqrt will always be ≤ `x/2`, so I think I can tighten my bounds to `[1, x/2]` to save work.

- **Approach Taken**: 
  - Handle tiny inputs up front:
    - Read current bits:
      `x == 0` → `0`
      
      `x == (1 || 2 || 3)` → `1`
    
    - Search space: `[low, high] = [1, x/2]` (for `x ≥ 4`, the sqrt is ≤ `x/2`).
    - While `low ≤ high`:
      - `mid = low + (high - low) / 2` (avoids overflow)

      - If `x / mid == mid` → perfect square → return `mid`.

      - Else if `mid > x / mid` → `mid^2` > x → move left: `high = mid - 1`(look for smaller).

      - Else → `mid^2 < x` → move right: `low = mid + 1`(look for larger).
    
    - If loop ends (not a perfect square), `high` lands on the largest value with `high*high ≤ x`. Return `high`.

## Challenges
- **Obstacles Faced**: 
  - Overflow using `mid*mid`. Solved by using `x / mid `in comparisons.

  - Correct return when not a perfect square. Classic off-by-one; returning `high` after the loop gives floor.
- **Edge Cases**: 
  - `x = 0` → `0`.

  - `x = 1,2,3` → `1` (short-circuit to avoid `high = x/2 = 0` corner).

  - Very large `x` (near `2^31−1`) still fine because no `mid*mid`.

## Optimization
- **Time Complexity**: `O(log x)`, due to binary search over the answer space..
- **Space Complexity**: `O(1)`, no extra data structures, just constant extra variables.

<!-- ## Alternative Solutions
- None that come to mind. -->

## Key Takeaways
- Binary search the *answer*, not the data. Make sure to set bounds smartly and let the math guide comparisons.

- Ditch `mid*mid` on `int`; `mid` vs `x/mid` keeps things safe and clean.

- When the loop ends, high is your floor(√`x`), return it, not `low`.

<!-- ## Additional Resources
- N/A -->
