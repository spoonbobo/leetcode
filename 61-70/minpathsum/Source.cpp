// solve by dynamic programming. O(m*n) time and space.
// beats 90% space, but not sure why time only beats 10%, can be optimized
// at any problem of (m-1, n-1), we are asking min(grid[m-2][n-1], grid[m-1][n-2])
// of course we have to consider the boundaries
// all we need to do is to calculate g

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[m][n], y, x;
        for (y = 0; y < m; y++) {
            for (x = 0; x < n; x++) {
                if (y == 0 && x == 0)
                    dp[y][x] = grid[y][x];
                else if (y == 0)
                    dp[y][x] = grid[y][x] + dp[y][x - 1]; // first column
                else if (x == 0)
                    dp[y][x] = grid[y][x] + dp[y - 1][x]; // first row
                else
                    dp[y][x] = grid[y][x] + min(dp[y - 1][x], dp[y][x - 1]); // any other case
                printf("(%d, %d): %d\n", y, x, dp[y][x]);
            }
        }
        return dp[m - 1][n - 1];
    }
};