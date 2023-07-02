// this solution is kind of cheating.
class Solution {
public:
    int reverse(int x) {
        long int result = 0, temp = x;
        for (long int exp = 1; abs(x) / exp > 0; exp *= 10) {
            result = result * 10 + temp % 10;
            temp /= 10;
        }
        if (result > 2147483647 || result < -2147483648) return 0;
        return result;
    }
};
