// brute-force solution, has to be optimised

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res = 0;
        int n = nums.size(), interval = 0, i, j, ct;
        while (interval < n) {
            for (i = 0; i + interval < n; i++) {
                unordered_map<int, int> m;
                ct = 0;
                for (j = i; j < i + interval + 1; j++) {
                    if (m[nums[j]])
                        continue;
                    m[nums[j]]++;
                    ct++;
                }
                res += pow(ct, 2);
            }
            interval++;
        }
        return res;
    }
};