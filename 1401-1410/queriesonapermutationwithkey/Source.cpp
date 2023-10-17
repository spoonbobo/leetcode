// O(n^2) solution, beats 61% time and 53% space
// Can be optimized by Fenwick Tree

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> P;
        vector<int> res;
        // init P
        int i, j, idx, tmp;
        for (i = 0; i < m; i++)
            P.push_back(i + 1);
        for (i = 0; i < queries.size(); i++) {
            // find idx
            auto it = find(P.begin(), P.end(), queries[i]);
            idx = it - P.begin();
            res.push_back(idx);
            tmp = P[idx];
            // update idx
            for (j = idx; j > 0; j--)
                P[j] = P[j - 1];
            P[0] = queries[i];
        }
        return res;
    }
};