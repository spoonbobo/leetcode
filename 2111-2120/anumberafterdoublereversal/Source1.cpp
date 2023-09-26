// O(1) one-liner

class Solution {
public:
    bool isSameAfterReversals(int num) {
        return (num < 10 | num % 10);
    }
};