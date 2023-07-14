// This solution only beats around 65% of time, seems there is better 1..

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // O(n) solution
        unordered_map<int, int> counter;
        int target = nums.size() / 2;
        for (int i = 0; i < nums.size(); i++) {
            if (++counter[nums[i]] > target)
                return nums[i];
        }
        return 1;
    }
};