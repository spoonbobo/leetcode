// O(n) time and space solution

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> res(2);
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (m[i + 1] == 2) {
                res[0] = i + 1;
            }
            if (m[i + 1] == 0) {
                res[1] = i + 1;
            }
        }
        return res;
    }
};