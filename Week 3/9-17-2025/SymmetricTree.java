// 101. Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/

//Definition for a binary tree node.
class TreeNode {
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

@SuppressWarnings("unused")
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null || (root.left == null && root.right == null))
            return true;
        else if (root.left == null && root.right != null || root.right == null && root.left != null)
            return false;
        else if (root.left.val == root.right.val)
            return isSymmetric(root.left, root.right);
        else
            return false;
    }

    public boolean isSymmetric(TreeNode leftChild, TreeNode rightChild) {
        // handle all potential null and false cases first
        if ((leftChild.left == null && rightChild.right == null) && (leftChild.right == null && rightChild.left == null)) {
            return true; // if all null, then return true(no more children to check and it is symmetric)
        }
        
        if ((leftChild.left == null && rightChild.right != null) || (leftChild.left != null && rightChild.right == null)) {
            return false; // if one node in the outer pair is null, but not the other then return false(is not symmetric)
        }
        
        if ((rightChild.left == null && leftChild.right != null) || (rightChild.left != null && leftChild.right == null)) {
            return false; // if one node in the inner pair is null, but not the other then return false(is not symmetric)
        }

        if (leftChild.left == null && rightChild.right == null)
            if (rightChild.left.val == leftChild.right.val)
                return isSymmetric(rightChild.left, leftChild.right); // if one pair is null(outer), and other is true(inner)
            else
                return false;
        else if (rightChild.left == null && leftChild.right == null)
            if (leftChild.left.val == rightChild.right.val)
                return isSymmetric(leftChild.left, rightChild.right); // if one pair is true(outer), and other is null(inner)
            else
                return false;
        else if ((leftChild.left.val == rightChild.right.val) && (rightChild.left.val == leftChild.right.val))
            return isSymmetric(leftChild.left, rightChild.right) && isSymmetric(rightChild.left, leftChild.right); // if all equal each other
        else 
            return false;
        
    }
}