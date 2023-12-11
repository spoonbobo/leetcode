// brute-force solution

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int>m;
        for (auto& e : arr) {
            m[e]++;
        }
        for (auto& p : m) {
            if (p.second > arr.size() * 0.25) {
                return p.first;
            }
        }
        return -1;
    }
};