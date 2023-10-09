// O(n**2) solution, worst case for insert is O(n) which is inserting at front.

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            res.insert(res.begin() + index[i], nums[i]);
        }
        return res;
    }
};