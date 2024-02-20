// cleaner version

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res = 0, n = nums.size(), left, interval = 0, e;
        vector<set<int>> dp(n);
        while (interval < n) {
            for (left = 0; left + interval < n; left++) {
                e = nums[left + interval];
                dp[left].insert(e);
                res += pow(dp[left].size(), 2);
            }
            interval++;
        }
        return res;
    }
};