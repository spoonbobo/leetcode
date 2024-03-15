// O(n) solution

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;
        for (auto& c : s)
            ones += c - '0';

        for (int i = 0; i < s.length(); i++) {
            if (i == s.length() - 1 && ones == 1)
                s[i] = '1';

            else if (i != s.length() - 1 && ones == 1)
                s[i] = '0';

            else if (ones > 1) {
                s[i] = '1';
                ones--;
            }

        }
        return s;
    }
};