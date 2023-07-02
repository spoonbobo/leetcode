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


// a better solution using limits
class Solution {
public:
    int reverse(int x) {
        int result = 0;

        while (x) {
            if (result > INT_MAX / 10 || result < INT_MIN / 10) return 0;
            result = result * 10 + x % 10;
            x /= 10;
        }

        return result;
    }
};