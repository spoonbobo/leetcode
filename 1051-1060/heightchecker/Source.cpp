// O(sort) solution, beats 100% time.

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // 1. copy heights into a temporary vector (list)
        vector<int> copy(heights.begin(), heights.end());

        // 2. sort temporary vector
        sort(copy.begin(), copy.end());

        // 3. compare 2 vectors (list), find total difference.
        int difference = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != copy[i])
                difference++;
        }

        return difference;
    }
};