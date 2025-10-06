# Problem 190. Reverse Bits - Notes

## Problem Understanding
- **Summary:** Reverse the 32-bit binary representation of an integer and return the resulting integer (treat the value as a 32-bit quantity even if the parameter type is `int`).
- **Input:** 32-bit integer `n`, interpreted bitwise over exactly 32 positions.
- **Output:** 32-bit integer whose bits are in the reverse order of `n`.
<!-- - **Constraints:** Explicit time or space constraints are not listed in the prompt. -->

## Approach

### Initial Thoughts
- I can scan all 32 positions from least significant to most significant and build the answer from left to right.
- Shifting is cleaner than using `pow` and avoids floating-point inaccuracies.
- Each step:  
  - Shift `ans` to the left by 1 (making space for the next bit).  
  - Extract the least significant bit from `n` using `(n & 1)`.  
  - Add that bit to `ans` using `ans |= (n & 1)` or by incrementing if it’s `1`.  
- Right-shifting `n` by 1 each iteration ensures we move through all bits.

### Approach Taken
- Loop exactly 32 times to cover all bits.  
  - On each iteration:
    - Left shift `ans` by one.  
    - Merge the current bit with `ans` using `ans |= (n & 1)`.  
    - Right shift `n` by one to move to the next bit.
- Prefer the pure bit manipulation method (Solution 2 or 3) since:  
  - It’s faster and avoids floating-point math.  
  - It directly works with binary operations, which are both efficient and exact.
- Signed integer edge case:  
  - Using `(n & 1)` is safe since it always extracts the least significant bit.  
  - Looping exactly 32 times reconstructs all bits correctly, regardless of sign.

### Complexity:
- **Time:** `O(32)` → `O(1)`  
- **Space:** `O(1)`

<!--
## Challenges
### Obstacles Faced
- 
### Edge Cases
- 
-->

<!-- ## Alternative Solutions -->

## Key Takeaways
- Bit manipulation provides an efficient and elegant way to solve constant-time problems.  
- Always prefer shifting (`<<`, `>>`, `&`, `|`) over math functions like `pow()` for bit-level tasks.  
- Pay attention to operator precedence, always use parentheses when mixing bitwise and logical comparisons.  
- Understanding these low-level patterns is essential for mastering binary arithmetic, masks, and hardware-efficient algorithms.  
- Practicing problems like this strengthens intuition for **bit manipulation**, an important concept for optimization and system-level programming.
