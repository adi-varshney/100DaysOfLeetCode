# Problem 217. Contains Duplicate - Notes

## Problem Understanding
- **Summary:** Given an integer array, return `true` if any value appears at least twice; otherwise return `false`.
- **Input:** `nums` — vector of integers (`1 <= nums.length <= 1e5`, each `nums[i]` in `[-1e9, 1e9]`).
- **Output:** Boolean indicating whether any duplicate exists.

## Approach
### Initial Thoughts
- Sorting groups equal values next to each other, so adjacent-equality implies a duplicate.
- A hash set can track seen values; encountering an already-seen value proves a duplicate.
- Sorting mutates input but uses little extra memory; a set preserves order but costs extra memory.

### Approach Taken
- **Solution 1 - Sort & Scan**
  - Sort `nums` in place.
  - Scan once and check if any `nums[i] == nums[i+1]`; return `true` if found, else `false`.
- **Solution 2 - Hash Set**
  - Maintain `unordered_set<int> seen`.
  - Insert the first element, then iterate; if `nums[i]` is in `seen`, return `true`, else insert and continue.
  - Return `false` if the loop finishes without a repeat.
- **Notes**
  - Problem constraints imply `nums.size() >= 1`, so accessing `nums[0]` is safe for the set approach.
  - If input must remain unmodified, prefer the set approach.

### Complexity:
- **Time:** 
  - Sort & Scan: `O(n log n)` for sort plus `O(n)` scan → overall `O(n log n)`.
  - Hash Set: average-case `O(n)` insert/find over `n` elements.
- **Space:** 
  - Sort & Scan: `O(1)` extra (in-place; ignoring sort implementation details).
  - Hash Set: `O(n)` extra for the set.

<!-- ## Challenges
### Obstacles Faced
- Placeholder.

### Edge Cases
- Placeholder.
-->

## Alternative Solutions
- Counting/bitset when the domain is small and bounded: `O(n)` time with `O(U)` space (not applicable here due to large value range).
- Early exit during input read by inserting into a set on the fly if streaming data is allowed.

## Key Takeaways
- Sorting + adjacent check is concise and memory-light but `O(n log n)` and mutates input.
- A hash set detects duplicates in one pass with average `O(n)` time at the cost of `O(n)` space.
- Always align the method with constraints and whether input mutation is acceptable.
