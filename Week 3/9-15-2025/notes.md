<!-- Problem 100. Same Tree notes -->

## Problem Understanding

- **Summary**: Given roots `p` and `q`, return `true` if the two binary trees are **structurally identical** _(essentially each node on one tree has a corresponding node on the other binary trees in the same position)_ **and** each _corresponding node_ has the **same value**.
- **Input**: Two `TreeNode` references, `p` and `q` (each may be `null`).
- **Output**: A `boolean`, `true` if the trees match exactly; otherwise false.

## Approach

- **Initial Thoughts**:

  - I think of this is just a generic graph traversal problem. Binary trees are just a special case of graphs(where there can't be any cycles, which only makes our solutions easier :D), and when you’re traversing graphs you usually pick between **DFS** or **BFS**.

  - In this case, recursive DFS is super easy to implement(which is what I did). Start at the root, check the current nodes, then dive into the left and right children. You just mirror the traversal on both trees at the same time.

  - The core idea is to make the base cases very clear:

    - if both nodes are `null` → match (`true`)

    - if one node is `null` but not the other → mismatch (`false`)

  - Once those null cases are clean, the rest is just checking the values and recursing down.

- **Approach Taken**:

  - Handle `null`s up front:

  - both `null` → `true`

  - one `null` → `false`

  - Otherwise compare `p.val == q.val` and recurse on `(p.left, q.left)` and `(p.right, q.right)`.

  - Return the **AND** of both subtree checks.

<!-- ## Challenges
- **Obstacles Faced**:
- **Edge Cases**: None -->

## Complexity

- **Time**: `O(N)`, where `N` is the number of nodes visited across the trees (in the equal-size/equal-shape case, that’s all nodes). Each node is compared once.
- **Space**: `O(H)` for recursion stack, where `H` is tree height (worst-case `O(N)`, best/avg balanced `O(log N)`).

## Alternative Solutions

- Iterative BFS/DFS with a queue/stack:
    - Push a pair `(p, q)` onto a queue/stack.

    - While not empty:

        - Pop `(a, b)`. If both `null`, continue. If exactly one is `null`, return `false`.

        - If `a.val != b.val`, return `false`.

        - Push `(a.left, b.left)` and `(a.right, b.right)`.

    - If the loop finishes, return `true`.

    - Same complexities: Time `O(N)`, Space `O(W)` where `W` is max width (BFS) or `O(H)` for stack (DFS).

## Key Takeaways

- Think of binary trees as graphs; traversal can be __DFS__ or __BFS__, but recursion makes DFS super simple.

- Set clean base cases first; it prevents annoying `null` bugs.

- Recursion depth can matter since balanced trees keep stack small (`O(log N)`), skewed ones don’t (`O(N)`).

<!-- ## Additional Resources
- N/A -->
