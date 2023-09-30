// 2 scan solution O(n)

class Solution {
public:
    int sumBase(int n, int k) {
        int newint = 0, exp = 0;
        while (n > 0) {
            newint += pow(10, exp) * (n % k); // 34%6 -> 4
            n /= k;
            exp++;
        }

        int res = 0;
        while (newint > 0) {
            res += newint % 10;
            newint /= 10;
        }

        return res;
    }
};