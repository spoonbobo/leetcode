class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<int, int> ct;
        for (auto& c : s) {
            ct[c]++;
        }
        vector<int> freq;
        for (auto& p : ct) {
            freq.push_back(p.second);
        }

        for (int i = 1; i < freq.size(); i++) {
            if (freq[i] != freq[0])
                return false;
        }

        return true;
    }
};