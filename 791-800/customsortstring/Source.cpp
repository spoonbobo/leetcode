// O(n), O(1) space

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> ct;

        for (auto& c : s) {
            ct[c]++;
        }
        string res = "";
        for (auto& c : order) {
            while (ct[c]--) {
                res += c;
            }
        }

        for (auto& p : ct) {
            for (int i = 0; i < p.second; i++) {
                res += p.first;
            }
        }
        return res;
    }
};