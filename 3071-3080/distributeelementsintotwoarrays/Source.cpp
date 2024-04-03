class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a{nums[0]};
        vector<int> b{nums[1]};
        vector<int> res;
        for (int i = 2; i < nums.size(); i++) {
            if (a[a.size() - 1] > b[b.size() - 1])
                a.push_back(nums[i]);
            else
                b.push_back(nums[i]);
        }
        for (int i = 0; i < a.size(); i++)
            res.push_back(a[i]);

        for (int i = 0; i < b.size(); i++)
            res.push_back(b[i]);
        return res;
    }
};