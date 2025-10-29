// 15. 3Sum
// https://leetcode.com/problems/3sum/

#include <algorithm>
#include <vector>
#include <set>
#include <array>
using namespace std;

// My first solution, Binary-search-based 3Sum
// O(n^2 log n) time, O(k) extra space for unique triplets
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); // sort to enable binary search and ordered triplets
        const int n = (int)nums.size();
        set<array<int, 3>> uniq; // set deduplicates triplets automatically

        // Pick first two numbers (i, j), then binary search for the third
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int target = -nums[i] - nums[j]; // we want nums[m] == target
                int l = j + 1, r = n - 1;        // search only after j to avoid reusing indices
                while (l <= r)
                {
                    int m = l + (r - l) / 2;
                    if (nums[m] == target)
                    { // found a valid triplet
                        uniq.insert({nums[i], nums[j], nums[m]});
                        break; // move on; other occurrences will be covered by other (i, j)
                    }
                    if (nums[m] < target)
                        l = m + 1; // need a larger number
                    else
                        r = m - 1; // need a smaller number
                }
            }
        }

        // Move unique triplets from set -> vector result
        vector<vector<int>> ans;
        ans.reserve(uniq.size());
        for (auto &t : uniq)
            ans.push_back({t[0], t[1], t[2]});
        return ans;
    }
};

// My second solution, O(n^2), best solution for 3 sum problem
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>>
            ans; // store vectors that store the solutions (integers x, y, z)

        for (int i = 0; i < nums.size(); i++)
        { // iterate through x
            if (nums[i] > 0)
                break;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // two sum problem with sorted array
            // since it is sorted now we can use two pointers method

            int target = -nums[i]; // z

            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right];

                if (sum == target)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    int lv = nums[left];
                    while (left < right && lv == nums[left])
                    {
                        left++;
                    }

                    int rv = nums[right];
                    while (left < right && rv == nums[right])
                    {
                        right--;
                    }
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