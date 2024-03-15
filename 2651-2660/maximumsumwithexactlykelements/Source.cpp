class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int target = 0;
        for (auto& c : nums) {
            target = max(target, c);
        }
        return target * k + (k - 1) * (k) / 2;
    }
};