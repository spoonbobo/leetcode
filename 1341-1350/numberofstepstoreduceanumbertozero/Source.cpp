// O(n/2) solution, beats 100% time

// Seems can be improved by bit manipulation

class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        while (true) {
            if (num == 0)
                break;
            if (num % 2 == 0)
                num /= 2;
            else
                num -= 1;
            steps++;
        }
        return steps;
    }
};