struct Node {
    int val = -1;
};

// O(n) time and space solution

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n, ct, i, max_length;
        unordered_map<int, Node> dpct;
        n = nums.size();
        ct = 0;
        dpct[ct].val = -1;
        max_length = 0;
        for (i = 0; i < n; i++) {
            ct += nums[i] == 0 ? -1 : 1;

            // if ct becomes 0 at arr[i], so arr[0] until arr[i] inclusively, is valid balanced array
            if (ct == 0)
                max_length = i + 1;

            // if ct is never found, then array is invalid
            else if (dpct[ct].val == -1)
                dpct[ct].val = i;

            // if ct met at arr[j] where j is first occurence of ct, then arr[j] until arr[i] inclusively
            // is valid balanced array
            else
                max_length = max(max_length, i - dpct[ct].val);
        }
        return max_length;
    }
};