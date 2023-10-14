// O(n) time, O(1) space solution

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        unordered_map<string, int> m;
        m["type"] = 0;
        m["color"] = 1;
        m["name"] = 2;
        int res = 0;
        int key = m[ruleKey];
        for (int i = 0; i < items.size(); i++) {
            if (items[i][key] == ruleValue) res++;
        }
        return res;
    }
};