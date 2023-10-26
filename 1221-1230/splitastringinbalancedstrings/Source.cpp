// O(n) stack solution, beats 100% time, but only 15% space, can be improved

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
        }

        // check
        for (auto& c : s) {
            if (c == 'R')
                rs.pop();
            else
                ls.pop();
            if (rs.size() == ls.size())
                ans++;
        }

        return ans;
    }
};