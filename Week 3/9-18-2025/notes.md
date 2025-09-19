<!-- Problem 104. Maximum Depth of Binary Tree notes -->

## Problem Understanding

- **Summary:** Return the **maximum depth** (number of nodes on the longest path from root → leaf).
- **Input:** A _TreeNode_ which is the `root` (can be `null`).
- **Output:** An _int_, which is the depth of the tree (0 if tree is empty).

## Approach

### Initial Thoughts

- Depth = how many **levels** tall the tree is.
- The main two ways(at least in my head) to traverse a graph are:
  - **DFS (recursive):** ask left/right for depths, take `max + 1`. Feels like the most direct definition.
  - **BFS (level order):** walk level by level; each full level processed ⇒ `depth++`.
- I specifically wanted to **practice BFS** here even though the classic recursive DFS is a one-liner(also included recursive DFS solution).

### Approach Taken (my code)

- **BFS version (what I wrote first):**

  1. If `root == null` → return `0`.
  2. Use `ArrayDeque<TreeNode>`; `add(root)`.
  3. While queue not empty(there are still levels to go):
     - `depth++` for the new level.
     - `currSize = queue.size()` **once** (freeze the level size).
     - Pop exactly `currSize` nodes; for each, enqueue its non-null children.
  4. Return `depth`.

- **Recursive DFS (faster in practice on LC):**
  - Base case: `null → 0`.
  - `maxDepth(node) = max(maxDepth(node.left), maxDepth(node.right)) + 1`.

## Challenges

### Obstacles Faced

- **Queue-size trap (BFS):** I initially thought I could loop on `i < queue.size()` because the for loop freezes the value(looking back its seems like a trivial silly mistake I made __¯\\\_(ツ)\_/¯__). That breaks because `size()` increases as I push children, so I overrun the level. Fix = store `currSize` before the inner loop.

<!-- ### Edge Cases

- none -->

## Optimization

- **Time:** **O(N)** for both BFS and DFS (each node visited once).
- **Space:**
  - **BFS:** **O(W)** where `W` is max width (worst-case `O(N)`).
  - **DFS (recursive):** **O(H)** call stack (`H` = height; worst `O(N)` skewed, ~`O(log N)` balanced).

<!-- ## Alternative Solutions -->

## Key Takeaways

- For height/depth questions, think **`max(left, right) + 1`** first.
- **BFS by levels** works fine, just **freeze the level size**.
- Both are **O(N)** time; the speed diff is mainly constant factors (recursion often wins here).
