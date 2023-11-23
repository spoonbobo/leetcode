// O(m*n*logn) solution, can be optimized, but I carelessly spotted the best solution, so maybe leave it to future by any chances getting back to this

bool check(vector<int>& vec) {
    int ref = vec[1]-vec[0];
    for (int i=1; i<vec.size()-1; i++) {
        if (vec[i+1]-vec[i] != ref)
            return false;
    }
    return true;
}

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m, n, i;
        int start, end;
        vector<bool> res;
        m = l.size(); n = nums.size();
        for (i=0; i<m; i++) {
            vector<int> svec(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(svec.begin(), svec.end());
            res.push_back(check(svec));
        }
        return res;
    }
};