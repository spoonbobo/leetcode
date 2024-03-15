class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;

        int a, b;
        a = b = 0;

        for (auto& e : nums1)
            m1[e]++;

        for (auto& e : nums2)
            m2[e]++;

        for (auto& e : nums1)
            if (m2[e])
                a++;

        for (auto& e : nums2)
            if (m1[e])
                b++;

        return vector<int>{a, b};

    }
};