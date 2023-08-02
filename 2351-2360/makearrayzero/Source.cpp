// O(sort) solution
// this problem is equivalent to asking how many unique numbers are there.

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == 0)
                break;
            if (i != nums.size() - 1 && nums[i] == nums[i + 1])
                continue;
            res++;
        }

        return res;
    }
};