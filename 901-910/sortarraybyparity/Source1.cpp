// optimized version, sorting numbers inplace, beats 97% time and 94% space

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                swap(nums[i], nums[k]);
                k++;
            }
        }

        return nums;
    }
};