// O(mn) complexity using cache. Beats 85% time and roughly 60% space

int colsum(vector<vector<int>>& grid, int col, int m) {
    // return sum of that column
    int sum = 0;
    for (int row = 0; row < m; row++)
        sum += grid[row][col] == 1 ? 1 : -1;
    return sum;
}

int rowsum(vector<vector<int>>& grid, int row, int n) {
    // return sum of that row
    int sum = 0;
    for (int col = 0; col < n; col++)
        sum += grid[row][col] == 1 ? 1 : -1;
    return sum;
}

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        // when traversing columns,  use cached rows,
        // on first row, get cached cols for zeros and ones.

        int m, n;
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> res(m, vector<int>(n));

        // initiated caches
        int* cacheRow = new int[m];
        int* cacheCol = new int[n];

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0)
                    cacheCol[col] = colsum(grid, col, m);
                if (col == 0)
                    cacheRow[row] = rowsum(grid, row, n);
                res[row][col] = cacheRow[row] + cacheCol[col];
            }
        }

        delete[] cacheRow;
        delete[] cacheCol;
        return res;
    }
};