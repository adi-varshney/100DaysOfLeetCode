// 88. Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if (nums2.length == 0)
            return;

        int i1 = m - 1, i2 = n - 1;
        for (int i = (m + n) - 1; i >= 0; i--) {
            if (i1 < 0) {
                nums1[i] = nums2[i2];
                i2--;
                continue;
            }

            if (i2 < 0) {
                nums1[i] = nums1[i1];
                i1--;
                continue;
            }

            if (nums1[i1] >= nums2[i2]) {
                nums1[i] = nums1[i1];
                i1--;
            } else if (nums1[i1] < nums2[i2]) {
                nums1[i] = nums2[i2];
                i2--;
            }
        }
    }
}