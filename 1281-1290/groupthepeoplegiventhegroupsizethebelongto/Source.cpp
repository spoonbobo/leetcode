// 2-scan O(n) solution

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> m;
        int k, gs, nelem;

        for (int i = 0; i < groupSizes.size(); i++)
            m[groupSizes[i]].push_back(i);

        for (auto& kv : m) {
            k = 0;
            gs = kv.second.size();
            while (k < gs) {
                nelem = min(kv.first, gs - k);
                vector<int> tmp(kv.second.begin() + k, kv.second.begin() + k + nelem);
                res.push_back(tmp);
                k += nelem;
            }
        }
        return res;
    }
};