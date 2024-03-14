// solution 1, linear search

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] >= k)
                break;
        }
        return i;
    }
};