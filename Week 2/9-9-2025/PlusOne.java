// Plus One
class Solution {
    public int[] plusOne(int[] digits) {
        if (digits[digits.length - 1] != 9) {
            digits[digits.length - 1]++;
            return digits;
        } else {
            int i = digits.length - 1;
            while (i >= 0) {
                if (digits[i] == 9 && i != 0) {
                    i--;
                } else if (digits[i] == 9) {
                    int[] arr = new int[digits.length + 1];
                    arr[0] = 1;
                    return arr;
                } else {
                    digits[i]++;
                    for (int j = i + 1; j < digits.length; j++) {
                        digits[j] = 0;
                    }
                    return digits;
                }
            }
        }
        return new int[1];
    }
}