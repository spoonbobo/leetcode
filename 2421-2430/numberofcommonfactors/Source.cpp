// O(n) solution, seems there is O(1) solution by number theory?

class Solution {
public:
    int commonFactors(int a, int b) {
        int res = 0;
        if (a > b) {
            swap(a, b);
        }
        if (b % a == 0)
            res++;

        for (int i = 1; i <= a / 2; i++) {
            if (a % i == 0 && b % i == 0)
                res++;
        }

        return res;
    }
};