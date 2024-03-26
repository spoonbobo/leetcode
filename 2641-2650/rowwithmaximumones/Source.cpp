// brute force
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> h;
        int maxval = 0, tmp;
        for (int i = 0; i < mat.size(); i++) {
            tmp = accumulate(mat[i].begin(), mat[i].end(), 0);
            if (tmp >= maxval)
                maxval = tmp;
            h[tmp].push_back(i);
        }
        sort(h[maxval].begin(), h[maxval].end());
        return vector<int>{h[maxval][0], maxval};
    }
};