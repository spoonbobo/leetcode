// O(sort) solution, beats 85.79% time

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // sort the array
        sort(piles.begin(), piles.end(), greater());
        for (int i = 1; i < piles.size() / 3; i++)
            piles[1] += piles[i * 2 + 1];
        return piles[1];
    }
};