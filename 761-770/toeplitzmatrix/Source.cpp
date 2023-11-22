// can be optimized.

// O(n) solution + O(n) space

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        vector<int> left;
        vector<int> right;
        int m, n, i, j, ref;

        m = matrix.size(); n = matrix[0].size();

        for (i = m - 1; i >= 0; i--)
            left.push_back(i);
        for (j = 1; j < n; j++)
            right.push_back(j);

        for (auto& e : left) {
            i = e; j = 0;
            ref = matrix[i++][j++];
            while (true) {
                if ((i >= m) || (j >= n))
                    break;
                if (matrix[i++][j++] != ref)
                    return false;
            }
        }

        for (auto& e : right) {
            i = 0; j = e;
            ref = matrix[i++][j++];
            while (true) {
                if ((i >= m) || (j >= n))
                    break;
                if (matrix[i++][j++] != ref)
                    return false;
            }
        }

        return true;
    }
};