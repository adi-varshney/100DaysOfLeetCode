// 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/

// Definition for a binary tree node.
class TreeNode {
    @SuppressWarnings("unused")
    int val;
    TreeNode left;
    TreeNode right;

    @SuppressWarnings("unused")
    TreeNode() {
    }

    @SuppressWarnings("unused")
    TreeNode(int val) {
        this.val = val;
    }

    @SuppressWarnings("unused")
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

// first intuitive solution I came up with - O(N^2) worst case time complexity
@SuppressWarnings("unused")
class Solution {
    public boolean isBalanced(TreeNode root) {
        if (root == null || (root.left == null && root.right == null))
            return true;
        return Math.abs(longestSubtree(root.left) - longestSubtree(root.right)) <= 1
                && (isBalanced(root.left) && isBalanced(root.right));
    }

    public int longestSubtree(TreeNode curr) {
        if (curr == null)
            return 0;

        return Math.max(longestSubtree(curr.left), longestSubtree(curr.right)) + 1;
    }
}

// second solution(had to use hints/outside resources to produce implmentation) - O(N) time complexity
@SuppressWarnings("unused")
class Solution2 {
    public boolean isBalanced(TreeNode root) {
        return subtreeHeight(root) != -1;
    }

    public int subtreeHeight(TreeNode curr) {
        if (curr == null)
            return 0;

        int ls = subtreeHeight(curr.left), rs = subtreeHeight(curr.right);
        if (ls == -1 || rs == -1)
            return -1;

        if (Math.abs(ls - rs) > 1)
            return -1;
        else
            return Math.max(ls, rs) + 1;
    }
}