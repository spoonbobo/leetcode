// O(m * sortn) solution

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int sum = 0, m = grid.size(), n = grid[0].size();
        // O(m * sortn)
        for (int row = 0; row < m; row++)
            sort(grid[row].begin(), grid[row].end());

        // O(n*m)
        for (int iter = 0; iter < n; iter++) {
            int maxelem = 0;
            for (int e = 0; e < m; e++) {
                if (grid[e][n - iter - 1] > maxelem)
                    maxelem = grid[e][n - iter - 1];
            }
            sum += maxelem;
        }

        return sum;
    }
};