// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/

#include <string>
#include <unordered_map>
using namespace std;

// My first solution, more intuitive for me
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> count1;

        for (char c : s)
        {
            count1[c]++;
        }

        unordered_map<char, int> count2;

        for (char c : t)
        {
            count2[c]++;
        }

        return count1 == count2;
    }
};

// My second solution, most (memory) efficient solution
class Solution2
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> count;

        for (int i = 0; i < s.size(); i++)
        {
            count[s[i]]++;
            count[t[i]]--;
        }

        for (const auto &pair : count)
        {
            if (pair.second != 0)
            {
                return false; // Found a value that isn't 0
            }
        }

        return true;
    }
};