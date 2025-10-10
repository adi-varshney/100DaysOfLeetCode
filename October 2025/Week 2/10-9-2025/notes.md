# Problem 206. Reverse Linked List - Notes

## Problem Understanding
- **Summary:** Reverse a singly linked list and return the new head.
- **Input:** `head` pointer to the first node of a singly linked list.
- **Output:** Pointer to the head of the reversed list.

## Approach

### Initial Thoughts
- Reversing a singly linked list can be done iteratively by walking the list once and flipping each `next` pointer to point backward.
- Track three moving pointers to avoid losing access to the remainder of the list.
- Edge considerations include an empty list and a single-node list.

### Approach Taken
- Used three pointers: `prev`, `head`, and `n` where `n` is `head->next`.
- Loop while `n` is not `nullptr`.  
  - Redirect `head->next` to `prev`.  
  - Advance `prev` to `head`, `head` to `n`, and `n` to `n->next`.
- After the loop, `head` sits on the original tail. Created a new node `new ListNode(head->val, prev)` and returned it as the reversed list’s head.
- Note on behavior:  
  - This matches the submitted code and produces the correct reversed order.  
  - It allocates one new node for the former tail value and leaves the original tail node unreachable.

### Complexity:
- **Time:** `O(n)` for a single pass over the list.
- **Space:** `O(1)` auxiliary space, though it performs one extra node allocation.

<!--
## Challenges
### Obstacles Faced
- 
### Edge Cases
- 
-->

## Alternative Solutions
- **Iterative in-place reversal without allocation:**  
  - Continue the loop until `head` becomes `nullptr`, always rewiring `head->next = prev`, then return `prev` directly with no new node created.
- **Recursive reversal:**  
  - Recurse to the end, then unwind by pointing `next->next = node` and `node->next = nullptr`. Simpler to read but uses call stack `O(n)`.

## Key Takeaways
- Three-pointer iteration is the standard pattern for reversing a singly linked list in `O(n)` time and `O(1)` space.
- Avoid unnecessary allocations during reversal to prevent memory leaks and keep the operation purely in-place.
- Always check trivial cases early(empty list and single-node list should return as-is).
