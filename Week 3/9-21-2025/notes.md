<!-- Problem 111. Minimum Depth of Binary Tree notes -->

## Problem Understanding

- **Summary:** Return the **minimum depth** (the number of nodes along the shortest path from the root → leaf node).
- **Input:** A _TreeNode_ which is the `root` (can be `null`).
- **Output:** An _int_, which is the depth of the tree (0 if tree is empty).

## Approach

### Initial Thoughts

- At first, I thought about traversing the entire tree like I usually do with DFS, but since the problem asks for the **minimum** depth, BFS feels more natural/applicable to this problem.
- With BFS, you explore level by level, so the first time you hit a leaf node (a node with no left or right child), you immediately know that’s the minimum depth.
- So in my head it made more sense to "just stop as soon as you hit a leaf with BFS, instead of going all the way down everywhere (DFS)." That way you avoid unnecessary work.

### Approach Taken

- If the root is `nullptr`, return `0` (empty tree).
- If the root itself is a leaf, return `1`.
- Use a `queue<TreeNode*>` to do level-order traversal.
- Keep track of depth, incrementing each time you move to a new level.
- For every node:
  - If it’s a leaf, return the current depth.
  - Otherwise, push its non-null children into the queue.
- This works because the first leaf encountered in BFS guarantees the shortest path.

## Challenges

- Initially declared `queue<TreeNode>` instead of `queue<TreeNode*>`, which caused pointer/value mismatch errors.
- Needed to handle `root == nullptr` upfront to avoid segmentation faults.

## Edge Cases

- Tree is empty (`root == nullptr`) → return 0.
- Tree has only one node (the root, which is also a leaf) → return 1.
- Very unbalanced tree (like a linked list) → depth equals the number of nodes.

## Complexity

- **Time:** `O(N)`, each node visited once.
- **Space:** `O(W)`, where W is the max width of the tree (≤ N).

## Key Takeaways

- BFS is usually best for **minimum depth** problems because it can short-circuit as soon as a leaf is found.
- Always remember to enqueue the root(i might have made that mistake once, oopsieee)!
- Be careful with pointer vs value types in C++ (`TreeNode*` vs `TreeNode`).
  - Still a little confused on this so will have to look into this more later

## Alternative Solutions

- **Recursive DFS:**
  - Explore left and right subtrees, return `1 + min(leftDepth, rightDepth)` but carefully handle null children.
  - Works but explores all paths, even when the min is already found.
- **DFS with stack (iterative):** Similar to BFS but less efficient for min depth since you may traverse deeper unnecessarily.
