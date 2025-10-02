// Remove Duplicates From Sorted Array
class Solution {
    public int removeDuplicates(int[] nums) {
        int currPos = 0;
        for (int pointer = 0; pointer<nums.length; pointer++) {
            if ( nums[pointer] > nums[currPos] ) {
                currPos++;
                nums[currPos] = nums[pointer];
            }
        }

        return currPos+1;
    }
}