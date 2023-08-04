// Using bs, very slow, needs to be optimized

int bs(vector<int>& nums, int q, int l, int r) {
    int mid;
    if (l <= r) {
        mid = l + (r - l) / 2;

        if (q == nums[mid]) return mid + 1;
        if (mid > 0 && q < nums[mid] && q > nums[mid - 1]) return mid;
        if (mid == 0 && nums[mid] > q) return 0;

        else if (nums[mid] > q) {
            return bs(nums, q, l, r - 1);
        }

        return bs(nums, q, mid + 1, r);
    }
    return nums.size();
}

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i] + nums[i - 1];
        }

        for (int q : queries) {
            cout << q << endl;
            ans.push_back(bs(nums, q, 0, nums.size() - 1));
        }

        return ans;
    }
};