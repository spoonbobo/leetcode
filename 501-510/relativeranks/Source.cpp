// O(sort) time, O(n) space for hashmap
// quite space expensive, can be optimized.

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> tmpvec{score.begin(), score.end()};
        sort(tmpvec.begin(), tmpvec.end(), greater<>());
        unordered_map<int, string> map;
        for (int i = 0; i < tmpvec.size(); i++) {
            if (i == 0)
                map[tmpvec[i]] = "Gold Medal";
            else if (i == 1)
                map[tmpvec[i]] = "Silver Medal";
            else if (i == 2)
                map[tmpvec[i]] = "Bronze Medal";
            else
                map[tmpvec[i]] = to_string(i + 1);
        }
        vector<string > res;
        for (int i = 0; i < score.size(); i++) {
            res.push_back(map[score[i]]);
        }
        return res;
    }
};