// 12. Integer To Roman
// https://leetcode.com/problems/integer-to-roman/

#include <string>
using namespace std;

// Longer but straightforward approach
class Solution
{
public:
    string intToRoman(int num)
    {
        string ans;

        // handling thousands place digits
        while (num >= 1000)
        {
            ans += 'M';
            num -= 1000;
        }

        // handling hundreds digit
        if ((num / 100) % 10 == 9)
        { // if hundreds place = 9
            ans += "CM";
            num -= 900;
        }

        if ((num / 100) % 10 >= 5)
        { // if hundreds place > 5
            ans += 'D';
            num -= 500;
        }

        if ((num / 100) % 10 == 4)
        { // if hundreds place = 4
            ans += "CD";
            num -= 400;
        }

        while (num >= 100)
        { // if hundreds place exists
            ans += 'C';
            num -= 100;
        }

        // handling tens digit
        if ((num / 10) % 10 == 9)
        { // if tens place = 9
            ans += "XC";
            num -= 90;
        }

        if ((num / 10) % 10 >= 5)
        { // if tens place > 5
            ans += 'L';
            num -= 50;
        }

        if ((num / 10) % 10 == 4)
        { // if tens place = 4
            ans += "XL";
            num -= 40;
        }

        while (num >= 10)
        { // if tens place exists
            ans += 'X';
            num -= 10;
        }

        // handling ones digit

        if (num % 10 == 9)
        { // if ones place = 9
            ans += "IX";
            num -= 9;
        }

        if (num % 10 >= 5)
        { // if ones place > 5
            ans += 'V';
            num -= 5;
        }

        if (num % 10 == 4)
        { // if ones place = 4
            ans += "IV";
            num -= 4;
        }

        while (num >= 1)
        { // if ones place exists
            ans += 'I';
            num -= 1;
        }

        return ans;
    }
};

// More concise approach
class Solution
{
public:
    string intToRoman(int num)
    {
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hrns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string ths[] = {"", "M", "MM", "MMM"};

        string ans;

        return ths[(num / 1000) % 10] + hrns[(num / 100) % 10] + tens[(num / 10) % 10] + ones[num % 10];
    }
};