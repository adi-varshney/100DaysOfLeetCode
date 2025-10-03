// 168. Excel Sheet Column Title
// https://leetcode.com/problems/excel-sheet-column-title/

#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        
        // 26^0 = 1 - A
        // 26^1 + 26^0 = 27 - AA
        // 26^2 + 26^1 + 26^0 = 703 - AAA
        // 26^3 + 26^2 + 26^1 + 26^0 = 18279 - AAAA
        // 26^4 + 26^3 + 26^2 + 26^1 + 26^0 = 475255 - AAAAA

        while (columnNumber > 0) {
            int carry = 0;
            if (columnNumber % 26 == 0) {
                ans = ('Z') + ans;
                columnNumber /= 26;
                columnNumber--;
                continue;
            }

            ans = (char)('@' + carry + columnNumber % 26) + ans;
            columnNumber -= columnNumber % 26;
            columnNumber /= 26;
        }

        return ans;
    }
};