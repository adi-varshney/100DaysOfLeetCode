# Problem 8. String to Integer (atoi) - Notes

## Problem Understanding

- **Summary:** Implement a function that converts a string to a 32-bit signed integer (should behave like the `atoi()` function in C/C++ with clear parsing rules, further explained below).
- **Input:** A string `s` containing arbitrary characters.
- **Output:** A 32-bit signed integer in the range [`-2³¹`, `2³¹ - 1`].

## Approach

### Initial Thoughts

- I started by creating a list of the rules and edge cases.

  #### Rules

  - Ignore leading whitespace.
  - Determine sign (`'+'` or `'-'`).
  - Convert digits until a non-digit is found.
  - Clamp to integer bounds if overflow occurs.
  - Return `0` if no digits are found.

- Built-in `stoi` and `stoll` can simplify parsing but throw exceptions on invalid input or overflow(but also is more memory intensive and often times slower, so convenience comes at the cost of efficiency).
- The challenge is mainly handling spaces, sign detection, and clamping behavior correctly.
- Manually iterating over characters provides more control, but `stoi` is acceptable if exceptions are caught properly.

### Approach Taken

**Solution 1 (Manual sign tracking + `stoi`):**

- Uses a scanning loop to handle spaces, optional signs, and digits.
- Records sign using `positive` and `seenSign` flags.
- Extracts substring up to the first invalid character and converts using `stoi`.
- Catches `invalid_argument` and `out_of_range` exceptions to handle invalid and overflow cases.
- Clamps to `INT_MAX` or `INT_MIN` based on sign when overflow occurs.

**Solution 2 (Simplified `stoi` with sign inference):**

- Attempts to directly call `stoi(s)`.
- If overflow occurs, rescans the input to find the first non-space sign or digit.
- Returns `INT_MIN` if `'-'` appears first, else `INT_MAX`.
- Simpler but slightly less robust than Solution 1 for complex edge cases.

**Solution 3 (Most optimal – manual conversion):**

- Iterates through the string manually:
  - Skips leading spaces.
  - Handles sign detection.
  - Reads digits and accumulates into `ans`.
  - Checks overflow during accumulation, clamping immediately if necessary.
- Avoids exceptions and is the most efficient and reliable.
- Uses `long` to safely store temporary results.

### Complexity

- **Time:** `O(n)`, each character in the string is processed once.
- **Space:** `O(1)`, only a few variables are used, no extra data structures.

## Challenges

### Obstacles Faced

- Handling leading/trailing spaces correctly.
- Distinguishing between invalid inputs (like `"+-12"`) and valid signed numbers.
- Detecting overflow before it happens without using exceptions.

### Edge Cases

- `"   -042"` → `-42`
- `"4193 with words"` → `4193`
- `"words and 987"` → `0`
- `"-91283472332"` → `INT_MIN`
- `"2147483648"` → `INT_MAX`

## Alternative Solutions

- **Manual digit-by-digit parse with overflow pre-check:** Similar to Solution 3 but checks `(ans > INT_MAX / 10)` before multiplication.

## Key Takeaways

- Manual digit parsing (Solution 3) is fastest and safest since it avoids exceptions entirely.
- Always check for overflow before final multiplication or addition.
- Simplified `stoi` approaches are concise but less reliable for edge-case-heavy problems.
- Proper state handling (space → sign → digits) ensures correct behavior for all valid/invalid inputs.
