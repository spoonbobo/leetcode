// O(n*m+indices.length) time, O(n+m) space
// there is a more intuitive solution using O(n+m+indices.length) at 
// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/solutions/425100/java-python-3-2-methods-time-o-m-n-l-and-o-l-codes-w-comment-and-analysis/

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        unordered_map<int,int> rs, cs;
        for (auto& idxs: indices) {
            rs[idxs[0]]++;
            cs[idxs[1]]++;
        }
        int ans = 0;
        for (int r=0; r<m; r++) {
            for (int c=0; c<n; c++) {
                if ((rs[r] + cs[c]) % 2 != 0)
                    ans++;
            }
        }
        return ans;
    }
};