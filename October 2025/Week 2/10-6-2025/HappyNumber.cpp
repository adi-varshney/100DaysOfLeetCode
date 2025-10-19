// 202. Happy Number
// https://leetcode.com/problems/happy-number/

using namespace std;

// Solution 1: HashSet
#include <unordered_set>
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> calculated;

        while (calculated.count(n) != 1) {
            calculated.insert(n);
            
            int ans = 0;
            while (n != 0) {
                ans += pow(n % 10, 2);
                n /= 10;
            }

            n = ans;

            //cout << n << endl; // testing purposes

            if (log10(n) - (int) log10(n)  == 0.0)
                return true;
        }
        
        //cout << n << endl; // testing purposes

        return false;
    }
};

// Solution 2: Pattern observation
class Solution2 {
public:
    bool isHappy(int n) {
        while (true) {
            if (n == 1 || n == 7)
                return true;
            else if (n < 10)
                return false;

            int ans = 0;
            while (n != 0) {
                ans += pow(n % 10, 2);
                n /= 10;
            }

            n = ans;

            //cout << n << endl; // testing purposes
        }

        return false;
    }
};