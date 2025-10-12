// 219. Contains Duplicate II
// https://leetcode.com/problems/contains-duplicate-ii/

#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        if (nums.size() == 1 || k == 0)
            return false;

        if (k == 1)
        {
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if (nums[i] == nums[i + 1])
                    return true;
            }
        }
        else
        {
            unordered_set<int> window;
            for (int i = 0; i < nums.size(); ++i)
            {
                if (window.find(nums[i]) != window.end())
                {
                    return true;
                }
                window.insert(nums[i]);

                if (window.size() > k)
                {
                    window.erase(nums[i - k]);
                }
            }
        }

        return false;
    }
};