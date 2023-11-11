// runtime can be optimized

int f(int& x) {
    int ret = 0;
    string sd = to_string(x);
    for (auto& c : sd)
        ret += c - '0';
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