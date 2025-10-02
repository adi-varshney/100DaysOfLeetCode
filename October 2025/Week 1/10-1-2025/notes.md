# Problem 160. Intersection of Two Linked Lists - Notes

## Problem Understanding
- **Summary:** Given heads of two singly linked lists `headA` and `headB` find the first node where they intersect by reference not by value return that node or `null` if they never meet
- **Input:** Two pointers to the starts of singly linked lists that may or may not share a tail segment
- **Output:** A pointer to the intersecting `ListNode` or `nullptr` if no intersection
- **Constraints:** Time complexity of `O(n+m)` and space complexity of `O(1)` 

## Approach

### Initial Thoughts
- My first solution used a hash set to store visited nodes then scan the other list which was simple but required extra memory(space complexity `O(n)` rather than the `O(1)` constraint)
- Since we need to check if the two lists every point to the same nodes we can check physical node address using `==`(pointer comparison works)
- I wanted `O(1)` space so I looked for a trick to align both lists before walking together
- Computing lengths then advancing the longer list to align seemed straightforward and easy to reason about

### Approach Taken
- Walk both lists once to compute their lengths while advancing as far as possible with two walkers
- After the first pass subtract lengths to find the difference then advance the longer head by that difference so both pointers have equal distance to the tail
- Move `headA` and `headB` forward in lockstep and compare pointers
- Return the first node where `headA == headB` otherwise return `nullptr` when both reach the end
- This matches my code which aligns by length then does a synchronized traversal

### Complexity:
- **Time:** `O(n + m)` where `n` and `m` are lengths of the two lists
- **Space:** `O(1)`

<!-- ## Challenges
### Obstacles Faced
- 
### Edge Cases
- lists with no intersection
- one list is empty
- intersection at the very first node of either list
-->

## Alternative Solutions
- **Two-pointer switching (concise)**
  - **Idea:** equalize distance by letting each pointer walk both lists; the length difference cancels.
  - **Steps:** set `pA=headA`, `pB=headB`; loop  
    `while (pA != pB) { pA = pA ? pA->next : headB; pB = pB ? pB->next : headA; }`  
    return `pA` (either the intersection or `nullptr`).
  - **Why it works:** each pointer travels `lenA + lenB` steps → they align at the first common node or end together.
  - **Complexity:** **Time:** `O(n + m)` • **Space:** `O(1)`
    - >Honestly I think that this solution is better than mine but both my second solution and this alternate solution fit constraints and are AC(accepted)
- Hash set method(my first inefficient solution) insert all nodes of list A then scan list B and return the first node found in the set simpler logic but space `O(n)`

## Key Takeaways
- Intersection means shared node identity pointer equality not value equality
- Aligning distances to the tail lets a lockstep walk find the first common node clean and `O(1)` space
- The switching trick is an elegant alternative that avoids explicit length math and still gives `O(1)` space
