# Problem 3. Longest Substring Without Repeating Characters - Notes

## Problem Understanding

- **Summary:** find the length of the longest contiguous substring with all unique characters.
- **Input:** a string `s` that may include letters, digits, symbols, and spaces.
- **Output:** an integer length of the longest substring without duplicate characters.

## Approach

### Initial Thoughts

- I think this screams sliding window with two pointers.
- I move `right` to expand while chars are unique.
- I move `left` when I hit a repeat to restore uniqueness.
- A set can tell me if a char is already in the window.
- An index table can jump `left` forward past the last duplicate faster.
- I should update the best length on each safe expansion.

### Approach Taken

- **Solution 1 - Sliding Window with `unordered_set`**
  - Keep `seen` for characters currently in the window.
  - Start `left = 0` and `right = 1` after inserting `s[0]`.
  - If `s[right]` is in `seen`, update `longest` with `right - left` then erase `s[left]` and move `left`.
  - Else insert `s[right]` and move `right`.
  - After the loop do a final `longest = max(longest, right - left)` to catch the tail window.
  - Handles empty or single length strings early.
- **Solution 2 - Optimized Sliding Window with last seen indexes**
  - Use `lastIndex` sized `128` filled with `-1` for ASCII.
  - Walk `right` from `0` to `n - 1`.
  - Set `left = max(left, lastIndex[s[right]] + 1)` to jump past the previous occurrence if it sits inside the current window.
    - **Why the `max` when moving `left`?**
      - It prevents `left` from moving backward when the last duplicate lies before the current window which would corrupt correctness.
  - Update `longest = max(longest, right - left + 1)` every step.
  - Record `lastIndex[s[right]] = right`.
  - Early return for empty or single length strings.

### Complexity:

- **Time:** `O(n)` for both solutions since each character is processed at most twice.
- **Space:** `O(min(n, charset))` for Solution 1 due to the set and `O(1)` for Solution 2 due to fixed size `128` table.

## Challenges

### Obstacles Faced

- Off by one when computing window length required careful `right - left + 1` for inclusive bounds.
- Remembering to update the answer after the loop in Solution 1 to include the final window.

### Edge Cases

- Empty string returns `0`.
- Single character string returns `1`.
- Repeats clustered like "bbbbbb".
- Mixed symbols and spaces still treated as valid distinct characters.

## Alternative Solutions

- Use an `unordered_map<char,int>` for last positions instead of a fixed array to support larger charsets.
- Use a `bitset<256>` for ASCII presence with a parallel queue or indexes though index jumping is cleaner.

## Key Takeaways

- Sliding window plus two pointers is the core pattern for no repeat substring.
- Jumping `left` with last seen indexes gives a clean `O(n)` pass with `O(1)` space.
- Always keep `left` monotonic using `max` and update best length on each safe step.
- Do a final best length check when a loop might end without a closing update.
