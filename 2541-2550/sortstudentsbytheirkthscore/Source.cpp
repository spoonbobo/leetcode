// O(nlogn||sort) solution, solved using priority queue.
// Space can be optimized.

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        // pq <score_k, vector<>row>
        priority_queue<pair<int, vector<int>>> pq;
        for (int row = 0; row < score.size(); row++) {
            pq.push(make_pair(score[row][k], score[row]));
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};