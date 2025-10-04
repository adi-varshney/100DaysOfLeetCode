// 171. Excel Sheet Column Number
// https://leetcode.com/problems/excel-sheet-column-number/

using namespace std;
#include <math.h>
#include <string>

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {

        // Each digit in the columnTitle string is basically a power of 226
        // Ex:
        // AAA
        // 26^2 * 1 + 26^1 * 2 + 26^0 * 1 = 703

        int ans = 0;
        for (int i = 0; i < columnTitle.size(); i++)
        {
            ans += pow(26, columnTitle.size() - 1 - i) * (columnTitle[i] - '@');
        }

        return ans;
    }
};