// 104. Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

// Definition for a binary tree node.

import java.util.ArrayDeque;

class TreeNode {
    @SuppressWarnings("unused")
    int val;
    TreeNode left;
    TreeNode right;
    @SuppressWarnings("unused")
    TreeNode() {}
    @SuppressWarnings("unused")
    TreeNode(int val) { this.val = val; }
    @SuppressWarnings("unused")
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}


// bfs solution that I wanted to try to make for the first time
// runs in 1ms = beating ~13% solutions, slower than recursive dfs
@SuppressWarnings("unused")
class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null)
            return 0;
        
        ArrayDeque<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);

        int depth = 0;
        while (!queue.isEmpty()) {
            depth++;
            
            //TreeNode[] arr = queue.toArray(new TreeNode[0]); // debugging
            //for (TreeNode o: arr) {
                //System.out.print(o.val + " ");
            //}
            //System.out.println();
            int currSize = queue.size(); // we actually need to create a variable for this, unlike i originally thought, otherwise it updates throughout the for loop creating issues in iteration

            // traversing the current level
            for (int i = 0; i<currSize; i++) {
                TreeNode curr = queue.pollFirst();

                if (curr.right != null) {
                    queue.add(curr.right);
                }

                if (curr.left != null) {
                    queue.add(curr.left);
                }
            }
        }

        return depth;
    }
}

// better/faster recursive dfs solution
// runs in 0ms = beating all solutions
@SuppressWarnings("unused")
class Solution2 {
    public int maxDepth(TreeNode currNode) {
        if (currNode == null) return 0;

        return Math.max(maxDepth(currNode.left), maxDepth(currNode.right)) + 1;        
    }
}