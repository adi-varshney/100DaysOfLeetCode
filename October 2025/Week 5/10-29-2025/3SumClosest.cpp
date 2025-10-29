// 16. 3Sum Closest
// https://leetcode.com/problems/3sum-closest/

#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

// O(n^2)
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());

        int ans = nums[0] + nums[1] + nums[2]; // store vectors that store the solutions (integers x, y, z)

        for (int i = 0; i < nums.size(); i++)
        { // iterate through x

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // two sum problem with sorted array
            // since it is sorted now we can use two pointers method

            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (abs(target - sum) < abs(target - ans))
                    ans = sum;

                if (sum == target)
                {
                    return target;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return ans;
    }
};