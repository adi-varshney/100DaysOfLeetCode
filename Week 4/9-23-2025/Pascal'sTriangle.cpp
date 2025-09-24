// 118. Pascal's Triangle
// https://leetcode.com/problems/pascals-triangle/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> t;
        t.emplace_back(vector<int> {1});
        if (numRows == 1)
            return t;
        
        for (int i = 2; i<=numRows; i++) {    
            t.emplace_back(createRow(t, i));
        }

        return t;
    }

    vector<int> createRow(vector<vector<int>>& t, int rowSize) {
        vector<int> row;
        row.push_back(1);

        for (int i = 0; i<rowSize-2; i++) {
            row.push_back(t[rowSize-2][i]+t[rowSize-2][i+1]);
        }

        row.push_back(1);

        return row;
    }
};