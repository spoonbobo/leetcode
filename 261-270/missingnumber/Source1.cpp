// O(n) solution, seems there is an optimization can be done
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // trivial case
        if (nums[nums.size() - 1] == nums.size() - 1)
            return nums.size();

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > i) {
                if (i - 1 >= 0 && nums[i - 1] == i - 1)
                    return i;
                if (i == 0)
                    return 0;
            }
        }
        return nums.size();
    }
};