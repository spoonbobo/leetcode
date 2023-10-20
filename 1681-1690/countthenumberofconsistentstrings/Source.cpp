// O(n) time & O(1) space solution;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0;
        bool ok;
        unordered_map<char, int> m;
        for (auto& c : allowed)
            m[c]++;
        for (int i = 0; i < words.size(); i++) {
            ok = true;
            for (int j = 0; j < words[i].size(); j++) {
                if (m[words[i][j]] == 0) {
                    ok = false;
                    break;
                }
            }
            res += ok;
        }
        return res;
    }
};