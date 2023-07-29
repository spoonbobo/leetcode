// O(sort) time solution

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans;
        sort(nums.begin(), nums.end());
        ans = (nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1);
        return ans;
    }
};