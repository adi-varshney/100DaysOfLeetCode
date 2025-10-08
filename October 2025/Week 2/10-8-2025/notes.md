# Problem 205. Isomorphic Strings - Notes

## Problem Understanding
- **Summary:**  
  Determine if two strings `s` and `t` are isomorphic, meaning the characters in `s` can be replaced to form `t` while maintaining order and consistent one-to-one mapping.
- **Input:**  
  Two strings `s` and `t` of equal length.
- **Output:**  
  `true` if `s` and `t` are isomorphic, otherwise `false`.

## Approach
### Initial Thoughts
- Need to ensure a bijection (one-to-one mapping) between characters of both strings.
- Must check both directions so that no two characters in `s` map to the same character in `t`.
- Use two maps: one for `s → t` and another for `t → s`.
- Iterate once through the strings to verify consistent mapping.

### Approach Taken
- Created two unordered maps `ST` and `TS` to track mappings.
- For each index `i`:
  - If neither character is mapped, add `ST[s[i]] = t[i]` and `TS[t[i]] = s[i]`.
  - If mappings exist, verify consistency in both directions.
  - Return `false` immediately if any mismatch occurs.
- Return `true` if loop completes without conflicts.

### Complexity:
- **Time:** `O(n)` — single pass through both strings.  
- **Space:** `O(1)` — constant size due to limited character set (or `O(k)` for distinct characters).

<!-- ## Challenges
### Obstacles Faced
- 
### Edge Cases
-  -->

## Alternative Solutions
- **Array Mapping Approach:**  
  Use two integer arrays of size 256 to store character relationships directly (faster and memory-efficient for ASCII).
- **Pattern Encoding Approach:**  
  Replace each character with its first occurrence index and compare the resulting encoded patterns for equality.

## Key Takeaways
- Always check mapping in both directions to enforce a true bijection.
- Using two hash maps prevents multiple characters from mapping to one.
- Fixed-size array method is simpler and faster for ASCII inputs.
- Strengthened understanding of bijective relationships and string structure preservation.
