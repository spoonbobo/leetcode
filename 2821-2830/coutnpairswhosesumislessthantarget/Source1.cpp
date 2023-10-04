// two-pointer + sort O(nlogn+n)->O(nlogn) solution

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int ans = 0;
        int i = 0, j = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while (i < j) {// i<j
            if (nums[i] + nums[j] < target) {
                cout << i << " " << j << endl;
                ans += j - i;
                i++; // tightening
            }
            else {
                j--; // loosenomg
            }
        }
        return ans;
    }
};