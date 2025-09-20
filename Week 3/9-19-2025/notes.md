<!-- Problem 110. Balanced Binary Tree notes -->

# Problem Understanding
- **Summary:** Determine if a binary tree is **height-balanced** (the height difference between left and right subtrees of every node is at most 1).  
- **Input:** A _TreeNode_ which is the `root` of the binary tree (can be `null`).  
- **Output:** A _boolean_, `true` if the tree is height-balanced, otherwise `false`.  

# Approach

## Initial Thoughts
- Right away, I thought of using recursion to compute heights of subtrees and check differences.  
- For each node:  
  - Get left subtree height  
  - Get right subtree height  
  - Compare them, and also check that both children are balanced  
- This works, but calling `height()` repeatedly might cause inefficiency.  
- I realized this is basically a DFS where I’m recomputing a lot of work (top-down style), so worst-case performance could be bad(I basically understood there was a better solution but needed help exploring/implementing this better solution).

## Approach Taken (my two solutions)

### **First solution (intuitive O(N²))**
- Recursive function `isBalanced(root)`:
  - If null or single node → balanced.  
  - Get heights of left and right using helper `longestSubtree`.  
  - Check: `abs(leftHeight - rightHeight) ≤ 1` AND both children are balanced.  
- `longestSubtree` recursively returns `1 + max(height(left), height(right))`.  
- Works fine, but recalculates heights for the same nodes multiple times.

**Complexity:**  
- Time: Worst case `O(N²)` (skewed tree → height recomputed at every node).  
- Space: __`O(H)`__ recursion stack (H = height of tree).

---

### **Second solution (optimized O(N))**
- Use **post-order DFS** (bottom-up).  
- Helper `subtreeHeight(node)` returns height if subtree is balanced, else returns `-1`.  
- At each node:
  - Get left height, right height.  
  - If either is `-1`, or difference > 1 → return `-1`.  
  - Else return `1 + max(left, right)`.  
- Finally, `isBalanced(root)` checks if result != `-1`.

**Complexity:**  
- Time: __`O(N)`__ (each node visited once).  
- Space: `O(H)` recursion stack.

<!-- # Challenges

## Obstacles Faced
- 

## Edge Cases
- -->

# Optimization
- The **bottom-up sentinel method** avoids redundant height calls.  
- Detect imbalance early and stop further recursion.  
- Classic case where **post-order traversal** is better because parent’s validity depends on children’s info.

# Key Takeaways
- If you need info from children to decide a parent’s state, use **post-order DFS**(essentially, traverse left subtree of parent then right subtree of parent for every node to determine current state).  
- Avoid recomputation by **carrying results upward** (height + balance info together).  
- Early exit strategies (like using `-1` as a 'sentinel') make recursive tree algorithms more efficient.