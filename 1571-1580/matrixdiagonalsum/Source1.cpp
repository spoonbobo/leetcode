// beats 100% time

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i = 0, j = mat.size() - 1;
        int sum = 0;
        while (true) {
            if (i > j)
                break;
            if (i == j)
                sum += mat[i][j]; // only happens if size is odd
            else
                sum += mat[i][i] + mat[j][j] + mat[i][j] + mat[j][i];
            i++; j--;
        }
        return sum;
    }
};