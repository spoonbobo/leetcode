// This solution is better as prune left tree and beats 30% more on time with space unchanged
// But still can try to use more space to accelerate the speed
// So, can be further optimized for sure

#include <iostream>
#include <vector>

using namespace std;

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
            if (find(res.begin(), res.end(), nums) != res.end()) {
                swap(nums[l], nums[i]);
                continue;
            }
            permuteall(nums, l + 1, r, res); // go deeper (also fixed left element)
            swap(nums[l], nums[i]); // swap back for sake of goodness
        }
    }

}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;

        permuteall(nums, 0, nums.size() - 1, res);

        return res;
    }
};  