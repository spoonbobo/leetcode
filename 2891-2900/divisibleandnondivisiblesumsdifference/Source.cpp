// O(1) time and space solution.

class Solution {
public:
    int differenceOfSums(int n, int m) {
        return (n * (n + 1) / 2) - (((float)(n / m) / (float)2) * ((float)2 * m + ((n / m) - 1) * (float)m)) * 2;
    }
};