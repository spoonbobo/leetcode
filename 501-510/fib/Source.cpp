// dp method, O(n) time, no need recursion

class Solution {
public:
    int fib(int n) {
        // trivial cases
        if (n <= 1) return n;
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        for (int i = 2; i < n; i++) {
            dp.push_back(dp[i - 1] + dp[i - 2]);
        }

        return dp[n - 1] + dp[n - 2];
    }
};