// O(sort) solution, beats 80% time, but space expensive, beats 20%. Can be optimized

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ctr;

        // O(nums1)
        for (auto num : nums1) {
            ctr[num]++;
        }

        // O(sort)
        vector<int> res;
        sort(nums2.begin(), nums2.end());
        for (int i = 0; i < nums2.size(); i++) {
            if (i != 0 && nums2[i] == nums2[i - 1])
                continue;
            if (ctr[nums2[i]])
                res.push_back(nums2[i]);
        }

        return  res;
    }
};