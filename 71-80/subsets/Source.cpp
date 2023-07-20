// By drawing out example, best solution is there!
// Image attached to same folder

void bt(vector<int>& nums, vector<vector<int>>& res, vector<int> traversed) {
    res.push_back(traversed);

    for (int i = 0; i < nums.size(); i++) {
        if (traversed.size() == 0 || nums[i] < traversed[traversed.size() - 1]) {
            traversed.push_back(nums[i]);
            bt(nums, res, traversed);
            traversed.pop_back();
        }
        else return;
    }
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        bt(nums, res, vector<int>{});
        return res;
    }
};