// O(m*n) solution

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int largest = INT_MIN, wealth;
        for (auto& a : accounts) {
            wealth = reduce(a.begin(), a.end());
            if (wealth > largest) largest = wealth;
        }
        return largest;
    }
};