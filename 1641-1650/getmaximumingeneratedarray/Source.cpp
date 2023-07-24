// dp solution
class Solution {
public:
    int getMaximumGenerated(int n) {
        // trivial cases
        if (n <= 1) return n;
        int max_elem = 1;
        vector<int> dp{0, 1};
        for (int i = 2; i < n; i++) {
            if (i % 2 == 0)
                dp.push_back(dp[i / 2]);
            else
                dp.push_back(dp[i / 2] + dp[i / 2 + 1]);
            if (dp[dp.size() - 1] > max_elem)
                max_elem = dp[dp.size() - 1];
        }
        int last_elem;
        if (n % 2 == 0)
            last_elem = dp[n / 2];
        else
            last_elem = dp[n / 2] + dp[n / 2 + 1];

        return max(max_elem, last_elem);
    }
};