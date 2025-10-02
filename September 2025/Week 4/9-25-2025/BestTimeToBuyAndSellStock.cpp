// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, minPrice = prices[0], maxPrice = prices[0];
        for (int i = 0; i<prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);

            profit = max(profit, prices[i]-minPrice);
        }

        return profit;
    }
};