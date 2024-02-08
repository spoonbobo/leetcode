// for each dp[i] at 1 iteration, it incurs itself and vowels after it to unroll
// O(1) space and O(n) solution

class Solution {
public:
    int countVowelStrings(int n) {
        int dp[5] = { 1,1,1,1,1 };
        for (int i = 1; i < n; i++) {
            dp[0] = dp[0] + dp[1] + dp[2] + dp[3] + dp[4];
            dp[1] = dp[1] + dp[2] + dp[3] + dp[4];
            dp[2] = dp[2] + dp[3] + dp[4];
            dp[3] = dp[3] + dp[4];
            dp[4] = dp[4];
        }
        return dp[0] + dp[1] + dp[2] + dp[3] + dp[4];
    }
};