# Problem 108. Convert Sorted Array to Binary Search Tree - Notes

## Problem Understanding
- **Summary:** Build a **height-balanced BST** from a **sorted (ascending)** integer array.
- **Input:** An _int[](vector\<int> in c++) nums_ (may be empty).
- **Output:** A _TreeNode_ (root of the BST), or `null` if `nums.length == 0`.

## Approach
### Initial Thoughts
- Sorted array → pick the **middle** as root so left < root < right and the tree stays balanced.
- Recursively build subtrees on the left/right halves.
- Base case should allow a **single element** to become a leaf.
- Only stop on an **invalid window**(i.e. start index __not <__ end index).
- Use **indices** (`start`, `end`) instead of slicing.

### Approach Taken
- Helper `build(nums, start, end)`:
  1. If `start > end` → `null`.
  2. `mid = start + (end - start) / 2`.
  3. Create `root = new TreeNode(nums[mid])`.
  4. `root.left = build(nums, start, mid - 1)`.
  5. `root.right = build(nums, mid + 1, end)`.
- Call `build(nums, 0, nums.length - 1)` and return the root.

> Note: I used the TreeNode(int val, TreeNode left, TreeNode right) _constructor_ instead of manually setting `root.left` and `root.right`, but it works out all the same.

<!-- ## Challenges
### Obstacles Faced
- Off-by-one base case (`>=` instead of `>`), which killed length-1 windows.

### Edge Cases
- Empty array → `null`.
- Single element → one-node tree.
- Duplicates are OK with consistent placement.
- Works for any int range. -->

## Complexity
- **Time:** `O(n)` — each element becomes one node.
- **Space:** `O(log n)` recursion depth on a balanced tree (ignore allocated nodes). `O(n)` if counting all nodes allocated.

## Key Takeaways
- For **sorted** inputs, think **divide & conquer**(implemented through recursion) with **mid as root** for balance.
- Be precise with range-recursion base cases and stop on **invalid** range (`start > end`).
- Prefer index windows over slicing to keep memory low(in contrast to creating copies of sub-arrays).