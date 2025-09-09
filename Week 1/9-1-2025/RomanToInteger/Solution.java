
import java.util.Map;

// Roman to Integer
class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> symbol_values = Map.of('I', 1, 'V', 5, 'X', 10, 'L', 50, 'C', 100, 'D', 500, 'M', 1000);

        int num = 0;

        for (int i = 0; i<s.length(); i++) {
            if ( i < s.length()-1 && symbol_values.get(s.charAt(i)) < symbol_values.get(s.charAt(i+1)) ) {
                num -= symbol_values.get(s.charAt(i));
                num += symbol_values.get(s.charAt(i+1));
                i++;
            } else
                num += symbol_values.get(s.charAt(i));                
        }

        return num;
    }
}