# Problem 191. Number of 1 Bits - Notes

## Problem Understanding
- **Summary:** Count the number of `1`s (set bits) in the binary representation of an unsigned integer `n`. This is also known as finding the **Hamming weight**.  
- **Input:** `n`, an unsigned integer.  
- **Output:** integer(_`int`_), total count of bits in `n` that are set to `1`.  
<!-- - **Constraints:** Not explicitly stated in the prompt. -->

## Approach

### Initial Thoughts
- Counting bits means examining each bit position in `n`.
- Using `log2()` and `pow()` can work but is inefficient and relies on floating-point math.
- A simpler and faster approach is to check the least significant bit (LSB) using `% 2` or `n & 1`.
- Right-shifting `n` (`n >>= 1`) repeatedly helps iterate through all bits efficiently.

### Approach Taken
- **Solution 1 (Using powers of two):**
  - While `n > 0`:
    - Find the largest power of 2 less than or equal to `n` using `log2(n)`.
    - Subtract that value from `n` and increment the counter.
  - Works but is slower and prone to precision issues due to floating-point operations.
- **Solution 2 (Bitwise approach, this was better solution(memory wise? idk it used less memory in Leetcode's judge but that could be a system discrepancy)):**
  - While `n > 0`:
    - Check if the least significant bit is `1` using `n & 1`.
    - Increment the counter if true.
    - Right-shift `n` (`n >>= 1`) to process the next bit.
  - Cleaner and fully integer-based, avoiding floating-point math entirely.

### Complexity:
- **Time:** `O(32)` or just `O(1)`, constant time since integers have 32 bits.  
- **Space:** `O(1)`, uses only a few integer variables.  

<!--
## Challenges
### Obstacles Faced
- Remembering to use `n & 1` instead of `% 2` for clarity and efficiency.
- Handling potential issues with signed vs. unsigned bit shifts.
### Edge Cases
- `n = 0` → 0 bits set.
- Powers of two → exactly one bit set.
-->

## Alternative Solutions
- **Brian Kernighan’s Algorithm:**  
  - Repeatedly apply `n = n & (n - 1)` until `n` becomes 0.  
  - Each iteration removes one set bit, so the number of iterations equals the number of `1`s.  
  - More efficient when `n` has few bits set.
- **Built-in Function:**  
  - Use `__builtin_popcount(n)` (GCC/Clang) or `__popcnt()` (MSVC) for a direct hardware-level count.

## Key Takeaways
- Learning more about **bit manipulation** is extremely valuable for efficient low-level problem-solving.
- Bitwise operations make counting set bits much simpler and faster.  
- Using `n & 1` and `n >>= 1` provides a clean way to traverse each bit.  
- Brian Kernighan’s trick optimizes further by skipping zero bits.  
