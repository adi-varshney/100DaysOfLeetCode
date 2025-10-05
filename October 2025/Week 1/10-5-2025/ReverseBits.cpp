// 190. Reverse Bits
// https://leetcode.com/problems/reverse-bits/

using namespace std;

// Solution 1(math)
#include <cmath>
class Solution
{
public:
    int reverseBits(int n)
    {
        int ans = 0;

        for (int i = 31; i >= 0; i--)
        {
            if (n & 1 == 1)
            {
                ans += pow(2, i);
            }

            n >>= 1;
        }

        return ans;
    }
};

// Solution 2(bit manipulation)
class Solution
{
public:
    int reverseBits(int n)
    {
        int ans = 0;

        for (int i = 31; i >= 0; i--)
        {
            ans <<= 1;

            if (n & 1 == 1)
            {
                ans++;
            }

            n >>= 1;
        }

        return ans;
    }
};

// Solution 3(more bit manipulation)
class Solution
{
public:
    int reverseBits(int n)
    {
        int ans = 0;

        for (int i = 31; i >= 0; i--)
        {
            ans <<= 1;

            ans = ans | (n & 1);

            n >>= 1;
        }

        return ans;
    }
};