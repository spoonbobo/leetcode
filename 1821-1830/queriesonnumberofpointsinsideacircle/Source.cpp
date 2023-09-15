// O(n_poitns * n_queries) solution, beats 100% time
// it's a brute force solution

// solve using euclid dist
float dist(const int& x1, const int& y1, const int& x2, const int& y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        float d;
        int ct;
        for (auto& q : queries) {
            ct = 0;
            for (auto& p : points) {
                d = dist(q[0], q[1], p[0], p[1]);
                if ((float)d <= q[2])
                    ct++;
            }
            res.push_back(ct);
        }
        return res;
    }
};