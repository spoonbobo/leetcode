// O(m*n) time complexity, seems can be optimized

int find_largest_loc(int r, int c, vector<vector<int>>& grid) {
    int max_v=INT_MIN;
    for (int i=r-1; i<r+2; i++) {
        for (int j=c-1; j<c+2; j++) {
            if (grid[i][j] > max_v)
                max_v = grid[i][j];
        }
    }
    return max_v;
}

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> res;
        for (int i=1; i<grid.size()-1; i++) {
            vector<int> tmp;
            for (int j=1; j<grid[0].size()-1; j++) {
                tmp.push_back(find_largest_loc(i,j,grid));
            }
            res.push_back(tmp);
        }
        return res;
    }
};