// there may be existing a way to achieve O(n), can be optimized.

class Solution {
public:
    string finalString(string s) {
        string ans = "";
        for (auto& c : s) {
            if (c == 'i') {
                reverse(ans.begin(), ans.end());
                continue;
            }
            ans += c;
        }
        return ans;
    }
};