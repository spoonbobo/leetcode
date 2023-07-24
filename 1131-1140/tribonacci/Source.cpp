// Similar to fib

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        else if (n <= 2) return 1;
        vector<int> dp{0, 1, 1};
        for (int i = 3; i < n; i++) {
            dp.push_back(dp[i - 1] + dp[i - 2] + dp[i - 3]);
        }

        return dp[n - 1] + dp[n - 2] + dp[n - 3];
    }
};