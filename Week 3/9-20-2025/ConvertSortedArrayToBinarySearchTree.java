// 108. Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

// Definition for a binary tree node.
class TreeNode {
    @SuppressWarnings("unused")
    int val;
    @SuppressWarnings("unused")
    TreeNode left;
    @SuppressWarnings("unused")
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

@SuppressWarnings("unused")
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        return createChildren(nums, 0, nums.length-1);
    }

    public TreeNode createChildren(int[] nums, int start, int end) {
        int middle = start + (end-start)/2;

        if (start > end)
            return null;
        
        return new TreeNode(nums[middle], createChildren(nums, start, middle-1), createChildren(nums, middle+1, end));
    }
}
