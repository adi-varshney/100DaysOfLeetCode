# Problem 145. Binary Tree Postorder Traversal - Notes

## Problem Understanding
- **Summary:** return the postorder traversal of a binary tree which means visit left subtree then right subtree then the node itself (depth-first order is _L-child_ -> _R-child_ -> _Root_)
- **Input:** pointer to the root node of a binary tree `TreeNode*` where each node has `val` `left` and `right`
- **Output:** vector of integers `vector<int>` containing node values in postorder
<!-- - **Constraints:** time or space limits not explicitly stated in the prompt -->

## Approach

### Initial Thoughts
- According to the problem description, it seems that postorder is left then right then node so we can use dfs for that order just like the last _preorder_ traversal problem, except we need to edit the order in which we add to the output order
- I’m thinking a tiny helper that stops at `nullptr` then recurses left and right then records the value
- And again, just like last problem, the stack depth equals tree height which is fine for typical inputs but skewed trees could go deep
- Recursion is usually the simplest and least error-prone for now

### Approach Taken
- Use a class member `output` to collect values during traversal
- Define `traverse(node)` that returns immediately on `nullptr`
- Recurse into `node->left` then `node->right` then `push_back(node->val)` to `output`
- Call `traverse(root)` inside `postorderTraversal` and return `output`

### Complexity:
- **Time:** `O(n)` where `n` is the number of nodes because each node is visited once
- **Space:** `O(h)` for recursion call stack where `h` is tree height worst case `O(n)` for a skewed tree best case `O(log n)` for a balanced tree

<!--
## Challenges
### Obstacles Faced
- placeholder

### Edge Cases
- placeholder
-->

## Alternative Solutions
- Iterative with one stack and a visited flag or color marking to simulate the L R Root order
- Iterative with two stacks push root to stack1 pop to stack2 then push children to stack1 finally read stack2
- Morris style postorder using threaded traversal with temporary links and path reversals `O(1)` extra space but trickier to implement
- Divide and conquer style that returns vectors from subcalls then concatenates less efficient due to repeated allocations

## Key Takeaways
- Postorder naturally fits recursion because the action on the node happens after exploring children
- Recursive solution is the simplest to write and reason about with `O(n)` time and `O(h)` space
- Iterative methods avoid recursion depth limits and are useful for very deep or adversarial trees
