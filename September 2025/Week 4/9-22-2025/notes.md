# Problem 112. Path Sum - Notes

## Problem Understanding
- **Summary:** Determine if there exists any **root-to-leaf** path whose node values **sum to `targetSum`**.
- **Input:** A _TreeNode_ which is the `root` (can be `nullptr`) and an _int_ `targetSum`.
- **Output:** A _bool_, `true` if at least one root→leaf path sums to `targetSum`, else `false`.

## Approach

### Initial Thoughts
- ok this looks like a classic tree traversal/check. i need *root-to-leaf*, not any prefix ending at an internal node.
- i think the idea here is to walk down the tree and keep a running sum. when i hit a leaf, compare to `targetSum`.
- recursion/dfs is the most obvious solution here(in my opinion), so pass either the **current sum so far** or the **remaining sum**. both work.
- i’ll also add a _'short-circuit'_ as soon as left or right returns true, _'bubble'_(as in no need to go forward with the rest of the program, just return true at that point and terminate) it up.

### Approach Taken (what I coded)
- First check if `root == nullptr`, return `false`.
- Use a helper `findLeaf(node, currSum, target)`:
  - add `node->val` to `currSum`.
  - if node is a **leaf** (`!left && !right`), return `currSum == target`.
  - otherwise, recurse on `left` and `right`, OR the results to short-circuit.
- This is a recursive DFS that accumulates the sum on the way down.

**Time Complexity:** `O(N)`, each node is visited once.  
**Space Complexity:** `O(H)`, recursion stack height `H` (worst-case `O(N)` for a skewed tree; `O(log N)` for balanced).

<!-- ## Challenges

### Obstacles Faced
-

## Optimization
-  -->


## Alternative Solutions (with complexities)

1) **DFS with “remaining sum” (subtract downwards)**
   - Logic: at each node, set `remaining = targetSum - node->val`; if leaf, check `remaining == 0`; else recurse(pretty much the same as my implementation).
   - **Time:** `O(N)`  
   - **Space:** `O(H)`

2) **Iterative DFS (stack of pairs)**
   - Use `stack<pair<TreeNode*, int>>` storing `(node, currSum)`. Pop, check leaf, push children with updated sums.
   - **Time:** `O(N)`  
   - **Space:** `O(H)` (stack holds at most one path’s worth of nodes; worst-case skew)

3) **BFS (queue of pairs)**
   - Use `queue<pair<TreeNode*, int>>`; level-order through the tree, tracking running sums; return true if any leaf hits target.
   - **Time:** `O(N)`  
   - **Space:** `O(W)` where `W` is max width of the tree (≤ `N`)

## Key Takeaways
- Only **root-to-leaf** paths count; always check at **leaf**.
- Recursive DFS is the most direct: pass running or remaining sum; both are clean and `O(N)`/`O(H)`.
- Iterative (stack/queue) versions are straightforward swaps if recursion depth is a concern.
