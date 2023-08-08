// O(sort) time and O(n) time. Can be optimized

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> map;
        int max_k = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0 && map[-nums[i]] > 0 && nums[i] > max_k)
                max_k = nums[i];
            map[nums[i]]++;
        }
        return max_k;
    }
};