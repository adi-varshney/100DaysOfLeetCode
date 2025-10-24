# Problem 12. Integer To Roman - Notes

## Problem Understanding

- **Summary:** Convert a given integer to its Roman numeral representation using the standard rules with subtractive notation.
- **Input:** An integer `num`.
- **Output:** A string representing `num` in Roman numerals.
- **Constraints:** `1 ≤ num ≤ 3999` and Roman rules use subtractive pairs for 4 and 9 at each place value.

## Approach

### Initial Thoughts

- Roman numerals are built from place values in thousands, hundreds, tens, and ones with special cases at 4 and 9.
- A greedy strategy works by taking the largest possible Roman value first and subtracting it from the number.
- A table lookup per digit also works by indexing prebuilt strings for each place value.
- The number of symbols and operations is bounded by a small constant due to the constraint up to 3999.

### Approach Taken

- Solution 1 uses a straightforward greedy construction per place value with while loops and explicit checks for 9, ≥5, 4, and the remainder.
- Solution 2 builds four lookup arrays for ones, tens, hundreds, and thousands and concatenates the indexed strings from each digit.
- Correctness follows from the canonical Roman system where greedy selection and placewise tables both cover all valid compositions without ambiguity.
- Common pitfalls include forgetting subtractive pairs, mishandling indexes for thousands, and mixing single characters with multi character strings.

### Complexity:

- **Time:** `O(1)` due to a fixed upper bound on operations for numbers up to 3999.
- **Space:** `O(1)` since only a constant amount of extra storage is used.

<!--
## Challenges
### Obstacles Faced
### Edge Cases
-->

## Alternative Solutions

- Greedy with a value symbol list by iterating over pairs like `(1000, "M"), (900, "CM"), (500, "D"), ...` subtracting and appending while `num` remains.
- Precompute a combined map for all place values into a single ordered list to simplify loops and reduce branching.
- Use integer division and remainder chaining with a compact table to minimize conditional checks while preserving readability.

## Key Takeaways

- Subtractive notation at 4 and 9 for each place value is the main detail to handle correctly.
- Both explicit greedy loops and digit indexed lookup tables are clean and run in `O(1)`.
- Constraints up to 3999 ensure thousands are only `""`, `"M"`, `"MM"`, or `"MMM"`.
- Clear mapping and consistent reduction of `num` prevent off by one or indexing mistakes.
