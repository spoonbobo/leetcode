// Slightly optimized version of source.cpp, modified score in-placed.

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        // pq <score_k, vector<>row>
        priority_queue<pair<int, vector<int>>> pq;
        for (int row = 0; row < score.size(); row++) {
            pq.push(make_pair(score[row][k], score[row]));
        }
        int i = 0;
        while (!pq.empty()) {
            score[i] = pq.top().second;
            pq.pop();
            i++;
        }
        return score;
    }
};