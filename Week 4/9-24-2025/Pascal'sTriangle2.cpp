// 119. Pascal's Triangle 2
// https://leetcode.com/problems/pascals-triangle-ii/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};
        for (int i = 1; i<rowIndex+1; i++) { // creating each row
            int prev = 1;
            int currRow = row.size();
            for (int j = 1; j<currRow; j++) { // creating each index in each row
                int curr = row[j];
                row[j] = row[j] + prev;
                prev = curr;
                    
            }
            row.push_back(1);
        }

        return row;
    }
};