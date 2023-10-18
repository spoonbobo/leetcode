// O(n^2) time O(1) space solution

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int res = 0, i, j, n = nums.size();
        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++) {
                if (abs(nums[i] - nums[j]) == k)
                    res++;
            }
        return res;
    }
};