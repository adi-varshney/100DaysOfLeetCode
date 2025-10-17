# Problem 2. Add Two Numbers - Notes

## Problem Understanding
- **Summary:** Add two non-empty linked lists where digits are stored in reverse order and return the sum as a linked list
- **Input:** Heads `l1`, `l2` of singly linked lists where each node holds one digit in reverse order
- **Output:** Head of a new linked list representing the digit-wise sum in reverse order

## Approach
### Initial Thoughts
- Use a dummy head to simplify building the result list and returning it cleanly
- Walk both lists in parallel adding current digits plus a running carry
- Create a new node for each resulting digit and advance pointers as available
- Append a final node if a carry remains after the loop

### Approach Taken
- Start `ans` as a dummy node and track `head` as the builder pointer
- Maintain `carry` initialized to zero and loop while either `l1` or `l2` exists
- For each step compute `sum` from available node values plus `carry` then set `head->val` to `sum % 10`
- Update `carry` to `1` if `sum >= 10` else `0` and advance `l1` and `l2` when present
- After the loop attach a last node with the leftover `carry` if nonzero and return `ans->next`

### Complexity:
- **Time:** `O(max(m, n))`
- **Space:** `O(max(m, n))`

<!--
## Challenges
### Obstacles Faced
- 
### Edge Cases
- 
-->

## Alternative Solutions
- Add in place by reusing nodes from one list when mutation is allowed and lengths differ only by traversal
- Recursive addition carrying the overflow forward for concise code at the cost of call stack usage
- For forward-order inputs use stacks to reverse traversal then add, which mirrors this solution’s logic

## Key Takeaways
- Dummy head simplifies linked-list construction and return handling
- Carry management is the core of digit-wise addition on lists
- Iterate until both lists are exhausted then handle any remaining carry
