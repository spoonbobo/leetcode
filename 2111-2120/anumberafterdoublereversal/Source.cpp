// O(1) solution, beats 100% time

class Solution {
public:
    bool isSameAfterReversals(int num) {
        string numstr = to_string(num);
        if (numstr[numstr.length() - 1] == '0' && numstr.length() > 1)
            return false;
        return true;
    }
};