/*
    base:
        n=1 return 
            [[1]]
        n=2 return 
            [[1], [1, 1]]
        n>2 return
            [1,i_0, i_1, ... i_n-1,1] where i_x = prevRow[x]+prevRow[x+1] 
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 1) {
            res.push_back(vector<int>{1});
            return res;
        }
        else if (numRows == 2) {
            res.push_back(vector<int>{1});
            res.push_back(vector<int>{1, 1});
            return res;
        }

        res.push_back(vector<int>{1});
        res.push_back(vector<int>{1, 1});

        for (int row = 2; row < numRows; row++) {
            res.push_back(vector<int>{});
            res[res.size() - 1].push_back(1);
            for (int e = 0; e < row - 1; e++) {
                res[res.size() - 1].push_back(res[row - 1][e] + res[row - 1][e + 1]);
            }
            res[res.size() - 1].push_back(1);
        }

        return res;
    }
};