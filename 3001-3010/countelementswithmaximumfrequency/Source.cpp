// 2-scan solution

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;
        int max_freq = 0;
        for (auto& e : nums) {
            m[e]++;
            if (m[e] > max_freq)
                max_freq = m[e];
        }
        int res = 0;
        for (auto& e : nums) {
            if (m[e] == max_freq)
                res++;
        }
        return res;
    }
};