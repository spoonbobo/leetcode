// O(n) solution, beats 100% time, 54% space

class Solution {
public:
    int xorOperation(int n, int start) {
        int res, k;
        res = start; k = start + 2;
        for (int i = 0; i < n - 1; i++) {
            res ^= k;
            k += 2;
        }
        return res;
    }
};