
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        if (s.length() % 2 == 1)
            return false;

        for (char curr : s) {
            if (curr=='(' || curr=='{' || curr=='[') {
                st.push(curr);
            } else {
                if (st.empty())
                    return false;
                
                if ( 
                    (curr == ')' && st.top() != '(') ||
                    (curr == ']' && st.top() != '[') ||
                    (curr == '}' && st.top() != '{') 
                   )
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }

// USING THIS HELPER FUNCTION USES MORE MEMORY?
//    bool validPair(stack<char>& s, char closingBrace) {
//        if (s.empty())
//            return false;
//        switch (closingBrace) {
//            case ')':
//                if ( s.top() == '(')
//                    return true;
//                else
//                    return false;
//            case '}':
//                if ( s.top() == '{')
//                    return true;
//                else
//                    return false;
//            case ']':
//                if ( s.top() == '[')
//                    return true;
//                else
//                    return false;
//            default: // should never get to here
//                return false;
//        }
//    }
};