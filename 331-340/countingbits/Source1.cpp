// 1pass solution, O(n) space
class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0)
            return vector<int>{0};
        if (n == 1)
            return vector<int>{0, 1};
        vector<int> dp{0, 1};
        for (int i = 2; i < n + 1; i++) {
            if (i % 2 == 0)
                dp.push_back(dp[i / 2]);
            else
                dp.push_back(dp[i - 1] + 1);
        }
        return dp;
    }
};