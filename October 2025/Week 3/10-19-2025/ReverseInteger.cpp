// 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/

#include <climits>

class Solution
{
public:
    int reverse(int x)
    {
        if (x == 0)
            return x;

        int ans = 0;
        while (x != 0)
        {
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10))
            {
                return 0; // Return 0 if reversing x would cause overflow/underflow
            }

            ans *= 10;
            ans += x % 10;
            x /= 10;
        }

        return ans;
    }
};