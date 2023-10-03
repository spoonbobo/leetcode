// O(n) solution.

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int median = n / 2;
        if (n % 2 != 0)
            res.push_back(0);
        for (int i = 0; i < median; i++) {
            res.push_back(i + 1); res.push_back(-1 * (i + 1));
        }
        return res;
    }
};