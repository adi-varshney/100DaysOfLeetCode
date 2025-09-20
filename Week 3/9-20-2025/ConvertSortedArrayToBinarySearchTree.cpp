// 108. Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return createChildren(nums, 0, nums.size() - 1);
    }

    TreeNode *createChildren(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return nullptr;

        int middle = start + (end - start) / 2;

        return new TreeNode(nums[middle], createChildren(nums, start, middle - 1), createChildren(nums, middle + 1, end));
    }
};