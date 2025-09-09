// Longest Common Prefix
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0)
            return "";

        String currLCP = strs[0];

        for (int i = 1; i < strs.length; i++) {
            currLCP = LCP(currLCP, strs[i]);

            if (currLCP.isEmpty())
                return currLCP;
        }

        return currLCP;
    }

    private static String LCP(String a, String b) {
        if (prefixMatches(a, b, Math.min(a.length(), b.length()))) {
            if (a.length() <= b.length())
                return a;
            else
                return b;
        } else {
            int low = 0;
            int high = Math.min(a.length(), b.length());

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (prefixMatches(a, b, mid)) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            return a.substring(0, high);
        }
    }

    private static boolean prefixMatches(String a, String b, int len) {
        for (int i = 0; i < len; i++) {
            if (a.charAt(i) != b.charAt(i))
                return false;
        }
        return true;
    }
}