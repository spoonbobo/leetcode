// https://spoonbobo.github.io/2023/09/25/leetcode-2317.html
// O(n) solution. 

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int res = 0;
        for (auto& n : nums) {
            res |= n;
        }
        return res;
    }
};