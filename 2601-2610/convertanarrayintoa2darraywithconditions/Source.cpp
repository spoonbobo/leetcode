// O(nKeys ** 2) solution, beats 6% time and around 20% space, have to optimize!

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        vector<vector<int>> res;

        for (auto& e : nums) {
            m[e]++;
        }

        while (n != 0) {
            vector<int> tmp;
            for (auto& p : m) {
                if (m[p.first] != 0) {
                    tmp.push_back(p.first);
                    m[p.first]--;
                    n--;
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};