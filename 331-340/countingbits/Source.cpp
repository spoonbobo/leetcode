// O(nlogn) solution
int bitcount(int i) {
    int ret = 0;
    while (i != 0) {
        ret += i & 1;
        i >>= 1;
    }
    return ret;
}
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i < n + 1; i++) {
            res.push_back(bitcount(i));
        }
        return res;
    }
};