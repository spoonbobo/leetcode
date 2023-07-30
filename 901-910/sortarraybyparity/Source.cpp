// O(n) solution but takes many space, beat 100% time

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> odd;
        vector<int> res;

        for (auto num : nums) {
            if (num % 2 == 0) res.push_back(num);
            else odd.push_back(num);
        }

        for (auto num : odd) {
            res.push_back(num);
        }

        return res;
    }
};