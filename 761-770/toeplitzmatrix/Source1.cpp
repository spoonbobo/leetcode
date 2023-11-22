// Optimized version, beats everything again

// O(n) solution

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int e, m, n, i, j, ref;

        m = matrix.size(); n = matrix[0].size();

        for (e = m - 1; e >= 0; e--) {
            i = e; j = 0;
            ref = matrix[i++][j++];
            while (true) {
                if ((i >= m) || (j >= n))
                    break;
                if (matrix[i++][j++] != ref)
                    return false;
            }
        }

        for (e = 1; e < n; e++) {
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