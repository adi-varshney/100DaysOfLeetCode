// 231. Power of Two
// https://leetcode.com/problems/power-of-two/

#include <cmath>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n < 1)
            return false;

        return log2(n) == (long)log2(n);
    }
};