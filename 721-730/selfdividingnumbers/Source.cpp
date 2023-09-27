// brute-force way to solve problem
// O(n*to_string(avg_length)) solution, beats 100% time;

bool validate(int x) {
    string xstr = to_string(x);
    for (auto& c : xstr) {
        if (c == '0' || x % (c - '0') != 0)
            return false;
    }
    return true;
}

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            if (validate(i))
                res.push_back(i);
        }
        return res;
    }
};