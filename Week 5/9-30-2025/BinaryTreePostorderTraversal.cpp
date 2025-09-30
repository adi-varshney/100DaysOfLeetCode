// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

#include <vector>
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

class Solution
{
public:
    vector<int> output;

    vector<int> postorderTraversal(TreeNode *root)
    {
        traverse(root);

        return output;
    }

    void traverse(TreeNode *currNode)
    {
        if (currNode == nullptr)
            return;

        traverse(currNode->left);
        traverse(currNode->right);

        output.push_back(currNode->val);
    }
};