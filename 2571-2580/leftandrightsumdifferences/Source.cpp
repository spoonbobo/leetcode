// prefix sums variant 
// O(n) solution (brute-force)

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> lefts{0};
        vector<int> rights{0};
        int n = nums.size();
        for (int i = 1; i < n; i++)
            lefts.push_back(lefts[i - 1] + nums[i - 1]);
        reverse(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
            rights.push_back(rights[i - 1] + nums[i - 1]);
        reverse(rights.begin(), rights.end());
        for (int i = 0; i < n; i++)
            nums[i] = abs(lefts[i] - rights[i]);
        return nums;
    }
};