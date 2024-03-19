class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ct = 0, descrep;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                descrep = nums[i - 1] - nums[i] + 1;
                nums[i] += descrep;
                ct += descrep;
            }
        }
        return ct;
    }
};