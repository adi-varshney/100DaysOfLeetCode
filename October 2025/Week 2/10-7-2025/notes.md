# Problem 203. Remove Linked List Elements - Notes

## Problem Understanding

- **Summary:** Remove all nodes from a singly linked list that have a value equal to a given integer `val`
- **Input:**
  - `head` (pointer to the first node of the linked list)
  - `val` (integer value to remove)
- **Output:** A pointer to the new head of the list with all nodes containing `val` removed

## Approach

### Initial Thoughts

- Need to traverse the list once and check each node’s value
- If a node’s value equals `val`, it should be skipped by adjusting pointers
- Might need to update `head` if the first few nodes are removed
- Nodes can appear consecutively or at the start/end of the list
- Removing the head node requires special handling since the head pointer must be updated

### Approach Taken

- First, handle edge case where the list is empty (`head == nullptr`)
- While the current head’s value equals `val`, move the head forward until it points to a valid node
- Store this cleaned `head` as `ans` (the new head)
- Traverse the list using a pointer
  - If the next node’s value equals `val`, skip it by linking to `head->next->next`
  - Otherwise, move to the next node
- Return the updated list’s head (`ans`)

### Complexity:

- **Time:** `O(n)`, one pass through all nodes
- **Space:** `O(1)`, in-place modification with constant extra memory

<!--
## Challenges
### Obstacles Faced
-

### Edge Cases
-
-->

## Alternative Solutions

- **Dummy Node Approach:** Create a sentinel node before the original head to handle head deletions more uniformly
- **Recursive Approach:** Recur through the list and return `head->next` if `head->val == val`, else connect `head` to the cleaned suffix

## Key Takeaways

- Skipping leading matches first prevents head-related bugs
- Pointer rewiring allows efficient deletion in a single traversal
- Dummy nodes can simplify pointer logic but increase setup overhead
- Reinforces understanding of pointer manipulation in linked lists
