// failed attempt

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int i, ps0, ps1, max_len; // problem size
        unordered_map<int, int> dp0;
        unordered_map<int, int> dp1;
        ps0 = nums[0] == 0 ? 1 : 0;
        ps1 = nums[0] == 1 ? 1 : 0;
        dp0[ps0]++; dp1[ps1]++;
        max_len = 0;

        for (i = 1; i < n; i++) {
            // update prefix sums
            ps0 += nums[i] == 0 ? 1 : 0;
            ps1 += nums[i] == 1 ? 1 : 0;
            dp0[ps0]++; dp1[ps1]++;

            if (dp0[ps1])
                max_len = ps1 * 2;
            if (dp1[ps0])
                max_len = ps0 * 2;
        }
        return max_len;
    }
};