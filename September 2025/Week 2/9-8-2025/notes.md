# Problem 58. Length of Last Word - Notes
## Problem Understanding

- **Summary**: Given a _String_ of words, return the length of the last word in the _String_. There can be extra spaces anywhere, and a word is defined as an consecutive letters without spaces in between them.
- **Input**: A single _String_, `s`.
- **Output**: An _integer_, the length of the last word in the _String_, `s`.

## Approach
- **Initial Thoughts**:
    - This is a pretty simple problem, just iterate from the back, until you find the first non-space character.
    - Once you find the first letter/non-space(' ') character, just start a while loop that increments a count until you reach the next space.
    - Once you reach the next space while iterating backwards, it means you have found the beginning of the last word, so you exit and return the count.

- **Approach Taken**:
    - Initialize `i = s.length() - 1` and `length = 0`.
    - Skip trailing spaces by using a `while (i >= 0)` and `s.charAt(i) == ' '` to decrement `i`.
    - Then, count the last word's length using another `while (i >= 0)` and `s.charAt(i) != ' '` to increment `length` and decrement `i`.
    - Return `length`.
    - This handles leading/trailing/multiple spaces and the “single-word string” case as well.

<!-- ## Challenges
- **Obstacles Faced**:
- **Edge Cases**: None -->

## Optimization
 - **Time Complexity**: `O(N)`, where N = s.length(). Each character is checked at most once (moving left).
 - **Space Complexity**: `O(1)`, no extra data structure are required. Only constant space is used for counters/indexes.

## Alternative Solutions
 - Call s = s.trim() first, then scan backward to the previous space (or start). Same O(N) time, still O(1) space.
 - Use s.trim() and lastIndexOf(' '): answer is s.length() - 1 - s.lastIndexOf(' ') after trimming. Beware of -1 when the string is a single word.

## Key Takeaways
 - Scanning from the end is a common pattern for “last word/trailing spaces” problems.
 - Always guard index checks in the correct order: i >= 0 && s.charAt(i) ... to avoid out-of-bounds.
 - Prefer pointer scans over split() to keep space O(1).

<!-- ## Additional Resources
- N/A -->
