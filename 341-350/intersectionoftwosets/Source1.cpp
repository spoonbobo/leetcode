// O(sort) solution, beats 100% time, 99% space

bool bs(vector<int>& nums1, int val) {
    int l = 0, r = nums1.size() - 1;
    int mid;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums1[mid] == val) return true;

        else if (nums1[mid] > val)
            r = mid - 1;

        else
            l = mid + 1;
    }

    return false;
}

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res; int val;
        for (int i = 0; i < nums2.size(); i++) {
            val = nums2[i];
            if (i != 0 && val == nums2[i - 1])
                continue;
            if (bs(nums1, val))
                res.push_back(val);
        }

        return  res;
    }