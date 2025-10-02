// 136. Single Number
// https://leetcode.com/problems/single-number/

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int i: nums) {
            ans ^= i;
        }

        return ans;
    }
};