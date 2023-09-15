// O(n) solution

class Solution {
public:
    int numberOfMatches(int n) {
        int matches = 0;
        while (true) {
            if (n == 1)
                break;
            if (n % 2 == 0) {
                matches += n / 2;
                n /= 2;
            }
            else {
                matches += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            }

        }
        return matches;
    }
};