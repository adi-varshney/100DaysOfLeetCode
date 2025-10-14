# Problem 226. Invert Binary Tree - Notes

## Problem Understanding
- **Summary:** Invert a binary tree by swapping every node’s left and right child pointers and return the root
- **Input:** Pointer `root` to the root of a binary tree with fields `val`, `left`, and `right`
- **Output:** Pointer to the root of the same tree after all left and right pointers are swapped

## Approach
### Initial Thoughts
- The operation at each node is a local swap of the two child pointers
- Recursion fits naturally because each subtree is the same problem
- A `nullptr` node or a leaf needs no further work and should be returned as is
- Swapping before recursion avoids traversing outdated pointers

### Approach Taken
- Check the base case and return `root` if it is `nullptr` or it is a leaf
- Swap left and right children:
    - Store `root->left` in a temporary pointer to preserve it during the swap
    - Assign `root->left = root->right` and then `root->right = temp` to complete the swap
- Recursively call `invertTree(root->left)` and `invertTree(root->right)` to invert the subtrees
- Return `root` so parent frames can relink correctly after recursion

### Complexity:
- **Time:** `O(n)` because each of the `n` nodes is visited once
- **Space:** `O(h)` for the recursion call stack where `h` is tree height with worst case `O(n)` and balanced case `O(log n)`

<!--
## Challenges
### Obstacles Faced
- 

### Edge Cases
- 
-->

## Alternative Solutions
- Iterative depth first traversal using a stack where each popped node is swapped and its non null children are pushed
- Iterative breadth first traversal using a queue to process nodes level by level and swap children for each node

## Key Takeaways
- Tree inversion is a classic per node swap combined with recursion
- Swapping children before recursive calls simplifies reasoning about traversal
- Space usage depends on tree height and may degrade on skewed trees
