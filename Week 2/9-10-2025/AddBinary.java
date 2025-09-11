class Solution {
    public String addBinary(String a, String b) {
        if ( a.equals("0") )
            return b;
        
        if ( b.equals("0") )
            return a;

        int i = a.length()-1, j = b.length()-1, carry = 0;
        StringBuilder result = new StringBuilder();
        while ( i>=0 || j>= 0 || carry == 1 ) {
            int dig1 = (i>=0) ? a.charAt(i) - '0' : 0;
            int dig2 = (j>=0) ? b.charAt(j) - '0' : 0;

            int total = dig1 + dig2 + carry;
            switch (total) {
                case 0 -> {
                    result.append('0');
                    carry = 0;
                    break;
                }
                case 1 -> {
                    result.append('1');
                    carry = 0;
                    break;
                }
                case 2 -> {
                    result.append('0');
                    carry = 1;
                    break;
                }
                case 3 -> {
                    result.append('1');
                    carry = 1;
                    break;
                }
            }

            j--;
            i--;
        }

        return result.reverse().toString();
    }
}