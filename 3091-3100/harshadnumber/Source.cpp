class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sod = 0;
        int y = x;
        while (x != 0) {
            sod += x % 10;
            x /= 10;
        }
        if (y % sod == 0)
            return sod;
        return -1;
    }
};