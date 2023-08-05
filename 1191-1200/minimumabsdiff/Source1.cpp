// Optimised solution, O(sort) time, O(n) space
// 2 scan to get the result.

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // sort arr
        sort(arr.begin(), arr.end());

        // get min O(n)
        int min_value = INT_MAX, val;
        for (int i = 1; i < arr.size(); i++) {
            val = abs(arr[i] - arr[i - 1]);
            if (val < min_value) min_value = val;
        }

        vector<vector<int>> res;
        for (int i = 1; i < arr.size(); i++) {
            val = abs(arr[i] - arr[i - 1]);
            if (val == min_value)
                res.push_back(vector<int>{arr[i - 1], arr[i]});
        }

        return res;
    }
};