# Problem 206. Reverse Linked List - Notes

## Problem Understanding
- **Summary:** Reverse a singly linked list and return the new head.
- **Input:** `head` pointer to the first node of a singly linked list.
- **Output:** Pointer to the head of the reversed list.

## Approach

### Initial Thoughts
- Flip each node’s `next` pointer so links point backward.
- Keep three moving pointers so the remainder of the list is never lost.
- Handle empty and single-node lists cleanly.

### Approach Taken
- Used three pointers: `prev`, `head`, and `n` where `n` starts as `head->next`.
- While `n` is not `nullptr`, rewired `head->next = prev`, advanced `prev = head`, advanced `head = n`, advanced `n = n->next`.
- After the loop, rewired the final node with `head->next = prev` and returned `head` as the new head.
- No new allocations were made and the reversal is fully in-place.

### Complexity:
- **Time:** `O(n)`
- **Space:** `O(1)`

<!--
## Challenges
### Obstacles Faced
- 
### Edge Cases
- 
-->

## Alternative Solutions
- Iterative variant using only two pointers by storing `next` in a temporary variable each step.
- Recursive reversal that reaches the tail then sets `next->next = node` and `node->next = nullptr` while unwinding, with call-stack space `O(n)`.

## Key Takeaways
- The three-pointer pattern is the standard in-place reversal for singly linked lists.
- Returning the last processed node after wiring its `next` to `prev` yields the new head without extra allocation.
- Always consider trivial cases early to keep code simple and safe.
