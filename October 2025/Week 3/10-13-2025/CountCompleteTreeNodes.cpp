// 222. Count Complete Tree Nodes
// https://leetcode.com/problems/count-complete-tree-nodes/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr) return 1;

        int d = findLeftDepth(root);
        // cout << d << endl;

        int left  = 1 << d;
        int right = (1 << (d + 1)) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // find if mid exists in the last level
            // Start from the bit just below the MSB (skip the root’s implicit '1')
            int mask = 1 << (d - 1);

            TreeNode* curr = root;

            // cout << endl << "left: " << left << "\nright: " << right << "\n\n";
            // cout << "mid: " << mid << "\n";

            while (mask && curr) {
                // cout << "curr node value: " << curr->val << "\n";
                if (mid & mask) 
                    curr = curr->right;    // bit 1 -> go right
                else             
                    curr = curr->left;     // bit 0 -> go left
                
                mask >>= 1;
            }

            if (curr == nullptr) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }

    int findLeftDepth(TreeNode* curr) {
        if (curr == nullptr)
            return -1;
        return 1+findLeftDepth(curr->left);
    }
};
