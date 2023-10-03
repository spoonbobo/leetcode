// O(n) solution, seems can be optimised!

int get_max(vector<int>& candies) {
    int maxe = INT_MIN;
    for (auto& c : candies) {
        if (c > maxe)
            maxe = c;
    }
    return maxe;
}

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxe = get_max(candies);
        for (auto& c : candies)
            ans.push_back(c + extraCandies >= maxe);
        return ans;
    }
};