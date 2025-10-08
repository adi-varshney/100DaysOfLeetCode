// 205. Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings/

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> ST;
        unordered_map<char, char> TS;

        for (int i = 0; i<s.length(); i++) {
            if (ST.find(s[i]) == ST.end() && TS.find(t[i]) == TS.end()) {
                ST[s[i]] = t[i];
                TS[t[i]] = s[i];
            } else {
                if (ST[s[i]] == t[i] && TS[t[i]] == s[i])
                    continue;
                else
                    return false;
            }
        }

        return true;
    }
};