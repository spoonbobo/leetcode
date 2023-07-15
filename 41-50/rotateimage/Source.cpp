// This is very interesting implementation
// credit to https://leetcode.com/problems/rotate-image/solutions/18872/a-common-method-to-rotate-the-image/
// to rotate clockwise: reverse row -> swap symmetry
// to rotate anti-clockwise: reverse col -> swap symmetry

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); i++)
            for (int j = i + 1; j < matrix.size(); j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};