// 228. Summary Ranges
// https://leetcode.com/problems/summary-ranges/

#include <vector>
#include <string>
#include <string_view>
using namespace std;

// My 1st approach
class Solution1 {
public:
    vector<string> ans;
    const vector<int>* numbers = nullptr;

    vector<string> summaryRanges(vector<int>& nums) {
        ans.clear();
        numbers = &nums;
        if (nums.empty()) return ans;
        ans.push_back(summaryRanges((int)nums.size() - 1));  
        return ans;
    }

    string summaryRanges(int index) {
        if (index == 0)
            return to_string((*numbers)[index]);

        string lastRange = summaryRanges(index - 1);

        size_t arrow = lastRange.find("->");
        string_view lv(lastRange);
        string_view begin, end;

        if (arrow == string::npos) {
            begin = lv;
            end   = lv;
        } else {
            begin = lv.substr(0, arrow);
            end   = lv.substr(arrow + 2);
        }

        int last = end.empty() ? 0 : stoi(string(end));

        if (last == (*numbers)[index] - 1) {
            if (arrow == string::npos) {
                lastRange += "->" + to_string((*numbers)[index]);
            } else {
                lastRange = string(begin) + "->" + to_string((*numbers)[index]);
            }
            return lastRange;
        }

        ans.push_back(lastRange);
        return to_string((*numbers)[index]);
    }
};

// My 2nd approach
// Recursive approach without using string_view, which is more straightforward, and more efficient
class Solution2 {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;
        helper(nums, 0, ans);
        return ans;
    }

private:
    void helper(const vector<int>& nums, int i, vector<string>& ans) {
        if (i >= (int)nums.size()) return;

        int j = i;
        while (j + 1 < (int)nums.size() && nums[j + 1] == nums[j] + 1) {
            ++j;
        }

        if (i == j) {
            ans.push_back(to_string(nums[i]));
        } else {
            ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
        }

        helper(nums, j + 1, ans);
    }
};
