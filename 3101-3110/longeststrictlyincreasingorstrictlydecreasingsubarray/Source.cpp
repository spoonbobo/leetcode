class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int i, j, n;
        i = 0; j = 1; n = nums.size();
        while (i < n && j < n) {
            if (!(nums[j] > nums[j - 1])) {
                i = j;
                j = i + 1;
            }
            else {
                ans = max(ans, j - i + 1);
                j++;
            }
        }

        i = 0; j = 1;
        while (i < n && j < n) {
            if (!(nums[j] < nums[j - 1])) {
                i = j;
                j = i + 1;
            }
            else {
                ans = max(ans, j - i + 1);
                j++;
            }
        }

        return ans;
    }
};`