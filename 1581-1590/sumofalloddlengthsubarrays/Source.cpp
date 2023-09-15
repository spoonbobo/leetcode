// achieves O(n), beats 100% time, but used O(n) space complexity too, can be optimized

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        if (arr.size() < 3)
            return reduce(arr.begin(), arr.end());
        int ans = 0, nelem = arr.size(), offset;
        int n = arr.size();
        vector<int> prefix_sum(arr.begin(), arr.end());
        while (nelem > 0) {
            offset = arr.size() - nelem;
            for (int i = 0; i < n - 2 - offset; i++) {
                prefix_sum[i] += arr[i + offset + 1] + arr[i + offset + 2];
                if (nelem == arr.size()) {
                    if (i == 0)
                        ans += prefix_sum[i];
                    else
                        ans += arr[i + offset + 2];
                }
                ans += prefix_sum[i];
            }
            nelem -= 2;
        }
        return ans;
    }
};