<!-- Problem 234. Palindrome Linked List - Notes -->

# Problem 234. Palindrome Linked List - Notes

## Problem Understanding

- **Summary:** Check whether a singly linked list reads the same forward and backward.
- **Input:** `head` of a singly linked list.
- **Output:** `true` if the list is a palindrome, otherwise `false`.
- **Constraint:** Aim for `O(n)` time and `O(1)` extra space.

## Approach

### Initial Thoughts

- I can get `O(1)` space by reversing only half of the list and then comparing halves.
- I need a clean way to know where the midpoint is and whether to skip the middle node for odd length.
- Pointer movement is the tricky part, not the comparison itself.

### Approach Taken

- **Length pass:** Walk once to compute `length`.
- **Reverse first half:** Iterate `length/2` steps from the head while reversing pointers in place.
- **Skip middle on odd:** If `length` is odd, advance the pointer on the second half by one.
- **Compare halves:** Walk the reversed first half and the remaining second half in lockstep and compare values.
- **Return result:** If all values match, return `true`, else `false`.
- **Notes:** This matches the follow-up since reversal is in place and only a few pointers are used.

### Complexity:

- **Time:** `O(n)`
- **Space:** `O(1)`

## Challenges

### Obstacles Faced

- **Pointer safety:** Keeping `curr`, `prev`, and `nxt` in the right order during the half reversal.
- **Odd length handling:** Remembering to skip the center node so it is not compared against anything.
- **Off-by-one risks:** Ensuring exactly `length/2` nodes are reversed.

### Edge Cases

- **Single node or empty:** Always palindrome.
- **Two nodes:** Works whether equal or not due to half reversal of one node.
- **All equal values:** Comparison still passes.
- **Highly unbalanced values:** Early mismatch should short-circuit correctly.

## Optimization

- **Two-pointer middle find:** Use `slow` and `fast` to find the midpoint without a separate length pass.
- **Reverse from middle:** Reverse the second half starting at `slow` and compare with the head.
- **Optional restore:** Reverse again after the check if the original list must be preserved.

## Alternative Solutions

- **Stack approach:** Push first half onto a stack and then compare while walking the second half.
  - Time `O(n)`, Space `O(n)`.
- **Array copy:** Copy values into a vector then two-pointer compare.
  - Time `O(n)`, Space `O(n)`.
- **Recursive check:** Compare mirrored nodes using recursion, but risks stack depth and extra space.

<!--
## Additional Resources
- Typical fast and slow pointer patterns for linked lists.
- In-place reversal template for singly linked lists.
-->

## Key Takeaways

- Reversing half the list enables `O(1)` extra space palindrome checks.
- Handling the odd middle element is essential for correctness.
- A fast–slow pointer midpoint find removes the need for an initial length pass while keeping the same `O(n)` and `O(1)`.
