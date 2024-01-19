// O(mn), beats 96% time, DP solution

int get_min(int* dp, int& n) {
    int minimum = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (dp[i] < minimum)
            minimum = dp[i];
    }
    return minimum;
}

int get_dp_min(int* dp, int& col, int& n) {
    int minimum = INT_MAX;
    for (int e = max(0, col - 1); e < min(col + 2, n); e++) {
        if (dp[e] < minimum)
            minimum = dp[e];
    }
    return minimum;
}

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m, n, row, col;
        m = matrix.size(); n = matrix[0].size();
        int* dp = new int[n];
        for (col = 0; col < n; col++)
            dp[col] = matrix[0][col];

        // start traversing at second row
        // for each element, query its upstream elements, to choose where it walks from
        for (row = 1; row < m; row++) {
            int* tmp = new int[n];
            for (int i = 0; i < n; i++)
                tmp[i] = dp[i];
            for (col = 0; col < n; col++) {
                // copy for ref
                dp[col] = matrix[row][col] + get_dp_min(tmp, col, n);
            }
            delete[] tmp;
        }

        return get_min(dp, n);
    }
};