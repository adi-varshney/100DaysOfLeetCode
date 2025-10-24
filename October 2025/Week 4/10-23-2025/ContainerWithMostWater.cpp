// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/

#include <vector>
#include <algorithm>
using namespace std;

// Solution 1, my original two-pointer approach
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int ans = min(height[left], height[right]) * (right - left);

        while (left < right)
        {
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }

            ans = max(min(height[left], height[right]) * (right - left), ans);
        }

        return ans; // return area of rectangle between lowest/min high and distance between values
    }
};

// Solution 2, slightly more optimized two-pointer approach
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int ans = min(height[left], height[right]) * (right - left);

        while (left < right)
        {
            if (height[left] < height[right])
            {
                int prev = height[left];
                while (left < right && height[left] <= prev)
                    ++left; // skip non-improving left heights
            }
            else
            {
                int prev = height[right];
                while (left < right && height[right] <= prev)
                    --right; // skip non-improving right heights
            }

            ans = max(min(height[left], height[right]) * (right - left), ans);
        }

        return ans; // return area of rectangle between lowest/min high and distance between values
    }
};