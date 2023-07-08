// O(n) time and space

unordered_map<int, int> memory;

class Solution {
public:
    int climbStairs(int n) {
        // trivial cases
        if (n == 1) return 1;
        if (n == 2) return 2;

        // base cases
        memory[1] = 1;
        memory[2] = 2;

        // from stair level of 3, we are uncertain
        // just like human, we explore the world by ourselves
        for (int i = 3; i < n; i++) {
            memory[i] = memory[i - 1] + memory[i - 2];
        }

        return memory[n - 1] + memory[n - 2];
    }
};