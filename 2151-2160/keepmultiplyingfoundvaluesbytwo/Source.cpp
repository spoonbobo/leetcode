// O(sort) solution beats 98% time and space

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > original)
                break;
            if (nums[i] == original)
                original *= 2;
        }

        return original;
    }
};