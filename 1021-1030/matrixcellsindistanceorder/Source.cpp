// O(sort) solution 

int dist(const int& r, const int& c, const int& rC, const int& cC) {
    return abs(rC - r) + abs(cC - c);
}

vector<int> decode(const int& x, const int& cols) {
    return vector<int>{x / cols, x% cols};
}

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<pair<int, int>> rec;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                rec.push_back(make_pair(dist(r, c, rCenter, cCenter), r * cols + c));
            }
        }
        sort(rec.begin(), rec.end());

        vector<vector<int>> res;
        for (auto& entry : rec)
            res.push_back(decode(entry.second, cols));

        return res;
    }
};