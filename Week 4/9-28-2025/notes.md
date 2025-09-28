# Problem 141. Linked List Cycle - Notes

## Problem Understanding

- **Summary:** Determine if a singly linked list contains a cycle
- **Input:** Pointer `head` to the first node of a singly linked list where each node is `ListNode { int val; ListNode* next; }`
- **Output:** `true` if some node is revisited by following `next` repeatedly otherwise `false`
- **Constraints:** List can be empty values may repeat nodes are unique by address mutations to node values are not guaranteed to be allowed

## Approach

### Initial Thoughts

- First thing I thought of was just tracking visited nodes with a set that works but takes `O(n)` extra space
- Then I realized you could also mutate the list by marking values as visited (like setting them to `INT_MAX`) which technically passed but felt like a hack and probably not the intended solution
- At that point I was stuck because both ideas had drawbacks (extra memory vs mutating input)
- I looked back at the problem page and saw one of the tagged topics was “two pointers” which made me think about fast/slow pointer patterns
- Since we can only start from the head node it couldn’t be left/right pointer style it had to be slow/fast traversal
- From there I pieced together the idea that if one pointer moves twice as fast as the other they will meet again if a cycle exists
- That realization gave me the intended approach (fast and slow two pointer method) even though I didn’t know the formal name for it

### Approach Taken

- Use the fast and slow two pointer method
  - Initialize `slow = head` and `fast = head ? head->next : nullptr`
  - While `fast != nullptr` **and** `fast->next != nullptr`
    - If `slow == fast` return `true`
    - Advance `slow = slow->next` and `fast = fast->next->next`
  - If loop ends return `false`
- Why this works
  - In a cycle the fast pointer gains one node per step on the slow pointer and must meet within at most `cycle_length` steps
  - Without a cycle the fast pointer reaches `nullptr` and loop exits safely
- Guard details that avoid runtime errors
  - Check both `fast` and `fast->next` before doing `fast->next->next`
  - Starting `fast = head->next` avoids an immediate match when `head` is not `nullptr` and keeps the equality check simple

### Complexity:

- **Time:** `O(n)` where `n` is number of nodes visited until meeting or termination
- **Space:** `O(1)` extra

<!--
## Challenges
### Obstacles Faced
-

### Edge Cases
-
-->

## Alternative Solutions

- Hash set of visited node addresses(My _first_ solution)
  - Insert each node pointer into `unordered_set<ListNode*>`
  - If a node is already present return `true`
  - **Time:** `O(n)` average **Space:** `O(n)` which violates constant space goal
- Mutate node values as a visited mark(My _second_ solution)
  - Set `node->val = INT_MAX` then check for repeats
  - Not safe because it mutates input may collide with legitimate `INT_MAX` values breaks const correctness and can corrupt data used elsewhere
  - **Time:** `O(n)` **Space:** `O(1)` but not acceptable under typical problem constraints
- Modify structure with a temporary sentinel pointer or self loop
  - Also mutates the list and risks losing original structure if an early return happens not recommended

## Key Takeaways

- Fast and slow two pointer method gives `O(n)` time and `O(1)` space with simple pointer math
- Always guard `fast` and `fast->next` before jumping two steps to prevent crashes/RE(Runtime Errors)s
- Avoid solutions that mutate node values or links because inputs are not guaranteed to be disposable or writable
