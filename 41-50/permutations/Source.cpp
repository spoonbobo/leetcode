// O(n*n!) solution
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void permuteall(vector<int>& nums, int l, int r, vector<vector<int>>& res) {
    if (l == r) {
        // reaches depth
        res.push_back(nums);
    }
    else {
        for (int i = l; i <= r; i++) {
            swap(nums[l], nums[i]);
            permuteall(nums, l + 1, r, res); // go deeper (also fixed left element)
            swap(nums[l], nums[i]); // swap back for sake of goodness
        }
    }

}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        permuteall(nums, 0, nums.size() - 1, res);

        return res;
    }
};