// brute force way
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> dp(pow(10, 5) + 1, 0);
        cout << dp.size() << endl;
        for (int i = 0; i < nums.size(); i++) {
            if (dp[nums[i]])
                return nums[i];
            dp[nums[i]]++;
        }
        return 1;
    }
};