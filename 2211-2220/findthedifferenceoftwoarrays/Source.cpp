// O(nums1+nums2) space + O(set_difference) time solution
// beats roughly 33% time and space, seems can be improved.

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> diff1;
        vector<int> diff2;
        set<int> s1{nums1.begin(), nums1.end()}, s2{ nums2.begin(), nums2.end() };
        vector<vector<int>> res;
        set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(diff1, diff1.begin()));
        set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), inserter(diff2, diff2.begin()));
        res.push_back(diff1);
        res.push_back(diff2);
        return res;

    }
};