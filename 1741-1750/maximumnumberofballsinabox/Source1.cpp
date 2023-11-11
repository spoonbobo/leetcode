// slightly optimized f compared to source.cpp

int f(int x) {
    int ret = 0;
    while (x) {
        ret += x % 10;
        x = x / 10;
    }
    return ret;
}

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int maxn = 1, sumofdigits;
        unordered_map<int, int> m;
        for (int i = lowLimit; i <= highLimit; i++) {
            sumofdigits = f(i);
            m[sumofdigits]++;
            if (m[sumofdigits] > maxn)
                maxn = m[sumofdigits];
        }
        return maxn;
    }
};