// 8. String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/

#include <string>
#include <climits>
#include <stdexcept>
using namespace std;

// Solution 1
class Solution {
public:
    int myAtoi(string s) {
        int end = 0;
        bool positive = true;
        bool seenSign = false;
        bool seenInt = false;
        while (true) {
            if (end >= s.size())
                break;
            else if (s[end] >= '0' && s[end] <= '9') {
                seenInt = true;
                seenSign = true; // sign does exist and thus is implicitly positive ('+')
                end++;
            } else {
                if (s[end] == ' ' && !seenSign) {
                    if (seenInt)
                        break;
                    else
                        end++;
                } else if ((s[end] == '+' || s[end] == '-') && !seenInt && !seenSign) {
                    seenSign = true;
                    positive = (s[end] == '+');
                    end++;
                } else break;
            }

        }

        if (!end) return 0;

        string val = s.substr(0, end);

        int ans;
        try {
            ans = stoi(val);
        } catch (const invalid_argument&) {
            return 0; // no digits
        } catch (const out_of_range&) {
            // clamp based on leading sign
            return (positive) ? INT_MAX : INT_MIN;
        }

        return ans;
    }
};

// Solution 2
class Solution2 {
public:
    int myAtoi(string s) {
        int ans;
        try {
            ans = stoi(s);
        } catch (const std::invalid_argument&) {
            return 0; // no digits
        } catch (const std::out_of_range&) {
            // look for a sign, if you don't see one before you find the first
            // number, then it is positive(return INT_MAX), else negative(return
            // INT_MIN)

            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '-')
                    return INT_MIN;

                if (s[i] == '+' || (s[i] >= '0' && s[i] <= '9') )
                    return INT_MAX;
            }
        }

        return ans;
    }
};

// Solution 3(Most Optimal)
class Solution3 {
public:
    int myAtoi(string s) {
        int n = s.length();
        bool neg = false;
        long ans = 0;

        int i = 0;
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (s[i] == '-' || s[i] == '+') {
            neg = (s[i] == '-');
            i++;
        }
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            ans = (long)(ans * 10) + (s[i] - '0');
            if (ans > INT_MAX && !neg) {
                return INT_MAX;
            } else if (ans > INT_MAX && neg) {
                return INT_MIN;
            }
            i++;
        }
        if (neg) {
            return ans * -1;
        }
        return ans;
    }
};