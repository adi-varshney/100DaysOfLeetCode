// 6. Zigzag Conversion
// https://leetcode.com/problems/zigzag-conversion/

#include <string>
#include <vector>
using namespace std;

// solution 1
// uses vector of vector of chars to store the zigzag pattern
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<vector<char>> zigzag(numRows);

        for (int i = 0; i < numRows; i++)
        {
            // add # of rows
            zigzag.push_back(vector<char>{});
        }

        int row = 0;
        bool diagonal = false;
        for (int i = 0; i < s.size(); i++)
        {
            zigzag[row].push_back(s[i]);

            if (diagonal)
            { // checks whether to go down or up now depending on if we are going down a column or up diagonally
                if (!row)
                {
                    row++;
                    diagonal = false;
                }
                else
                    row--;
            }
            else
            {
                if (row == numRows - 1)
                {
                    row--;
                    diagonal = true;
                }
                else
                    row++;
            }
        }

        string ans;
        ans.reserve(s.size());
        for (const vector<char> &row : zigzag)
        {
            for (char curr : row)
            {
                ans += curr;
            }
        }

        return ans;
    }
};

// solution 2, best
// uses vector of strings to store the zigzag pattern
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> zigzag(numRows);

        int row = 0;
        bool diagonal = false;
        for (int i = 0; i < s.size(); i++)
        {
            zigzag[row] += s[i];

            if (diagonal)
            { // checks whether to go down or up now depending on if we are going down a column or up diagonally
                if (!row)
                {
                    row++;
                    diagonal = false;
                }
                else
                    row--;
            }
            else
            {
                if (row == numRows - 1)
                {
                    row--;
                    diagonal = true;
                }
                else
                    row++;
            }
        }

        string ans;
        ans.reserve(s.size());
        for (const auto &row : zigzag)
        {
            for (auto curr : row)
            {
                ans += curr;
            }
        }

        return ans;
    }
};