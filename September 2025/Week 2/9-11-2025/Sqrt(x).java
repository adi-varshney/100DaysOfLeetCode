// 69. Sqrt(x)
// https://leetcode.com/problems/sqrtx/description/

class Solution {
    public int mySqrt(int x) {
        if ( x == 0 )
            return 0;
        if ( x == 1 || x == 2 || x == 3 )
            return 1;

        int low = 1, high = x/2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (x/mid == mid) {
                return mid;
            } else if (mid > x/mid) {
                high = mid - 1;
            } else if (mid < x/mid) {
                low = mid + 1;
            }
        }

        return high;
    }
}