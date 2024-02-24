class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> arr;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2) {
            arr.push_back(nums[i + 1]);
            arr.push_back(nums[i]);
        }
        return arr;
    }
};