// O(logn) solution, but seems there is a faster and more straight forward solution

int bs(vector<int>& nums, int left, int right) {
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] - mid == 1) {
            if (mid - 1 >= 0 && nums[mid - 1] == mid - 1)
                return mid;
            else if (mid == 0)
                return 0;
        }

        if (nums[mid] == mid) // search right
            left = mid + 1;

        else
            right = mid - 1;
    }

    return nums.size();
}

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return bs(nums, 0, nums.size() - 1);
    }
};