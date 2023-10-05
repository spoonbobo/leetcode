// prefix sums variant 
// O(n) solution, slightly optimised compared to source.cpp, however, less memory could be used.

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        // sum
        int n = nums.size();
        vector<int> ps{nums[0]};
        vector<int> rps{nums[n - 1]};
        for (int i = 1; i < n; i++) {
            ps.push_back(ps[i - 1] + nums[i]);
            rps.push_back(rps[i - 1] + nums[n - i - 1]);
        }
        for (int i = 0; i < n; i++)
            nums[i] = abs(ps[i] - rps[n - i - 1]);

        return nums;
    }
};