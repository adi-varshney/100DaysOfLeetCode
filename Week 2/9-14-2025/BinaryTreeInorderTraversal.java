// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/ 

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;


// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();

        if (root == null)
            return ans;

        Stack<TreeNode> s = new Stack();
        s.push(root);

        int lastPopped = -101;
        while (!s.empty()) {
            if (s.peek().right == null) { // right doesn't exist
                if (s.peek().left != null && (ans.isEmpty() || s.peek().left.val != lastPopped)) { // left exists and
                                                                                                   // you haven't
                                                                                                   // checked it
                    s.push(s.peek().left); // go left
                } else { // left doesn't exist/you have checked it
                    lastPopped = s.pop().val;
                    ans.add(lastPopped); // go to parent(you are done with this node)
                }
            } else { // right exists
                if (ans.isEmpty() || s.peek().right.val != lastPopped) { // check right to see if you haven't already
                                                                         // gone there
                    if (s.peek().left != null && (ans.isEmpty() || s.peek().left.val != lastPopped)) { // left exists
                                                                                                       // and you
                                                                                                       // haven't
                                                                                                       // checked it
                        s.push(s.peek().left); // go left
                    } else { // left doesn't exist/you have checked it
                        ans.add(s.peek().val);
                        s.push(s.peek().right); // go right
                    }
                } else {
                    lastPopped = s.pop().val;
                    // ans.add(lastPopped); // go to parent(you are done with this node)
                }
            }
        }

        return ans;
    }
}

// much cleaner solution
class Solution2 {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();

        if (root == null)
            return ans;

        Stack<TreeNode> s = new Stack();
        TreeNode curr = root;

        while (curr != null || !s.empty()) {
            while (curr != null) { // go left as far as possible
                s.push(curr);
                curr = curr.left;
            }
            curr = s.pop(); // go to parent
            ans.add(curr.val); // add parent
            curr = curr.right; // go right
        }

        return ans;
    }
}