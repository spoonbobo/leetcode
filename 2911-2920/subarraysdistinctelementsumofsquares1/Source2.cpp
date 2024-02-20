// dp solution O(n**2) time and space, simplify source1.cpp

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res = 0, n = nums.size(), left, interval = 0, e;
        vector<unordered_map<int, int>> dp(n);
        while (interval < n) {
            for (left = 0; left + interval < n; left++) {
                e = nums[left + interval];
                if (dp[left][e]) {
                    res += pow(dp[left].size(), 2);
                    continue; // this is already in dp[left]
                }
                dp[left][e]++;
                res += pow(dp[left].size(), 2);
            }
            interval++;
        }
        return res;
    }
};