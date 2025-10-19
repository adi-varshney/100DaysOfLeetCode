// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) // accounts for empty and single char strings
            return s.size();

        unordered_set<char>
            seen; // storing all values currently in the sliding window range

        int longest = 1; // storing max length seen
        int left = 0;    // left window bound
        int right = 1;   // right window bound

        seen.insert(s[0]);

        while (true) {
            if (right >= s.size())
                break;

            if (seen.count(s[right]) == 1) {
                longest = max(longest, right - left);
                seen.erase(s[left]);
                left++;
            } else {
                seen.insert(s[right]);
                right++;
            }
        }

        longest = max(longest, right - left);
        return longest; // returning the max length
    }
};

// Solution 2, Optimized Sliding Window
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) // accounts for empty and single char strings
            return s.size();

        vector<int> lastIndex(128, -1); // storing last seen positions of all 128 ASCII table values(0-127)

        int longest = 1; // storing max length seen
        int left = 0;    // left window pointer
        int right = 0;   // right window pointer

        while (right < s.size()) {
            left = max(lastIndex[s[right]] + 1, left); // jump to the next index after the last seen index of s[right] if it's within the current window

            longest = max(longest, right - left + 1);

            lastIndex[s[right]] = right;
            right++;
        }

        return longest; // returning the max length
    }
};