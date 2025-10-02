# Problem 144. Binary Tree Preorder Traversal - Notes

## Problem Understanding
- **Summary:** return the preorder traversal(meaning the current node, then visit left child, then right child) of a binary tree
- **Input:** A `TreeNode* root` pointer to the root of a binary tree which may be null
- **Output:** A `vector<int>` list of node values in preorder
<!-- - **Constraints:** none explicitly stated for time or space -->

## Approach
### Initial Thoughts
- My first thought was that it would be easiest and most efficient to create an vector to hold our order and add to it as we traversed as intended using dfs
- In the main method we just need to call some recursive method that iterates through every node creating the call stack for methods in the order we want(preorder traversal, so prioritize and traverse the the left side of every subtree first, then right)

>The _most skewed trees_ will **dictate** the time complexity since recursion depth equals height of call stack(in dfs)

### Approach Taken
- Use a vector, `output`, to preserve order of values during traversal
- Wrote `traverse(node)` that pushes `node->val` then calls itself on `node->left` then `node->right`
- Returned `output` from `preorderTraversal` after a single call to `traverse(root)`
- Correctness comes from visiting each node exactly once before its children which matches preorder

### Complexity:
- **Time:** `O(n)` where `n` is the number of nodes since each node is processed once
- **Space:** `O(h)` auxiliary for recursion where `h` is tree height worst case `O(n)` on a skewed tree and best case `O(log n)` on a balanced tree

<!-- ## Challenges
### Obstacles Faced
- 
### Edge Cases
- empty tree should return an empty list
-->

## Alternative Solutions
- Iterative stack approach that pushes right child before left child to preserve preorder without recursion
- Morris preorder traversal that uses temporary threading for `O(1)` extra space at the cost of more complex pointer manipulations

## Key Takeaways
- Preorder means process node before exploring its subtrees
- Recursion mirrors the tree shape and makes preorder concise/easy
- An explicit stack reproduces the same order while avoiding recursion limits
