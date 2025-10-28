<!-- Problem 242. Valid Anagram notes -->

# Problem 242. Valid Anagram - Notes

## Problem Understanding

- **Summary:** check if `t` is an anagram of `s` by verifying equal character multiset
- **Input:** two strings `s` and `t`
- **Output:** `true` if they are anagrams and `false` otherwise
- **Follow up/Constraint:** handle cases where inputs may include Unicode characters

## Approach

### Initial Thoughts

- If the strings differ in length, they can’t be anagrams.
- A frequency count is the most efficient check, each character’s occurrences must balance out.
- Two maps work but use unnecessary memory since both store similar data.
- Using a single map that increments for `s` and decrements for `t` halves memory usage.
- For lowercase-only inputs, a fixed-size array of length 26 outperforms maps entirely.

### Approach Taken

- **First solution:** Uses two `unordered_map<char, int>` structures, one for each string, then checks equality.
- **Improved solution:** Uses one `unordered_map` and updates counts in a single pass, verifying all final counts are zero.
- This design minimizes overhead while maintaining readability and linear runtime.

### Complexity:

- **Time:** `O(n)`,  every character is processed once.
- **Space:** `O(k)`, number of unique characters (`≤26` for lowercase inputs).

## Challenges

### Obstacles Faced

- Forgetting to handle unequal lengths early wastes unnecessary work.
- Comparing two hash maps directly is slower than maintaining a single counter map.
- Maps introduce extra hashing overhead compared to array indexing.

### Edge Cases

- Empty strings → return `true`.
- Single-character strings → only equal if identical.
- Repeated letters → must correctly cancel to zero.
- Long inputs → must stay within `O(n)` time.

## Optimization

- Replace the `unordered_map` with an integer array of size 26 for constant-time lookups.
- Early exit once a negative count appears, immediately confirms mismatch.
- Reserve space in hash maps to avoid rehashing if large input sizes are expected.
- Sorting-based solution (`sort(s.begin(), s.end()) == sort(t.begin(), t.end())`) is simpler but slower at `O(n log n)`.

## Alternative Solutions

- **Array-based solution:** fixed-size array for `a–z`, best for lowercase letters.
- **Unicode-ready version:** use `unordered_map<char32_t, int>` to handle broader character sets.
- **Sorting version:** conceptually simple, modifies inputs, slower for large strings.

## Key Takeaways

- Counting frequencies provides the cleanest `O(n)` solution.
- Using one map is twice as efficient as using two.
- Fixed arrays outperform maps when the character range is small and known.
- Always handle unequal lengths upfront for quick rejection.

<!-- Alternative Solutions -->
<!-- Additional Resources -->
