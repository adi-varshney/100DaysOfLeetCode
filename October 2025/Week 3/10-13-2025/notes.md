# Problem 222. Count Complete Tree Nodes - Notes

## Problem Understanding
- **Summary:** Find how many nodes exist in a *complete binary tree* without having to visit every node.  
- **Input:** The `root` node of a complete binary tree.  
- **Output:** The total number of nodes in the tree as an integer.

## Approach
### Initial Thoughts
- A *complete binary tree* is a special kind of tree where:
  - Every level except possibly the last is completely full.
  - The last level is filled from left to right with no gaps.
- Because of this structure, we can use **binary search** instead of traversing the entire tree.
- If the tree has height `d` (number of edges on the leftmost path from root to leaf):
  - The first node on the last level has index `2^d`.
  - The last possible node (if the tree were full) has index `2^(d+1) - 1`.
- So, we can search for which of these possible nodes actually exist, the rightmost one will give the total node count.

### Approach Taken
- **Step 1: Find Tree Height (`d`)**
  - Start from the root and keep going left until you reach `nullptr`.
  - The number of edges you move down is the *depth* of the tree.
  - Example: If you move down twice before hitting `nullptr`, `d = 2`.

- **Step 2: Handle Small Cases**
  - If the tree is empty (`root == nullptr`), return `0`.
  - If only the root exists (`root->left == nullptr`), return `1`.

- **Step 3: Binary Search for the Last Node**
  - Think of each node in the tree as having an index (like positions in a complete array-based tree).
  - The possible range of indices for the last level is `[2^d, 2^(d+1) - 1]`.
  - Use binary search to find the largest index that still exists:
    1. Pick the middle index `mid`.
    2. To check if node `mid` exists:
       - Use the binary representation of `mid` to guide your path from the root.
       - Skip the most significant bit (since it just marks the root).
       - For each remaining bit:
         - `0` means go to the left child.
         - `1` means go to the right child.
       - If you reach a null pointer, that node doesn’t exist.
    3. If the node exists, move `left = mid + 1` (search further right).
    4. If it doesn’t exist, move `right = mid - 1` (search leftward).
  - When the loop ends, `right` will point to the index of the last existing node, which equals the total count of nodes.

### Complexity:
- **Time:** `O((log n)^2)`, each binary search step takes `O(log n)` time to traverse down the tree, and there are `O(log n)` such steps.
- **Space:** `O(1)`, only a few pointers and variables are used.

<!-- ## Challenges
### Obstacles Faced
-
### Edge Cases
-  -->

## Alternative Solutions
- Another way to solve this is using **height comparison**:
  - For any subtree, find both the leftmost and rightmost depths.
  - If they’re equal, that subtree is *perfect* (completely filled), so we can directly calculate its nodes using `2^height - 1`.
  - Otherwise, recursively count nodes in the left and right subtrees.
  - This also runs in `O((log n)^2)` but doesn’t use binary search.

## Key Takeaways
- The structure of a complete binary tree allows counting nodes efficiently without visiting them all.  
- Binary search over node indices helps locate the last existing node quickly.  
- Bitwise traversal (`0 → left`, `1 → right`) translates each index into a direct path from root to leaf.  
- This approach cleverly combines tree properties with binary search and bit manipulation to reduce complexity.
