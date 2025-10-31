// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        static const vector<string> mappings = {"", "", "abc", "def", "ghi",
                                                "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans;
        string curr;
        backtrack(digits, ans, curr, 0, mappings);

        return ans;
    }

    void backtrack(const string &digits, vector<string> &ans, string &curr, int index,
                   const vector<string> &mappings)
    {
        if (curr.size() == digits.size())
        {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < mappings[digits[index] - '0'].size(); i++)
        {
            curr.push_back(mappings[digits[index] - '0'][i]);
            backtrack(digits, ans, curr, index + 1, mappings);
            curr.pop_back();
        }
    }
};