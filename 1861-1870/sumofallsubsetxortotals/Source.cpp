// solve by backtracking, beats 100% time, and good space
// Without callstacks, use O(1) memory, actual O(n(n-1)/2) mem for this bt problem

void bt(vector<int>& nums, int left, int tempsum, int height, const int& n, int& res) {

    res += tempsum;

    // subset reaches return state
    if (height == n)
        return;

    for (int i = left; i < n; i++) {
        tempsum ^= nums[i]; // xor
        bt(nums, i + 1, tempsum, height + 1, n, res);
        tempsum ^= nums[i];
    }
}

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        bt(nums, 0, 0, 0, n, res);
        return res;
    }
};