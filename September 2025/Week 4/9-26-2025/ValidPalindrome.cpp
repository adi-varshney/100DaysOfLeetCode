// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/

#include <ctype.h>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int leftPtr = 0, rightPtr = s.size()-1;

        // ascii values: 48('0')-57('9'), 65('A')-91('Z'), and 97('a') - 122('z')
        while (leftPtr < rightPtr) {
            char leftLower = tolower(s[leftPtr]);
            char rightLower = tolower(s[rightPtr]);

            if (!(leftLower >= '0' && leftLower <= '9') && !(leftLower >= 'A' && leftLower <= 'Z') && !(leftLower >= 'a' && leftLower <= 'z')) {
                leftPtr++;
                continue;
            }
            
            if (!(rightLower >= '0' && rightLower <= '9') && !(rightLower >= 'A' && rightLower <= 'Z') && !(rightLower >= 'a' && rightLower <= 'z')) {
                rightPtr--;
                continue;
            }

            if (leftLower != rightLower)
                return false;

            leftPtr++;
            rightPtr--;
        }

        return true;
    }
};