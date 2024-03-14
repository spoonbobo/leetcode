// solution 2, binary search

int bs(vector<int>& nums, int l, int r, const int& k) {
    int mid = l + (r - l) / 2;
    if (l > r)
        return 0;
    if (mid > 0 && nums[mid] >= k && nums[mid - 1] < k)
        return mid;
    else if (mid > 0 && nums[mid] >= k && nums[mid - 1] >= k)
        return bs(nums, l, mid - 1, k);
    return bs(nums, mid + 1, r, k);
}

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return bs(nums, 0, nums.size() - 1, k);
    }
};