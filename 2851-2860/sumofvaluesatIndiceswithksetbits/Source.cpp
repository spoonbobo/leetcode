// O(n) solution

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0, ct, idx;
        // loop through all nums
        for (int i = 0; i < nums.size(); i++) { // k can be 0
            // for each num, count the 1 set bit by looking at the rightmost bit
            ct = 0;
            idx = i;
            while (idx) {
                ct += idx & 1;
                idx >>= 1;
            }
            if (ct == k) {
                ans += nums[i];
            }
        }
        return ans;
    }
};