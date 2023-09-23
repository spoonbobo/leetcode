// O(n) solution, beats 100% time, but seems to have O(1) solution.

class Solution {
public:
    int addDigits(int num) {
        int tmp; string strint;
        while (true) {
            strint = to_string(num);
            if (strint.length() == 1)
                break;
            tmp = 0;
            for (auto& c : strint)
                tmp += c - '0';
            num = tmp;
        }
        return num;
    }
};