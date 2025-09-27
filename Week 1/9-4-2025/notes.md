# Problem 21. Merge Two Sorted Lists - Notes
## Problem Understanding
 - **Summary**: Given the heads(_first element/position_) for two(2) __sorted__ linked lists, merge both lists into 1 __sorted__ linked list.
 - **Input**: Two(2) `ListNode` objects, each representing the head of a sorted linked list, where each node stores an `integer` value.
 - **Output**: A single `ListNode` that is the head of the merged sorted linked list.

## Approach
 - **Initial Thoughts**:
     * Well to make a merge the linked lists, we need we need to start by iterating through all the nodes of each and add whichever one is least. However, since we only have access to the head nodes of the input lists, we cannot directly append to the end of a result list. Therefore we will need two loops:
       + One that will create the first merged list.
       + One that will reverse the merged list. 
     * This is because when we first create the merged list, it will have to be in reverse order as we start at the smallest ends of the two given linked lists. 
     * Finally, we reverse the constructed list to restore the correct order (least to greatest) before returning its head. 
  <!-- * Finally, once we reverse the linked list, we return the head and we are done. -->

 - **Approach Taken**:
  * Compare the current nodes of `list1` and `list2`.
  * Append the smaller node to a temporary list (`sort`) such that nodes are inserted at the head (reverse building).
  * Continue until one or both lists are exhausted.
  * If one list remains, append the remaining nodes in the same way.
  * Reverse the temporary list (`sort`) to produce the final correctly ordered linked list.
  * Return the new head node.

<!-- ## Challenges
 - **Obstacles Faced**:
 - **Edge Cases**: -->

## Optimization
- **Time Complexity**: `O(N + M)`, where `N` and `M` are the lengths of the two lists.  
  We traverse every node once to build the reversed list and once more to reverse it.
- **Space Complexity**: `O(N + M)`.  
  Each new `ListNode` is created during the merge process. The reversing step does not require extra memory beyond pointers (`prev`, `next`).

<!-- ## Alternative Solutions
- None that come to mind. -->

## Key Takeaways
- Learned how to merge two linked lists when only head nodes are available, by:
  * Building in reverse order,
  * and then reverse the linked list.
 - Learned how to efficiently reverse a linked list without needing to allocate extra memory.
   * Create `prev` and `next` nodes/variables to change/move the head of the list forward.
 - Also reinforced that ListNode.next doesn't actually remove the current node, it simply gives the pointer to the next node.

<!-- ## Additional Resources
- N/A -->