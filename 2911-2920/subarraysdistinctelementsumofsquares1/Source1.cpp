// dp solution O(n**2) time and space

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res = 0, n = nums.size(), left, interval = 0, e;
        vector<unordered_map<int, int>> dp(n);
        vector<int> unique_ct(n, 0);
        while (interval < n) {
            for (left = 0; left + interval < n; left++) {
                e = nums[left + interval];
                if (dp[left][e]) {
                    res += pow(unique_ct[left], 2);
                    continue; // this is already in dp[left]
                }
                dp[left][e]++;
                unique_ct[left]++;
                res += pow(unique_ct[left], 2);
            }
            interval++;
        }
        return res;
    }
};