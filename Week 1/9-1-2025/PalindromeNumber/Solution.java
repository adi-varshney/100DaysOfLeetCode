class Solution {
    public boolean isPalindrome(int x) {
        if (x<0)
            return false;
        if (x == 0)
            return true;
        
        if (x % 10 == 0)  // A palindrome number can't end with 0 because an integer can't begin with 0(had to look at editorial for this optimization).
            return false; // It did eliminate a lot of test cases and speed up runtime a lot(to my surprise).

        int len = (int) (Math.log10(x) + 1);
        if (len == 1)
            return true;

        for (int i = 1 ; i<=len/2; i++) {
            int dig1 = ( (int) (x/(Math.pow(10,len-i))) ) % 10;
            int dig2 = ( (int) (x/(Math.pow(10,i-1))) ) % 10;

            if (dig1 != dig2)
                return false;
        }

        return true;
    }
}