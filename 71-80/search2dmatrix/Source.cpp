bool bs(vector<vector<int>>& matrix, int l, int r, int n, int& target) {
    int mid, val;
    while (l <= r) {
        mid = l + (r - l) / 2;
        val = matrix[mid / n][mid % n];
        if (val == target) return true;

        else if (val > target) r = mid - 1;

        else l = mid + 1;
    }
    return false;
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /* if (matrix.size() == 1 && matrix[0].size() == 1)
            return matrix[0][0] == target; */

            // some other trivial cases
        if (target > matrix[matrix.size() - 1][matrix[0].size() - 1]) return false;

        if (target < matrix[0][0]) return false;

        if (target == matrix[0][0]) return true;
        if (target == matrix[matrix.size() - 1][matrix[0].size() - 1]);

        return bs(matrix, 0, matrix.size() * matrix[0].size() - 1, matrix[0].size(), target);
    }
};