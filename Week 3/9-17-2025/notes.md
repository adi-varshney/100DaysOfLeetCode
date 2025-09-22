<!-- Problem 101. Symmetric Tree notes -->

## Problem Understanding

- **Summary**: Check if a binary tree is a mirror of itself around its center(meaning that for every pair of nodes at symmetric positions, values must match and their children must cross-match: L.left ↔ R.right and L.right ↔ R.left.).
- **Input**: A TreeNode `root`.
- **Output**: A boolean, `true` if it is a mirror; otherwise, `false`.

## Approach

### Initial Thoughts

- "Symmetric" → literally a mirror. So I shouldn’t walk one tree. I should compare **left vs right at the same time**.
- If both nodes are `null`, that spot is fine. If one’s `null` and the other isn’t, that breaks symmetry. If values differ, also a break.
- The real idea here is **cross children**. We need to compare `L.left` with `R.right` and `L.right` with `R.left`. That’s the '_mirror_'.
- This is just recursive DFS on **pairs**(No fancy traversal needed).
- I kept thinking the parent compare should also "catch" the kids, but that check actually happens **in the next recursive call** on those two child nodes, not at the parent level.
- Never touch `.val` before confirming not `null`. Early returns save me from Null Pointer Exceptions(I'll be referring to them as NPEs from here on forward).

### Approach Taken(although can be written MUCH more compact/concisely):

- Handle root fast: empty tree or single node → `true`; exactly one child → `false`.
- If `root.left.val == root.right.val`, call a helper with `(left, right)`.
- **Helper** is a "guard-all-cases-first" style:
  - Explicitly checks every `null`/non-`null` combo for the **outer** pair (`left.left` vs `right.right`) and **inner** pair (`left.right` vs `right.left`), returning `false` on any mismatch.
  - If values line up, recurse on mirrored grandchildren:
    - `isSymmetric(left.left, right.right)` and `isSymmetric(right.left, left.right)`.
- This ordering avoids NPEs and only recurses when structures are compatible.

<!-- ## Challenges
- **Obstacles Faced**:  -->

### Edge Cases

- `root == null` → `true`.
- Single node → `true`.
- Exactly one child at root → `false`.
- Structural asymmetry deeper down (one missing mirrored node).
- Very tall/skewed trees (stack depth).

### Complexity

- **Time**: `O(N)`, each node participates in at most one mirrored comparison.
- **Space**: `O(H)` recursion stack (balanced `≈ O(log N)`, skewed `≈ O(N)`).

<!-- ## Alternative Solutions
- none -->

## Key Takeaways

- Mirror problems = **pairwise comparison**

- The many nested `if`s for every null case are verbose and easy to slip an NPE; ordering early exits correctly matters.

- The core pattern to recognize symmetry is to utilize **cross-child recursion**.

- Cleaner structure beats long conditional ladders, and simpler code(_if possible_) is almost always better.

<!-- ## Additional Resources
- N/A -->
