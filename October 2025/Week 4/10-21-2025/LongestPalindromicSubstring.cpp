// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/

#include <string>
using namespace std;

// First solution/attempt
// Store current longest palindrome in a string variable
class Solution
{
public:
    string longestPalindrome(
        string s)
    { // 5. Longest Palindromic Substring - LeetCode Medium
        if (s.size() <= 1)
            return s;

        string ans = s.substr(0, 1);

        if (s.size() == 2)
        {
            return (s[0] == s[1]) ? s : s.substr(1);
        }

        for (int i = 0; i < s.size() - 1; i++)
        {
            int leftCurr = i - 1;
            int rightCurr = i + 1;

            while (checkPair(leftCurr, rightCurr, s))
            { // recurse through pairs till you find the longest palindrome starting at this
                leftCurr--;
                rightCurr++;
            }

            if ((int)ans.size() < rightCurr - leftCurr - 1)
                ans = s.substr(leftCurr + 1, rightCurr - leftCurr - 1);

            leftCurr = i;
            rightCurr = i + 1;
            while (checkPair(leftCurr, rightCurr, s))
            { // recurse through pairs till you find the longest palindrome starting at this
                leftCurr--;
                rightCurr++;
            }

            if ((int)ans.size() < rightCurr - leftCurr - 1)
                ans = s.substr(leftCurr + 1, rightCurr - leftCurr - 1);
        }

        return ans;
    }

    bool checkPair(int x, int y, string &s)
    {
        if (x < 0 || y >= s.size())
            return false;
        return s[x] == s[y];
    }
};

// Best Solution(2nd attempt/solution)
// Use pointers(left and right) to track the start and end of the longest palindrome found so far (instead of storing current longest palindrome in a string variable)
class Solution2
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() <= 1)
            return s;

        if (s.size() == 2)
        {
            return (s[0] == s[1]) ? s : s.substr(1);
        }

        int left = 0;
        int right = 1;

        for (int i = 0; i < s.size() - 1; i++)
        {
            int leftCurr = i - 1;
            int rightCurr = i + 1;

            while (checkPair(leftCurr, rightCurr, s))
            { // recurse through pairs till you find the longest palindrome starting at this
                leftCurr--;
                rightCurr++;
            }

            if (right - left < rightCurr - leftCurr - 1)
            {
                left = leftCurr + 1;
                right = rightCurr;
            }

            leftCurr = i;
            rightCurr = i + 1;
            while (checkPair(leftCurr, rightCurr, s))
            { // recurse through pairs till you find the longest palindrome starting at this
                leftCurr--;
                rightCurr++;
            }

            if (right - left < rightCurr - leftCurr - 1)
            {
                left = leftCurr + 1;
                right = rightCurr;
            }
        }

        return s.substr(left, right - left);
    }

    bool checkPair(int x, int y, string &s)
    {
        if (x < 0 || y >= s.size())
            return false;
        return s[x] == s[y];
    }
};