// two pointers
// beats 100% time, 80% time

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_k = -1;
        int i = 0, j = nums.size() - 1;
        while (nums[i] < 0 && nums[j] > 0 && i < nums.size() && j >= 0) {
            if (abs(nums[i]) == nums[j])
                return nums[j];
            if (abs(nums[i]) < nums[j])
                j--;
            else
                i++;
        }
        return max_k;
    }
};