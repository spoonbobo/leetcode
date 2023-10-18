// Hash table solution, O(n^2) time and O(n) space
// it's less optimized version of source.cpp

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        // key is number, value is occurences;
        unordered_map<int, vector<int>> ct;
        for (int i = 0; i < nums.size(); i++)
            ct[nums[i]].push_back(i);

        int res = 0, i, j;
        for (i = 0; i < nums.size(); i++) {
            if (ct[nums[i] + k].size() > 0) {
                for (j = 0; j < ct[nums[i] + k].size(); j++) {
                    if (ct[nums[i] + k][j] > i) break;
                }
                res += ct[nums[i] + k].size() - j;
            }
            if (ct[nums[i] - k].size() > 0) {
                for (j = 0; j < ct[nums[i] - k].size(); j++) {
                    if (ct[nums[i] - k][j] > i) break;
                }
                res += ct[nums[i] - k].size() - j;
            }
        }

        return res;
    }
};