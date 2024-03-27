class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto& e : nums) {
            m[e]++;
        }
        int res = 0;
        for (auto& p : m) {
            if (p.second == 1)
                res += p.first;
        }
        return res;
    }
};