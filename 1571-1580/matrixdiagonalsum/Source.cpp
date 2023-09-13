// beats 32% time, can be optimised by traversing m/2

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i = 0, j = mat.size() - 1;
        int sum = 0;
        while (i < mat.size()) {
            if (i == j)
                sum += mat[i][j]; // only happens if size is odd
            else
                sum += mat[i][i] + mat[j][i];
            i++; j--;
        }
        return sum;
    }
};