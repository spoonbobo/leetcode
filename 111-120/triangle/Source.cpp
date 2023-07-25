// dp solution, beats 100% time ( n/2 * (2 + n - 1) ) and 98% space (O(n))

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // trivial cases
        if (triangle.size() == 1)
            return triangle[0][0];
        else if (triangle.size() == 2)
            return min(triangle[0][0] + triangle[1][0], triangle[0][0] + triangle[1][1]);

        vector<int> dp {triangle[0][0] + triangle[1][0], triangle[0][0] + triangle[1][1]};
        int prev, temp;

        for (int row = 2; row < triangle.size(); row++) {
            prev = dp[0];
            dp[0] += triangle[row][0];
            for (int e = 1; e < row; e++) {
                temp = dp[e];
                dp[e] = triangle[row][e] + min(prev, dp[e]);
                prev = temp;
            }
            dp.push_back(triangle[row][row] + prev);
        }

        sort(dp.begin(), dp.end());
        return dp[0];
    }
};