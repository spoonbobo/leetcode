// Optimised O(n) solution that beats 99% time 87% space

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> digits;
        for (auto num : nums) {
            string s = to_string(num);
            for (char c : s) {
                digits.push_back(c - '0');
            }
        }
        return digits;
    }
};