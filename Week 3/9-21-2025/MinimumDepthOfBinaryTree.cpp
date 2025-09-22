// 111. Minimum Depth of Binary Tree
// https://leetcode.com/problems/minimum-depth-of-binary-tree/

#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        
        queue<TreeNode*> q;
        q.push(root);

        int depth = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            depth++;
            
            for (int i = 0; i<levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                if (curr->left == nullptr && curr->right == nullptr)
                    return depth;
                
                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);              
            }
            
        }

        return -1;
    }
};