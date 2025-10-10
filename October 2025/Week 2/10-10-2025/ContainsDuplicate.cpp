// 217. Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/

using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_set>

// Solution 1
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                return true;
        }

        return false;
    }
};

// Solution 2(just included to test which solution is faster)
class Solution2
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> seen;
        seen.insert(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            if (seen.find(nums[i]) != seen.end())
                return true;
            seen.insert(nums[i]);
        }

        return false;
    }
};