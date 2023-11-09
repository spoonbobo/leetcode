// O(n) time prefix sum solution, O(1) space
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, ps = 0;
        for (auto& e: gain) {
            ps+=e;
            if (ps>ans) ans=ps;
        }
        return ans;
    }
};