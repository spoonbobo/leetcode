struct Node {
    int val = -1;
    bool found = false;
};

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n, ct, i, max_length;
        unordered_map<int, Node> dpct;
        n = nums.size();
        ct = 0;
        dpct[ct].val = -1;
        dpct[ct].found = true;
        max_length = 0;
        for (i = 0; i < n; i++) {
            ct += nums[i] == 0 ? -1 : 1;
            if (!dpct[ct].found) {
                dpct[ct].val = i;
                dpct[ct].found = true;
            }
            else {
                max_length = max(max_length, i - dpct[ct].val);
            }
        }
        return max_length;
    }
};