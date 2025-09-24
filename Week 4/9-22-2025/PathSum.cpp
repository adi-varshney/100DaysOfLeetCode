// 112. Path Sum
// https://leetcode.com/problems/path-sum/

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        
        return findLeaf(root, 0, targetSum);
    }

    bool findLeaf(TreeNode* curr, int currSum, int targetSum) {
        if (curr == nullptr)
            return false;
            
        currSum += curr->val;
        if (!curr->left && !curr->right)
            return currSum == targetSum;
        else
            return findLeaf(curr->left, currSum, targetSum) || findLeaf(curr->right, currSum, targetSum);
            
    }
};