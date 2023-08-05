// O(sort) and O(n) space, needs to be optimized!

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // sort arr
        sort(arr.begin(), arr.end());

        // hash map (value, vector)
        unordered_map<int, vector<vector<int>>>rec;

        // also, record min
        int min_value = INT_MAX, val;
        for (int i = 1; i < arr.size(); i++) {
            val = abs(arr[i] - arr[i - 1]);
            rec[val].push_back(vector<int>{arr[i - 1], arr[i]});
            if (val < min_value) min_value = val;
        }

        // return hash map.
        return rec[min_value];
    }
};