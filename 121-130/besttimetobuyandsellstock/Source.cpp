// O(n) solution

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy, day, max_profit;
        buy = 0; day = 1; max_profit = 0;
        while (day < prices.size()) {
            if ((prices[day] - prices[buy]) > max_profit) {
                max_profit = prices[day] - prices[buy];
            }
            else if (prices[day] < prices[buy]) {
                buy = day;
            }
            day++;
        }
        return max_profit;
    }
};