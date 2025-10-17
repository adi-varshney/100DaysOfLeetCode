# Problem 231. Power of Two - Notes

## Problem Understanding

- **Summary:** Determine if an integer `n` is a power of two
- **Input:** Integer `n` in 32-bit range
- **Output:** Boolean indicating whether `n` equals `2^k` for some integer `k >= 0`

## Approach

### Initial Thoughts

- Power of two means exactly one set bit in binary representation
- Alternate ideas include repeated division by two until one or a remainder appears
- A math idea is using `log2(n)` and checking if it is an integer

### Approach Taken

- Guard against nonpositive values since powers of two are positive only
- Compute `log2(n)` and compare it to its truncated version
- If the logarithm is an integer then `n` is a power of two
- Note on precision since floating point can round near large powers and cause mistakes

### Complexity:

- **Time:** `O(1)`
- **Space:** `O(1)`

<!-- ## Challenges
### Obstacles Faced
-
### Edge Cases
-  -->

## Alternative Solutions

- Bit trick using single set bit check with `n > 0` and `(n & (n - 1)) == 0`
- Bit count check with `n > 0` and `__builtin_popcount(n) == 1`
- Division loop with `while n % 2 == 0` then check `n == 1`
- Divisibility by highest power in range with `n > 0` and `(1 << 30) % n == 0` for 32-bit signed integers

## Key Takeaways

- Powers of two have one set bit which enables simple `O(1)` bit checks
- Floating point comparisons can be unsafe near large values or due to rounding
- Prefer integer bitwise methods for robustness and clarity
