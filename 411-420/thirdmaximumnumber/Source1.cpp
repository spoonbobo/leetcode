// Seems to be an optimized solution to Source.cpp
// as it reduces some complexity for set insert operation

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // naive approach
        // trivial cases
        if (nums.size() == 1)
            return nums[0];

        sort(nums.begin(), nums.end(), greater<>());
        set<int> seen;
        seen.insert(nums[0]);
        int last_seen = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == last_seen) continue;
            else {
                last_seen = nums[i];
                seen.insert(nums[i]);
                if (seen.size() == 3)
                    return nums[i];
            }
        }
        return nums[0];
    }
};