// O(jewels * stones) solution

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        for (char& c : stones) {
            if (find(jewels.begin(), jewels.end(), c) != jewels.end())
                ans++;
        }
        return ans;
    }
};