## Problem Understanding

- **Summary**: Given a binary tree, return its inorder traversal (Left → Node → Right) as a list of integers.
- **Input**: Root `TreeNode root` (may be `null`).
- **Output**: A `List<Integer>` with the inorder sequence.

## Approach

- **Initial Thoughts**:

  - I know inorder is _left, visit, right_. Recursion is easy, but I wanted to implement iterative as I hadn't done it before with binary trees.

  - I tried to simulate the call-stack with a `Stack<TreeNode>`.

  - My idea was to keep pushing children like I’m walking the tree; then, check which node I just finished to avoid re-walking subtrees.

  - I used `lastPopped` (the last node value I popped) to guess if I already returned from a child, then decide to go left, visit, or go right.

- **Approach Taken**:

  - Early return if `root == null`.

  - Push `root` on a `Stack<TreeNode>`.

  - Maintain `int lastPopped = -101` (outside valid `val` range on LeetCode).

  - If `peek().right == null`:

    - If left exists and `left.val != lastPopped`, push left.

    - Else pop current, set `lastPopped`, and visit (add to `ans`).

  - Else (right exists):

    - If `right.val != lastPopped`:

      - If left exists and `left.val != lastPopped`, push left.

      - Else _visit_ current and push right.

    - Else (we’ve returned from right): pop current (done).

  - Return `ans`.

## Challenges

- **Obstacles Faced**:

  - I first tried checking against `ans.get(ans.size()-1)` (last visited value). That fails when a subtree has depth because the last visited value isn’t necessarily the immediate child. Switching to `lastPopped` fixed the obvious double-add and some loops.

  - Had to remove the extra `ans.add(...)` after returning from right; otherwise nodes with right children were added twice.

  - Using `.val` to infer structure is fool proof and only works here only because duplicates aren’t in the judge(guess i kinda got lucky here).

- **Edge Cases Checked**:

  - `root == null` → return `[]`.

  - Single-node tree → `[root.val]`.

  - Purely left-skewed or right-skewed trees → should traverse linearly.

  - Duplicates: this method is not safe if duplicate `val`s appear (not tested in LC #94).

## Optimization

- **Time Complexity**: `O(N)`, where N = total number of nodes, because each node is pushed/popped/visited a constant number of times.
- **Space Complexity**: `O(N)`, worst case for the height of the stack is N.

## Alternative Solutions

- Cleaner Iterative (pointer + stack)

  - Idea: simulate recursion directly. Keep a pointer `cur` and a stack `s`.

    - While `cur` isn’t null, keep pushing it and move to `cur.left` (this builds the left spine like recursion would).

    - When you hit `null`, pop from the stack → that node’s left is done, so visit it.

    - Then set `cur = popped.right` and repeat.

  - Why it works: each node is pushed once on the way down its left path and popped once when its left is finished. No value-based checks, so duplicates are fine.

  - Time Complexity: `O(N)`, each node pushed/popped/visited once.

  - Space Complexity: `O(H)` auxiliary, stack depth equals tree height (worst `O(N)`, balanced `O(log N)`).

  - Code is the second solution in my `.java` file.

## Key Takeaways

- Don’t use node values to encode traversal state (structure > values).

- The classic iterative inorder is basically “simulate recursion”: **left spine push** → **pop/visit** → **go right**.

- The inner `while` isn’t something to immediately ignore. It’s just "shovel everything left" so the next pop is the correct inorder visit.

- If I need flags, store pointer/state (e.g., `(node, leftDone)`), not `val`.
