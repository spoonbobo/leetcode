// Faster loading the truck by computing possible loads for each loading process
// Beats 99% time, and same space with previous

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

        int ptr = 0, res = 0, load;
        while (truckSize > 0) {
            if (rec[keys[ptr]] == 0) {
                ptr++;
                if (ptr > keys.size() - 1) break;
            }
            load = min(rec[keys[ptr]], truckSize);
            res += load * keys[ptr];
            rec[keys[ptr]] -= load;
            truckSize -= load;
        }
        return res;
    }
};