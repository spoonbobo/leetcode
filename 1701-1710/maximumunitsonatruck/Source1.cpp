// Slight optimization of source.cpp, beats bit more space.
// Seems there is some greedy method to solve this

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // hash(n, appear)
        unordered_map<int, int> rec;
        set<int> rec2;
        for (int i = 0; i < boxTypes.size(); i++) {
            rec[boxTypes[i][1]] += boxTypes[i][0];
            rec2.insert(boxTypes[i][1]);
        }
        vector<int> keys(rec2.begin(), rec2.end());
        sort(keys.begin(), keys.end(), greater<>());

        int ptr = 0, res = 0;
        while (truckSize > 0) {
            if (rec[keys[ptr]] == 0) {
                ptr++;
                if (ptr > keys.size() - 1) break;
            }
            rec[keys[ptr]]--;
            res += keys[ptr];
            truckSize--;
        }
        return res;
    }
};