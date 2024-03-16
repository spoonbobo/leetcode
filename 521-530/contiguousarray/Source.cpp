// brute-force O(n^3)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int interval = nums.size();
        int res = 0;
        while (interval > 0) {
            for (int i = 0; i + interval <= nums.size(); i++) {
                int bits[2] = { 0, 0 };
                for (int j = i; j < i + interval; j++) {
                    bits[nums[j]]++;
                }
                if (bits[0] == bits[1])
                    return interval;
            }
            interval--;
        }
        return 0;
    }
};