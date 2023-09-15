// O(digitCount(num)) solution, beats 100% time

class Solution {
public:
    int countDigits(int num) {
        int ans = 0;
        string numstr = to_string(num);
        int digit;
        for (char& c : numstr) {
            digit = c - '0';
            if (num % digit == 0) ans++;
        }
        return ans;
    }
};