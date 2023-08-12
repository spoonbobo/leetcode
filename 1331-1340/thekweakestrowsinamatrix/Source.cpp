// O(sort) priority queue solution, beats 84% time and space

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // pq<score, row>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; int row, col;
        for (row = 0; row < mat.size(); row++) {
            int temp = 0;
            for (col = 0; col < mat[0].size(); col++) {
                if (mat[row][col] == 0)
                    break;
                temp++;
            }
            pq.push(make_pair(temp, row));
        }

        vector<int> res;
        while (k > 0) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};