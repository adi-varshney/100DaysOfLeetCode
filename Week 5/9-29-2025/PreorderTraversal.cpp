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

    vector<int> preorderTraversal(TreeNode *root)
    {
        traverse(root);

        return output;
    }

    void traverse(TreeNode *node)
    {
        if (node == nullptr)
            return;
        else
            output.push_back(node->val);

        traverse(node->left);
        traverse(node->right);
    }
};