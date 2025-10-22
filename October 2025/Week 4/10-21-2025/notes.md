# Problem 5. Longest Palindromic Substring - Notes

## Problem Understanding

- **Summary:** Return the longest contiguous substring that reads the same forwards and backwards.
- **Input:** A string `s` of English letters and digits.
- **Output:** The longest palindromic substring of `s`.

## Approach

### Initial Thoughts

- Expanding around centers is simple and effective.
- Every palindrome has a center at a character or between two characters.
- Track the best window using indices with an exclusive right end.
- A helper that checks bounds and equality keeps expansion clean.
- Early returns avoid edge case bugs on very short strings.

### Approach Taken

- Handle `s.size() ≤ 1` with a direct return.
- Handle `s.size() == 2` by comparing the two characters.
- Maintain `left` and `right` as the best window with `right` exclusive.
- For each index `i`, expand odd center with `(i-1, i+1)` while characters match.
- After each expansion set `L = leftCurr + 1` and `R = rightCurr` and update the best window if `(R - L)` is larger.
- For each index `i`, expand even center with `(i, i+1)` and update using the same `L` and `R` rule.
- Return `s.substr(left, right - left)` using the exclusive right convention.

### Complexity:

- **Time:** `O(n^2)`
- **Space:** `O(1)`

## Challenges

### Obstacles Faced

- Off by one mistakes from mixing inclusive and exclusive ends.

### Edge Cases

- Uniform strings and leading even centers require careful indexing.

## Alternative Solutions

- Manacher’s Algorithm achieves `O(n)` time with higher implementation complexity(This is SUPER niche and won't be used in interviews or other situations for the most part).
- Dynamic Programming uses `O(n^2)` time and `O(n^2)` space by marking palindromic intervals(I personally feel like my expanding centers approach is easier to implement and more intuitive than using DP here).

## Key Takeaways

- Use an exclusive right index to simplify substring handling.
- Check both odd and even centers to capture all palindromes.
- Centralized bound checks reduce duplication and bugs.
- Small early returns keep the main loop straightforward.
