// beats 96% runtime and 75% space
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // naive approach
        // trivial cases
        if (nums.size() == 1)
            return nums[0];

        sort(nums.begin(), nums.end(), greater<>());
        set<int> seen;

        for (int i = 0; i < nums.size(); i++) {
            seen.insert(nums[i]);
            if (seen.size() == 3) return nums[i];
        }
        return nums[0];
    }
};