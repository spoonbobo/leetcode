// O(n) solution

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for (auto& o : operations) {
            if (find(o.begin(), o.end(), '-') != o.end()) {
                res--;
            }
            else res++;
        }
        return res;
    }
};