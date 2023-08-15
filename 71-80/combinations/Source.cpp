// backtracking solution, very slow in time and expensive in space (beats 13% time and space only, can definitely be optimized)

void bt(int left, int n, vector<int> traversed, vector<vector<int>>& res, int k) {
    if (traversed.size() == k) {
        res.push_back(traversed);
        return;
    }

    for (int node = left; node < n + 1; node++) {
        traversed.push_back(node);
        bt(node + 1, n, traversed, res, k);
        // backtracking
        traversed.pop_back();
    }

}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        bt(1, n, vector<int>{}, res, k);
        return res;
    }
};