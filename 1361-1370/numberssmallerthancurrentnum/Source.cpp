// O(sort) time complexity solution. Use O(n) space for hash table

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, int> tracker;
        vector<int> res(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        int num = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i == 0 || !(i != 0 && nums[i] == nums[i - 1]))
                tracker[nums[i]] = num;
            num++;
        }
        for (int i = 0; i < n; i++)
            res[i] = tracker[res[i]];
        return res;
    }
};