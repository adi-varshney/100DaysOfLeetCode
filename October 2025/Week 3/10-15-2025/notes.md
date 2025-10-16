# Problem 228. Summary Ranges - Notes

## Problem Understanding
- **Summary:** Given a sorted, unique integer array `nums`, the goal is to return the smallest sorted list of ranges that exactly cover all numbers in the array. Each range represents consecutive integers grouped together.
- **Input:** `nums`, a sorted array of unique integers.
- **Output:** A vector of strings where each string represents a range:
  - `"a->b"` if the range has more than one number.
  - `"a"` if the range has only one number.

## Approach
### Initial Thoughts
- Since the array is sorted and contains unique integers, consecutive numbers differ by `1`.
- A range starts at a number and ends when the next number is not consecutive.
- We can use recursion to move through the array:
  - Keep track of the start and end of each range.
  - When the current number isn’t consecutive, record the range and continue recursively.

### Approach Taken
- Two recursive implementations were written:
  - **Solution1:** Recursive approach with string manipulation using `string_view` to parse and extend the last range. It maintains an internal recursive call stack where the function builds and finalizes ranges one at a time.
    - Each recursive call returns the *current working range* while storing finalized ranges in `ans`.
    - Uses the `find("->")` operation to detect whether the range is a single value or a span.
    - If the current number is consecutive with the last, the range is extended; otherwise, the completed range is pushed to `ans`.
  - **Solution2:** A cleaner recursive helper approach without string parsing.
    - A helper function processes from index `i`, extending `j` while numbers remain consecutive.
    - Adds the constructed range to `ans` (`"a->b"` or `"a"`) and recurses from the next index after the range.

### Complexity:
- **Time:** `O(n)`, Each element is visited once while checking for consecutive sequences.
- **Space:** `O(n)`, Result storage plus recursion stack for `n` elements in the worst case.

## Challenges
### Obstacles Faced
- Handling consecutive range detection using recursion without overlapping or missing elements.
- Maintaining consistent string manipulation while preserving efficiency in Solution1.
### Edge Cases
- Empty array → should return an empty vector.
- Array with one element → should return just that number (no arrow).
- All consecutive numbers → should return a single range `"start->end"`.


## Alternative Solutions
- **Iterative Two-Pointer Approach:** Use a simple loop with `start` and `end` pointers. When a break in sequence occurs, push the current range and reset pointers. This avoids recursion entirely and has the same complexity.

## Key Takeaways
- Recursive solutions can mimic iterative traversal when structured to finalize one range per call.
- Using `string_view` avoids unnecessary string copies and improves efficiency when parsing or extending strings.
- The clean helper recursion (Solution2) is more readable and efficient, illustrating the importance of simplicity in recursive range detection.
