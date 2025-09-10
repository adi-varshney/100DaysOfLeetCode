<!-- Problem 6. One Plus notes -->
## Problem Understanding
- **Summary**: Given an `int[]` which represents a number(each index is a digit of the entire number), increment it by one, and return the array of the incremented number. 
- **Input**: An *integer array*(`int[]`), digits.
- **Output**: Another *integer array*(`int[]`), which is the array format of the number incremented by one.

## Approach
- **Initial Thoughts**: 
    - This problem seems easy for the most part, as long as we make sure to take all edge cases (digits as `9`s, as described below in the *Challenges* section) into consideration.
    - Just need to increment the first digit from the right that isn’t `9`.
    - If there **is/are** `9` digit(s), then you need to *carry the 1* until you find the first digit that isn’t a `9`.
    - If you can’t find a non-nine digit, then you must create a new array for the next power of ten (i.e., `999` → `1000`).

- **Approach Taken**: 
    - Check the **last** digit:
    - If it’s **not** `9`, just do `digits[n-1]++` and return `digits`, and we're done.
    - Otherwise, walk left with an index `i` until:
        - You hit a digit that **isn’t** `9` → `digits[i]++`, then set everything to the right (`i+1 … end`) to `0`, and return `digits`.
    - Or you reach the front and it’s still `9` → the number was all `9`s. Create a new array of size `n+1` with `1` at the first index(index `0`) and the rest `0`s, and return that.

## Challenges
- **Obstacles Faced**: Carrying the `1` across a run of trailing `9`s without messing up indexes.
- **Edge Cases**:
    - Numbers starting with the digit `9`(or had multiple `9`s in row).
        - Single digit `9` → `[9]` becomes `[1,0]`.
        - Trailing `9`s → `[1,9,9]` becomes `[2,0,0]`.
        - All `9`s → `[9,9,9]` becomes `[1,0,0,0]`.
        - No `9`s at all → quick early return (e.g., `[2,3,4]` → `[2,3,5]`).

## Optimization
- **Time Complexity**: `O(k)` where `k` = the number of trailing 9s (worst-case `O(n)` when the array is all `9`s). Most inputs return in `O(1)` due to the early exit on the last digit.
- **Space Complexity**: `O(1)` in-place when there exists a non-`9` digit. `O(n)` only in the *all-9s* case where we allocate a new array of length `n+1`.

<!-- ## Alternative Solutions
- None that I, at least, could come up with. -->

## Key Takeaways
- *Don’t overthink it*, and just treat it like real addition with carry.
- Early returns are can cut times by a lot (like if the last digit isn’t `9`, just bump and bounce).
- When you do hit `9`s, **increment the first non**-`9` **and zero everything to the right**.
- All `9`s? Make a new array (`1` followed by zeros).
- Avoid converting the array to a big `int`/`long` (due to possible overflow and as it's not needed here).
- Watch the off-by-one on the left scan and make sure you handle the “never found a non-`9`” path.

<!-- ## Additional Resources
- N/A -->