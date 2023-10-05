// prefix sums variant 
// O(n) solution, O(1) space used, beats 100% time, and 60% space

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        // sum
        int sumv = accumulate(nums.begin(), nums.end(), 0);
        int tmp, n = nums.size(), prev = 0;
        for (int i = 0; i < n; i++) {
            tmp = nums[i];
            nums[i] = abs(sumv - (nums[i] + prev));
            sumv -= tmp;
            prev += tmp;
        }
        return nums;
    }
};