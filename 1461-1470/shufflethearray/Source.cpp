// O(n) solution, has to be optimized

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        int k = 0;
        while (k < n) {
            res.push_back(nums[k]); res.push_back(nums[k + n]);
            k++;
        }
        return res;
    }
};