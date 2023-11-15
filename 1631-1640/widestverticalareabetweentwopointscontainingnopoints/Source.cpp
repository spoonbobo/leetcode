// O(nlogn) solution, beats 93% time

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        // get the widest width (x) with no point (y/x) in between them
        vector<int> xs;
        for (auto& coord : points)
            xs.push_back(coord[0]);
        sort(xs.begin(), xs.end());
        int ans = 0, dist;
        for (int i = 0; i < xs.size() - 1; i++) {
            dist = abs(xs[i + 1] - xs[i]);
            if (dist > ans)
                ans = dist;
        }
        return ans;
    }
};