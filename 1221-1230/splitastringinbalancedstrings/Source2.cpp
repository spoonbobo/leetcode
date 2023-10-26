// O(n) time and O(1) space solution

class Solution {
public:
    int balancedStringSplit(string s) {
        int ls, rs, ans;
        ls = rs = ans = 0;
        for (auto& c : s) {
            c == 'R' ? rs++ : ls++;
            if (ls == rs)
                ans++;
        }
        return ans;
    }
};