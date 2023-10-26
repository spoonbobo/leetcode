// Optimized O(n) solution of source.cpp, but still using stack, ending up in memory problem

class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        stack<int> rs;
        stack<int> ls;

        // init
        for (auto& c : s) {
            if (c == 'R')
                rs.push(1);
            else
                ls.push(1);
            if (rs.size() == ls.size())
                ans++;
        }

        return ans;
    }
};