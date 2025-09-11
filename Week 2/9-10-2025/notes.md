<!-- Problem 67. Add Binary -->
## Problem Understanding
 - **Summary**: Given two *binary* strings `a` and `b`, return their sum as a *binary* string.
 - **Input**: Two strings, `a` and `b`, each made of `'0'` and `'1'` only (no leading zeros except the number `0` itself).
 - **Output**: A *String* representing `a + b` in base-2.

## Approach
- **Initial Thoughts**:
  - The easiest way to tackle this probably is most likely to keep an ongoing carry to take care of the possibility of hitting the next biggest power of 2.
  - Im thinking its probably best to implement this idea by walking from the rightmost bits to the left, add digits with a carry, and then, at the end, build the answer in reverse.
  - No need to convert to big integers, instead use `char` subtraction: `a.charAt(i) - '0'` gives the bit(`0` or `1`).
  - Make sure to keep in mind that lengths can differ and there might be a leftover `carry` and the very end.

- **Approach Taken**: 
  - Two pointers: `i = a.length() - 1`, `j = b.length() - 1`, and an `int carry = 0`.
  - While any work remains, `i >= 0 || j >= 0 || carry == 1`, do:
    - Read current bits:
      `dig1 = (i >= 0) ? a.charAt(i) - '0' : 0`
      `dig2 = (j >= 0) ? b.charAt(j) - '0' : 0`
    - Compute `total = dig1 + dig2 + carry`.
    - Append the result bit and update `carry`:
      - `total == 0` → append `'0'`, `carry = 0`
      - `total == 1` → append `'1'`, `carry = 0`
      - `total == 2` → append `'0'`, `carry = 1`
      - `total == 3` → append `'1'`, `carry = 1`
    - Decrement `i`, `j`.
  - Build with `StringBuilder`, then `result.reverse().toString()` for the final answer.
  - Also, if `a.equals("0")` return `b`; if `b.equals("0")` return `a`.

<!-- ## Challenges
- **Obstacles Faced**: Didn't consider the possibility that the stack could be empty mid loop during calculation. It was a small issue, and quickly resolved with one if statement.
- **Edge Cases**: Empty stack when checking for pairs. For example the following test case is where an issue arose: `')('` -->

## Optimization
- **Time Complexity**: `O(N+M)`, where `N = a.length()`, `M = b.length()` (linear pass + reverse).
- **Space Complexity**: `O(N+M)`, for the output string (can't avoid since result may be one longer than max(len(a), len(b))). `StringBuilder` is optimal for appends.

<!-- ## Alternative Solutions
- None that come to mind. -->

## Key Takeaways
- Keep it simple and add bits from the back(beginning of the binary number), and just carry as you go (works great and scales).
- `char - '0'` makes it simple to convert integer `char`s to integers.
- Build in reverse with `StringBuilder`, then flip it = Simple + fast.
- Remember to handle uneven lengths(ex. one binary number is longer than the other) and that last carry(in case the last digit carries) and you’re done.

<!-- ## Additional Resources
- N/A -->
